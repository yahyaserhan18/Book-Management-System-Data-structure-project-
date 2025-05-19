#pragma once
#include <iostream>
#include <iomanip>
#include "clsBook.h"
#include "DataLayer.h"
#include "inputs.h"
#include "clsMyQueue.h"
#include "userModel3.h"
#include "clsBookRequest.h"

using namespace std;

class PrModel3 {
private:
    static clsMyQueue<clsBook> _RequestedBooks; 

    static void _LoadRequestsFromUserModel() {
        _RequestedBooks.clear();
        for (int i = 0; i < userModel3::BookRequests().size(); i++) {
            clsBookRequest request = userModel3::BookRequests().getItem(i);
            if (!request.isSupplied) {
                _RequestedBooks.push(request.Book);
            }
        }
    }

public:
    static void ShowAddSuppliedBookScreen() {
        system("cls");
        cout << "===========================================" << endl;
        cout << "         Add Supplied Book Screen           " << endl;
        cout << "===========================================" << endl << endl;

        _LoadRequestsFromUserModel();

        if (_RequestedBooks.size() == 0) {
            cout << "-> No book requests found in the queue :(\n";
        }
        else {
            cout << "Next book to supply (first in queue):\n\n";
            clsBook nextBook = _RequestedBooks.front();

            cout << left
                << setw(6) << "ID"
                << "| " << setw(20) << "Name"
                << "| " << setw(15) << "Author"
                << "| " << setw(15) << "Category"
                << endl;
            cout << string(60, '-') << endl;
            cout << left
                << setw(6) << nextBook.ID
                << "| " << setw(20) << nextBook.Name
                << "| " << setw(15) << nextBook.Author
                << "| " << setw(15) << nextBook.Category
                << endl << endl;

            if (inputs::readNumberInRange(0, 1, "Do you want to supply this book to the library? (Yes:1 / No:0): ")) {
                DataLayer::DbBooks::AddBook(nextBook); 

                // durumu güncelle (isSupplied)
                for (int i = 0; i < userModel3::BookRequests().size(); i++) {
                    if (userModel3::BookRequests().getItem(i).Book.ID == nextBook.ID) {
                        clsBookRequest updated = userModel3::BookRequests().getItem(i);
                        updated.isSupplied = true;
                        userModel3::BookRequests().updateItem(i, updated);
                        break;
                    }
                }

                _RequestedBooks.pop(); //Ekledikten sonra kuyruktan kaldır
                cout << "\n-> Book successfully added to the library :)\n";
            }
            else {
                cout << "\n-> Operation cancelled.\n";
            }
        }

        cout << "\nPress any key to go back...";
        system("pause>0");
    }
};


clsMyQueue<clsBook> PrModel3::_RequestedBooks;

