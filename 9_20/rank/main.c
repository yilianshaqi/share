#include<stdio.h>
#include"rank.h"

void  main()
{
	data_t array[LEN]={8,2,7,2,6,9,0,1};
	int ret,i;
//	ret=insertsort(array,LEN);
//	ret=binary_insert_sort(array,LEN);
	if(RANK_ERROR==ret)
	{
		return;
	}
	quicksort(array,0,LEN-1);
	for(i=0;i<LEN;i++)
	{
		printf("%5d",array[i]);
	}
	printf("\n");
	return;
}
