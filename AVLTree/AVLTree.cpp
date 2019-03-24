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
	if (a > b)
		c = a + b;
	if (a < b)
		c = a - b;
	std::cout << c.maxVal() << std::endl;
	std::cout << c;
	//n -> n elements
	std::cout << "d= ";
	std::cin >> d;
	std::cout << d;
	

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
	test3();
	
	//for memory leaks
	_CrtDumpMemoryLeaks();
    
}

