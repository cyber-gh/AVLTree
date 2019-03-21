#pragma once
#include "Node.h"
#include <functional>
#include <stack>
template<typename T>
class BST{
protected:
	Node<T>* root;
	Node<T>* insert(Node<T>* curr, T value);
	void preorder(Node<T>* curr);
	void inorder(Node<T>* curr);
	void postorder(Node<T>* curr);
	Node<T>* remove(Node<T>* curr, T value);
	Node<T>* succ(Node<T>* curr);
	Node<T>* search(Node<T>* curr, T value);

	void traverseValue(Node<T>* curr, std::function<void(T)> it = [](T value) {std::cout << T << " "; });


	
public:
	BST();
	BST(T value);
	//BST(BST& other);
	~BST();

	void insert(T value);
	void remove(T value);
	bool search(T value);
	T maxVal();
	void preorder();
	void inorder();
	void postorder();

	void traverse(std::function<void(T)> it) {
		traverseValue(root, it);
	}
	
	//test functions
	
};

#include "BST.tpp"

