#include"C_LineEdit_Basic.h"
#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
	int i;
	while(1)
	{
		printf("��ѡ��:\n1.���ļ�  2.��ʾ�ļ�����\n"
			"3.������  4.ɾ����  5.������  6.�޸���\n"
			"7.���Ҵ�  8.�����\n"
			"9.�����˳�  0.�����༭\n");
		
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