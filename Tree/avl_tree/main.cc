#include "avl_tree.h"

int main( )
{ 
	AVLTree* t = new AVLTree();
	t->Insert(34);
	t->Insert(18);
	t->Insert(7);
	t->Insert(69);
	t->Insert(55);

	t->Bfs();
	return 0;
}
