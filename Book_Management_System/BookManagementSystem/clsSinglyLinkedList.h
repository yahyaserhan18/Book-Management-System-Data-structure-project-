#pragma once
#include <iostream>
#include <string>
using namespace std;

template <class T>
class clsSinglyLinkedList
{
public:
    class Node {
    public:
        T value;
        Node* next;
    };

protected:
    Node* _Head;
    int _Length;

public:
    clsSinglyLinkedList() {
        _Head = nullptr;
        _Length = 0;
    }

    bool isEmpty() {
        return _Head == nullptr;
    }

    int size() {
        return _Length;
    }

    void insertAtBeginning(T value) {
        Node* new_node = new Node();
        new_node->value = value;
        new_node->next = _Head;
        _Head = new_node;
        _Length++;
    }

    void insertAtEnd(T value) {
        Node* new_node = new Node();
        new_node->value = value;
        new_node->next = nullptr;

        if (isEmpty()) {
            _Head = new_node;
        }
        else {
            Node* current = _Head;
            while (current->next != nullptr)
                current = current->next;

            current->next = new_node;
        }
        _Length++;
    }

    void print() {
        if (isEmpty()) {
            cout << "[ ]\n";
            return;
        }

        Node* current = _Head;
        cout << "[ ";
        while (current != nullptr) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << "]\n";
    }

    bool deleteFirst() {
        if (isEmpty()) return false;

        Node* temp = _Head;
        _Head = _Head->next;
        delete temp;
        _Length--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;

        if (_Head->next == nullptr) {
            delete _Head;
            _Head = nullptr;
        }
        else {
            Node* current = _Head;
            Node* prev = nullptr;

            while (current->next != nullptr) {
                prev = current;
                current = current->next;
            }

            prev->next = nullptr;
            delete current;
        }

        _Length--;
        return true;
    }

    void clear() {
        while (!isEmpty()) {
            deleteFirst();
        }
    }

    T firstElement() {
        return isEmpty() ? T() : _Head->value;
    }

    T lastElement() {
        if (isEmpty()) return T();

        Node* current = _Head;
        while (current->next != nullptr)
            current = current->next;

        return current->value;
    }

    Node* find(T value) {
        Node* current = _Head;
        while (current != nullptr) {
            if (current->value == value)
                return current;
            current = current->next;
        }
        return nullptr;
    }

    Node* getNodeByIndex(int index) {
        if (index < 0 || index >= _Length) return nullptr;

        Node* current = _Head;
        for (int i = 0; i < index; i++)
            current = current->next;

        return current;
    }

    T getItemByIndex(int index) {
        Node* node = getNodeByIndex(index);
        return (node == nullptr ? T() : node->value);
    }

    bool updateItem(int index, T newValue) {
        Node* node = getNodeByIndex(index);
        if (node != nullptr) {
            node->value = newValue;
            return true;
        }
        return false;
    }

    bool insertAfter(int index, T value) {
        Node* node = getNodeByIndex(index);
        if (node == nullptr) return false;

        Node* new_node = new Node();
        new_node->value = value;
        new_node->next = node->next;
        node->next = new_node;

        _Length++;
        return true;
    }

    bool deleteNode(Node* node) {
        if (isEmpty() || node == nullptr) return false;

        if (node == _Head) {
            return deleteFirst();
        }

        Node* current = _Head;
        Node* prev = nullptr;

        while (current != nullptr && current != node) {
            prev = current;
            current = current->next;
        }

        if (current == nullptr) return false;

        prev->next = current->next;
        delete current;
        _Length--;
        return true;
    }
};
