// #include <stdio.h>
// #include <freertos/FreeRTOS.h>
// #include <freertos/task.h>
// #include "freertos/queue.h"
// #include <esp_system.h>
// #include <esp_log.h>
// #include <driver/gpio.h>
// #include "esp_timer.h"




// #ifndef APP_CPU_NUM
// #define APP_CPU_NUM PRO_CPU_NUM
// #endif

// #define SEG_A_GPIO 12
// #define SEG_B_GPIO 13
// #define SEG_C_GPIO 35
// #define SEG_D_GPIO 33
// #define SEG_E_GPIO 34
// #define SEG_F_GPIO 10
// #define SEG_G_GPIO 11
// #define VBUS_INTR GPIO_NUM_42

// #define LED_BLUE1 3
// #define LED_BLUE2 4
// #define RGB_RED 15
// #define RGB_GREEN 16
// #define RGB_BLUE 17

// #define BTN1 GPIO_NUM_19
// #define BTN2 GPIO_NUM_21
// #define BTN3 GPIO_NUM_18


// xQueueHandle BTN1Queue;
// xQueueHandle BTN2Queue;
// xQueueHandle BTN3Queue;
// xQueueHandle VBUS_INTRQueue;



// bool isLed_menu = true;
// bool isLed_setup = false;

// uint32_t pre_time_BTN1 = 0;
// uint32_t pre_time_BTN2 = 0;
// uint32_t pre_time_BTN3 = 0;
// uint8_t pre_time_vbus_intr = 0;

// bool vbus_flag =true;
// int menu_cursor=0;
// int setup_cursor=0;

// static void led_menu()
// {
//     isLed_menu = true;
//     isLed_setup = false;
//     gpio_set_direction(LED_BLUE1, GPIO_MODE_OUTPUT);
//     if(menu_cursor==0)
//     {
//         gpio_set_level(LED_BLUE2, 1);
//         gpio_set_level(LED_BLUE1, 0);
//     }
//     if(menu_cursor == 1)
//     {
//         gpio_set_level(LED_BLUE1, 1);
//         gpio_set_level(LED_BLUE2, 0);
//     }
// }

