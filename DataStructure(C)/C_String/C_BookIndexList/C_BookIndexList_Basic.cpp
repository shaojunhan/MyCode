#include"C_BookIndexList_Basic.h"

char buf[MaxLineLen+1];//书目缓冲区
WordListType wlist;//词表
NoListType nlist;//常用词表

//
Status InitIdxList(IdxListType &idxlist)
{
	int i;
	for(i=0;i<MaxKeyNum+1;i++)
	{
		InitString(idxlist.item[i].key);
		InitList(idxlist.item[i].bnolist);
	}

	idxlist.last=0;
	return OK;
}

void GetLine(FILE *f)
{
	int l;
	//
	if(f && !feof(f))
	{
		fgets(buf,MaxLineLen,f);
		l=strlen(buf);
		if(feof(f))
			l++;
		buf[l-1]=0;
	}
}

//
void ExtractKeyWord(ElemType &bno)
{
	char *s1,*s2,*p;
	char *kbuf=NULL;
	int l,i;

	for(i=0;i<wlist.last;i++)//
	{
		free(wlist.item[i]);
		wlist.item[i]=NULL;
	}
	wlist.last=0;

	if(buf[0]<'0' || buf[0]>'9')//
		return;

	bno=(buf[0]-'0')*1000+(buf[1]-'0')*100+(buf[2]-'0')*10+(buf[3]-'0')*1;//
	s2=&buf[3];
	do
	{
		s1=s2+1;//
		s2=strchr(s1,' ');
		if(!s2)
		{
			p=buf+strlen(buf);
			s2=s1<p?p:NULL;
		}
		if(s2)
		{
			l=s2-s1;
			kbuf=(char*)malloc((l+1)*sizeof(char));//
			if(!kbuf)
				exit(OVERFLOW);

			for(i=0;i<l;i++)//
				*(kbuf+i)=*(s1+i);
			*(kbuf+i)='\0';
		
			for(i=nlist.last-1;i>=0 && strcmp(kbuf,nlist.item[i])!=0;i--);//
			if(i>=0)
			{
				free(kbuf);
				kbuf=NULL;
				continue;
			}
			wlist.item[wlist.last++]=kbuf;//
			if(wlist.last>=MaxWordNum)//
				break;
		}
	}while(s2);
}

//
Status InsIdxList(IdxListType &idxlist,ElemType bno)
{
	HString wd;
	int i,j;
	bool b;

	InitString(wd);
	for(i=0;i<wlist.last;i++)
	{
		GetWord(i+1,wd);
		j=Locate(idxlist,wd,b);
		if(!b)//
		{
			InsertNewKey(idxlist,j,wd);
			idxlist.last++;
		}
		InsertBookNo(idxlist,j,bno);
	}

	return OK;
}

void PutText(FILE *g,IdxListType idxlist)
{
	int i,j;
	Link p;
	int len;

	if(g)
	{
		fprintf(g,"%d",idxlist.last);
		for(i=0;i<idxlist.last;i++)
		{
			fputc('\n',g);
			for(j=0;j<idxlist.item[i].key.len;j++)
				fprintf(g,"%c",*(idxlist.item[i].key.ch+j));
			ClearString(idxlist.item[i].key);

			fputc('\n',g);
			p=idxlist.item[i].bnolist;
			len=ListLength(idxlist.item[i].bnolist);
			fprintf(g,"%d\n",len);
			for(j=len-1;j>=0;j--)
			{
				fprintf(g,"%d",p->data);
				if(j)
					fputc(10,g);
				p=p->next;
			}
			ClearList(idxlist.item[i].bnolist);
		}
		fclose(g);
	}
}

//
void GetWord(int i,HString &wb)
{
	if(i>0 && i<=wlist.last)
		StrAssign(wb,wlist.item[i-1]);
}

//
int Locate(IdxListType idxlist,HString wd,bool &b)
{
	int i;
	int j=1;

	for(i=0;i<idxlist.last && (j=StrCompare(idxlist.item[i].key,wd))<0;i++);
	b=!j;
	return i+1;
}

//
void InsertNewKey(IdxListType &idxlist,int i,HString wd)
{
	int j;

	if(i<1 || i>idxlist.last+1 || idxlist.last>=MaxKeyNum)
		return;
	else
	{
		for(j=idxlist.last-1;j>=i-1;j--)
		{
			idxlist.item[j+1].key.ch=idxlist.item[j].key.ch,idxlist.item[j].key.ch=NULL;
			idxlist.item[j+1].key.len=idxlist.item[j].key.len,idxlist.item[j].key.len=0;
			idxlist.item[j+1].bnolist=idxlist.item[j].bnolist,idxlist.item[j].bnolist=NULL;
		}
		StrCopy(idxlist.item[i-1].key,wd);
	}
}

