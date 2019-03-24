#include <iostream>
#include "AVL.h"
#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  


void test() {


	AVL<int> a, b, c;
	a.insert(2);
	a.insert(3);
	a.insert(4);
	b.insert(3);
	c = a + b;
	c = a - b;
	//std::cout << c.maxVal() << std::endl;
	c.inorder();

}

AVL<int> val() {
	AVL<int> a;
	a.insert(3);
	return a;
}

void test2() {
	AVL<int> v,c ;
	c.insert(2);
	v = c;
	v = val();
	v.inorder();
}

int main(){
	test();
	
	//for memory leaks
	_CrtDumpMemoryLeaks();
    
}

