#ifndef _download_
#define _download_
#define BUF_SIZE 4096
#define PORT 6000
typedef struct DATA
{
	char func[10];
	char state[10];
	char data[BUF_SIZE];
}Data;
#define search 0
#define end 1
#define send 2


#endif
