// C_LinkList_StudentHealthNote.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"C_LinkList_StudentHealthNote_Basic.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

LinkList L;
Student e;
FILE *in,*out;

void Insert();
void ReadIn();
void DeleteNum();
void DeleteName();
void ModifyNum();
void ModifyName();
void SearchNum();
void SearchName();
void visit(Student e);
void Save();
void exit();

int main()
{
	int key=0;
	char keys[64];
	
	InitList(L);
	
loop2:
	printf("\t\t1.向链表中插入数据(按学号非降序)\n"
		"\t\t2.将文件中的数据插入链表(学号非降序)\n"
		"\t\t3.按学号删除\n"
		"\t\t4.按姓名删除\n"
		"\t\t5.按学号修改\n"
		"\t\t6.按姓名修改\n"
		"\t\t7.按学号查找\n"
		"\t\t8.按姓名查找\n"
		"\t\t9.显示所有记录\n"
		"\t\t10.保存到文件\n"
		"\t\t11.退出\n");
	
loop1:
	printf("请输入操作:");
	scanf("%s%*c",keys);
	key=atoi(keys);
	
	switch(key)
	{
	case 1:
		Insert();
		break;
	case 2:
		ReadIn();
		break;
	case 3:
		DeleteNum();
		break;
	case 4:
		DeleteName();
		break;
	case 5:
		ModifyNum();
		break;
	case 6:
		ModifyName();
		break;
	case 7:
		SearchNum();
		break;
	case 8:
		SearchName();
		break;
	case 9:
		DisplayAll(L,visit);
		getchar();
		break;
	case 10:
		Save();
		break;
	case 11:
		exit();
		break;
	default:
		printf("输入错误!");
		goto loop1;
	}
	system("cls");
	goto loop2;

	system("pause");
	return 0;
}

//InsertAscend
void Insert()
{
	char sex[4];
	int i;
	Student s;
	char c='N';

	printf("请输入修改后的姓名 学号 性别 年龄 班级 健康状况(1,2,3)");
	scanf("%s%s%s%d%s%d%*c",e.name,e.num,sex,&e.age,e.stuclass,&i);
	if(!strcmp(sex,"男"))
		e.sex=1;
	else
		e.sex=0;
	switch(i)
	{
	case 1:
		e.health=GOOD;
		break;
	case 2:
		e.health=GENERAL;
		break;
	case 3:
		e.health=BAD;
		break;
	}


	if(SearchNum(L,e.num,s))
	{
		printf("已存在该学号的学生信息!按任意键返回...");
		getchar();
		return;
	}

	if(InsertAscend(L,e))
		printf("插入成功\n");
	else
		printf("插入失败\n");
}

//ReadIn
void ReadIn()
{
	in=fopen("student.bin","rb+");
	if(in)
	{
		ReadIn(L,in);
		printf("读取成功!");
		fclose(in);
		DisplayAll(L,visit);
	}
	else
	{
		printf("打开文件失败,按任继建返回...");
		getchar();
	}
}

//DeleteNum
void DeleteNum()
{
	char num[10];
	char c='N';
	
	printf("请输入学号");
	scanf("%s%*c",num);
	printf("确定删除?Y/N");
	scanf("%c",&c);
	if(c=='Y' || c=='y')
		if(DeleteNum(L,num,e))
			printf("删除成功\n");
		else
			printf("删除失败\n");
	else
	{
		printf("删除已经取消,按任意键返回\n");
		getchar();
		return;
	}		
}

//DeleteName
void DeleteName()
{
	char name[20];
	char c='N';
	
	printf("请输入姓名");
	scanf("%s%*c",name);
	printf("确定删除?Y/N");
	scanf("%c",&c);
	if(c=='Y' || c=='y')
		if(DeleteName(L,name,e))
			printf("删除成功\n");
		else
			printf("删除失败\n");
		else
		{
			printf("删除已经取消,按任意键返回\n");
			getchar();
			return;
		}
}

//ModifyNum
void ModifyNum()
{
	char sex[4];
	int i;
	char num[10];
	char c='N';

	printf("请输入要修改的学生学号:");
	scanf("%s",num);

	printf("请输入修改后的姓名 学号 性别 年龄 班级 健康状况(1,2,3)");
	scanf("%s%s%s%d%s%d",e.name,e.num,sex,&e.age,e.stuclass,&i);
	if(strcmp(sex,"男"))
		e.sex=1;
	else
		e.sex=0;
	switch(i)
	{
	case 1:
		e.health=GOOD;
		break;
	case 2:
		e.health=GENERAL;
		break;
	case 3:
		e.health=BAD;
		break;
	}

	printf("确定修改?Y/N");
	scanf("%c",&c);
	if(c=='Y' || c=='y')
		if(ModifyNum(L,num,e))
			printf("修改成功\n");
		else
			printf("修改失败\n");
		else
		{
			printf("修改已经取消,按任意键返回\n");
			getchar();
			return;
		}
}

//ModifyName
void ModifyName()
{
	char sex[4];
	int i;
	char name[20];
	char c='N';

	printf("请输入要修改的学生姓名:");
	scanf("%s",name);

	printf("请输入修改后的姓名 学号 性别 年龄 班级 健康状况(1,2,3)");
	scanf("%s%s%s%d%s%d",e.name,e.num,sex,&e.age,e.stuclass,&i);
	if(strcmp(sex,"男"))
		e.sex=1;
	else
		e.sex=0;
	switch(i)
	{
	case 1:
		e.health=GOOD;
		break;
	case 2:
		e.health=GENERAL;
		break;
	case 3:
		e.health=BAD;
		break;
	}

	printf("确定修改?Y/N");
	scanf("%c",&c);
	if(c=='Y' || c=='y')
		if(ModifyName(L,name,e))
			printf("修改成功\n");
		else
			printf("修改失败\n");
		else
		{
			printf("修改已经取消,按任意键返回\n");
			getchar();
			return;
		}
		
		
}

//SearchNum
void SearchNum()
{
	char num[10];

	printf("请输入要修改的学生学号:");
	scanf("%s",num);

	if(SearchNum(L,num,e))
		visit(e);
	else
	{
		printf("查找失败!检查输入是否正确,按任意键返回...");
		getchar();
		return;
	}
}

//SearchName
void SearchName()
{
	char name[20];

	printf("请输入要修改的学生姓名:");
	scanf("%s",name);

	if(SearchName(L,name,e))
		visit(e);
	else
	{
		printf("查找失败!检查输入是否正确,按任意键返回...");
		getchar();
		return;
	}
	
}

//visit
void visit(Student e)
{
	char sex[4];
	char health[10];
	if(e.sex==1)
		strcpy(sex,"男");
	switch(e.health)
	{
	case GOOD:
		strcpy(health,"健康");
		break;
	case GENERAL:
		strcpy(health,"一般");
		break;
	case BAD:
		strcpy(health,"虚弱");
		break;
	}

	printf("\n姓名:%s\n学号:%s\n年龄:%d\n性别:%s\n班级:%s\n健康状况:%s"
		,e.name,e.num,e.age,sex,e.stuclass,health);
}

//Save
void Save()
{
	out=fopen("student.bin","wb+");
	if(out)
	{
		Save(L,out);
		fclose(out);
		printf("保存成功");
	}
	printf("按任意键返回...");
	getchar();
}
//exit
void exit()
{
	char c='N';
	
	printf("确定退出？Y/N");
	scanf("%c",&c);
	if(c=='Y' || c=='y')
		exit(0);
	else
		printf("退出已经取消\n");
}