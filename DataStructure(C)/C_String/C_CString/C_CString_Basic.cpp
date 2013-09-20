#include"C_CString_Basic.h"
#include<stdlib.h>
#include<math.h>
#include<string.h>

//占位字符
char blank='#';

//赋值
Status StrAssign(CString &T,char *chars)
{
	int i,j,t;
	Link p,q;
	int size;
	
	while(T.head)//初始化，清空链表
		T.tail=T.head->next,free(T.head),T.head=T.tail;
	
	if(!(j=strlen(chars)))//初始化条件
		return FALSE;
	else
	{
		size=j/CHUNKSIZE;//块的数量
		if(j%CHUNKSIZE)
			size++;
		
		for(t=0;t<size;t++)
		{
			p=(Link)malloc(sizeof(struct LNode));
			if(!p)
				exit(ERROR);
			
			if(t==0)//初始头结点
				T.head=p;
			else
				q->next=p;
			q=p;
			
			for(i=0;i<CHUNKSIZE && *chars;i++)//给块赋值
				*(p->ch+i)=*chars++;
			
			if(!*chars)//最后一个块
			{
				p->next=NULL,T.length=j,T.tail=p;
				for(i;i<CHUNKSIZE;i++)
					*(p->ch+i)=blank;
			}
		}
	}

	return OK;
}

//连接串
Status Concat(CString &T,CString S1,CString S2)
{
	int i;
	Link p,q;
	Link ps;
	
	while(T.head)//初始化-清空链表
		T.tail=T.head->next,free(T.head),T.head=T.tail;
	
	i=S1.length;
	ps=S1.head;
	while(ps)//复制串S1
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
	
	ps=S2.head;//复制串S2
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
	
	if(q)//处理尾指针
		q->next=NULL,T.tail=q,T.length=S1.length+S2.length;
	
	return OK;
}

