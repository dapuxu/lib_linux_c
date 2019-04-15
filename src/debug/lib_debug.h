#ifndef __LIB_DEBUG_H__
#define __LIB_DEBUG_H__
#include <stdio.h>
#include "includes.h"
/******************************************* Enum ********************************************/
/* debug���������ʽ */
typedef enum {
	DEBUG_TYPE_CONSOLE,								/* �ն���� */
	DEBUG_TYPE_UART,									/* ������� */
	DEBUG_TYPE_NET,									/* TCP���   */
	DEBUG_TYPE_LOG,									/* ��־�ļ��洢 */
	DEBUG_TYPE_LCD,									/* lcd����� */
	DEBUG_MAX_DIRE_TYPE
}DEBUG_TYPE_T;

/* ���Կ��� */
typedef enum {
	DEBUG_SWITCH_CLOSE,
	DEBUG_SWITCH_OPEN
}DEBUG_SWITCH_T;


/* ������żУ�� */
typedef enum {
    UART_DATABIT_5 = 5,
    UART_DATABIT_6,
    UART_DATABIT_7,
    UART_DATABIT_8
}UART_DATABIT_T;

/* ������żУ�� */
typedef enum {
    UART_STOPBIT_1 = 1,
    UART_STOPBIT_2
}UART_STOPBIT_T;

/* ������żУ�� */
typedef enum {
    UART_PARITY_NONE,
    UART_PARITY_ODD,
    UART_PARITY_EVEN
}UART_PARITY_T;

/* �������� */
typedef enum {
    UART_FLOWCTRL_NONE,
	UART_FLOWCTRL_SOFT,
	UART_FLOWCTRL_HARD
}UART_FLOWCTRL_T;

/****************************************** Define *******************************************/
#define MAX_DEV_MANE_SIZE		100							/* �豸�ļ������� */

/****************************************** Struct *******************************************/
/*uart ������Ϣ*/
typedef struct {
	int 				uart_fd;							/* ���ھ�� */
	char 				uart_name[MAX_DEV_MANE_SIZE];		/* �����豸�� */
	unsigned int 		baudfate;							/* ������ */
	unsigned char 		databits;							/* ����λ */
	unsigned char		stopbits;							/* ֹͣλ */
	UART_PARITY_T		parity;								/* ��żУ��:1-����,2-ż�� */
	UART_FLOWCTRL_T		flowctrl;							/* ����:1-������,   2-Ӳ����      */
}DEBUG_UART_INFO;

/*tcp ������Ϣ*/
typedef struct {
	int 	net_fd;
	bool 	(*Debug_Net_Interface)(char *debug_buf, unsigned int buf_len);
}DEBUG_NET_INFO;

/*file �ļ���־��Ϣ*/
typedef struct {
	FILE * 				log_fd;
	char 				log_name[MAX_DEV_MANE_SIZE];
	unsigned int 		max_log_size;
}DEBUG_LOG_INFO;

/*tcp ������Ϣ*/
typedef struct {
	int 	lcd_fd;
	bool 	(*Debug_LCD_Interface)(char *debug_buf, unsigned int buf_len);
}DEBUG_LCD_INFO;

/* debug����ע����Ϣ */
typedef struct {
	unsigned char 		DebugType;
	DEBUG_UART_INFO		*Uart;
	DEBUG_NET_INFO		*Net;
	DEBUG_LOG_INFO		*Log;
	DEBUG_LCD_INFO		*Lcd;
}DEBUG_INFO;


/******************************************* Func *******************************************/

/********************************************************************************************/
/*	������:Debug_Msg 																			*/
/*	��	��:������Ϣ���		 																	*/
/*	��	��:[in]debug_type:������Ϣ�������															*/
/*		   [in]swit:�����������																	*/
/*		   [in]data:���������Ϣ																	*/
/*	����ֵ:��																					*/
/********************************************************************************************/
void Debug_Msg(unsigned char debug_type, DEBUG_SWITCH_T swit, char *data);

/********************************************************************************************/
/*	������:Debug_Init 																			*/
/*	��	��:����ע����Ϣ���սӿ�	 																	*/
/*	��	��:[in]info:���Խӿ�ע����Ϣ																	*/
/*	����ֵ:ע��ɹ��Ľӿ�,bit[0]-����̨ bit[1]-���� bit[2]-����												*/
/*			bit[3]-��־�ļ� bit[4]-LCD��ͨ��														*/
/********************************************************************************************/
char Debug_Init(DEBUG_INFO *info);


#endif