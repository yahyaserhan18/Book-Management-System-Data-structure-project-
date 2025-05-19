#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <iomanip>
#include <ctime>
#include "clsBook.h"
#include <sstream>

using namespace std;

class clsBorrowedBook {
public:
    clsBook Book;
    string BorrowDate;
    string ReturnDate;
    bool isReturned = false;
    int BorrowDuration; // ödünç alma süresi gün olarak
    int Rating = 0; // puanlamak için 1-5 arasında model5 için


    bool operator==(const clsBorrowedBook& other) const {
        return Book.ID == other.Book.ID; //id ye göre karşılaştırma
    }

    clsBorrowedBook() {
        isReturned = false;
        BorrowDate = "";
        ReturnDate = "";
        //
        BorrowDuration = 0;
     
    }

    clsBorrowedBook(clsBook b) {
        Book = b;

        // Get current time for BorrowDate
        time_t now = time(0);
        char* dt = ctime(&now);
        BorrowDate = string(dt);
        BorrowDate.pop_back(); // Remove '\n'

        //
        BorrowDuration = 0;
    }
    //kiyaslayabilmek için
    bool operator<(const clsBorrowedBook& other) const {
        return this->Book.ID < other.Book.ID; 
    }


  
    void SetReturnedNow() {
        time_t now = time(0);
        char* dt = ctime(&now);
        ReturnDate = string(dt);
        ReturnDate.pop_back();
        isReturned = true;


    }


    void Print() const {
        cout << left
            << setw(6) << Book.ID
            << "| " << setw(20) << Book.Name
            << "| " << setw(25) << BorrowDate
            << "| " << setw(25) << (isReturned ? ReturnDate : "--")
            << endl;
    }

    void PrintWithoutEndlineAtEnd() const{
        cout << left
            << setw(6) << Book.ID
            << "| " << setw(20) << Book.Name
            << "| " << setw(25) << BorrowDate;
            /*<< "| " << setw(25) << (isReturned ? ReturnDate : "--");*/
    }
};


// Bu fonksiyon, clsBorrowedBook nesnesini cout (veya başka bir ostream) ile ekrana düzgün ve hizalanmış biçimde yazdırmak için kullanılır.
// cout << book; // << Operatörü Tanımlı Değil!
//C++ dili, kendi veri türleri (int, string, char...) için << operatörünü zaten biliyor.
// Ama kendi oluşturduğun sınıflar (örneğin clsBorrowedBook) için bunu senin tanımlaman gerekir.
inline ostream& operator<<(ostream& os, const clsBorrowedBook& book) {
    os << left
        << setw(6) << book.Book.ID
        << "| " << setw(20) << book.Book.Name
        << "| " << setw(25) << book.BorrowDate
        << "| " << setw(25) << (book.isReturned ? book.ReturnDate : "----")<<endl;
    return os;
}
