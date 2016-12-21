#ifndef _rank_h_
#define _rank_h_
#define LEN 8
typedef int data_t ;
int insertsort(data_t *data ,int size);
void quicksort(data_t *data,int left,int right);
int binary_insert_sort(data_t *data,int size);
enum state 
{
	RANK_ERROR,
	RANK_OK
};


#endif