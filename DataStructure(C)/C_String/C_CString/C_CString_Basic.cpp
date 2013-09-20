#include"C_CString_Basic.h"
#include<stdlib.h>
#include<math.h>
#include<string.h>

//ռλ�ַ�
char blank='#';

//��ֵ
Status StrAssign(CString &T,char *chars)
{
	int i,j,t;
	Link p,q;
	int size;
	
	while(T.head)//��ʼ�����������
		T.tail=T.head->next,free(T.head),T.head=T.tail;
	
	if(!(j=strlen(chars)))//��ʼ������
		return FALSE;
	else
	{
		size=j/CHUNKSIZE;//�������
		if(j%CHUNKSIZE)
			size++;
		
		for(t=0;t<size;t++)
		{
			p=(Link)malloc(sizeof(struct LNode));
			if(!p)
				exit(ERROR);
			
			if(t==0)//��ʼͷ���
				T.head=p;
			else
				q->next=p;
			q=p;
			
			for(i=0;i<CHUNKSIZE && *chars;i++)//���鸳ֵ
				*(p->ch+i)=*chars++;
			
			if(!*chars)//���һ����
			{
				p->next=NULL,T.length=j,T.tail=p;
				for(i;i<CHUNKSIZE;i++)
					*(p->ch+i)=blank;
			}
		}
	}

	return OK;
}

//���Ӵ�
Status Concat(CString &T,CString S1,CString S2)
{
	int i;
	Link p,q;
	Link ps;
	
	while(T.head)//��ʼ��-�������
		T.tail=T.head->next,free(T.head),T.head=T.tail;
	
	i=S1.length;
	ps=S1.head;
	while(ps)//���ƴ�S1
	{
		p=(Link)malloc(sizeof(struct LNode));
		if(!p)
			exit(ERROR);
		
		*p=*ps;
		ps=ps->next;
		
		if(!T.head)
			T.head=p;
		else
			q->next=p;
		q=p;
	}
	
	ps=S2.head;//���ƴ�S2
	while(ps)
	{
		p=(Link)malloc(sizeof(struct LNode));
		if(!p)
			exit(ERROR);
		
		*p=*ps;
		ps=ps->next;
		if(q)
			q->next=p;
		else
			T.head=p;
		q=p;
	}
	
	if(q)//����βָ��
		q->next=NULL,T.tail=q,T.length=S1.length+S2.length;
	
	return OK;
}

//�ַ����Ƚ�
Status StrCompare(CString T,CString S)
{
	int pi,pj;
	int i;
	
	pi=0,pj=0,i=0;
	while(i<T.length && i<S.length)
	{
		i++;//�Ƚϵ�i���ַ�
		while(*(T.head->ch+pi)==blank)//����ǰ��Ŀ��ַ�
		{
			pi++;
			if(pi>=CHUNKSIZE)
				pi=0,T.head=T.head->next;
		}
		
		while(*(S.head->ch+pj)==blank)
		{
			pj++;
			if(pj>=CHUNKSIZE)
				pj=0,S.head=S.head->next;
		}
		
		if(*(T.head->ch+pi)!=*(S.head->ch+pi))//��i���ַ�����ʱ�Ƚ�
			return *(T.head->ch+pi)-*(S.head->ch+pj);
		else//��ȣ�������һ���Ƚ�
		{
			pi++;
			if(pi>=CHUNKSIZE)
				pi=0,T.head=T.head->next;
			
			pj++;
			if(pj>=CHUNKSIZE)
				pj=0,S.head=S.head->next;
		}
	}
	
	return T.length-S.length;
}

//���ַ�����
int StrLength(CString S)
{
	return S.length;
}

//���posλ�ÿ�ʼ����Ϊlen���Ӵ�
Status SubString(CString &Sub,CString S,int pos,int len)
{
	int i,pi;
	int size;
	Link p,q;
	
	if(pos<0 || len<0 || len>S.length-pos+1)
		return ERROR;
	
	while(Sub.head)//��ʼ��-�������
		Sub.tail=Sub.head->next,free(Sub.head),Sub.head=Sub.tail;
	
	size=len/CHUNKSIZE;
	if(len%CHUNKSIZE)
		size++;
	
	while(size--)//�½�����Ϊlen�Ŀ��Ӵ�
	{
		p=(Link)malloc(sizeof(struct LNode));
		if(!p)
			exit(ERROR);
		
		if(!Sub.head)
			Sub.head=p;
		else
			q->next=p;
		q=p;
	}
	if(q)
		q->next=NULL;
	Sub.tail=q,Sub.length=len;

	i=0;
	while(i<pos-1)//�ҵ�posǰ��λ��
	{
		while(*(S.head->ch+pi)==blank)
		{
			pi++;
			if(pi>=CHUNKSIZE)
				pi=0,S.head=S.head->next;
		}
		
		i++;
		pi++;
		if(pi>=CHUNKSIZE)
			pi=0,S.head=S.head->next;
	}
	
	i=0;
	p=Sub.head;
	while(len--)//���Ӵ���ֵ
	{
		while(*(S.head->ch+pi)==blank)//�����ո�
		{
			pi++;
			if(pi>=CHUNKSIZE)
				pi=0,S.head=S.head->next;
		}
		
		*(p->ch+i)=*(S.head->ch+pi);//��ֵ
		
		pi++;//����S����һ��
		if(pi>=CHUNKSIZE)
			pi=0,S.head=S.head->next;
		
		i++;//�Ӵ�Sub����һ��
		if(i>=CHUNKSIZE)
			i=0,p=p->next;
		
		if(!len)//���Ŀ�
			for(;i<CHUNKSIZE;i++)
				*(p->ch+i)=blank;
	}
	
	return OK;
}

