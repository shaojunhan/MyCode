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
		printf("输入存盘路径(长度不超过%d):",PATH_MAX_SIZE-1);
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
				printf("文件太大.");
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
	printf("输入在l行之前插入m行:");//
	scanf("%d%d%*c",&l,&m);

	if(l<1 || l>n+1 || m<0 || m>LINE_MAX_SIZE-l+1)//
	{
		printf("输入错误.");
		return ERROR;
	}

	for(i=n+m-1;i>=m+l-1;i--)//
		StrCopy(T[i],T[i-m]);
	
	printf("输入%d行:",m);
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

	printf("删除从l行开始的m行:");
	scanf("%d%d",&l,&m);

	if(l<1 || m<0 || m>n-l+1)
	{
		printf("输入错误.");
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

	printf("把从l行开始的m行插入在原k之前:");
	scanf("%d%d%d%*c",&l,&m,&k);

	if(l<1 || m<0 || m>n-l+1 || k<1 || k>n-m+1)
	{
		printf("输入错误.");
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
	printf("输入要修改的行(%d-%d):",1,n);
	scanf("%d%*c",&l);
	if(l<1 || l>n)
	{
		printf("行号不合法.");
		return ERROR;
	}
	else
	{
		printf("输入修改后的内容:");
		scanf("%s%*c",line);
		ClearString(T[l-1]);//
		StrAssign(T[l-1],line);
		printf("修改成功.");
	}

	return OK;
}

Status Search()//
{
	int i,j;
	char c;
	bool flag=1;
	HString V;

	printf("请输入模式串:");
	scanf("%s%*c",line);
	InitString(V);
	StrAssign(V,line);

	printf("结果:\n");
	for(i=0;flag && i<n;i++)//
	{
		j=1;
		while(j)
		{
			if(j=Index(T[i],V,j))
			{
				printf("行:%d,列:%d",i+1,j);//
				printf("是否继续查找(Y/N):");
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

	printf("请输入待替换的字符串:");//
	scanf("%s%*c",line);
	InitString(V1);
	StrAssign(V1,line);

	printf("替换为:");//
	scanf("%s%*c",line);
	InitString(V2);
	StrAssign(V2,line);

	for(i=0;flag && i<n;i++)//
	{
		if(Replace(T[i],V1,V2))//
		{
			printf("替换成功,是否继续替换(Y/N):");
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
		printf("输入存盘路径(长度不超过%d):",PATH_MAX_SIZE-1);
		scanf("%s",path);
	}

	fp=fopen(path,"wb+");
	if(!fp)
	{
		printf("文件保存错误.");
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
				printf("文件太大.");
				return ERROR;
			}
		}while(i>0);
	}

	fclose(fp);
	return OK;
}