// static void led_setup()
// {
//     isLed_menu =  false;
//     isLed_setup = true;
//     switch (setup_cursor)
//     {
//         case 0: // Display '0'
//             gpio_set_level(SEG_A_GPIO, 1);
//             gpio_set_level(SEG_B_GPIO, 1);
//             gpio_set_level(SEG_C_GPIO, 1);
//             gpio_set_level(SEG_D_GPIO, 1);
//             gpio_set_level(SEG_E_GPIO, 1);
//             gpio_set_level(SEG_F_GPIO, 1);
//             gpio_set_level(SEG_G_GPIO, 0);
//             break;
//         case 1: // Display '1'
//             gpio_set_level(SEG_A_GPIO, 0);
//             gpio_set_level(SEG_B_GPIO, 1);
//             gpio_set_level(SEG_C_GPIO, 1);
//             gpio_set_level(SEG_D_GPIO, 0);
//             gpio_set_level(SEG_E_GPIO, 0);
//             gpio_set_level(SEG_F_GPIO, 0);
//             gpio_set_level(SEG_G_GPIO, 0);
//             break;
//         case 2: // Display '2'
//             gpio_set_level(SEG_A_GPIO, 1);
//             gpio_set_level(SEG_B_GPIO, 1);
//             gpio_set_level(SEG_C_GPIO, 0);
//             gpio_set_level(SEG_D_GPIO, 1);
//             gpio_set_level(SEG_E_GPIO, 1);
//             gpio_set_level(SEG_F_GPIO, 0);
//             gpio_set_level(SEG_G_GPIO, 1);
//             break;
//         case 3: // Display '3'
//             gpio_set_level(SEG_A_GPIO, 1);
//             gpio_set_level(SEG_B_GPIO, 1);
//             gpio_set_level(SEG_C_GPIO, 1);
//             gpio_set_level(SEG_D_GPIO, 1);
//             gpio_set_level(SEG_E_GPIO, 0);
//             gpio_set_level(SEG_F_GPIO, 0);
//             gpio_set_level(SEG_G_GPIO, 1);
//             break;
//         case 4: // Display '4'
//             gpio_set_level(SEG_A_GPIO, 0);
//             gpio_set_level(SEG_B_GPIO, 1);
//             gpio_set_level(SEG_C_GPIO, 1);
//             gpio_set_level(SEG_D_GPIO, 0);
//             gpio_set_level(SEG_E_GPIO, 0);
//             gpio_set_level(SEG_F_GPIO, 1);
//             gpio_set_level(SEG_G_GPIO, 1);
//             break;
//         case 5: // Display '5'
//             gpio_set_level(SEG_A_GPIO, 1);
//             gpio_set_level(SEG_B_GPIO, 0);
//             gpio_set_level(SEG_C_GPIO, 1);
//             gpio_set_level(SEG_D_GPIO, 1);
//             gpio_set_level(SEG_E_GPIO, 0);
//             gpio_set_level(SEG_F_GPIO, 1);
//             gpio_set_level(SEG_G_GPIO, 1);
//             break;
//         case 6: // Display '6'
//             gpio_set_level(SEG_A_GPIO, 1);
//             gpio_set_level(SEG_B_GPIO, 0);
//             gpio_set_level(SEG_C_GPIO, 1);
//             gpio_set_level(SEG_D_GPIO, 1);
//             gpio_set_level(SEG_E_GPIO, 1);
//             gpio_set_level(SEG_F_GPIO, 1);
//             gpio_set_level(SEG_G_GPIO, 1);
//             break;
//         case 7: // Display '7'
//             gpio_set_level(SEG_A_GPIO, 1);
//             gpio_set_level(SEG_B_GPIO, 1);
//             gpio_set_level(SEG_C_GPIO, 1);
//             gpio_set_level(SEG_D_GPIO, 0);
//             gpio_set_level(SEG_E_GPIO, 0);
//             gpio_set_level(SEG_F_GPIO, 0);
//             gpio_set_level(SEG_G_GPIO, 0);
//             break;
//         case 8: // Display '8'
//             gpio_set_level(SEG_A_GPIO, 1);
//             gpio_set_level(SEG_B_GPIO, 1);
//             gpio_set_level(SEG_C_GPIO, 1);
//             gpio_set_level(SEG_D_GPIO, 1);
//             gpio_set_level(SEG_E_GPIO, 1);
//             gpio_set_level(SEG_F_GPIO, 1);
//             gpio_set_level(SEG_G_GPIO, 1);
//             break;
//         case 9: // Display '9'
//             gpio_set_level(SEG_A_GPIO, 1);
//             gpio_set_level(SEG_B_GPIO, 1);
//             gpio_set_level(SEG_C_GPIO, 1);
//             gpio_set_level(SEG_D_GPIO, 1);
//             gpio_set_level(SEG_E_GPIO, 0);
//             gpio_set_level(SEG_F_GPIO, 1);
//             gpio_set_level(SEG_G_GPIO, 1);
//             break;
//         default:
//             printf("Invalid setup_cursor value\n");
//             break;
//     }
       
// }


// void BTN2Task(void *params)
// {
//     gpio_set_direction(BTN2, GPIO_MODE_INPUT);
//     gpio_set_intr_type(BTN2, GPIO_INTR_NEGEDGE);
//     int BTN_NUMBER = 0;
//     while (1)
//     {

//         if (xQueueReceive(BTN2Queue, &BTN_NUMBER, portMAX_DELAY))
//         {
//             printf(" Button 2 pressed!\n");
//             xQueueReset(BTN2Queue);
//         }
//         vTaskDelay(10/portTICK_PERIOD_MS);
//     }
// }


// void BTN1Task(void *params)
// {
//     gpio_set_direction(BTN1, GPIO_MODE_INPUT);
//     gpio_set_intr_type(BTN1, GPIO_INTR_NEGEDGE);
//     int BTN_NUMBER = 0;
//     while (1) {
//         if (xQueueReceive(BTN1Queue, &BTN_NUMBER, portMAX_DELAY)) {
//             printf("Button 1 pressed!\n");
//             if (isLed_menu && menu_cursor < 1) {  // Only allow increment if < 1
//                 menu_cursor++;
//                 led_menu();
//             }
//             xQueueReset(BTN1Queue);
//         }
//         vTaskDelay(10 / portTICK_PERIOD_MS);
//     }
// }



