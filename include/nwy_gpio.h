/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====
    Copyright (c) 2018 Neoway Technologies, Inc.
    All rights reserved.
    Confidential and Proprietary - Neoway Technologies, Inc.
    Author: Shi.Shaogang
    Date: 2018.06
*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*/

#ifndef __NWY_GPIO_H__
#define __NWY_GPIO_H__

#ifdef __cplusplus
extern "C" {
#endif
/*----------------------------Type Definition-----------------------------*/
typedef enum nwy_num{
    NWY_GPIO_32 = 32,
    NWY_GPIO_33 = 33,
    NWY_GPIO_61 = 61,
    NWY_GPIO_71 = 71,
    NWY_GPIO_75 = 75,
    NWY_GPIO_76 = 76,
    NWY_GPIO_84 = 84,
    NWY_GPIO_85 = 85,
    NWY_GPIO_99 = 99,
    NWY_GPIO_126 = 126
}nwy_num_t;

typedef enum nwy_dir{
    NWY_INPUT = 0,  
    NWY_OUTPUT,    
    NWY_IRQ_RISING,
    NWY_IRQ_FALLING,
    NWY_IRQ_RISING_FALLING,
    NWY_IRQ_HIGH,
    NWY_IRQ_LOW,
    NWY_SLEEP_WAKE
}nwy_dir_t;

typedef enum nwy_val{
    NWY_LOW = 0,
    NWY_HIGH    
}nwy_val_t;

typedef enum {
    NWY_FALLING_SLEEP_WAKEUP = 0,
    NWY_RISING_SLEEP_WAKEUP
}nwy_slp_trig_mode_t;

typedef enum {
    NWY_WAKE_STATE = 0,
    NWY_SLEEP_STATE
}nwy_state_t;

/*---------------------------Function Definition--------------------------*/
int nwy_gpio_set_val(int gpio_n, int value);
int nwy_gpio_get_val(int gpio_n);
int nwy_gpio_set_dir(int gpio_n, int dir);
int nwy_gpio_get_dir(int gpio_n);
int nwy_gpio_irq_config(int gpio_n, int irq_mode, void (*irq_callback)(int));
int nwy_gpio_irq_config_with_debounce(int gpio_n, int irq_mode, void (*irq_callback)(int), int debounce_ms);
int nwy_gpio_pm_config(int gpio_n, int irq_mode, int sleep_mode, int sleep_en, void (*irq_callback)(int));
int nwy_gpio_pm_state_get(void);
int nwy_gpio_irq_close(int gpio_n);
int nwy_gpio_irq_enable(int gpio_n);
int nwy_gpio_irq_disable(int gpio_n);
int nwy_vbus_get(void);

#ifdef __cplusplus
   }
#endif

#endif 
