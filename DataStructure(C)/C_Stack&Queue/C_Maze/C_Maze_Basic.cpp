#include"C_Maze_Basic.h"
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>

MAZE Maze;
int Row,Line;
int i=0;
Position Start,End;
Position Adj[4]={{-1,0},{0,1},{1,0},{0,-1}};//4个邻接点

Position NextPos(Position pos)
{
	Position s=pos;
	Position temp=Adj[Maze[pos.x][pos.y]-1];
	s.x+=temp.x;
	s.y+=temp.y;

	return s;
}

void visit(ElemType e)
{
	static char c[3]={' ',' ','\n'};
	printf("%c%c%c(%d,%d)",c[0],c[1],c[2],e.x,e.y);
	c[0]='-',c[1]='-',c[2]='>';
}

void Maze_S()//Stack
{
	LinkStack S;
	InitStack(S);
	Position curpos;
	Position lastpos;
	int curstep=0;

	curpos=Start;
	do
	{
		if(curpos.x==End.x && curpos.y==End.y)
		{
			Push(S,curpos);
			break;
		}
		if(Maze[curpos.x][curpos.y]==1)
		{
			Push(S,curpos);
			lastpos=curpos;
			curpos=NextPos(curpos);
			Maze[lastpos.x][lastpos.y]++;
		}
		else
		{
			if(Pop(S,curpos))
			{
				while(!StackEmpty(S) && Maze[curpos.x][curpos.y]>4)
					Pop(S,curpos);

				if(Maze[curpos.x][curpos.y]>0 && Maze[curpos.x][curpos.y]<=4)
				{
					Push(S,curpos);
					lastpos=curpos;
					curpos=NextPos(curpos);
					Maze[lastpos.x][lastpos.y]++;
				}
			}
		}
	}while(!StackEmpty(S));

	ClearPrint();
	StackTraverse(S,Animation);
	printf("路径:");
	StackTraverse(S,visit);
	printf("\n");

	DestroyStack(S);
}

void Maze_BFS()
{
	LinkStack S;
	InitStack(S);

	if(BFS(S,Start))
	{
		ClearPrint();
		StackTraverse(S,Animation);
		printf("路径:");
		StackTraverse(S,visit);
		printf("\n");
	}
	else
	{
		printf("不存在路径\n");
	}

	DestroyStack(S);
}

int BFS(LinkStack &S,Position curpos)//Breadth First Search
{
	int flag=0;
	Position nextpos;

    if(Maze[curpos.x][curpos.y]==0 || Maze[curpos.x][curpos.y]>4)
    {
        return 0;
    }
	else if(curpos.x==End.x && curpos.y==End.y)
	{
		Push(S,curpos);
		return 1;
	}

    while(Maze[curpos.x][curpos.y]>0 && Maze[curpos.x][curpos.y]<=4)
    {
        nextpos=NextPos(curpos);
		Maze[curpos.x][curpos.y]++;
        if(BFS(S,nextpos))
			flag=1;
    }

	if(flag)
		Push(S,curpos);
    return flag;
}

void Maze_R()//Recursion
{
	Position curpos;
	Position nextpos;
	LinkStack S;
	LinkStack KS;
	int *a;
	int i=0;
	int j=0;
	int n=0;
	LinkQueue Q;

	InitStack(S);
	InitQueue(Q);
	InitStack(KS);

	a=(int*)malloc((Row*Line)*sizeof(int));

	n=i;
	EnQueue(Q,Start);
	Push(KS,Start);
	i=1;
	a[i]=n;

	while(!QueueEmpty(Q))
	{
		DeQueue(Q,curpos);
		j++;
		n=j;
		if(curpos.x==End.x && curpos.y==End.y)
		{
			break;
		}

		while( Maze[curpos.x][curpos.y]>0 && Maze[curpos.x][curpos.y]<=4)
		{
			nextpos=NextPos(curpos);
			Maze[curpos.x][curpos.y]++;
			if(Maze[nextpos.x][nextpos.y]==1)
			{
				EnQueue(Q,nextpos);
				Push(KS,nextpos);
				i++;
				a[i]=n;
			}
		}	
	}

	while(i>j)
	{
		Pop(KS,nextpos);
		i--;
	}

	i=j;
	for(;i>0;)
	{
		GetTop(KS,curpos);
		Push(S,curpos);
		for(j=i;j>a[i];j--)
			Pop(KS,nextpos);
		i=a[i];
	}

	if(!StackEmpty(S))
	{
		ClearPrint();
		StackTraverse(S,Animation);
		printf("路径:");
		StackTraverse(S,visit);
		printf("\n");
	}
	else
	{
		printf("不存在路径!\n");
	}

	DestroyStack(S);
	DestroyQueue(Q);
	DestroyStack(KS);
	free(a);
}

void Build()
{
	int m,n;
	int k=0;
	int i,j;

loop1:
	printf("输入迷宫行、列:");
	scanf("%d%d%*c",&m,&n);
	fflush(stdin);

	if((m<=0 || n<=0) || (m>MAXSIZE-2 || n>MAXSIZE-2))
		goto loop1;

	Row=m,Line=n;

loop2:
	printf("选择自动后者手动输入(1-自动 2-手动):");
	scanf("%d%*c",&k);
	switch(k)
	{
	case 1:
		srand(time(0));

		for(i=1;i<Row+1;i++)
		{
			for(j=1;j<Line+1;j++)
			{
				Maze[i][j]=(int)((rand()%3)!=0);
			}
		}

		for(i=0;i<Row+2;i++)
		{
			Maze[i][0]=0;
			Maze[i][Line+1]=0;
		}
		for(j=1;j<Line+1;j++)
		{
			Maze[0][j]=0;
			Maze[Row+1][j]=0;
		}

		Row+=2;
		Line+=2;
		printf("创建成功!\n");
		OutPut();
		break;
	case 2:
		for(i=0;i<Row;i++)
		{
			for(j=0;j<Line;j++)
			{
				scanf("%d%*c",&k);
				Maze[i][j]=(int)(k!=0);
			}
		}

		printf("创建完成!\n");
		OutPut();
		break;
	default:
		goto loop2;
	}

	printf("请输入起点(格式(x,y)):");
	scanf("(%d,%d)%*c",&Start.x,&Start.y);
	printf("请输入终点(格式(x,y)):");
	scanf("(%d,%d)",&End.x,&End.y);
}


void OutPut()
{
	for(int i=0;i<Row;i++)
	{
		for(int j=0;j<Line;j++)
		{
			printf("%3d",Maze[i][j]);
		}
		printf("\n");
	}
}

void Animation(Position e)
{
	i++;
	Maze[e.x][e.y]=i;
	Sleep(1000);
	system("cls");
	OutPut();
}

void ClearPrint()
{
	for(int i=0;i<Row;i++)
	{
		for(int j=0;j<Line;j++)
		{
			Maze[i][j]=(Maze[i][j]!=0)?-1:0;
		}
	}
}
