#include <iostream>
#include "AVL.h"
#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  


void test() {


	AVL<int> a, b, c, d;
	a.insert(2);
	a.insert(3);
	a.insert(4);
	b.insert(3);
	a.remove(2);
	a.remove(6);
	c = a + b;
	c = a - b;
	std::cout << c.maxVal() << std::endl;
	std::cout << c;
	//std::cout << "d= ";
	//std::cin >> d;
	//std::cout << d;
	

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

void test3() {
	AVL<int> a;
	std::cin >> a;
	int* temp = a.inorder();
	for (int i = 0; i < a.sz(); i++) std::cout << temp[i] << " ";
	free(temp);
}

int main(){
	test();
	
	//for memory leaks
	_CrtDumpMemoryLeaks();
    
}

