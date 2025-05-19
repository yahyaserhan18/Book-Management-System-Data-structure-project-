#pragma once
#include <iostream>
#include "clsDblLinkedList.h";

using namespace std;

template <class T>
class clsMyQueue
{
protected:
	clsDblLinkedList <T> _QueueList;
public:
	void push(T value) {
		_QueueList.insertAtEnd(value);
	}
	void pop() {
		_QueueList.deleteFirst();
	}
	void print() {
		_QueueList.print();
	}
	int size() {
		return _QueueList.size();
	}
	T front() {
		return _QueueList.FirstElement();
	}
	T back() {
		return _QueueList.LastElement();
	}

	/// /////////

	T getItem(int index) {
		return _QueueList.getItemByIndex(index);
	}

	void reverse() {
		_QueueList.reverse();
	}

	void updateItem(int index, T newValue) {
		_QueueList.updateItem(index, newValue);
	}
	void insertAfter(int index, T value) {
		_QueueList.insertAfter(index, value);
	}

	void insertAtFront(T value) {
		_QueueList.insertAtBeginning(value);
	}

	void insertAtBack(T value) {
		_QueueList.insertAtEnd(value);
	}

	void clear() {
		_QueueList.clear();
	}

};

