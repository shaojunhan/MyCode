#include"C_LineEdit_Basic.h"
#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
	int i;
	while(1)
	{
		printf("请选择:\n1.打开文件  2.显示文件内容\n"
			"3.插入行  4.删除行  5.拷贝行  6.修改行\n"
			"7.查找串  8.替代串\n"
			"9.存盘退出  0.放弃编辑\n");
		
		scanf("%d%*c",&i);
		switch(i)
		{
		case 1:
			Open();
			break;
		case 2:
			Disply();
			system("pause");
			break;
		case 3:
			Insert();
			break;
		case 4:
			Delete();
			break;
		case 5:
			Copy();
			break;
		case 6:
			Modify();
			break;
		case 7:
			Search();
			break;
		case 8:
			Replace();
			break;
		case 9:
			Save();
			break;
		case 0:
			GiveIn();
			break;
		}
		system("cls");
	}
	system("pause");
	return 0;
}