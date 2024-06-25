#pragma once
#include<iostream>
using namespace std;
template<class T> class clsDblLinkedList
{
protected:
	int _Size=0;


public:
	 class Node
	{
	public:
		T _value;
		Node* next;
		Node* prev;
	};

	Node* head=NULL;

	
	
	void InsertAtBeginning(T value)
	{
		Node* NewNode = new Node();
		NewNode->_value = value;
		NewNode->prev = NULL;
		NewNode->next = head;

		if (head!=NULL)
		{
			head->prev = NewNode;
		}
		head = NewNode;
		_Size++;
	}

	void PrintList()
	{
		Node* temp = head;
		
		while (temp!=NULL)
		{
			cout << temp->_value << " ";
			temp = temp->next;
		}
		cout << "\n";
		delete temp;
	}

	Node* Find(T value)
	{
		Node* current = head;
		while (current!=NULL)
		{
			if (current->_value == value)
				return current;

			current = current->next;

		}
		return NULL;
	}

	void InsertAfter(Node* current, T value)
	{
		Node* NewNode = new Node();

		NewNode->_value = value;
		NewNode->next = current->next;
		NewNode->prev = current;
		if (current->next != NULL)
		{
			current->next->prev = NewNode;
		}
		current->next = NewNode;
		_Size++;
	}
	void InsertAtEnd(T value)
	{
		Node* NewNode = new Node();

		NewNode->_value = value;
		NewNode->next = NULL;
		if (head == NULL)
		{
			NewNode->prev = NULL;
			head = NewNode;
		}
		else
		{
			Node* current = head;
			while (current->next!=NULL)
			{
				current = current->next;
			}
			current->next = NewNode;
			NewNode->prev = current;
		}
		_Size++;
	}

	void DeleteNode(Node*& NodeToDelete)
	{
		if (head == NULL || NodeToDelete == NULL)
		{
			return;
		}
		if (head == NodeToDelete)
		{
			head = NodeToDelete->next;
		}
		if (NodeToDelete->next != NULL)
		{
			NodeToDelete->next->prev = NodeToDelete->prev;
		}

		if (NodeToDelete->prev != NULL)
		{
			NodeToDelete->prev->next = NodeToDelete->next;
		}

		delete NodeToDelete;
		_Size--;

	}
	void DeleteFirstNode()
	{
		if (head == NULL)
		{
			return;
		}
		Node* temp = head;
		head = head->next;
		if (head != NULL)
		{
			head->prev = NULL;
		}
		delete(temp);

		_Size--;
	}
	void DeleteLastNode()
	{
		if (head == NULL)
		{
			return;
		}
		if (head->next == NULL)
		{
			delete head;
			head = NULL;
			return;
		}
		Node* current = head;
		while (current->next->next != NULL)
		{
			current = current->next;
		}
		Node* temp = current->next;
		current->next = NULL;
		delete(temp);
		_Size--;
	}

	int Size()
	{
		return _Size;
	}
	bool ISEmpty()
	{
		return(_Size == 0 ? true : false);
	}

	void Clear()
	{
		while (_Size>0)
		{
			DeleteFirstNode();
		}
		
	}

	void Reverse()
	{
		Node* current = head;
		Node* temp = nullptr;

		while (current!=nullptr)
		{
			temp = current->prev;
			current->prev = current->next;
			current->next = temp;
			current = current->prev;
		}
		if (temp != nullptr)
		{
			head = temp->prev;
		}
	}

	Node* GetNode(int Index)
	{
		int Counter = 0;
		if (Index > _Size - 1 || Index < 0)
			return NULL;
		Node* current = head;
		while (current!=NULL&&(current->next!=NULL))
		{
			if (Counter == Index)
				break;
			current = current->next;
			Counter++;
		}
		return current;
	}

	T GetItem(int Item)
	{
		Node* Currrent = GetNode(Item);
		if (Currrent == NULL)
			return NULL;
		else
		return Currrent->_value;
	}

	bool UpdateItem(int Index, T NewValue)
	{
		Node* ItemNode = GetNode(Index);
		if (ItemNode != NULL)
		{
			ItemNode->_value = NewValue;
			return true;
		}
		return false;
			
	}

	bool InsertAfter(int Index, T NewValue)
	{
		Node* ItemNode = GetNode(Index);
		if (ItemNode != NULL)
		{
			InsertAfter(ItemNode, NewValue);
			return true;
		}
		else
			return false;
		
	}
};

