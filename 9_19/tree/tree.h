#ifndef _tree_h_
#define _tree_h_
typedef int data_t;

typedef struct TREE
{
	data_t data;
	struct TREE *lchild;
	struct TREE *rchild;
}Tree;
enum state
{
	TREE_ERROR,
	TREE_OK
};
Tree *creatnode(data_t tdata);
Tree* creattree( data_t *tdata,int size );
void showtree(Tree *ptree);
int destroy(Tree *ptree);



#endif 
