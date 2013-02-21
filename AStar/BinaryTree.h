#pragma once

#include <iostream>

template <class DataType> class Node;
template <class DataType> class BinaryTree;

template <class DataType>
class Node
{
	public:
		template <class DataType> friend class BinaryTree;
		DataType Data;
		Node* Left;
		Node* Right;
		Node* Parent;

		~Node();

	private:
		Node(DataType data, Node<DataType>* parent);
};

template <class DataType>
class BinaryTree
{
	public:
		BinaryTree();
		~BinaryTree();

		void Insert(DataType data);
		void Remove(DataType remove);
		bool Contains(DataType data) const;
		Node<DataType>* Search(DataType searchData) const;
		void Clear();
	private:
		void Insert(DataType data, Node<DataType>* left);
		Node<DataType>* Search(DataType searchData, Node<DataType>* currentNode) const;
		Node<DataType>* _root;
		int _count;
};

// NODE FUNCTIONS
template <class DataType>
Node<DataType>::Node(DataType data, Node<DataType>* parent)
{
	Data = data;
	Parent = parent;
	Left = NULL;
	Right = NULL;
}

template <class DataType>
Node<DataType>::~Node()
{
	if(Left != NULL)
		delete Left;
	if(Right != NULL)
		delete Right;
}

//BINARYTREE FUNCTIONS
template <class DataType>
BinaryTree<DataType>::BinaryTree()
{
	_root = NULL;
	_count = 0;
}

template <class DataType>
BinaryTree<DataType>::~BinaryTree()
{
	if(_root != 0)
		delete _root;
}

template <class DataType>
void BinaryTree<DataType>::Insert(DataType data)
{
	if(_count == 0)
		_root = new Node<DataType>(data, _root);
	else
	{
		if(data < _root->Data)
		{
			if(_root->Left != NULL)
				Insert(data, _root->Left);
			else
				_root->Left = new Node<DataType>(data, _root);
		}
		if(data > _root->Data)
		{
			if(_root->Right != NULL)
				Insert(data, _root->Right);
			else
				_root->Right = new Node<DataType>(data, _root);
		}
	}
	_count++;
}

template <class DataType>
void BinaryTree<DataType>::Insert(DataType data, Node<DataType>* leaf)
{
		if(data < leaf->Data)
		{
			if(_root->Left != NULL)
				Insert(data, leaf->Left);
			else
				leaf->Left = new Node<DataType>(data, leaf);
		}
		else if(data > leaf->Data)
		{
			if(leaf->Right != NULL)
				Insert(data, leaf->Right);
			else
				leaf->Right = new Node<DataType>(data, leaf);
		}
}

template <class DataType>
Node<DataType>* BinaryTree<DataType>::Search(DataType searchData) const
{
	if(_root != NULL)
	{
		Node<DataType>* currentNode = _root;
	
		if(searchData == currentNode->Data)
			return currentNode;
		else
			return Search(searchData, currentNode);
	}
}

template <class DataType>
Node<DataType>* BinaryTree<DataType>::Search(DataType searchData, Node<DataType>* currentNode) const
{
	if(searchData == currentNode->Data)
		return currentNode;
	else
	{
		if(searchData < currentNode->Data && currentNode->Left != NULL)
			return Search(searchData, currentNode->Left);
		if(searchData > currentNode->Data && currentNode->Right != NULL)
			return Search(searchData, currentNode->Right);
		if(currentNode->Left == NULL && currentNode->Right == NULL)
			return NULL;
	}
}

template <class DataType>
void BinaryTree<DataType>::Clear()
{
	delete _root;
	_root = NULL;
}

template <class DataType>
void BinaryTree<DataType>::Remove(DataType data)
{
	if((*this).Contains(data))
	{
		Node<DataType>* nodeToRemove = Search(data);

		// If node is root
		if(nodeToRemove == _root)
		{

		}
		
		// If node is leaf
		if(nodeToRemove->Left == NULL && nodeToRemove->Right == NULL)
		{
			if(nodeToRemove == nodeToRemove->Parent->Left)
				nodeToRemove->Parent->Left = NULL;
			else
				nodeToRemove->Parent->Right = NULL;
		}

		// If node has right child and no left child
		if(nodeToRemove->Left == NULL && nodeToRemove->Right != NULL)
			nodeToRemove->Parent->Right = nodeToRemove->Right;

		// If node has left child and no right child
		if(nodeToRemove->Left != NULL && nodeToRemove->Right == NULL)
			nodeToRemove->Parent->Left = nodeToRemove->Left;

		//nodeToRemove->~Node();
	}
}

template <class DataType>
bool BinaryTree<DataType>::Contains(DataType data) const
{
	if(_root != NULL)
	{
		if(Search(data) != NULL)
			return true;
		else
			return false;
	}
}