//���ӵĳ�ʼ������
Status InitString(CString &T)
{
	T.head=T.tail=NULL;
	T.length=0;
	return OK;
}

//�����ַ���
Status DestroyString(CString &S)
{
	return 0;
}

//����ַ���
Status ClearString(CString &S)
{
	while(S.head)
		S.tail=S.head->next,free(S.head),S.head=S.tail;
	S.head=S.tail=NULL,S.length=0;
	return OK;
}

//�ж��Ƿ�Ϊ�մ�
Status StrEmpty(CString S)
{
	return S.length==0?TRUE:FALSE;
}

//�ַ�������
Status StrCopy(CString &T,CString S)
{
	Link p,q=NULL;

	while(T.head)//��ʼ��-�������
		T.tail=T.head->next,free(T.head),T.head=T.tail;

	T.head=NULL;
	while(S.head)
	{
		p=(Link)malloc(sizeof(struct LNode));
		if(!p)
			exit(ERROR);
		
		*p=*S.head;//���鿽��
		S.head=S.head->next;
		
		if(!T.head)//��ʼͷ���
			T.head=p;
		else//��ͷ���
			q->next=p;
		q=p;
	}
	
	if(q)//����β���
		q->next=NULL;
	T.tail=q,T.length=S.length;
	
	return OK;
}

//ģʽƥ��KMP�㷨
int Index(CString S,CString T,int pos)
{
	int pi,pj,i,j,counter;
	Link pt,ps;
	
	if(pos<0 || pos>S.length-T.length+1)//��ʼ����
		return 0;
	
	int *nextval=(int*)malloc((T.length+1)*sizeof(struct LNode));
	if(!nextval)
		exit(OVERFLOW);
	
	nextval[1]=0;
	i=pi=1,j=pj=0;
	pt=ps=T.head;
	
	while(i<T.length)//��ģʽ����next����ֵ
	{
		while(*(ps->ch+pi)==blank)//�������ַ�
		{
			pi++;
			if(pi>=CHUNKSIZE)
				pi=0,ps=ps->next;
		}
		
		while(*(pt->ch+pj)==blank)
		{
			pj++;
			if(pj>=CHUNKSIZE)
				pj=0,pt=pt->next;
		}
		
		if(j==0 || *(pt->ch+pj)==*(ps->ch+pi))//��һ�����j+1=j
		{
			i++,j++;
			
			pj++;
			if(pj>=CHUNKSIZE)
				pj=0,pt=pt->next;
			pi++;
			if(pi>=CHUNKSIZE)
				pi=0,ps=ps->next;
			
			if(j==0)
				nextval[i]=j;
			else
				nextval[i]=nextval[j];
		}
		else//�ڶ���������ص���һ��λ��
		{
			j=nextval[j];
			counter=pj=0;
			pt=T.head;
			
			while(counter<j)
			{
				while(*(pt->ch+pj)!=blank)
					counter++;
				pj++;
				if(pj>=CHUNKSIZE)
					pj=0,pt=pt->next;
			}
		}
	}
	
	i=pi=0,ps=S.head;
	while(i<pos-1)//�ҵ�pos��ǰһ���ַ�
	{
		if(*(ps->ch+pi)!=blank)
			i++;
		pi++;
		if(pi>=CHUNKSIZE)
			pi=0,ps=ps->next;
	}

	j=pj=0,pt=T.head;
	while(i<S.length && j<T.length)//ƥ��
	{
		while(*(ps->ch+pi)==blank)
		{
			pi++;
			if(pi>=CHUNKSIZE)
				pi=0,ps=ps->next;
		}

		while(*(pt->ch+pj)==blank)
		{
			pj++;
			if(pj>=CHUNKSIZE)
				pj=0,pt=pt->next;
		}
		
		if(j==0 || *(ps->ch+pi)==*(pt->ch+pj))
		{
			i++,j++;
			pi++,pj++;
			
			if(pj>=CHUNKSIZE)
				pj=0,pt=pt->next;
			if(pi>=CHUNKSIZE)
				pi=0,ps=ps->next;
		}
		else
		{
			j=nextval[j];
			counter=pj=0;
			pt=T.head;
			
			while(counter<j)
			{
				while(*(pt->ch+pj)!=blank)
					counter++;
				pj++;
				if(pj>=CHUNKSIZE)
					pj=0,pt=pt->next;
			}
		}
	}

	free(nextval);

	if(j>=T.length)
		return i-T.length+1;
	else
		return 0;
}

