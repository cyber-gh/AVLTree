#include <iostream>
#include "BST.h"

int main(){
	BST<int> bst;
	bst.insert(50);
	bst.insert(30);
	bst.insert(20);
	bst.insert(40);
	bst.insert(20);
	bst.insert(70);
	bst.insert(60);
	bst.insert(80);
	bst.inorder();
	bst.remove(20);
	std::cout << std::endl;
	bst.inorder();
    
}
