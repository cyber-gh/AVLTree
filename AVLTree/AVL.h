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
	AVL<T>(const AVL<T>& other);

	~AVL() {}

	void insert(T value);
	void remove(T value);

	AVL<T>& operator=(AVL<T> other);

	AVL<T>& operator+=(const AVL<T>& other);
	AVL<T> operator+(const AVL<T>& other);
	AVL<T>& operator-=(const AVL<T>& other);
	AVL<T> operator-(const AVL<T>& other);	
	
};

#include "AVL.tpp"


