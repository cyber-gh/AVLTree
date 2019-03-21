#include "BST.h"


template<typename T>
Node<T>* BST<T>::insert(Node<T>* curr, T value){
	if (curr == nullptr) return (new Node<T>(value));

	if (value < curr->value)
		curr->leftNode = insert(curr->leftNode, value);
	else if (value > curr->value)
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
Node<T>* BST<T>::search(Node<T>* curr, T value){
	if (curr == nullptr) return;
	if (curr->value == value) return curr;
	if (curr->value < value)
		return search(curr->rightNode, value);
	return search(curr->leftNode, value);
}

template<typename T>
void BST<T>::traverseValue(Node<T>* curr, std::function<void(T)> it){
	if (curr == nullptr) return;
	it(curr->value);
	traverseValue(curr->leftNode, it);
	traverseValue(curr->rightNode, it);
	
}



template<typename T>
BST<T>::BST() {
	this->root = nullptr;
	std::cout << "isntance without value" << std::endl;

}

template<typename T>
BST<T>::BST(T value){
	root = new Node<T>(value);
	std::cout << "isntance with value" << std::endl;
}



template<typename T>
BST<T>::~BST(){
	if (root == nullptr) return;
	std::stack<Node<T>* > st;
	st.push(root);
	while (!st.empty()) {
		Node<T>* curr = st.top();

		st.pop();
		if (curr->rightNode != nullptr) st.push(curr->rightNode);
		if (curr->leftNode != nullptr) st.push(curr->leftNode);

		free(curr);
		curr = nullptr;
	}
	root = nullptr;
	
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
bool BST<T>::search(T value){
	return (search(root, value) != nullptr);
}

template<typename T>
T BST<T>::maxVal(){
	Node<T>* it = root;
	while (it->rightNode != nullptr)
		it = it->rightNode;
	return it->value;
}

template<typename T>
void BST<T>::preorder(){
	preorder(root);
}

template<typename T>
void BST<T>::inorder(){
	//std::cout << "called bst inroder";
	inorder(root);
}

template<typename T>
void BST<T>::postorder(){
	postorder(root);
}

template<typename T>
void BST<T>::postorder(Node<T>* curr){
	if (curr == nullptr) return;

	
	postorder(curr->leftNode);
	postorder(curr->rightNode);
	std::cout << curr->value << " ";
}



