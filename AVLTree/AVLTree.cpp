#include <iostream>
#include "AVL.h"
#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  


void test() {
	AVL<int> a,b,c;
	a.insert(1);
	a.insert(2);
	
	b.insert(3);
	b.insert(4);
	b.insert(5);
	c = a + b;
	c.inorder();

}

int main(){
	test();
	_CrtDumpMemoryLeaks();
    
}

