#include"C_SysConvert_Basic.h"
#include<stdlib.h>
#include<stdio.h>
#include<sys/timeb.h>

int main(int argc,char *argv[])
{
	timeb t1,t2;
	long s;
	int n;

	printf("����Ҫת���Ľ���(2-16):");
loop1:
	scanf("%d%*c",&n);
	if(n<2 || n>16)
	{
		printf("���벻�Ϸ�,����������:");
		goto loop1;
	}
	printf("����Ҫת��������:");
	scanf("%ld",&s);

	ftime(&t1);
	Convert(s,n);
	ftime(&t2);

	double t=(t2.time-t1.time)*1000+t2.millitm-t1.millitm;
	t/=1000;
	printf("\n�����ʱ:%.5lfs",t);
	system("pause");
	return 0;
}