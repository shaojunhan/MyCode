#include"C_BookIndexList_Basic.h"

int main(int argc,char *atgv[])
{
	FILE *f,*g;
	IdxListType idxlist;//
	BookListType booklist;//
	int m;
	Link p;

	//Reserve();
	ListBuffer();

//加载索引表
	char ibuf[MaxLineLen];
	HString wd;
	int len,l,bno;
	int i,j,k;

	InitString(wd);
	InitIdxList(idxlist);
	f=fopen("idxlist.b","r");//
	len=0,fscanf(f,"%d",&len);
	for(i=0;i<len;i++)
	{
		fgets(ibuf,MaxNoNum,f);
		fgets(ibuf,MaxNoNum,f);//
		l=strlen(ibuf);
		ibuf[l-1]=0;
		StrAssign(wd,ibuf);
		InsertNewKey(idxlist,i+1,wd);
		++idxlist.last;

		l=0,fscanf(f,"%d",&l);//
		for(j=0;j<l;j++)
		{
			fscanf(f,"%d",&bno);
			ListInsert(idxlist.item[i].bnolist,j+1,bno);
		}
	}
	fclose(f);

	//加载书目表
	booklist.last=0;
	g=fopen("booklist.b","rb+");//
	if(!g)
		exit(ERROR);
	len=0,fscanf(g,"%d",&len);//
	fgets(ibuf,MaxLineLen,g);
	for(i=0;i<len;i++)
	{
		fgets(ibuf,MaxLineLen,g);
		l=strlen(ibuf);
		if(i==len-1)
			l++;
		ibuf[l-1]=0;

		booklist.item[i].bno=(ibuf[0]-'0')*1000+(ibuf[1]-'0')*100+(ibuf[2]-'0')*10+(ibuf[3]-'0');
		InitString(booklist.item[i].bname);
		StrAssign(booklist.item[i].bname,(&ibuf[3])+1);
	}
	booklist.last=len;
	fclose(g);

	while(1)
	{
		printf("请输入要查询的书目(输入00退出):");
		scanf("%s",ibuf);
		if(!strcmp(ibuf,"00")) break;

		i=0,j=idxlist.last-1,m=(i+j)/2;
		StrAssign(wd,ibuf);
		l=1;
		while(m<=j && m>=i)//从小到大排列
		{
			l=StrCompare(idxlist.item[m].key,wd);
			if(!l)
				break;
			else if(l>0)
				j=m-1;
			else
				i=m+1;
			m=(i+j)/2;
		}

		if(!l)
		{
			p=idxlist.item[m].bnolist;
			for(i=0;i<ListLength(idxlist.item[m].bnolist);i++)
			{
				bno=p->data;
				p=p->next;
				for(j=0;j<booklist.last;j++)
				{
					if(bno==booklist.item[j].bno)
					{

						printf("%d",bno);
						for(k=0;k<StrLength(booklist.item[j].bname);k++)
							printf("%c",*(booklist.item[j].bname.ch+k));
						printf("\n");
					}
				}
			}
		}
		else
		{
			printf("Sorry!没有查找到...\n");
		}
	}

	for(i=0;i<idxlist.last;i++)//
	{
		ClearString(idxlist.item[i].key);
		ClearList(idxlist.item[i].bnolist);
	}

	for(i=0;i<booklist.last;i++)
		ClearString(booklist.item[i].bname);

	printf("欢迎再次使用本系统!\n");
	system("pause");
	return 0;
}
