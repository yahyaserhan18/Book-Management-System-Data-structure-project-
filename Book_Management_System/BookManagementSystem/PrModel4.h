#pragma once
#include <iostream>
#include <iomanip>
#include "clsBook.h"
#include "DataLayer.h"
#include "inputs.h"
#include "clsBinaryTree.h"
#include "clsBorrowedBook.h"
#include "PrModel2.h"

using namespace std;

class PrModel4 {
private:
    static clsBinaryTree<clsBorrowedBook> _BorrowedTree;

    static void _LoadDataIntoTree() {
        _BorrowedTree.clear();
        for (int i = 0; i < PrModel2::BorrowedList().size(); i++) {
            _BorrowedTree.Insert(PrModel2::BorrowedList().getItemByIndex(i));
        }
    }

    static void _PrintHeader() {
        cout << left << setw(6) << "ID" << "| " << setw(20) << "Name" << "| "
            << setw(25) << "Borrow Date" << "| " 
            << setw(12) << "Publish Year" << "| " << setw(12) << "Borrow Duration(Days)" << endl;
        cout << string(100, '-') << endl;
    }

    static void _PrintContent(clsBorrowedBook book) {
        book.PrintWithoutEndlineAtEnd();
        cout << "| " << setw(12) << book.Book.PublishYear
            << "| " << setw(12) << book.BorrowDuration << endl;
    }

public:
    static void ShowAnalyzeBorrowDurationScreen() {
        system("cls");
        cout << "=============================================" << endl;
        cout << "  Analyze Borrow Duration (30 Days Filter)" << endl;
        cout << "=============================================" << endl;

        _LoadDataIntoTree();

        //>=30
        cout <<endl<< "-> borrowed duration more 30 days :\n";
        _PrintHeader();

        _BorrowedTree.InOrderTraversal([](clsBorrowedBook book) {
            if (book.BorrowDuration >= 30) {
                _PrintContent(book);
            }
            });

        cout << endl << endl;
        //<30
        cout << "-> borrowed duration under 30 days :\n";
        _PrintHeader();

        _BorrowedTree.InOrderTraversal([](clsBorrowedBook book) {
            if (book.BorrowDuration < 30) {
                _PrintContent(book);
            }
            });


        cout << "\nPress any key to go back...";
        system("pause>0");
    }

    static void ShowFilterByPublishYearScreen() {
        system("cls");
        cout << "=============================================" << endl;
        cout << "   Filter Borrowed Books (After 1950)" << endl;
        cout << "=============================================" << endl;

        _LoadDataIntoTree();

      

        //>=1950
        cout<<endl << "-> publication year After 1950 : " << endl;
        _PrintHeader();
        _BorrowedTree.InOrderTraversal([](clsBorrowedBook book) {
            if (book.Book.PublishYear >= 1950) {
                _PrintContent(book);
            }
            });

        cout << endl << endl << endl;


        //<1950
        cout <<endl<< "-> publication year before 1950 : " << endl;
        _PrintHeader();
        _BorrowedTree.InOrderTraversal([](clsBorrowedBook book) {
            if (book.Book.PublishYear < 1950) {
                _PrintContent(book);
            }
            });

        cout << "\nPress any key to go back...";
        system("pause>0");
    }

    static void ShowFilterOldBooksLongBorrowScreen() {
        system("cls");
        cout << "==============================================================" << endl;
        cout << "  Old Books (<=1950) with Long Borrow Duration (>30 Days)" << endl;
        cout << "==============================================================" << endl;

        _LoadDataIntoTree();

        _PrintHeader();

        _BorrowedTree.InOrderTraversal([](clsBorrowedBook book) {
            if (book.Book.PublishYear <= 1950 && book.BorrowDuration > 30) {
                _PrintContent(book);
            }
            });

        cout << "\nPress any key to go back...";
        system("pause>0");
    }
};

// static tanimlama
clsBinaryTree<clsBorrowedBook> PrModel4::_BorrowedTree;