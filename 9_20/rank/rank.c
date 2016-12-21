#include<stdio.h>
#include"rank.h"
int insertsort(data_t *data,int size)
{
	if(NULL==data)
	{
		return RANK_ERROR;
	}
	data_t temp;
	int i,j;
	for(i=1;i<size;i++)
	{
		temp=data[i];
		j=i-1;
		while(temp<data[j])//ÅÐ¶ÏÅÅÐò·½Ïò
		{
			data[j+1]=data[j];
			j--;
			if(j<0)
			{
				break;
			}
		}
		data[j+1]=temp;
	}
	return RANK_OK;
}

int binary_insert_sort(data_t *data,int size)
{
	if(NULL==data)
	{
		return RANK_ERROR;
	}
	int low,high,mid;
	int i,j,temp;
	for(i=1;i<size;i++)
	{	
		temp=data[i];
		low=0;
		high=i-1;
		while(low<=high)
		{
			mid=(low+high)/2;
			if(data[mid]<temp)//ÅÐ¶ÏÅÅÐò·½Ïò
			{
				high=mid-1;
			}
			else
			{
				low=mid+1;
			}
		}
		for(j=i;j>low;j--)
		{
			data[j]=data[j-1];
		}
		data[j]=temp;
	}
	return RANK_OK;
}
void quicksort(data_t *data,int left,int right)//µÝ¹é¿ìÅÅ
{	
	if(left>=right)
	{
		return ;
	}
	int i,j,key;
	i=left;
	j=right;
	key=data[i];
	
	while(i<j)
	{
		while(i<j&&key>data[j])
		{
			j--;
		}
		data[i]=data[j];
		
		while(i<j&&key<=data[i])
		{
			i++;
		}
		data[j]=data[i];
	}
	data[i]=key;
	quicksort(data,left,i-1);
	quicksort(data,j+1,right);
	return;
}


