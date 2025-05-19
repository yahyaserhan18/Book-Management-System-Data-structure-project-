#pragma once
#include <iostream>
#include <string>

using namespace std;

template <class T>
class clsCircularLinkedList
{
public:
    class Node {
    public:
        T value;
        Node* next;
    };

protected:
    Node* _Last;
    int _Length;

public:
    clsCircularLinkedList() {
        _Last = NULL;
        _Length = 0;
    }

    bool isEmpty() {
        return _Length == 0;
    }

    int size() {
        return _Length;
    }

    void insertAtBeginning(T value) {
        Node* new_node = new Node();
        new_node->value = value;

        if (isEmpty()) {
            new_node->next = new_node;
            _Last = new_node;
        }
        else {
            new_node->next = _Last->next;
            _Last->next = new_node;
        }
        _Length++;
    }

    void insertAtEnd(T value) {
        Node* new_node = new Node();
        new_node->value = value;

        if (isEmpty()) {
            new_node->next = new_node;
            _Last = new_node;
        }
        else {
            new_node->next = _Last->next;
            _Last->next = new_node;
            _Last = new_node;
        }
        _Length++;
    }

 
    void print() {
        if (isEmpty()) {
            cout << "-> Is Empty :(\n";
            return;
        }

        Node* current = _Last->next;
        do {
            cout << current->value;
            current = current->next;
        } while (current != _Last->next);
        cout << "\n";
    }

    bool deleteFirst() {
        if (isEmpty()) return false;

        Node* first = _Last->next;
        if (_Last == first) {
            delete first;
            _Last = NULL;
        }
        else {
            _Last->next = first->next;
            delete first;
        }
        _Length--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;

        Node* current = _Last->next;
        if (_Last == current) {
            delete _Last;
            _Last = NULL;
        }
        else {
            while (current->next != _Last)
                current = current->next;

            current->next = _Last->next;
            delete _Last;
            _Last = current;
        }
        _Length--;
        return true;
    }

    void clear() {
        while (!isEmpty()) {
            deleteFirst();
        }
    }

    T FirstElement() {
        return isEmpty() ? T() : _Last->next->value;
    }

    T LastElement() {
        return isEmpty() ? T() : _Last->value;
    }

    Node* find(T value) {
        if (isEmpty()) return NULL;

        Node* current = _Last->next;
        do {
            if (current->value == value)
                return current;
            current = current->next;
        } while (current != _Last->next);

        return NULL;
    }

    Node* getNodeByIndex(int index) {
        if (index < 0 || index >= _Length) return NULL;

        Node* current = _Last->next;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current;
    }

    T getItemByIndex(int index) {
        Node* node = getNodeByIndex(index);
        return (node == NULL ? T() : node->value);
    }

    bool updateItem(int index, T newValue) {
        Node* node = getNodeByIndex(index);
        if (node != NULL) {
            node->value = newValue;
            return true;
        }
        return false;
    }

    bool insertAfter(int index, T value) {
        Node* node = getNodeByIndex(index);
        if (node == NULL) return false;

        Node* new_node = new Node();
        new_node->value = value;
        new_node->next = node->next;
        node->next = new_node;

        if (node == _Last)
            _Last = new_node;

        _Length++;
        return true;
    }

    bool deleteNode(Node* node) {
        if (isEmpty() || node == NULL) return false;

        Node* current = _Last->next;
        Node* prev = _Last;
        do {
            if (current == node) {
                if (current == _Last && current == _Last->next) {
                    delete current;
                    _Last = NULL;
                }
                else {
                    prev->next = current->next;
                    if (current == _Last)
                        _Last = prev;
                    delete current;
                }
                _Length--;
                return true;
            }
            prev = current;
            current = current->next;
        } while (current != _Last->next);

        return false;
    }
};
