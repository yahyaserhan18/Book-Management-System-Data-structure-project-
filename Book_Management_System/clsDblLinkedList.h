#pragma once
#include <iostream>
#include <string>

using namespace std;

template <class T>
class clsDblLinkedList
{
public:
	class Node {
	public:
		T value;
		Node* next;
		Node* prev;
	};

protected:
	Node* _Front;
	Node* _Back;
	Node* _Curr;
	int _Length;

public:

	clsDblLinkedList() {
		_Front = _Back = _Curr = NULL;
		_Length = 0;
	}
	
	bool isEmpty(){
		return _Length == 0;
	}
	int size() {
		return _Length;
	}

	void insertAtBeginning(T value) {
		Node* new_node = new Node();
		new_node->value = value;
		new_node->prev = NULL;
		new_node->next = NULL;
		if (isEmpty())
			_Front = _Back = new_node;
		else {
			new_node->next = _Front;
			_Front->prev = new_node;
			_Front = new_node;
		}
			_Length++;
		
	}
	void insertAtEnd(T value) {
		Node* new_node = new Node();
		new_node->value = value;
		new_node->prev = NULL;
		new_node->next = NULL;
		if (isEmpty())
			_Front = _Back = new_node;
		else {
			new_node->prev = _Back;
			_Back->next = new_node;
			_Back = new_node;
		}
		_Length++;
	}
	Node* Find(T value) {
		if (value == _Back->value)
			return _Back;

		_Curr = _Front;

		while (_Curr->next != NULL) {
			if (_Curr->value == value)
				return _Curr;
			_Curr = _Curr->next;
		}

		return NULL;
	}

	bool insertAfter(Node* insertAfterNode, T value) {
		if (insertAfterNode == NULL)
			return 0;
		if (insertAfterNode->value == _Back->value)
		{
			insertAtEnd(value);
			return 1;
		}

		Node* new_node = new Node();
		new_node->value = value;
		new_node->prev = insertAfterNode;
		new_node->next = insertAfterNode->next;

		insertAfterNode->next->prev = new_node;
		insertAfterNode->next = new_node;

		_Length++;
		return 1;
	}


	bool deleteFirst() {
		if (isEmpty())return 0;
		
		Node* temp = _Front;
		if (_Length == 1) {
			_Back = _Front = NULL;
		}
		else
		{
			_Front = _Front->next;
			_Front->prev = NULL;
		}
		delete temp;
		_Length--;
		return 1;
	}
	bool deleteLast() {
		if (isEmpty())return 0;

		Node* temp = _Back;
		if (_Length == 1) {
			_Back = _Front = NULL;
		}
		else
		{
			_Back = _Back->prev;
			_Back->next = NULL;
		}
		delete temp;
		_Length--;
		return 1;
	}

	bool deleteNode(Node* node) {
		if (isEmpty() || node == NULL)return 0;

		if (node == _Front) {
			deleteFirst();
			return 1;
		}
		if (node == _Back) {
			deleteLast();
			return 1;
		}

		node->prev->next = node->next;
		node->next->prev = node->prev;
		delete node;
		_Length--;
		return 1;
	}


	void print() {
		_Curr = _Front;

		cout << "\n[ ";
		while (_Curr != NULL) {
			cout << _Curr->value << " ";
			_Curr = _Curr->next;
		}cout << "]\n";

	}

	void clear() {
		
		while (_Length > 0) {
			deleteFirst();
		}
		
		//my way :
		/*
		while (_Front!=NULL) {
			_Curr = _Front;
			_Front = _Front->next;
			delete _Curr;
		}
		_Back = NULL;
		_Curr = NULL;
		_Length = 0;
		
		*/
	}

	void reverse() {
		if (_Length == 1 || _Length == 0)
			return;

		_Curr = _Front;
		Node* temp = nullptr;
		_Back = _Front;
		while (_Curr != NULL) {
			temp = _Curr->prev;
			_Curr->prev = _Curr->next;
			_Curr->next = temp;

			if (_Curr->prev == NULL)
				_Front = _Curr;
			_Curr = _Curr->prev;

		}
		
		//my Way :
		/*
				Node* nextNode = _Front->next;
		_Curr = _Front;

		for (int i = 1; i <= _Length; i++) {
			if (i == 1)
				_Back = _Front;

			_Curr->next = _Curr->prev;
			_Curr->prev = nextNode;

			if (_Length > i) {
				_Curr = nextNode;
				nextNode = nextNode->next;
		}
		}
		_Front = _Curr;
		
		*/
	}

	T FirstElement() {
		return _Front->value;
	}
	T LastElement() {
		return _Back->value;
	}

	Node* getNodeByIndex(int index) {
		if (index<0  || index >= _Length)
			return NULL;
		if (index == _Length)
			return _Back;

		_Curr = _Front;
		for (int i = 0; i < _Length; i++) {
			if (i == index)
				return _Curr;
			_Curr = _Curr->next;
		}
		return NULL;

	}

	T getItemByIndex(int index) {
		Node* itemNode = getNodeByIndex(index);

		return (itemNode == NULL ? NULL : itemNode->value);
	}

	bool updateItem(int index , T newValue) {
		Node* node = getNodeByIndex(index);
		
		if (getNodeByIndex(index) != NULL)
		{
			node->value = newValue;
			return true;
		}
		else return false;
	}

	bool insertAfter(int index, T value) {
		Node* currNode = getNodeByIndex(index);
		if (currNode == NULL)
			return 0;
		return insertAfter(currNode, value);
		
	}
};

