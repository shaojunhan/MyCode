#ifndef C_Maze_Basic_2012_10_28_21_46
#define C_Maze_Basic_2012_10_28_21_46

#include"C_Maze_Header.h"
#include"C_Maze_LinkStack.h"
#include"C_Maze_LinkQueue.h"

void Maze_S();//Stack
int BFS(LinkStack &S,Position Start);//Breadth First Search
void Maze_BFS();
void Maze_R();//Recursion
void Build();
void OutPut();
Position NextPos(Position pos);
void visit(ElemType e);
void Animation(Position);
void ClearPrint();

#endif
