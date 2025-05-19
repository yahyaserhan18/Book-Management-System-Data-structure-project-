#pragma once
#include <iostream>
#include <list>
#include <vector>
#include <utility>

using namespace std;

template <class K, class V>
class clsHashTable
{
private:
    static const int TABLE_SIZE = 10;
    vector<list<pair<K, V>>> table;

    int hashFunction(K key) {
        return hash<K>{}(key) % TABLE_SIZE;
    }


public:
    clsHashTable() {
        table.resize(TABLE_SIZE);
    }


    void insert(K key, const typename V::value_type& item) {
        int index = hashFunction(key);
        for (auto& element : table[index]) {
            if (element.first == key) {
                element.second.push_back(item); // listeye yeni unsur ekleme
                return;
            }
        }
        V newList = { item };
        table[index].push_back(make_pair(key, newList));
    }

    void insert(K key, const V& values) {
        int index = hashFunction(key);
        for (auto& element : table[index]) {
            if (element.first == key) {
                element.second.insert(element.second.end(), values.begin(), values.end());
                return;
            }
        }
        table[index].push_back(make_pair(key, values));
    }


    bool search(K key, V& value) {
        int index = hashFunction(key);
        for (auto& element : table[index]) {
            if (element.first == key) {
                value = element.second;
                return true;
            }
        }
        return false;
    }

    bool remove(K key) {
        int index = hashFunction(key);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->first == key) {
                table[index].erase(it);
                return true;
            }
        }
        return false;
    }

    void print() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << ": ";
            for (auto& element : table[i]) {
                cout << "(" << element.first << ", " << element.second << ") -> ";
            }
            cout << "NULL\n";
        }
    }
    void printNonEmpty() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (!table[i].empty()) {
                cout << i << ": ";
                for (auto& element : table[i]) {
                    cout << "(" << element.first << ", " << element.second << ") -> ";
                }
                cout << "NULL\n";
            }
        }
    }


    void clear() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            table[i].clear();
        }
    }

    //
    void getBucket(int index, vector<pair<K, V>>& out) {
        if (index >= 0 && index < TABLE_SIZE) {
            out.clear();
            for (auto& element : table[index]) {
                out.push_back(element);
            }
        }
    }

};