//�ַ����滻
Status Replace(CString &S,CString T,CString V)
{
	int i;
	
	i=1;
	while(i)
	{
		i=Index(S,T,i);//���ҵ�����ǰ��ƥ�䴮λ��
		if(i)
		{
			StrDelete(S,i,T.length);//ɾ��
			StrInsert(S,V,i);//����
			i+=V.length;//����V.length����
		}
	}
	
	Zip(S);//ѹ��

	return OK;
}

//�����ַ���
Status StrInsert(CString &S,CString T,int pos)
{
	int pi,pj;
	Link pt,ps,pv,qv=NULL;
	
	if(pos<0 || pos>S.length+1)
		return FALSE;
	
	CString V;
	InitString(V);

	pt=T.head;
	while(pt)//��ʼ�������봮
	{
		pv=(Link)malloc(sizeof(struct LNode));
		if(!pv)
			exit(OVERFLOW);
		
		*pv=*pt;
		pt=pt->next;
		
		if(!V.head)
			V.head=pv;
		else
			qv->next=pv;
		qv=pv;
	}
	
	if(qv)
		qv->next=NULL;
	V.tail=qv,V.length=T.length;
	
	pj=pi=0;
	ps=S.head;
	while(pj<pos-1)//���ҵ���pos���ַ����ڿ�
	{
		if(*(ps->ch+pi)!=blank)
			pj++;
		pi++;
		if(pi>=CHUNKSIZE)
			pi=0,ps=ps->next;
	}
	
	pt=(Link)malloc(sizeof(struct LNode));
	if(!pt)
		exit(OVERFLOW);
	
	*pt=*ps,pj=pi;//��ֵ�pos���ַ����ڿ�
	for(pj;pj<CHUNKSIZE;pj++)
		*(ps->ch+pj)=blank;
	for(pi--;pi>=0;pi--)
		*(pt->ch+pi)=blank;
	
	ps->next=V.head;
	V.tail->next=pt;
	if(!pt->next)
		S.tail=pt;

	S.length+=T.length;
	return OK;
}

//ɾ����pos��λ�ÿ�ʼlen���ַ�
Status StrDelete(CString &S,int pos,int len)
{
	int pi,pj;
	Link ps;
	
	if(pos<0 || len<0 || len>S.length-pos+1)//����
		return ERROR;
	
	pi=0,pj=0;
	ps=S.head;
	while(pi<pos-1)//���ҵ���pos-1���ַ�λ��
	{
		if(*(ps->ch+pj)!=blank)
			pi++;
		pj++;
		if(pj>=CHUNKSIZE)
			pj=0,ps=ps->next;
	}
	
	while(pi<len+pos-1)//ɾ��
	{
		if(*(ps->ch+pj)!=blank)
			pi++,*(ps->ch+pj)=blank;
		pj++;
		if(pj>=CHUNKSIZE)
			pj=0,ps=ps->next;
	}
	
	S.length-=len;
	Zip(S);

	return OK;
}

//ѹ���ַ�����ȥ������ո�
Status Zip(CString &S)
{
	int pi,pj,j,i;
	Link p,q=NULL,head=NULL;

	j=S.length/CHUNKSIZE;//����
	if(S.length%CHUNKSIZE)
		j++;

	for(i=0;i<j;i++)//��������
	{
		p=(Link)malloc(sizeof(struct LNode));
		if(!p)
			exit(OVERFLOW);

		if(!head)
			head=p;
		else
			q->next=p;
		q=p;
	}
	if(q)
		q->next=NULL;

	pj=pi=0,p=head;
	S.tail=S.head;
	i=0;
	while(i<S.length)
	{
		if(*(S.tail->ch+pi)!=blank)
		{
			*(p->ch+pj)=*(S.tail->ch+pi);
			pj++;
			i++;
			if(pj>=CHUNKSIZE)
				pj=0,p=p->next;
		}
		pi++;
		if(pi>=CHUNKSIZE)
			pi=0,S.tail=S.tail->next;
	}

	for(;p && pj<CHUNKSIZE;pj++)
		*(p->ch+pj)=blank;

	while(S.head)//����ԭ����
	{
		S.tail=S.head->next;
		free(S.head);
		S.head=S.tail;
	}

	S.head=head;//����������
	S.tail=q;
	return OK;
}