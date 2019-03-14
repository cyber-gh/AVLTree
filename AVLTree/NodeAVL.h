#pragma once
#include "Node.h"
template<typename T>
class NodeAVL :
	public Node<T>
{
private:
	int height;
public:
	NodeAVL() : Node() {
		height = -1;
	}
	NodeAVL(T value) :Node(T) {
		height = -1;
	}
	~NodeAVL();
};

