#include <iostream>
#include "AVL.h"

int main(){
	AVL<int> bst;
	
	bst.insert(50);
	bst.inorder();
	bst.insert(30);
	bst.insert(20);
	bst.insert(40);
	bst.insert(20);
	bst.insert(70);
	bst.insert(60);
	bst.insert(80);
	
    
}

