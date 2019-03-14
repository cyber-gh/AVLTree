#pragma once
#include <iostream>

template<typename T>
class Node{
protected:
	T value;
	Node* leftNode;
	Node* rightNode;
	template<class T> friend class BST;

public:
	Node() : Node(T()) {} //delegating the value constructor with the default value
	Node(T value);
	~Node();
};


template<typename T>
inline Node<T>::Node(T value) {
	this->value = value;
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
