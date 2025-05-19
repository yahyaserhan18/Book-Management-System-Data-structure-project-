#pragma once
#include <iostream>
#include <iomanip>
#include "clsBook.h"
#include "DataLayer.h"
#include "inputs.h"
#include "global.h"
#include "clsBinaryTree.h"
#include "clsBorrowedBook.h"
#include "PrModel2.h"

using namespace std;

static class userModel4 {
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
            << setw(12) << "Publisher" << "| " << setw(12) << "Language"
            << setw(10) << "| " << "page count" << endl;
        cout << string(100, '-') << endl;
    }

    static void _PrintContent(clsBorrowedBook book) {
        book.PrintWithoutEndlineAtEnd();
        string publisher = book.Book.IsLocalPublisher ? "Local" : "foreign";
        string language = book.Book.Language == global::BookLanguages::turkish ? "Turkish" : "English";

        cout << "| " << setw(12) << publisher
            << "| " << setw(12) << language 
            <<"| "<<setw(10) <<book.Book.PageCount <<endl;
    }


public:
    static void ShowFilterByPublisherScreen() {
        system("cls");
        cout << "===============================" << endl;
        cout << "  Filter by Publisher (Local)" << endl;
        cout << "===============================\n\n";

        _LoadDataIntoTree();

        cout << "-> Local Publisher:\n";
        _PrintHeader();
        _BorrowedTree.InOrderTraversal([](clsBorrowedBook book) {
            if (book.Book.IsLocalPublisher)
                _PrintContent(book);
            });

        cout << "\n-> Foreign Publisher:\n";
        _PrintHeader();
        _BorrowedTree.InOrderTraversal([](clsBorrowedBook book) {
            if (!book.Book.IsLocalPublisher)
                _PrintContent(book);
            });

        cout << "\nPress any key to go back...";
        system("pause>0");
    }

    static void ShowFilterByLanguageScreen() {
        system("cls");
        cout << "===============================" << endl;
        cout << "  Filter by Language" << endl;
        cout << "===============================\n\n";

        _LoadDataIntoTree();

        cout << "-> Turkish Books:\n";
        _PrintHeader();
        _BorrowedTree.InOrderTraversal([](clsBorrowedBook book) {
            if (book.Book.Language == global::BookLanguages::turkish)
                _PrintContent(book);
            });

        cout << "\n-> English Books:\n";
        _PrintHeader();
        _BorrowedTree.InOrderTraversal([](clsBorrowedBook book) {
            if (book.Book.Language == global::BookLanguages::english)
                _PrintContent(book);
            });

        cout << "\nPress any key to go back...";
        system("pause>0");
    }

    static void ShowFilterByPageCountScreen() {
        system("cls");
        cout << "===============================================" << endl;
        cout << "  Filter by Page Count (Threshold: 1000)" << endl;
        cout << "===============================================\n\n";

        _LoadDataIntoTree();

        cout << "-> Books with < 1000 pages:\n";
        _PrintHeader();
        _BorrowedTree.InOrderTraversal([](clsBorrowedBook book) {
            if (book.Book.PageCount < 1000)
                _PrintContent(book);
            });

        cout << "\n-> Books with >= 1000 pages:\n";
        _PrintHeader();
        _BorrowedTree.InOrderTraversal([](clsBorrowedBook book) {
            if (book.Book.PageCount >= 1000)
                _PrintContent(book);
            });

        cout << "\nPress any key to go back...";
        system("pause>0");
    }
};

clsBinaryTree<clsBorrowedBook> userModel4::_BorrowedTree;
