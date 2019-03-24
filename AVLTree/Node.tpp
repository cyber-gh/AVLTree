#include "Node.h"

template<typename T>
inline void Node<T>::updateHeight() {
	height = std::max(Node<T>::getHeight(leftNode), Node<T>::getHeight(rightNode)) + 1;
}

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

template<typename T>
inline int Node<T>::getHeight(Node<T>* node) {
	if (node == nullptr) return 0;
	return node->height;
}

template<typename T>
inline int Node<T>::getBalance(Node<T>* node) {
	if (node == nullptr) return 0;
	return Node<T>::getHeight(node->leftNode) - Node<T>::getHeight(node->rightNode);
}
