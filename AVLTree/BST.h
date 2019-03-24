#pragma once
#include "Node.h"
#include <functional>
#include <stack>
#include <vector>
template<typename T>
class BST{
protected:
	Node<T>* root;
	int size = 0;
	Node<T>* insert(Node<T>* curr, T value);
	void preorder(Node<T>* curr);
	void inorder(Node<T>* curr);
	void postorder(Node<T>* curr);
	Node<T>* remove(Node<T>* curr, T value);
	Node<T>* succ(Node<T>* curr);
	Node<T>* search(Node<T>* curr, T value) const ;

	void traverseValue(Node<T>* curr, std::function<void(T)> it = [](T value) {std::cout << T << " "; }) const ;


	
public:
	BST();
	BST(T value);
	//BST(BST& other) {}
	~BST();

	void insert(T value);
	void remove(T value);
	bool search(T value) const ;
	T maxVal();
	void preorder();
	void inorder();
	void postorder();
	int sz() {
		return this->size;
	}


	// something of a replacement for an iterator
	void traverse(std::function<void(T)> it) const {
		traverseValue(root, it);
	}

	
};

#include "BST.tpp"