// void BTN3Task(void *params)
// {
//     gpio_set_direction(BTN3, GPIO_MODE_INPUT);
//     gpio_set_intr_type(BTN3, GPIO_INTR_NEGEDGE);
//     int BTN_NUMBER = 0;
//     while (1) {
//         if (xQueueReceive(BTN3Queue, &BTN_NUMBER, portMAX_DELAY)) {
//             printf("Button 3 pressed!\n");
//             if (isLed_menu && menu_cursor > 0) {  // Only allow decrement if > 0
//                 menu_cursor--;
//                 led_menu();
//             }
//             xQueueReset(BTN3Queue);
//         }
//         vTaskDelay(10 / portTICK_PERIOD_MS);
//     }
// }


// void VBUS_INTRTask(void *params)
// {
//     gpio_set_direction(VBUS_INTR, GPIO_MODE_INPUT);
//     gpio_set_intr_type(VBUS_INTR, GPIO_INTR_POSEDGE);
//     int BTN_NUMBER = 0;
//     while (1)
//     {
//         if (xQueueReceive(VBUS_INTRQueue, &BTN_NUMBER, portMAX_DELAY))
//         {
            
//             if(vbus_flag)
//             {
//                 printf("Charging....!\n");
//                 vbus_flag=false;
//                 vTaskDelete(NULL);
//             }
//             xQueueReset(VBUS_INTRQueue);
//         }
//         vTaskDelay(100/portTICK_PERIOD_MS);
//     }
// }

// static void display_number_8()
// {
//     // Configure GPIOs for the 7-segment display
//     gpio_set_direction(SEG_A_GPIO, GPIO_MODE_OUTPUT);
//     gpio_set_direction(SEG_B_GPIO, GPIO_MODE_OUTPUT);
//     gpio_set_direction(SEG_C_GPIO, GPIO_MODE_OUTPUT);
//     gpio_set_direction(SEG_D_GPIO, GPIO_MODE_OUTPUT);
//     gpio_set_direction(SEG_E_GPIO, GPIO_MODE_OUTPUT);
//     gpio_set_direction(SEG_F_GPIO, GPIO_MODE_OUTPUT);
//     gpio_set_direction(SEG_G_GPIO, GPIO_MODE_OUTPUT);

//     // Turn on all segments to display '8'
//     gpio_set_level(SEG_A_GPIO, 1);
//     gpio_set_level(SEG_B_GPIO, 1);
//     gpio_set_level(SEG_C_GPIO, 1);
//     gpio_set_level(SEG_D_GPIO, 1);
//     gpio_set_level(SEG_E_GPIO, 1);
//     gpio_set_level(SEG_F_GPIO, 1);
//     gpio_set_level(SEG_G_GPIO, 1);

//     // Keep the display on for 5 seconds
//     printf("\n--------------------------------------------\n");
//     printf("1.Testing Seven Segment Display\n");
//     vTaskDelay(5000 / portTICK_PERIOD_MS);

//     // Turn off all segments
//     gpio_set_level(SEG_A_GPIO, 0);
//     gpio_set_level(SEG_B_GPIO, 0);
//     gpio_set_level(SEG_C_GPIO, 0);
//     gpio_set_level(SEG_D_GPIO, 0);
//     gpio_set_level(SEG_E_GPIO, 0);
//     gpio_set_level(SEG_F_GPIO, 0);
//     gpio_set_level(SEG_G_GPIO, 0);
// }

// static void display_led()
// {
      
//     printf("2.Testing LEDs D5(RGB),D6 and D8\n");

//     gpio_set_direction(LED_BLUE1, GPIO_MODE_OUTPUT);
//     gpio_set_level(LED_BLUE1, 0);
//     vTaskDelay(1500 / portTICK_PERIOD_MS);
//     gpio_set_level(LED_BLUE1, 1);

