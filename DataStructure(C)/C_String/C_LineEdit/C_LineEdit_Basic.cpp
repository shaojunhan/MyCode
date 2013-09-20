#include"C_LineEdit_Basic.h"
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

HString T[MAX_SIZE];//
char path[PATH_MAX_SIZE]="",line[LINE_MAX_SIZE];//
FILE *fp;//
int n;//

Status Open()//
{
	int i;

	if(!path[0])
	{
		printf("�������·��(���Ȳ�����%d):",PATH_MAX_SIZE-1);
		scanf("%s",path);
	}

	fp=fopen(path,"rb+");//
	if(!fp)
	{
		printf("open error.");
		return ERROR;
	}
	else
	{
		n=0;
		do{
			fgets(line,LINE_MAX_SIZE,fp);
			i=strlen(line);
			line[i-1]=0;
			i--;
			if(i>0)
			{
				StrAssign(T[n],line);//
				n++;
			}
			if(n>MAX_SIZE)
			{
				printf("�ļ�̫��.");
				return ERROR;
			}
		}while(i>0);
	}

	fclose(fp);
	return OK;
}

Status Disply()//
{
	int i;
	for(i=0;i<n;i++)
		StrPrint(T[i]);

	return OK;
}

Status Insert()//
{
	int i,l,m;
	HString V;

	InitString(V);//
	printf("������l��֮ǰ����m��:");//
	scanf("%d%d%*c",&l,&m);

	if(l<1 || l>n+1 || m<0 || m>LINE_MAX_SIZE-l+1)//
	{
		printf("�������.");
		return ERROR;
	}

	for(i=n+m-1;i>=m+l-1;i--)//
		StrCopy(T[i],T[i-m]);
	
	printf("����%d��:",m);
	for(i=0;i<m;i++)
	{
		scanf("%s",line);
		StrAssign(T[l-1+i],line);
	}
	n+=m;

	return OK;
}

Status Delete()//
{
	int i,l,m;

	printf("ɾ����l�п�ʼ��m��:");
	scanf("%d%d",&l,&m);

	if(l<1 || m<0 || m>n-l+1)
	{
		printf("�������.");
		return ERROR;
	}

	for(i=l-1;i<n-m;i++)//
		StrCopy(T[i],T[i+m]);

	for(i;i<n;i++)
		ClearString(T[i]);//
	n-=m;

	return FALSE;
}

Status Copy()//
{
	int i,l,m,k;

	printf("�Ѵ�l�п�ʼ��m�в�����ԭk֮ǰ:");
	scanf("%d%d%d%*c",&l,&m,&k);

	if(l<1 || m<0 || m>n-l+1 || k<1 || k>n-m+1)
	{
		printf("�������.");
		return ERROR;
	}

	HString *V;
	V=(HString*)malloc(m*sizeof(HString));
	for(i=0;i<m;i++)
		InitString(V[i]);

	for(i=0;i<m;i++)//
		StrCopy(V[i],T[l-1+i]);

	for(i=n-1;i>=k-1;i--)//
		StrCopy(T[i+m],T[i]);

	for(i=0;i<m;i++)
		StrCopy(T[k-1+i],V[i]);
	n+=m;

	for(i=0;i<m;i++)
		ClearString(V[i]);
	free(V);
	return OK;
}

Status Modify()//
{
	int l;
	printf("����Ҫ�޸ĵ���(%d-%d):",1,n);
	scanf("%d%*c",&l);
	if(l<1 || l>n)
	{
		printf("�кŲ��Ϸ�.");
		return ERROR;
	}
	else
	{
		printf("�����޸ĺ������:");
		scanf("%s%*c",line);
		ClearString(T[l-1]);//
		StrAssign(T[l-1],line);
		printf("�޸ĳɹ�.");
	}

	return OK;
}

Status Search()//
{
	int i,j;
	char c;
	bool flag=1;
	HString V;

	printf("������ģʽ��:");
	scanf("%s%*c",line);
	InitString(V);
	StrAssign(V,line);

	printf("���:\n");
	for(i=0;flag && i<n;i++)//
	{
		j=1;
		while(j)
		{
			if(j=Index(T[i],V,j))
			{
				printf("��:%d,��:%d",i+1,j);//
				printf("�Ƿ��������(Y/N):");
				scanf("%c%*c",&c);
				if(c=='N' || c=='n')
				{
					flag=0;
					break;
				}
				else
					j+=V.len;
			}
		}
	}

	return OK;
}

Status Replace()//
{
	int i;
	char c;
	bool flag=1;
	HString V1,V2;

	printf("��������滻���ַ���:");//
	scanf("%s%*c",line);
	InitString(V1);
	StrAssign(V1,line);

	printf("�滻Ϊ:");//
	scanf("%s%*c",line);
	InitString(V2);
	StrAssign(V2,line);

	for(i=0;flag && i<n;i++)//
	{
		if(Replace(T[i],V1,V2))//
		{
			printf("�滻�ɹ�,�Ƿ�����滻(Y/N):");
			scanf("%c%*c",&c);
			if(c=='N' || c=='n')
			{
				flag=0;
				break;
			}
		}
	}
	
	return OK;
}

Status Save()//
{
	int i;
	if(!path[0])
	{
		printf("�������·��(���Ȳ�����%d):",PATH_MAX_SIZE-1);
		scanf("%s",path);
	}

	fp=fopen(path,"wb+");
	if(!fp)
	{
		printf("�ļ��������.");
		return ERROR;
	}
	else
	{
		for(i=0;i<n;i++)//
		{
			T[i].ch[T[i].len]=0;
			fputs(T[i].ch,fp);
			fputc(10,fp);
		}
		fputc(10,fp);
		fclose(fp);
	}

	exit(0);
}

Status GiveIn()//
{
	int i;
	for(i=0;i<n;i++)
		ClearString(T[i]);
	n=0;

	fp=fopen(path,"rb+");//
	if(!fp)
	{
		printf("open error.");
		return ERROR;
	}
	else
	{
		n=0;
		do{
			fgets(line,LINE_MAX_SIZE,fp);
			i=strlen(line);
			line[i-1]=0;
			i--;
			if(i>0)
			{
				StrAssign(T[n],line);//
				n++;
			}
			if(n>MAX_SIZE)
			{
				printf("�ļ�̫��.");
				return ERROR;
			}
		}while(i>0);
	}

	fclose(fp);
	return OK;
}