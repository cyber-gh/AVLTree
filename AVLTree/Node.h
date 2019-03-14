#pragma once
#include <iostream>

template<typename T>
class Node{
protected:
	T value;
	int height;
	Node* leftNode;
	Node* rightNode;
	void updateHeight() { 
		height = max((leftNode == nullptr?-1:leftNode->height), (rightNode == nullptr?-1:rightNode->height)) + 1; 
	}
	template<class T> friend class BST;

public:
	Node() : Node(T()) {} //delegating the value constructor with the default value
	Node(T value);
	~Node();
};


template<typename T>
inline Node<T>::Node(T value) {
	this->value = value;
	this->height = -1;
	leftNode = nullptr;
	rightNode = nullptr;
	//std::cout << value;
}

template<typename T>
inline Node<T>::~Node() {
	if (leftNode != nullptr)free(leftNode);
	if (rightNode != nullptr) free(rightNode);
	leftNode = nullptr;
	rightNode = nullptr;
}
