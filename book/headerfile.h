#ifndef _book
#define _book

struct date
{
	int year;
	int month;
	int day;
};

typedef struct Book
{
	char name[30];
	char author[20];
	struct date version;
	char publish[30];
	char abstract[100];
	
}book;
#define NUM  20 
book *num[NUM];

int addbook(void );
int deletebook(void);
int findbook(void);









#endif 