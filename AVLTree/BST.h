#pragma once
#include "Node.h"
template<typename T>
class BST{
protected:
	Node<T>* root;
	Node<T>* insert(Node<T>* curr, T value);
	void preorder(Node<T>* curr);
	void inorder(Node<T>* curr);
	Node<T>* remove(Node<T>* curr, T value);
	Node<T>* succ(Node<T>* curr);
public:
	BST();
	BST(T value);
	~BST();

	void insert(T value);
	void remove(T value);
	void preorder();
	void inorder();
	//test functions
	
};

#include "BST.tpp"