//     gpio_set_direction(LED_BLUE2, GPIO_MODE_OUTPUT);
//     gpio_set_level(LED_BLUE2, 0);
//     vTaskDelay(1500 / portTICK_PERIOD_MS);
//     gpio_set_level(LED_BLUE2, 1);

//     gpio_set_direction(RGB_RED, GPIO_MODE_OUTPUT);
//     gpio_set_level(RGB_RED, 0);
//     vTaskDelay(1500 / portTICK_PERIOD_MS);
//     gpio_set_level(RGB_RED, 1);

//     gpio_set_direction(RGB_GREEN, GPIO_MODE_OUTPUT);
//     gpio_set_level(RGB_GREEN, 0);
//     vTaskDelay(1500 / portTICK_PERIOD_MS);
//     gpio_set_level(RGB_GREEN, 1);

//     gpio_set_direction(RGB_BLUE, GPIO_MODE_OUTPUT);
//     gpio_set_level(RGB_BLUE, 0);
//     vTaskDelay(1500 / portTICK_PERIOD_MS);
//     gpio_set_level(RGB_BLUE, 1);
// }





// static void IRAM_ATTR BTN_UP_interrupt_handler(void *args)
// {
    
//     int pinNumber = (int)args;
//     if(esp_timer_get_time() - pre_time_BTN1 > 400000)
//     {
//         xQueueSendFromISR(BTN1Queue, &pinNumber, NULL);

//     }
//     pre_time_BTN1= esp_timer_get_time();
// }

// static void IRAM_ATTR BTN_DOWN_interrupt_handler(void *args)
// {
//     int pinNumber = (int)args;
//     if(esp_timer_get_time() - pre_time_BTN2 > 400000)
//     {
//         xQueueSendFromISR(BTN2Queue, &pinNumber, NULL);
//     }
//     pre_time_BTN2 = esp_timer_get_time();
// }

// static void IRAM_ATTR BTN_PWR_interrupt_handler(void *args)
// {
//     int pinNumber = (int)args;
//     if(esp_timer_get_time() - pre_time_BTN3 > 400000){
//     xQueueSendFromISR(BTN3Queue, &pinNumber, NULL);
//     }
//     pre_time_BTN3 = esp_timer_get_time();
// }


// static void IRAM_ATTR VBUS_INTR_interrupt_handler(void *args)
// {
//     int pinNumber = (int)args;
//     if(esp_timer_get_time() - pre_time_vbus_intr > 400000){
//     xQueueSendFromISR(VBUS_INTRQueue, &pinNumber, NULL);
//     }
//     pre_time_vbus_intr = esp_timer_get_time();
// }



// void app_main()
// {
//     BTN1Queue = xQueueCreate(10, sizeof(int));
//     BTN2Queue = xQueueCreate(10, sizeof(int));
//     BTN3Queue = xQueueCreate(10, sizeof(int));
//     VBUS_INTRQueue = xQueueCreate(10, sizeof(int));


//     gpio_install_isr_service(0);
//     gpio_isr_handler_add(BTN1, BTN_UP_interrupt_handler, (void *)BTN1);
//     gpio_isr_handler_add(BTN2, BTN_DOWN_interrupt_handler, (void *)BTN2);
//     gpio_isr_handler_add(BTN3, BTN_PWR_interrupt_handler, (void *)BTN3);
//     gpio_isr_handler_add(VBUS_INTR, VBUS_INTR_interrupt_handler, (void *)VBUS_INTR);

//     // display_number_8();
//     // display_led();
//     xTaskCreate(BTN1Task, "BTN_UPTask", 2048, NULL, 1, NULL);
//     xTaskCreate(BTN2Task, "BTN_DOWNTask", 2048, NULL, 1, NULL);
//     xTaskCreate(BTN3Task, "BTN_PWRTask", 2048, NULL, 1, NULL);
//     xTaskCreate(VBUS_INTRTask, "VBUS_INTRTask", 8000, NULL, 1, NULL);
//     led_menu();

// }




#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include "freertos/queue.h"
#include <esp_system.h>
#include <esp_log.h>
#include <driver/gpio.h>
#include "esp_timer.h"






