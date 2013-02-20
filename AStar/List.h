/*   /--------------------------------------------------------------------------------------------------------------------------------------------------\
	|																-	LIST.H	-																		 |
	| Program: AStar.exe																																 |
	| Author: Henri Keeble (KEE09195812)																												 |
	| Description: This file contains the declarations and definitions for a simple templated Linked List class, along with a declaration and			 |
	| definitions of a class for each individual node.																									 |
	 \--------------------------------------------------------------------------------------------------------------------------------------------------/  */
#pragma once
#include <iostream>

// NODE CLASS
template <class DataType>
class Node
{
	public:
		template <class DataType> friend class List;
		~Node<DataType>() { delete _child; }
		DataType GetData() const { return _data; }
		Node<DataType>* GetChild() const { return _child; }
		void SetChild(Node* child) { _child = child; }
	private:
		Node<DataType>(DataType nodeData, Node* child) { _child = child; _data = nodeData; }
		DataType _data;
		Node<DataType>* _child;
};

// LIST CLASS
template <class DataType>
class List
{
	public:
		List(void);
		~List(void);
		int GetCount() const;
		void Add(DataType data);
		void Remove(DataType data);
		int FirstIndexOf(DataType data) const;
		bool Contains(DataType data) const;
		void Print() const;

		DataType operator()(int param) const;

	private:
		Node<DataType>* head;
		Node<DataType>* tail;
		Node<DataType>* operator()(int param);
		int count;
};

// LIST FUNCTIONS
// List Constructor
template <class DataType>
List<DataType>::List(void)
{
	count = 0;
}

// List Destructor
template <class DataType>
List<DataType>::~List(void)
{
	if(count != 0)
		delete head;
}

// Get Count Function
template <class DataType>
int List<DataType>::GetCount() const
{
	return count;
}

// Add Function
template <class DataType>
void List<DataType>::Add(DataType data)
{
	if(count == 0)
	{
		head = new Node<DataType>(data, NULL);
		tail = head;
	}
	else
	{
		Node<DataType>* newNode = new Node<DataType>(data, NULL);
		tail->SetChild(newNode);
		tail = newNode;
	}
	count++;
}

// Remove Function
template <class DataType>
void List<DataType>::Remove(DataType data)
{
	if((*this).Contains(data))
	{
		int i = FirstIndexOf(data);
		Node<DataType>* ParentNode = (*this)(i-1);
		Node<DataType>* NodeToRemove = (*this)(i);
		
		if(tail == NodeToRemove)
		{
			tail = ParentNode;
			ParentNode->SetChild(NULL);
		}
		else
			ParentNode->SetChild(NodeToRemove->GetChild());
		count--;
	}
}

// Search Function
template <class DataType>
int List<DataType>::FirstIndexOf(DataType data) const
{
	if(Contains(data))
	{
		Node<DataType>* searchNode = head;
		int i;
		for(i = 0; i < count; i++)
		{
			if(searchNode->GetData() == data)
				break;
			searchNode = searchNode->GetChild();
		}
		return i;
	}
	else
		return NULL;
}

// Contains Function
template <class DataType>
bool List<DataType>::Contains(DataType data) const
{
	bool contains = false;

	Node<DataType>* searchNode = head;
	for(int i = 0; i < count; i++)
	{
		if(searchNode->GetData() == data)
		{
			contains = true;
			break;
		}
		searchNode = searchNode->GetChild();
	}

	return contains;
}

// Print Function
template <class DataType>
void List<DataType>::Print() const
{
	Node<DataType>* currentNode = head;
	for(int i = 0; i < count; i++)
	{
		cout << currentNode->GetData() << endl;
		currentNode = currentNode->GetChild();
	}
}

// Operator Overloads
// Public () Operator
template <class DataType>
DataType List<DataType>::operator()(int param) const
{
	Node<DataType>* currentNode = head;
	for(int i = 0; i < param; i++)
		currentNode = currentNode->GetChild();
	return currentNode->GetData();
}

// Private () Operator
template <class DataType>
Node<DataType>* List<DataType>::operator()(int param)
{
		Node<DataType>* currentNode = head;
	for(int i = 0; i < param; i++)
		currentNode = currentNode->GetChild();
	return currentNode;
}