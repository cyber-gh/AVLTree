#include "BST.h"


template<typename T>
Node<T>* BST<T>::insert(Node<T>* curr, T value){
	if (curr == nullptr) return (new Node<T>(value));

	if (value < curr->value)
		curr->leftNode = insert(curr->leftNode, value);
	if (value > curr->value)
		curr->rightNode = insert(curr->rightNode, value);

	return curr;
}

template<typename T>
void BST<T>::preorder(Node<T>* curr){
	if (curr == nullptr) return;

	std::cout << curr->value << " ";
	preorder(curr->leftNode);
	preorder(curr->rightNode);
}

template<typename T>
void BST<T>::inorder(Node<T>* curr){
	if (curr == nullptr) return;

	inorder(curr->leftNode);
	std::cout << curr->value << " ";
	inorder(curr->rightNode);
}

template<typename T>
Node<T>* BST<T>::remove(Node<T>* curr, T value){
	if (curr == nullptr) return curr;


	//recontrsuct the tree on the way up
	if (value < curr->value)
		curr->leftNode = remove(curr->leftNode, value);
	else if (value > curr->value)
		curr->rightNode = remove(curr->rightNode, value);
	else {
		//found the node, now deleting
		if (curr->leftNode == nullptr) {
			Node<T>* temp = curr->rightNode;
			delete curr;
			return temp;
		}
		if (curr->rightNode == nullptr) {
			Node<T>* temp = curr->leftNode;
			delete curr;
			return temp;
		}

		Node<T>* nxt = succ(curr);
		curr->value = nxt->value;

		curr->rightNode = remove(curr->rightNode, nxt->value);
	}

	return curr;

}

template<typename T>
Node<T>* BST<T>::succ(Node<T>* curr)
{
	curr = curr->rightNode;
	while (curr->leftNode != nullptr)
		curr = curr->leftNode;
	return curr;
}

template<typename T>
BST<T>::BST() {
	this->root = nullptr;
}

template<typename T>
BST<T>::BST(T value){
	root = new Node<T>(value);
}

template<typename T>
BST<T>::~BST()
{
	if (root != nullptr) free(root);
	root = nullptr;
	//TODO delete all tree
}

template<typename T>
inline void BST<T>::insert(T value) {
	root = insert(root, value);
}

template<typename T>
void BST<T>::remove(T value){
	root = remove(root, value);
}

template<typename T>
void BST<T>::preorder(){
	preorder(root);
}

template<typename T>
void BST<T>::inorder(){
	inorder(root);
}

