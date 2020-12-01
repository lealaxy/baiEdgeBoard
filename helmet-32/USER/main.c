#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "usart.h"
#include "uart2.h"
#include "uart3.h"
#include "timer.h"

 
/************************************************
 ALIENTEKս��STM32������ʵ��4
 ����ʵ�� 
 ����֧�֣�www.openedv.com
 �Ա����̣�http://eboard.taobao.com 
 ��ע΢�Ź���ƽ̨΢�źţ�"����ԭ��"����ѻ�ȡSTM32���ϡ�
 ������������ӿƼ����޹�˾  
 ���ߣ�����ԭ�� @ALIENTEK
************************************************/


/*
										TX     RX
����1 ����  		 		PA9   PA10
����2 EdgeBoard  		PA2   PA3      
����3 OLED 					PB10  PB11
��� 								PA1

*/
int main(void)
{		
    u8 t=0;
    delay_init();	    	 //��ʱ������ʼ��	  
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
    uart_init(9600);	 //���ڳ�ʼ��Ϊ9600
    uart2_Init(9600);
    uart3_Init(9600);
		TIM_SetCompare2(TIM2,800);	
		TIM2_PWM_Init(19999,71);
    LED_Init();			     //LED�˿ڳ�ʼ��
 	while(1)
	{
//        uart1_test();
        uart2_test();
//        uart3_test();
        delay_ms(5);
        if(++t>100)
        {
            t=0;
            LED0=!LED0;
        }
	}	 
 }

