#pragma once
#include <algorithm>


template<typename T>
class Node{
private:
	T value;
	int height;
	Node* leftNode;
	Node* rightNode;
	void updateHeight() { 
		height = std::max(Node<T>::getHeight(leftNode), Node<T>::getHeight(rightNode)) + 1;
	}

	template<class T> friend class BST;
	template<class T> friend class AVL;

public:
	Node() : Node(T()) {} //delegating to the value constructor with the default value
	Node(T value);
	~Node();

	static int getHeight(Node<T>* node) {
		if (node == nullptr) return -1;
		return node->height;
	}
	static int getBalance(Node<T>* node) {
		if (node == nullptr) return 0;
		return Node<T>::getHeight(node->leftNode) - Node<T>::getHeight(node->rightNode);
	}
};


template<typename T>
Node<T>::Node(T value) {
	this->value = value;
	this->height = 1;
	leftNode = nullptr;
	rightNode = nullptr;
}

template<typename T>
Node<T>::~Node() {
}
