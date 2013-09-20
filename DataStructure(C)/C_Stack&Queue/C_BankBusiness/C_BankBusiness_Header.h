/*
#ifndef C_BANKBUSINESS_HEADER_H_INCLUDED
#define C_BANKBUSINESS_HEADER_H_INCLUDED
*/

#pragma once
#define ERROR 0
#define OK 1
#define FALSE 0
#define TRUE 1

#define Interval 5 //�����ͻ�����������ʱ��
#define Delay 30 //�ͻ�����ҵ������ʱ��

typedef int Status;
typedef struct
{
    int ArrivedTime;
    int Duration;
}QElemType;

typedef struct
{
    int OccurTime;
    int NType;
}SElemType;


/*
#endif // C_BANKBUSINESS_HEADER_H_INCLUDED
*/
