
#pragma once
#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "clsDoublyCircularLinkedList.h"
#include "global.h"

using namespace std;

class clsBook {
public:
    int ID;
    string Name;
    string Author;
    string Category;
    int PublishYear;
    int PageCount;
    string DamageNote;
    string Timestamp;
    clsDoublyCircularLinkedList<string> Comments;
    float Rating; // average rating
    bool isReaded;

    bool IsLocalPublisher;
    global::BookLanguages Language;


    // İki kitabı karşılaştırmanın tanımı
    bool operator==(const clsBook& other) const {
        return ID == other.ID; 
    }

    clsBook() {

    }
    clsBook(int id, string name, string author, string category,
        int publishYear, int pageCount,bool isLocalPublisher , global::BookLanguages language)
    {
        this->ID = id;
        this->Name = name;
        this->Author = author;
        this->Category = category;
        this->PublishYear = publishYear;
        this->PageCount = pageCount;
        this->DamageNote = "";
        this->Rating = 0.0f;
        this->IsLocalPublisher = isLocalPublisher;
        this->Language = language;

        // create timestamp
        time_t now = time(0);
        char buffer[26]; // ctime_s requires at least 26 chars
        ctime_s(buffer, sizeof(buffer), &now);
        Timestamp = string(buffer);
        Timestamp.pop_back(); // remove '\n'

    }

    void Print()  {
        cout << "ID           : " << ID << endl;
        cout << "Name         : " << Name << endl;
        cout << "Author       : " << Author << endl;
        cout << "Category     : " << Category << endl;
        cout << "Publish Year : " << PublishYear << endl;
        cout << "Page Count   : " << PageCount << endl;
        cout << "Timestamp    : " << Timestamp << endl;


        if (!DamageNote.empty())
            cout << "Damage Note: " << DamageNote << endl;

        cout << "Average Rating: " << Rating << endl;

        if (!Comments.isEmpty()) {
            cout << "Comments:" << endl;
            for (int i = 0; i < Comments.size();i++) {
                cout << "- " << Comments.getItemByIndex(i) << endl;
            }
           
        }
    }
};

#endif

