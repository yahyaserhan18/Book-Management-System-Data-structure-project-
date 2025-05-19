/*
#pragma once
#include <iostream>
#include <string>

using namespace std;

template <class T>
class clsBinaryTree
{
public:
    class Node {
    public:
        T value;
        Node* left;
        Node* right;

        Node(T val) : value(val), left(NULL), right(NULL) {}
    };

protected:
    Node* _Root;

    void _inOrder(Node* node) {
        if (node == NULL) return;
        _inOrder(node->left);
        cout << node->value << " ";
        _inOrder(node->right);
    }

    void _preOrder(Node* node) {
        if (node == NULL) return;
        cout << node->value << " ";
        _preOrder(node->left);
        _preOrder(node->right);
    }

    void _postOrder(Node* node) {
        if (node == NULL) return;
        _postOrder(node->left);
        _postOrder(node->right);
        cout << node->value << " ";
    }

    void _clear(Node* node) {
        if (node == NULL) return;
        _clear(node->left);
        _clear(node->right);
        delete node;
    }

    Node* _deleteNode(Node* root, T value) {
        if (root == NULL) return root;

        if (value < root->value)
            root->left = _deleteNode(root->left, value);
        else if (value > root->value)
            root->right = _deleteNode(root->right, value);
        else {
            if (root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            Node* successorParent = root;
            Node* successor = root->right;
            while (successor->left != NULL) {
                successorParent = successor;
                successor = successor->left;
            }

            if (successorParent != root)
                successorParent->left = successor->right;
            else
                successorParent->right = successor->right;

            root->value = successor->value;
            delete successor;
        }
        return root;
    }

public:
    clsBinaryTree() {
        _Root = NULL;
    }

    bool isEmpty() {
        return _Root == NULL;
    }

    Node* getRoot() {
        return _Root;
    }

    void insert(T value) {
        Node* newNode = new Node(value);
        if (_Root == NULL) {
            _Root = newNode;
            return;
        }

        Node* current = _Root;
        Node* parent = NULL;

        while (current != NULL) {
            parent = current;
            if (value < current->value)
                current = current->left;
            else
                current = current->right;
        }

        if (value < parent->value)
            parent->left = newNode;
        else
            parent->right = newNode;
    }

    Node* find(T value) {
        Node* current = _Root;
        while (current != NULL) {
            if (current->value == value)
                return current;
            else if (value < current->value)
                current = current->left;
            else
                current = current->right;
        }
        return NULL;
    }

    void printInOrder() {
        cout << "InOrder: ";
        _inOrder(_Root);
        cout << endl;
    }

    void printPreOrder() {
        cout << "PreOrder: ";
        _preOrder(_Root);
        cout << endl;
    }

    void printPostOrder() {
        cout << "PostOrder: ";
        _postOrder(_Root);
        cout << endl;
    }

    void clear() {
        _clear(_Root);
        _Root = NULL;
    }

    void deleteValue(T value) {
        _Root = _deleteNode(_Root, value);
    }
};


*/

#pragma once
#include <iostream>
#include <functional>
using namespace std;

template <class T>
class clsBinaryTree {
public:
    class Node {
    public:
        T value;
        Node* left;
        Node* right;

        Node(T val) : value(val), left(NULL), right(NULL) {}
    };

protected:
    Node* _Root;

    void _inOrder(Node* node) {
        if (node == NULL) return;
        _inOrder(node->left);
        cout << node->value << " ";
        _inOrder(node->right);
    }

    void _preOrder(Node* node) {
        if (node == NULL) return;
        cout << node->value << " ";
        _preOrder(node->left);
        _preOrder(node->right);
    }

    void _postOrder(Node* node) {
        if (node == NULL) return;
        _postOrder(node->left);
        _postOrder(node->right);
        cout << node->value << " ";
    }

    void _clear(Node* node) {
        if (node == NULL) return;
        _clear(node->left);
        _clear(node->right);
        delete node;
    }

    Node* _deleteNode(Node* root, T value) {
        if (root == NULL) return root;

        if (value < root->value)
            root->left = _deleteNode(root->left, value);
        else if (value > root->value)
            root->right = _deleteNode(root->right, value);
        else {
            if (root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            Node* successorParent = root;
            Node* successor = root->right;
            while (successor->left != NULL) {
                successorParent = successor;
                successor = successor->left;
            }

            if (successorParent != root)
                successorParent->left = successor->right;
            else
                successorParent->right = successor->right;

            root->value = successor->value;
            delete successor;
        }
        return root;
    }

    void _inOrderWithCallback(Node* node, function<void(T)> callback) {
        if (node == NULL) return;
        _inOrderWithCallback(node->left, callback);
        callback(node->value);
        _inOrderWithCallback(node->right, callback);
    }

public:
    clsBinaryTree() {
        _Root = NULL;
    }

    bool isEmpty() {
        return _Root == NULL;
    }

    Node* getRoot() {
        return _Root;
    }

    void Insert(T value) {
        Node* newNode = new Node(value);
        if (_Root == NULL) {
            _Root = newNode;
            return;
        }

        Node* current = _Root;
        Node* parent = NULL;

        while (current != NULL) {
            parent = current;
            if (value < current->value)
                current = current->left;
            else
                current = current->right;
        }

        if (value < parent->value)
            parent->left = newNode;
        else
            parent->right = newNode;
    }

    Node* find(T value) {
        Node* current = _Root;
        while (current != NULL) {
            if (current->value == value)
                return current;
            else if (value < current->value)
                current = current->left;
            else
                current = current->right;
        }
        return NULL;
    }

    void printInOrder() {
        cout << "InOrder: ";
        _inOrder(_Root);
        cout << endl;
    }

    void printPreOrder() {
        cout << "PreOrder: ";
        _preOrder(_Root);
        cout << endl;
    }

    void printPostOrder() {
        cout << "PostOrder: ";
        _postOrder(_Root);
        cout << endl;
    }

    void clear() {
        _clear(_Root);
        _Root = NULL;
    }

    void deleteValue(T value) {
        _Root = _deleteNode(_Root, value);
    }

    void InOrderTraversal(function<void(T)> callback) {
        _inOrderWithCallback(_Root, callback);
    }
};