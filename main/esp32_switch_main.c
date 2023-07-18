/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "servo.h"
#include "ble.h"

//初始化引脚配置+舵机驱动+MQTT
void Sys_Init(void)
{
    /*舵机初始化*/
    Servo_Init(32);     //GPIO23
    
    /*蓝牙初始化*/
    Ble_Init();
}
/*命令接收 任务*/




void app_main(void)
{
    Sys_Init();
    
    
}
