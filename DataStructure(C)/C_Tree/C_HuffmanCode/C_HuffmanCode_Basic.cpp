#include"C_HuffmanCode_Basic.h"
#include<limits.h>//INT_MAX����ͷ�ļ�
#include<stdlib.h>
#include<string.h>
#include<math.h>

#if CHAR
ElemType Nil='#';
#elif INT
ElemType Nil=-1;
#endif;

void Select(HuffmanTree &HT,int i,int &s1,int &s2)
{
	int j,temp;
	bool flag;

	flag=0;
	s1=s2=-1;
	for(j=0;j<i;j++)
	{
		if((HT+j)->parent==-1)
		{
			if(s1==-1 || s2==-1 || (HT+j)->weight<(HT+s1)->weight || (HT+j)->weight<(HT+s2)->weight)
			{
				if(0==flag)
				{
					s1=j;
					flag=1;
				}
				else
				{
					s2=j;
					flag=0;
				}
			}
		}
	}
	if((HT+s1)->weight>(HT+s2)->weight)//��֤Ȩs1<s2
	{
		temp=s1;
		s1=s2;
		s2=temp;
	}
}

int HuffmanCoding(HuffmanTree &HT,HuffmanCode &HC,int *w,ElemType *data,int n)
{
	int i;
	int s1,s2;

	HT=(HuffmanTree)malloc((2*n-1)*sizeof(HTNode));
	if(!HT)
		exit(OVERFLOW);

	for(i=0;i<n;i++)//��ʼҶ��
	{
		(HT+i)->e=*(data+i);
		(HT+i)->weight=*(w+i);
		(HT+i)->parent=(HT+i)->lchild=(HT+i)->rchild=-1;
	}

	for(;i<2*n-1;i++)//��ʼ��Ҷ��
	{
		(HT+i)->e=Nil;
		(HT+i)->weight=0;
		(HT+i)->parent=(HT+i)->lchild=(HT+i)->rchild=-1;
	}

	for(i=n;i<2*n-1;i++)
	{
		Select(HT,i,s1,s2);//s1��s2Ϊ��СȨֵ����s1<s2
		(HT+i)->lchild=s1;(HT+i)->rchild=s2;
		(HT+s1)->parent=i;(HT+s2)->parent=i;
	}
	
	CreateHuffmanCode(HT,HC,n);//�����շ��������
	return 1;//���سɹ�״̬
}

int CreateHuffmanCode(HuffmanTree HT,HuffmanCode &HC,int n)
{
	//�㷨һ:(��Ҷ�ӽڵ�˳������)
#if TEST
	int i;
	int j,k;
	int start;
	char *cd;

	cd=(char*)malloc(n*sizeof(char));
	HC=(HuffmanCode)malloc(n*sizeof(HCNode));
	if(!HC || !cd)
		exit(OVERFLOW);
		
	*(cd+n-1)='\0';
	for(i=0;i<n;i++)
	{
		start=n-1;
		k=i;
		for(j=(HT+i)->parent;j!=-1;j=(HT+j)->parent)
		{
			if((HT+j)->lchild==k)
				*(cd+(--start))='0';
			else
				*(cd+(--start))='1';
			k=j;
		}
		(HC+i)->e=(HT+i)->e;
		(HC+i)->code=(char*)malloc((n-start)*sizeof(char));
		if(!(HC+i)->code)
			exit(OVERFLOW);
		strcpy((HC+i)->code,(cd+start));
	}
	free(cd);
	return 1;
#else
	//�㷨��:����ջ���ɺշ��������(�Ӹ��ڵ�����)
	int root;
	int i,p;
	int cdlen;
	char *cd;

	cd=(char*)malloc(n*sizeof(char));
	HC=(HuffmanCode)malloc(n*sizeof(HCNode));
	if(!cd || !HC)
		exit(OVERFLOW);

	root=n;
	for(i=0;i<n;i++)
		(HT+i)->weight=0;
	for(i=n;i<2*n-1;i++)
	{
		(HT+i)->weight=0;
		if((HT+i)->parent==-1)
			root=i;
	}

	p=root;
	cdlen=0;
	while(p!=-1)
	{
		if((HT+p)->weight==0)
		{
			(HT+p)->weight=1;
			if((HT+p)->lchild!=-1)
			{
				p=(HT+p)->lchild;
				*(cd+cdlen++)='0';
			}
			else if((HT+p)->rchild==-1)
			{
				*(cd+cdlen)='\0';
				(HC+p)->e=(HT+p)->e;
				(HC+p)->code=(char*)malloc((cdlen+1)*sizeof(char));
				if(!(HC+p)->code)
					exit(OVERFLOW);
				strcpy((HC+p)->code,cd);
			}
		}
		else if((HT+p)->weight==1)
		{
			(HT+p)->weight=2;
			if((HT+p)->rchild!=-1)
			{
				*(cd+cdlen++)='1';
				p=(HT+p)->rchild;
			}
		}
		else
		{
			(HT+p)->weight=0;
			p=(HT+p)->parent;
			cdlen--;
		}
	}
	free(cd);
	return 1;
#endif;
}

int TransCoding(HuffmanTree HT,char *code,ElemType &e,int n)//����
{
	int len,pointer;
	int i,root;

	root=-1;
	for(i=n;i<2*n-1;i++)//�ҵ����ڵ�
		if((HT+i)->parent==-1)
		{
			root=i;
			break;
		}

	len=strlen(code);
	pointer=root;
	for(i=0;pointer!=-1 && i<len;i++)//�Ӹ������ҵ�Ҷ��
	{
		if(*(code+i)=='0')
			pointer=(HT+pointer)->lchild;
		else
			pointer=(HT+pointer)->rchild;
	}

	if(pointer==-1 || (HT+pointer)->lchild!=-1 || (HT+pointer)->rchild!=-1)
	{
		e=Nil;
		return 0;
	}
	else
		e=(HT+pointer)->e;
	return 1;
}

int GenerateCoding(HuffmanTree HT,char *code,ElemType e,int n)//ת��
{
	int i,p,start;
	int leaf;
	char *cd;

	leaf=-1;
	for(i=0;i<n;i++)
		if(e==(HT+i)->e)
		{
			leaf=i;
			break;
		}

	if(leaf==-1)
	{
		e=Nil;
		return 0;
	}

	cd=(char*)malloc((n)*sizeof(char));
	if(!cd)
		exit(OVERFLOW);

	*(cd+n-1)='\0';
	start=n-1;
	p=leaf;
	for(p=(HT+leaf)->parent;p!=-1;p=(HT+p)->parent)
	{
		if((HT+p)->lchild==leaf)
			*(cd+(--start))='0';
		else
			*(cd+(--start))='1';
		leaf=p;
	}
	strcpy(code,(cd+start));
	free(cd);
	return 1;
}
