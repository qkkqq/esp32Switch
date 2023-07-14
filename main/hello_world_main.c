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

#include "driver/ledc.h"


//初始化引脚配置+舵机驱动+MQTT
void Sys_Init(void)
{
    /*舵机初始化*/
    ledc_timer_config_t timer_conf = {
        .speed_mode = LEDC_HIGH_SPEED_MODE,
        .duty_resolution = LEDC_TIMER_8_BIT,            //PWM占空比分辨率
        .timer_num = LEDC_TIMER_1,
        .freq_hz = 50,                                  //// PWM信号频率
//        .clk_cfg = LEDC_USE_REF_TICK,
    };
    ledc_timer_config(&timer_conf);                    //配置定时器
    
    ledc_channel_config_t ledc_conf = {
        .gpio_num = 23,                                 //GPIO23
        .speed_mode = LEDC_HIGH_SPEED_MODE,
        .channel = LEDC_CHANNEL_7,                      //通道
        .timer_sel = LEDC_TIMER_1,                      //时钟
    };
    ledc_channel_config(&ledc_conf);                  //配置通道
    
    /*MQTT初始化*/
}
/*命令接收 任务*/

/*舵机驱动*/
/*角度转占空比*/
int alculate_PWM(int degree)
{ //0-180度
 //20ms周期，高电平0.5-2.5ms，对应0-180度角度
  const float deadZone = 6.4;//对应0.5ms（0.5ms/(20ms/256）) 舵机转动角度与占空比的关系：(角度/90+0.5)*1023/20
  const float max = 32;//对应2.5ms
  if (degree < 0)
    degree = 0;
  if (degree > 180)
    degree = 180;
  return (int)(((max - deadZone) / 180) * degree + deadZone);
}
/*控制舵机*/
void Senor_Control(int degree)
{
    int duty;
    duty = alculate_PWM(degree);                                       //角度转换
    ledc_set_duty(LEDC_HIGH_SPEED_MODE,LEDC_CHANNEL_7,duty);  //设置占空比
    ledc_update_duty(LEDC_HIGH_SPEED_MODE, LEDC_CHANNEL_7);     //更新占空比
}


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
