#include "DoublyLinkedList.hpp"
#include <iostream>
#include <string>
using namespace std;

DoublyLinkedList::Node::Node(DataType data)
{
	next = NULL;
	prev = NULL;
	value = data;
}

DoublyLinkedList::DoublyLinkedList()
{
	head_ = NULL;
	tail_ = NULL;
	size_ = 0;
}

DoublyLinkedList::~DoublyLinkedList()
{
	if(head_ == NULL)
		return;
	Node* killer = head_;
	Node* killer2 = head_ -> next;
	while(killer != NULL)
	{
		killer2 = killer -> next;
		delete killer;
		killer = killer2;
	}
}

bool DoublyLinkedList::empty() const
{
	return size_ == 0;
}

unsigned int DoublyLinkedList::size() const
{
	return size_;
}

unsigned int DoublyLinkedList::capacity() const
{
	return CAPACITY;
}

void DoublyLinkedList::print() const
{
	if(head_ == NULL)
		cout << "The list is empty." << endl;
	else
	{
		Node* printnode = head_;
		while(printnode != NULL)
		{
			cout << printnode -> value << endl;
			printnode = printnode -> next;
		}
	}
}

bool DoublyLinkedList::insert_front(DataType value)
{
	if(size_ == CAPACITY)
		return false;
	if(head_ == NULL)
	{
		head_ = new Node(value);
		tail_ = head_;
		size_++;
		return true;
	}
	else
	{
		Node* newnode = new Node(value);
		head_ -> prev = newnode;
		newnode -> next = head_;
		head_ = newnode;
		size_++;
		return true;
	}
}

bool DoublyLinkedList::remove_front()
{
	if(head_ == NULL)
		return false;
	else if(size_ == 1)
	{
		size_--;
		delete head_;
		head_ = NULL;
		tail_ = NULL;
		return true;
	}
	else
	{
		Node* deleteme = head_;
		head_ = head_ -> next;
		head_ -> prev = NULL;
		size_--;
		delete deleteme;
		return true;
	}
}

bool DoublyLinkedList::insert_back(DataType value)
{
	if(size_ == CAPACITY)
		return false;
	if(tail_ == NULL)
	{
		head_ = new Node(value);
		tail_ = head_;
		size_++;
		return true;
	}
	else
	{
		Node* newnode = new Node(value);
		newnode -> prev = tail_;
		tail_ -> next = newnode;
		tail_ = newnode;
		size_++;
		return true;
	}
}

bool DoublyLinkedList::remove_back()
{
	if(tail_ == NULL)
		return false;
	else if(size_ == 1)
	{
		delete head_;
		head_ = tail_ = NULL;
		size_--;
		return true;
	}
	else
	{
		size_--;
		tail_ = tail_ -> prev;
		delete tail_ -> next;
		tail_ -> next = NULL;
		return true;
	}
}

bool DoublyLinkedList::insert(DataType value, unsigned int index)
{
	if(size_ == CAPACITY)
		return false;
	else if(size_ - 1 < index)
	{
		size_++;
		Node* newnode = new Node(value);
		Node* traveller = head_;
		for(unsigned i = 0; i < index; i++)
			traveller = traveller -> next;
		traveller -> next -> prev = newnode;
		traveller -> prev -> next = newnode;
		newnode -> next = traveller -> next;
		newnode -> prev = traveller -> prev;
		return true;
	}
	else
		return insert_back(value);
}

bool DoublyLinkedList::remove(unsigned int index)
{
	if(head_ == NULL)
		return false;
	else if(index > size_)
		return remove_back();
	else
	{
		Node* remove = head_;
		size_--;
		for(unsigned i = 0; i < index; i++)
			remove = remove -> next;
		remove -> prev -> next = remove -> next;
		remove -> next -> prev = remove -> prev;
		delete remove;
		return true;
	}
}

unsigned int DoublyLinkedList::search(DataType value) const
{
	if(head_ == NULL)
		return size_;
	else
	{
		Node* searcher = head_;
		unsigned index = 0;
		while(searcher -> value != value)
		{
			index++;
			if(index >= size_)
				return size_;
			searcher = searcher -> next;
		}
		return index;
	}
}

DoublyLinkedList::DataType DoublyLinkedList::select(unsigned int index) const
{
	if(head_ == NULL)
		return 0;
	else if(index > size_ - 1)
		return tail_ -> value;
	else
	{
		Node* chooser = head_;
		for(unsigned i = 0; i < index; i++)
			chooser = chooser -> next;
		return chooser -> value;
	}
}

bool DoublyLinkedList::replace(unsigned int index, DataType value)
{
	if(head_ == NULL)
		return false;
	else if(index > size_)
		return false;
	else
	{
		getNode(index) -> value = value;
		return true;
	}
}

DoublyLinkedList::Node* DoublyLinkedList::getNode(unsigned int index) const
{
	if(head_ == NULL)
	{
		Node* voidNode = new Node(0);
		return voidNode;
	}
	else if(index > size_)
	{
		Node* voidNode = new Node(0);
		return voidNode;
	}
	else
	{
		Node* getter = head_;
		for(unsigned i = 0; i < index; i++)
			getter = getter -> next;
		return getter;
	}
}

bool DoublyLinkedList::full() const
{
	return size_ == CAPACITY;
}
