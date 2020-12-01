#ifndef UART3_H
#define UART3_H


#include "sys.h"
#include "stdarg.h"	 	 
#include "stdio.h"	 	 
#include "string.h"
#include "delay.h"

#define USART3_REC_LEN  			200  	//�����������ֽ��� 200
	  	
extern u8  USART3_RX_BUF[USART3_REC_LEN]; //���ջ���,���USART_REC_LEN���ֽ�.ĩ�ֽ�Ϊ���з� 
extern u16 USART3_RX_STA;         		//����״̬���

void uart3_Init(u32 baudrate);
void uart3_test(void);
void u3_printf(char *fmt,...);
void HMISends(char *buf1);
void HMISendb(u8 buf);
void HMISendstart(void);
void open_page(void);
void close_page(void);
void main_page(void);

#endif
