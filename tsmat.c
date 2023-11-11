/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====
    Copyright (c) 2018 Neoway Technologies, Inc.
    All rights reserved.
    Confidential and Proprietary - Neoway Technologies, Inc.
*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*/

#include "nwy_at.h"
#include "nwy_common.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

/*---------------------------Macro Definition---------------------------*/

#undef LOG_MSG_TAG
#define LOG_MSG_TAG      "AT_TEST"

#undef LOG_MSG_LEVEL
#define LOG_MSG_LEVEL    LOG_DEBUG

#undef LOG_MSG_MASK
#define LOG_MSG_MASK     LOG_MASK_STD

int handle_onUnsolicited(char *cmd, const char *urc_info, int urc_len);
int fd1; //дескриптор канала fifo1
int fd2; //дескриптор канала fifo2
char bufin[]="Передаем привет для чтения из fifo";
char bufout[200];
char clearbuf[200];

int oldbuf_len;



nwy_at_urc_t at_cmd_urc_table[] = 
{
    {"+CMT",            handle_onUnsolicited},
    {"+CLCC",           handle_onUnsolicited},
    {"RING",            handle_onUnsolicited},
    {"NO CARRIER",      handle_onUnsolicited},
    {"+CSQ",            handle_onUnsolicited},
    {"+COPS",           handle_onUnsolicited},
    {"+CREG",           handle_onUnsolicited},
    {"+CUSD",           handle_onUnsolicited},
    {"+CUSD",           handle_onUnsolicited},
    {"+CPIN",           handle_onUnsolicited},
};

int nwy_at_urc_table_size = sizeof(at_cmd_urc_table)/sizeof(at_cmd_urc_table[0]);

/*---------------------------Function Definition--------------------------*/

int handle_onUnsolicited(char *cmd, const char *urc_info, int urc_len)
{
    
    printf("\n=====================================\n");
    printf("cmd: %s\n", cmd);
    printf("info: %s\n", urc_info);
    printf("length: %d\n", urc_len);
    printf("=====================================\n");
    

    // printf("oldbuf_len: %d\n", oldbuf_len);
    // printf("clearbuf: %s\n", clearbuf);

    write(fd2,urc_info,urc_len) ;

    return 0;
}

int main()
{
    int ret;
    char *sptr = NULL;
    int i = 0;
    char send_cmd[NWY_AT_LEN_MAX] = {0};
    char resp[NWY_AT_LEN_MAX] = {0};


    int status;
    
    /*
    status = system(NULL);
    if (status)
      printf("Shell execution is supported.");
    else
      printf("Shell execution is not supported.");
    */



    int l = strlen(bufin);

//удалить fifo, если он уже есть
    unlink("/tmp/tsmat.pipein");
    unlink("/tmp/tsmat.pipeout");
//создать fifo  и открыть его для всех
    if((mkfifo("/tmp/tsmat.pipein", S_IRWXO | S_IRWXG | S_IRWXU)) == -1) {
        printf("Невозможно создать /tmp/tsmat.pipein\n");
        return 1;
    }
    if((mkfifo("/tmp/tsmat.pipeout", S_IRWXO | S_IRWXG | S_IRWXU)) == -1) {
        printf("Невозможно создать /tmp/tsmat.pipeout\n");
        return 1;
    }
//Открываем fifo для чтения и записи
    if((fd1=open("/tmp/tsmat.pipein", O_RDWR | O_NONBLOCK)) == - 1)  {
        // printf("/tmp/tsmat.pipein\n");
        return 2;
    }

    if((fd2=open("/tmp/tsmat.pipeout", O_RDWR | O_NONBLOCK)) == - 1)  {
        // printf("/tmp/tsmat.pipeout\n");
        return 2;
    }

    printf("Pipe size S: %d\n", fcntl(fd2, F_GETPIPE_SZ));
    fcntl(fd2, F_SETPIPE_SZ, 4096);
    printf("Pipe size E: %d\n", fcntl(fd2, F_GETPIPE_SZ));


    printf("nwy at test start\n");

    ret = nwy_at_port_init(NULL);
    if (ret != 0)
    {
        printf("nwy_at_port_init failed\n");
        return -1;
    }

    ret = nwy_at_reg_urc_cb_func(at_cmd_urc_table, nwy_at_urc_table_size);
    if(ret == NWY_RES_OK)
    {
        printf("register success!\n");
    }


    while(1)
    {
        unsigned int rlen = read(fd1, &bufout, 1024);

        if(rlen == -1) printf("Ошибка чтения из fifo\n");
        else{
            bufout[rlen-1] = '\0';
            printf("Получено из канала fifo:%s\n",bufout);
            printf("Длина:%d\n",rlen);
            sprintf(send_cmd, "%s%s", bufout, "\r\n");
            ret = nwy_at_send_cmd(send_cmd, resp, NWY_AT_WAIT_DEFAULT);

            if (ret != 0)
            {
                printf("Send at cmd failed: %d\r\n", ret);
                return 1;
            } else {
                // printf("Send OK\r\n");

            }
            if(resp != NULL)
            {
                printf("\n**********************************\n");
                printf("%s", resp);
                printf("%d", strlen(resp));
                printf("\n**********************************\n");

                write(fd2,resp,strlen(resp)) ;

            }
        }



        sleep(1);

    }

error:
    nwy_at_unreg_urc_cb_func();
    nwy_at_port_deinit();

    return 0;
}
