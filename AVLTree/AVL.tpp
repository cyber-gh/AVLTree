#include "AVL.h"

template<typename T>
Node<T>* AVL<T>::insert(Node<T>* curr, T value) {
	if (curr == nullptr) return (new Node<T>(value));

	if (value < curr->value)
		curr->leftNode = insert(curr->leftNode, value);
	else if (value > curr->value)
		curr->rightNode = insert(curr->rightNode, value);
	else return curr;

	curr->updateHeight();

	int balance = Node<T>::getBalance(curr);

	// left heavy
	if (balance > 1) {
		if (value < curr->leftNode->value)
			return rightRotate(curr);
		if (value > curr->leftNode->value) {
			curr->leftNode = leftRotate(curr->leftNode);
			return rightRotate(curr);
		}
	}

	// right heavy
	if (balance < -1) {
		if (value > curr->rightNode->value)
			return leftRotate(curr);
		if (value < curr -> rightNode->value) {
			curr->rightNode = rightRotate(curr->rightNode);
			return leftRotate(curr);
		}
	}

	// if is balanced return and go up
	return curr;

}

template<typename T>
Node<T>* AVL<T>::remove(Node<T>* curr, T value){
	// same as bst remove
	if (curr == nullptr) 
		return curr;

	if (value < curr->value)
		curr->leftNode = remove(curr->leftNode, value);
	else if (value > curr->value)
		curr->rightNode = remove(curr->rightNode, value);
	else {
		//found it, now deleting

		//only one child
		if (curr->leftNode == nullptr || curr->rightNode == nullptr) {
			Node<T>* temp = (curr->leftNode == nullptr) ? curr->rightNode : curr->leftNode;

			// no child
			if (temp == nullptr) {
				temp = curr;
				curr = nullptr;
			}
			else {
				*curr = *temp;
				free(temp);
			}
		}
		else {
			//both children, find succ
			Node<T>* temp= succ(curr);
			curr->value = temp->value;
			curr->rightNode = remove(curr->rightNode, temp->value);
		}
	}

	if (curr == nullptr)
		return curr;

	curr->updateHeight();

	int balance = Node<T>::getBalance(curr);
	//TODO to be continued 
}



template<typename T>
Node<T>* AVL<T>::leftRotate(Node<T>* curr){
	Node<T>* rightSonCurr = curr->rightNode;
	Node<T>* leftSonOfRightSonCurr = rightSonCurr->leftNode;
	
	rightSonCurr->leftNode = curr;
	curr->rightNode = leftSonOfRightSonCurr;

	curr->updateHeight();
	rightSonCurr->updateHeight();

	return rightSonCurr;
}

template<typename T>
Node<T>* AVL<T>::rightRotate(Node<T>* curr){
	Node<T>* leftSonCur = curr->leftNode;
	Node<T>* rightSonOfLeftSonCurr = curr->rightNode;

	leftSonCur->rightNode = curr;
	curr->leftNode = rightSonOfLeftSonCurr;

	curr->updateHeight();
	leftSonCur->updateHeight();

	return leftSonCur;
}

template<typename T>
inline void AVL<T>::insert(T value) {
	this->root = insert(this->root, value);
}
