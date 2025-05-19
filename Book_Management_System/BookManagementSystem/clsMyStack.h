#pragma once
#include <iostream>
#include "clsMyQueue.h";

template <class T>
class clsMyStack : public clsMyQueue <T>
{

public:

	void push(T value) {
		clsMyQueue<T>::_QueueList.insertAtBeginning(value);
		//stack.insertAtBeginning(value);
	}

	T top() {
		return clsMyQueue<T>::front();
	}
	T bottom() {
		return clsMyQueue<T>::back();

	}


};

