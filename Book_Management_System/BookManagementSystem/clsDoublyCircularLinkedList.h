#pragma once
#include <iostream>
#include <string>

using namespace std;

template <class T>
class clsDoublyCircularLinkedList
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
    int _Length;

public:

    clsDoublyCircularLinkedList() {
        _Front = NULL;
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
            new_node->next = new_node->prev = new_node;
            _Front = new_node;
        }
        else {
            Node* last = _Front->prev;
            new_node->next = _Front;
            new_node->prev = last;
            last->next = new_node;
            _Front->prev = new_node;
            _Front = new_node;
        }
        _Length++;
    }

    void insertAtEnd(T value) {
        if (isEmpty()) {
            insertAtBeginning(value);
        }
        else {
            Node* new_node = new Node();
            Node* last = _Front->prev;
            new_node->value = value;
            new_node->next = _Front;
            new_node->prev = last;
            last->next = new_node;
            _Front->prev = new_node;
            _Length++;
        }
    }

    Node* Find(T value) {
        if (isEmpty()) return NULL;

        Node* current = _Front;
        do {
            if (current->value == value)
                return current;
            current = current->next;
        } while (current != _Front);

        return NULL;
    }

    bool insertAfter(Node* insertAfterNode, T value) {
        if (insertAfterNode == NULL) return false;

        Node* new_node = new Node();
        new_node->value = value;
        new_node->next = insertAfterNode->next;
        new_node->prev = insertAfterNode;

        insertAfterNode->next->prev = new_node;
        insertAfterNode->next = new_node;

        _Length++;
        return true;
    }

    bool deleteFirst() {
        if (isEmpty()) return false;

        if (_Length == 1) {
            delete _Front;
            _Front = NULL;
        }
        else {
            Node* last = _Front->prev;
            Node* temp = _Front;
            _Front = _Front->next;
            _Front->prev = last;
            last->next = _Front;
            delete temp;
        }
        _Length--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;

        if (_Length == 1) {
            delete _Front;
            _Front = NULL;
        }
        else {
            Node* last = _Front->prev;
            Node* new_last = last->prev;
            new_last->next = _Front;
            _Front->prev = new_last;
            delete last;
        }
        _Length--;
        return true;
    }

    bool deleteNode(Node* node) {
        if (isEmpty() || node == NULL) return false;

        if (_Length == 1 && node == _Front) {
            delete _Front;
            _Front = NULL;
        }
        else {
            if (node == _Front)
                _Front = _Front->next;
            node->prev->next = node->next;
            node->next->prev = node->prev;
            delete node;
        }
        _Length--;
        return true;
    }

    void print() {
        if (isEmpty()) {
            cout << "\n[ ]\n";
            return;
        }

        Node* current = _Front;
        cout << "\n[ ";
        do {
            cout << current->value << " ";
            current = current->next;
        } while (current != _Front);
        cout << "]\n";
    }

    void clear() {
        while (!isEmpty()) {
            deleteFirst();
        }
    }

    void reverse() {
        if (isEmpty() || _Length == 1) return;

        Node* current = _Front;
        Node* temp = NULL;
        do {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        } while (current != _Front);

        _Front = _Front->prev;
    }

    T FirstElement() {
        return _Front->value;
    }

    T LastElement() {
        return _Front->prev->value;
    }

    Node* getNodeByIndex(int index) {
        if (index < 0 || index >= _Length) return NULL;

        Node* current = _Front;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current;
    }

    T getItemByIndex(int index) {
        Node* itemNode = getNodeByIndex(index);
        return (itemNode == NULL ? T() : itemNode->value);
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
        Node* currNode = getNodeByIndex(index);
        if (currNode == NULL)
            return false;
        return insertAfter(currNode, value);
    }
};