//
Status InsertBookNo(IdxListType &idxlist,int i,int bno)
{
	int k;
	if(i<1 || i>idxlist.last)
		return ERROR;

	if(LocateElem(idxlist.item[i-1].bnolist,bno,compare))
		k=FALSE;
	else
		k=ListInsert(idxlist.item[i-1].bnolist,ListLength(idxlist.item[i-1].bnolist)+1,bno);
	return k;
}


//缓冲
void NoBuffer(FILE *f)
{
	int i;

	//常用字表
	char nbuf[MaxLineLen];
	int len,l;

	f=fopen("nolist.b","r");
	if(!f)
		exit(ERROR);

	for(i=0;i<nlist.last;i++)//
		free(nlist.item[i]),nlist.item[i]=NULL;
	nlist.last=0;

	while(!feof(f) && nlist.last<MaxNoNum)
	{
		fgets(nbuf,MaxNoNum,f);
		l=strlen(nbuf);
		if(feof(f))
			l++;
		nbuf[l-1]=0;

		nlist.item[nlist.last]=(char*)malloc((l)*sizeof(char));
		if(!nlist.item[nlist.last])
			exit(OVERFLOW);
		for(i=0;i<l;i++)
			*(nlist.item[nlist.last]+i)=*(nbuf+i);
		nlist.last++;
	}
}

//
void ListBuffer()
{
	int len;
	int i=0;
	FILE *f;
	int bno;
	IdxListType idxlist;//

	f=fopen("nolist.b","r");//
	if(!f)
		exit(ERROR);
	NoBuffer(f);
	fclose(f);

	InitIdxList(idxlist);
	f=fopen("booklist.b","r");//
	if(!f)
		exit(ERROR);

	len=0,fscanf(f,"%d",&len);//
	fgets(buf,MaxLineLen,f);
	for(i=0;i<len;i++)
	{
		GetLine(f);
		ExtractKeyWord(bno);
		InsIdxList(idxlist,bno);
	}
	fclose(f);

	f=fopen("idxlist.b","wb+");//
	if(!f)
		exit(ERROR);
	PutText(f,idxlist);
	fclose(f);
}


//
void Reserve()
{
	FILE *f;
	int len,i,j;
	int bno;
	char c[4];
	//char *p;

	f=fopen("booklist.b","wb+");//
	if(!f)
		exit(ERROR);

	//BookListType booklist;
	printf("初始化书目表\n");
	printf("输入书目数:");
loop1:
	scanf("%d%*c",&len);
	if(len<0)
	{
		printf("输入错误,请重新输入:");
		goto loop1;
	}

	fprintf(f,"%d\n",len);
	for(i=0;i<len;i++)
	{
		printf("输入书号:");
		scanf("%d%*c",&bno);
		
		bno=bno>0?bno:bno*(-1);
		for(j=1;j<=4;j++)
		{
			c[4-j]=bno%10+'0';
			bno/=10;
		}
		for(j=0;j<4;j++)
			fputc(c[j],f);
		printf("输入书名:");
		gets(buf);

		for(j=0;j<strlen(buf);j++)
			fputc(buf[j],f);
		fputc('\n',f);
//
/*
		InitString(booklist.item[i].bname);
		booklist.item[i].bno=bno;
		StrAssign(booklist.item[i].bname,buf);
	}
	booklist.last=len;

	fprintf(f,"%d\n",len);
	for(i=0;i<booklist.last;i++)
	{
		bno=booklist.item[i].bno;
		for(j=1;j<=4;j++)
		{
			c[4-j]=bno%10+'0';
			bno/=10;
		}

		for(j=0;j<=4;j++)
			fputc(c[j],f);
		p=booklist.item[i].bname.ch;
		len=booklist.item[i].bname.len;
		for(j=0;j<len;j++,p++)
			fputc(*p,f);
		fputc(10,f);
		fputs("\r\n",f);

		ClearString(booklist.item[i].bname);
	}
*/
//
	}
	fclose(f);
}

//比较函数
int compare(ElemType e1,ElemType e2)
{
	return e1>e2?1:e1==e2?0:-1;
}