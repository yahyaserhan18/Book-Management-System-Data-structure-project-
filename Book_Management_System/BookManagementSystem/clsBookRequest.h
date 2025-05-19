#pragma once
#include <iostream>
#include <iomanip>
#include "clsBook.h"
using namespace std;

class clsBookRequest {
public:
    static int NextID; // Otomatik artan talep numarası
    int RequestID;
    int Priority;      // 1: Normal, 2: Akademik
    clsBook Book;      // Talep edilen kitap
    bool isAcademic;   // Akademik mi?
    bool isSupplied;

    // Varsayılan constructor (gerekli)
    clsBookRequest() : RequestID(0), Priority(1), isAcademic(false), Book(), isSupplied(false){}

    clsBookRequest(clsBook book, bool academic = false)
        : Book(book), isAcademic(academic) {
        RequestID = NextID++;
        Priority = academic ? 2 : 1;
        isSupplied = false;
    }

    bool operator==(const clsBookRequest& other) const {
    return Book.ID == other.Book.ID && isAcademic == other.isAcademic;
      }

    void Print() const {
        cout << left
            <<setw(6) << Book.ID
            << "| " << setw(20) << Book.Name
            << "| " << setw(10) << (isAcademic ? "Yes" : "No") 
        << "| " << setw(10) << (isSupplied ? "Yes" : "No")<< endl;
    }

    static void PrintHeader() {
        cout << left
            << setw(6) << "RID"
            << "| " << setw(6) << "BID"
            << "| " << setw(20) << "Book Name"
            << "| " << setw(10) << "Academic"
            << "| " << setw(5) << "Prio" << endl;
        cout << string(55, '-') << endl;
    }
};

// Statik üzellik tanımlaması
int clsBookRequest::NextID = 1;
