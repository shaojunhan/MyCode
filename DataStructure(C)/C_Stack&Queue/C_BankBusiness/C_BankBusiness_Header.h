/*
#ifndef C_BANKBUSINESS_HEADER_H_INCLUDED
#define C_BANKBUSINESS_HEADER_H_INCLUDED
*/

#pragma once
#define ERROR 0
#define OK 1
#define FALSE 0
#define TRUE 1

#define Interval 5 //两个客户到达的最大间隔时间
#define Delay 30 //客户办理业务的最大时间

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
