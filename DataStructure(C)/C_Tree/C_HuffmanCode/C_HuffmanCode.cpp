#include"C_HuffmanCode_Basic.h"
#include<stdio.h>
#include<limits.h>
#include<string.h>

#define CHAR_MAX_SIZE 27
#define CODE_MAX_SIZE 26
int n;
int main(int argc,char *argv[])
{
	int i;
	char buf[CHAR_MAX_SIZE];
	int weight[CHAR_MAX_SIZE];
	HuffmanTree HT;
	HuffmanCode HC;

	n=0;
	printf("����������ַ�:");
	scanf("%s%*c",buf);
	n=strlen(buf);

	printf("�����ӦȨֵ:");
	for(i=0;i<n;i++)
		scanf("%d%*c",&weight[i]);

	HuffmanCoding(HT,HC,weight,buf,n);

	while(1)
	{
		char c;
		char code[CODE_MAX_SIZE];

		printf("1.�����ַ�����ת��"
		"\n2.���������з���"
		"\n3.�˳�����\n");
		scanf("%d%*c",&i);
		switch(i)
		{
		case 1:
			printf("�����ַ�:");
			scanf("%c%*c",&c);
			GenerateCoding(HT,code,c,n);
			printf("\nת��Ϊ:%s\n",code);
			break;
		case 2:
			printf("�������:");
			scanf("%s%*c",code);
			TransCoding(HT,code,c,n);
			printf("\n����Ϊ:%c\n",c);
			break;
		case 3:
			goto loop1;
		default:
			break;
		}
	}

loop1:
	return 0;
}