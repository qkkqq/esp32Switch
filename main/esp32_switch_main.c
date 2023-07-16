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

#include "esp_gap_ble_api.h"//GAP设置头文件，广播和连接相关参数配置
#include "esp_gatts_api.h"//GATT配置头文件，创建Service和Characteristic
#include "esp_bt_main.h"//蓝牙栈空间的初始化头文件
#include "servo.h"

//初始化引脚配置+舵机驱动+MQTT
void Sys_Init(void)
{
    /*舵机初始化*/
    Servo_Init(32);     //GPIO23
    
    /*蓝牙初始化*/
}
/*命令接收 任务*/




void app_main(void)
{
    Sys_Init();
    printf("Hello world!\n");
/*
    
    esp_chip_info_t chip_info;
    esp_chip_info(&chip_info);
    printf("This is %s chip with %d CPU cores, WiFi%s%s, ",
            CONFIG_IDF_TARGET,
            chip_info.cores,
            (chip_info.features & CHIP_FEATURE_BT) ? "/BT" : "",
            (chip_info.features & CHIP_FEATURE_BLE) ? "/BLE" : "");

    printf("silicon revision %d, ", chip_info.revision);

    printf("%dMB %s flash\n", spi_flash_get_chip_size() / (1024 * 1024),
            (chip_info.features & CHIP_FEATURE_EMB_FLASH) ? "embedded" : "external");

    printf("Free heap: %d\n", esp_get_free_heap_size());

    for (int i = 10; i >= 0; i--) {
        printf("Restarting in %d seconds...\n", i);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
    printf("Restarting now.\n");
*/
    while(1)
    {
        for(int i=0;i<2;i++)
        {
            Senor_Control(i*180);
            vTaskDelay(1000 / portTICK_PERIOD_MS);  //延时1s
        }
    }
    fflush(stdout);
    esp_restart();
}
