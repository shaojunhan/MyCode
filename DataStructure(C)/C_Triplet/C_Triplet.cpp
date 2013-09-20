// C_Triplet.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"C_Triplet_Header.h"
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[])
{
	Triplet T;
	InitTriplet(T,5,7,9);

	ElemType e;
	Get(T,2,e);
	printf("%d ",e);

	Put(T,2,8);
	Get(T,2,e);
	printf("%d ",e);

	Max(T,e);
	printf("%d ",e);

	Min(T,e);
	printf("%d",e);

	printf("\nIs Ascending?%d(1-Y;0-N)\n",IsAscending(T));
	printf("Is Descendding?%d(1-Y;0-N)",IsDescending(T));
	system("pause");
	return 0;
}
