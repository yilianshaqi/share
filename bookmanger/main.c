#include<stdio.h>
#include "headerfile.h"

void main()
{	
	int i=1;
	while(i)
	{
		printf("Please choose option: 1=Addbook 2=Findbook 3=Deletebook 4=Esc\n");
		int option ;
		scanf("%d",&option);
		switch (option)
		{
			case 1: addbook();
					break;
			case 2: findbook();
					break;
			case 3: deletebook();
					break;
			default : printf("thank you");
					i=0;
					break;
		}
	}
}
