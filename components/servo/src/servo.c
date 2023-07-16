#include "servo.h"

/*舵机初始化*/
void Servo_Init(char gpioPin)
{
    ledc_timer_config_t timer_conf = {
        .speed_mode = LEDC_HIGH_SPEED_MODE,
        .duty_resolution = LEDC_TIMER_8_BIT,            //PWM占空比分辨率
        .timer_num = LEDC_TIMER_1,
        .freq_hz = 50,                                  //// PWM信号频率
//        .clk_cfg = LEDC_USE_REF_TICK,
    };
    ledc_timer_config(&timer_conf);                    //配置定时器
    
    ledc_channel_config_t ledc_conf = {
        .gpio_num = gpioPin,                                 //GPIO23
        .speed_mode = LEDC_HIGH_SPEED_MODE,
        .channel = LEDC_CHANNEL_7,                      //通道
        .timer_sel = LEDC_TIMER_1,                      //时钟
    };
    ledc_channel_config(&ledc_conf);                  //配置通道
}

/*角度转占空比*/
int Alculate_PWM(int degree)
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
    duty = Alculate_PWM(degree);                                       //角度转换
    ledc_set_duty(LEDC_HIGH_SPEED_MODE,LEDC_CHANNEL_7,duty);  //设置占空比
    ledc_update_duty(LEDC_HIGH_SPEED_MODE, LEDC_CHANNEL_7);     //更新占空比
}