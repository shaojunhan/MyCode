#ifndef C_Maze_Header_2012_10_28_16_27
#define C_Maze_Header_2012_10_28_16_27

#define ERROR 0
#define OK 1
#define FALSE 0
#define TRUE 1

#define MAXSIZE 100

typedef int Status;
typedef int MAZE[MAXSIZE][MAXSIZE];

typedef struct
{
	int x;
	int y;

}Position,ElemType;

typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}*Link;

#endif