//字符串比较
Status StrCompare(CString T,CString S)
{
	int pi,pj;
	int i;
	
	pi=0,pj=0,i=0;
	while(i<T.length && i<S.length)
	{
		i++;//比较第i个字符
		while(*(T.head->ch+pi)==blank)//跳过前面的空字符
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
		
		if(*(T.head->ch+pi)!=*(S.head->ch+pi))//第i个字符不等时比较
			return *(T.head->ch+pi)-*(S.head->ch+pj);
		else//相等，进行下一个比较
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

//求字符长度
int StrLength(CString S)
{
	return S.length;
}

//求从pos位置开始长度为len的子串
Status SubString(CString &Sub,CString S,int pos,int len)
{
	int i,pi;
	int size;
	Link p,q;
	
	if(pos<0 || len<0 || len>S.length-pos+1)
		return ERROR;
	
	while(Sub.head)//初始化-清空链表
		Sub.tail=Sub.head->next,free(Sub.head),Sub.head=Sub.tail;
	
	size=len/CHUNKSIZE;
	if(len%CHUNKSIZE)
		size++;
	
	while(size--)//新建长度为len的空子串
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
	while(i<pos-1)//找到pos前的位置
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
	while(len--)//给子串赋值
	{
		while(*(S.head->ch+pi)==blank)//跳过空格
		{
			pi++;
			if(pi>=CHUNKSIZE)
				pi=0,S.head=S.head->next;
		}
		
		*(p->ch+i)=*(S.head->ch+pi);//赋值
		
		pi++;//主串S的下一个
		if(pi>=CHUNKSIZE)
			pi=0,S.head=S.head->next;
		
		i++;//子串Sub的下一个
		if(i>=CHUNKSIZE)
			i=0,p=p->next;
		
		if(!len)//最后的块
			for(;i<CHUNKSIZE;i++)
				*(p->ch+i)=blank;
	}
	
	return OK;
}

//增加的初始化函数
Status InitString(CString &T)
{
	T.head=T.tail=NULL;
	T.length=0;
	return OK;
}

//销毁字符串
Status DestroyString(CString &S)
{
	return 0;
}

//清空字符串
Status ClearString(CString &S)
{
	while(S.head)
		S.tail=S.head->next,free(S.head),S.head=S.tail;
	S.head=S.tail=NULL,S.length=0;
	return OK;
}

//判断是否为空串
Status StrEmpty(CString S)
{
	return S.length==0?TRUE:FALSE;
}

//字符串拷贝
Status StrCopy(CString &T,CString S)
{
	Link p,q=NULL;

	while(T.head)//初始化-清空链表
		T.tail=T.head->next,free(T.head),T.head=T.tail;

	T.head=NULL;
	while(S.head)
	{
		p=(Link)malloc(sizeof(struct LNode));
		if(!p)
			exit(ERROR);
		
		*p=*S.head;//整块拷贝
		S.head=S.head->next;
		
		if(!T.head)//初始头结点
			T.head=p;
		else//非头结点
			q->next=p;
		q=p;
	}
	
	if(q)//处理尾结点
		q->next=NULL;
	T.tail=q,T.length=S.length;
	
	return OK;
}

//模式匹配KMP算法
int Index(CString S,CString T,int pos)
{
	int pi,pj,i,j,counter;
	Link pt,ps;
	
	if(pos<0 || pos>S.length-T.length+1)//初始条件
		return 0;
	
	int *nextval=(int*)malloc((T.length+1)*sizeof(struct LNode));
	if(!nextval)
		exit(OVERFLOW);
	
	nextval[1]=0;
	i=pi=1,j=pj=0;
	pt=ps=T.head;
	
	while(i<T.length)//求模式串的next函数值
	{
		while(*(ps->ch+pi)==blank)//跳过空字符
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
		
		if(j==0 || *(pt->ch+pj)==*(ps->ch+pi))//第一种情况j+1=j
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
		else//第二种情况，回到上一个位置
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
	while(i<pos-1)//找到pos的前一个字符
	{
		if(*(ps->ch+pi)!=blank)
			i++;
		pi++;
		if(pi>=CHUNKSIZE)
			pi=0,ps=ps->next;
	}

	j=pj=0,pt=T.head;
	while(i<S.length && j<T.length)//匹配
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

//字符串替换
Status Replace(CString &S,CString T,CString V)
{
	int i;
	
	i=1;
	while(i)
	{
		i=Index(S,T,i);//查找到的最前的匹配串位置
		if(i)
		{
			StrDelete(S,i,T.length);//删除
			StrInsert(S,V,i);//插入
			i+=V.length;//跳过V.length长度
		}
	}
	
	Zip(S);//压缩

	return OK;
}

//插入字符串
Status StrInsert(CString &S,CString T,int pos)
{
	int pi,pj;
	Link pt,ps,pv,qv=NULL;
	
	if(pos<0 || pos>S.length+1)
		return FALSE;
	
	CString V;
	InitString(V);

	pt=T.head;
	while(pt)//初始化待插入串
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
	while(pj<pos-1)//查找到第pos个字符所在块
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
	
	*pt=*ps,pj=pi;//拆分第pos个字符所在块
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

//删除第pos个位置开始len个字符
Status StrDelete(CString &S,int pos,int len)
{
	int pi,pj;
	Link ps;
	
	if(pos<0 || len<0 || len>S.length-pos+1)//条件
		return ERROR;
	
	pi=0,pj=0;
	ps=S.head;
	while(pi<pos-1)//查找到第pos-1个字符位置
	{
		if(*(ps->ch+pj)!=blank)
			pi++;
		pj++;
		if(pj>=CHUNKSIZE)
			pj=0,ps=ps->next;
	}
	
	while(pi<len+pos-1)//删除
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

//压缩字符串，去除多余空格
Status Zip(CString &S)
{
	int pi,pj,j,i;
	Link p,q=NULL,head=NULL;

	j=S.length/CHUNKSIZE;//块数
	if(S.length%CHUNKSIZE)
		j++;

	for(i=0;i<j;i++)//建空链表
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

	while(S.head)//销毁原链表
	{
		S.tail=S.head->next;
		free(S.head);
		S.head=S.tail;
	}

	S.head=head;//处理新链表
	S.tail=q;
	return OK;
}