#ifndef APP_CPU_NUM
#define APP_CPU_NUM PRO_CPU_NUM
#endif



#define BTN1 GPIO_NUM_19
#define BTN2 GPIO_NUM_21
#define BTN3 GPIO_NUM_18


xQueueHandle BTN1Queue;
xQueueHandle BTN2Queue;
xQueueHandle BTN3Queue;





uint32_t pre_time_BTN1 = 0;
uint32_t pre_time_BTN2 = 0;
uint32_t pre_time_BTN3 = 0;






void BTN1Task(void *params)
{
    gpio_set_direction(BTN1, GPIO_MODE_INPUT);
    gpio_set_intr_type(BTN1, GPIO_INTR_NEGEDGE);
    int BTN_NUMBER = 0;
    while (1)
    {

        if (xQueueReceive(BTN1Queue, &BTN_NUMBER, portMAX_DELAY))
        {
            printf(" Button 1 pressed!\n");
            xQueueReset(BTN1Queue);
        }
        vTaskDelay(10/portTICK_PERIOD_MS);
    }
}


void BTN2Task(void *params)
{
    gpio_set_direction(BTN2, GPIO_MODE_INPUT);
    gpio_set_intr_type(BTN2, GPIO_INTR_NEGEDGE);
    int BTN_NUMBER = 0;
    while (1)
    {

        if (xQueueReceive(BTN2Queue, &BTN_NUMBER, portMAX_DELAY))
        {
            printf(" Button 2 pressed!\n");
            xQueueReset(BTN2Queue);
        }
        vTaskDelay(10/portTICK_PERIOD_MS);
    }
}

void BTN3Task(void *params)
{
    gpio_set_direction(BTN3, GPIO_MODE_INPUT);
    gpio_set_intr_type(BTN3, GPIO_INTR_NEGEDGE);
    int BTN_NUMBER = 0;
    while (1)
    {
        if (xQueueReceive(BTN3Queue, &BTN_NUMBER, portMAX_DELAY))
        {
            printf(" Button 3 pressed!\n");          
            xQueueReset(BTN3Queue);
        }
        vTaskDelay(10/portTICK_PERIOD_MS);
    }
            

}


 



static void IRAM_ATTR BTN1_interrupt_handler(void *args)
{
    
    int pinNumber = (int)args;
    if(esp_timer_get_time() - pre_time_BTN1 > 400000)
    {
        xQueueSendFromISR(BTN1Queue, &pinNumber, NULL);

    }
    pre_time_BTN1= esp_timer_get_time();
}

static void IRAM_ATTR BTN2_interrupt_handler(void *args)
{
    int pinNumber = (int)args;
    if(esp_timer_get_time() - pre_time_BTN2 > 400000)
    {
        xQueueSendFromISR(BTN2Queue, &pinNumber, NULL);
    }
    pre_time_BTN2 = esp_timer_get_time();
}

static void IRAM_ATTR BTN3_interrupt_handler(void *args)
{
    int pinNumber = (int)args;
    if(esp_timer_get_time() - pre_time_BTN3 > 400000){
    xQueueSendFromISR(BTN3Queue, &pinNumber, NULL);
    }
    pre_time_BTN3 = esp_timer_get_time();
}




void app_main()
{
    BTN1Queue = xQueueCreate(10, sizeof(int));
    BTN2Queue = xQueueCreate(10, sizeof(int));
    BTN3Queue = xQueueCreate(10, sizeof(int));



    gpio_install_isr_service(0);
    gpio_isr_handler_add(BTN1, BTN1_interrupt_handler, (void *)BTN1);
    gpio_isr_handler_add(BTN2, BTN2_interrupt_handler, (void *)BTN2);
    gpio_isr_handler_add(BTN3, BTN3_interrupt_handler, (void *)BTN3);
    
    xTaskCreate(BTN1Task, "BTN_UPTask", 2048, NULL, 1, NULL);
    xTaskCreate(BTN2Task, "BTN_DOWNTask", 2048, NULL, 1, NULL);
    xTaskCreate(BTN3Task, "BTN_PWRTask", 2048, NULL, 1, NULL);
    

}