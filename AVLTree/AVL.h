#pragma once
#include "BST.h"
template<typename T>
class AVL :
	public BST<T>
	
{
private:
	Node<T>* insert(Node<T>* curr, T value);
	Node<T>* remove(Node<T>* curr, T value);
	Node<T>* leftRotate(Node<T>* curr);
	Node<T>* rightRotate(Node<T>* curr);

public:
	AVL(): BST<T>(){}
	AVL(T value): BST<T>(value){}
	~AVL() {}

	void insert(T value);
};

#include "AVL.tpp"

