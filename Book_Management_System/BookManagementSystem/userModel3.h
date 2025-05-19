#pragma once
#include <iostream>
#include <iomanip>
#include "clsBook.h"
#include "DataLayer.h"
#include "inputs.h"
#include "global.h"
#include "clsMyQueue.h"
#include "clsBookRequest.h"

using namespace std;

static class userModel3 {
private:
    static clsMyQueue<clsBookRequest> _Requests;

    static bool _IsBookAlreadyRequested(int bookID) {
        for (int i = 0; i < _Requests.size(); i++) {
            if (_Requests.getItem(i).Book.ID == bookID) {
                return true;
            }
        }
        return false;
    }

public:
    static clsMyQueue<clsBookRequest> BookRequests() {
        return _Requests;
    }
    static void ShowRequestBookScreen() {
        system("cls");
        cout << "=============================" << endl;
        cout << "     Request Book Screen     " << endl;
        cout << "=============================" << endl << endl;

        int id = inputs::readIntNumber("Enter Book ID to request: ");
        clsBook* book = DataLayer::DbBooks::FindById(id);

        if (book == nullptr) {
            cout << "-> Book not found :(\n";
        }
        else if (_IsBookAlreadyRequested(id)) {
            cout << "-> This book has already been requested!\n";
        }
        else {
            _Requests.push(clsBookRequest(*book));
            cout << "-> Book request added successfully :)\n";
        }

        cout << "\nPress any key to go back...";
        system("pause>0");
    }

    static void ShowViewRequestsScreen() {
        system("cls");
        cout << "=============================" << endl;
        cout << "        View Requests         " << endl;
        cout << "=============================" << endl << endl;

        if (_Requests.size() == 0) {
            cout << "-> No requests found :(\n";
        }
        else {
            cout << left
                << setw(6) << "ID"
                << "| " << setw(20) << "Name"
                << "| " << setw(10) << "Academic" 
                << "| " << setw(10) << "is Supplied" << endl;
            cout << string(55, '-') << endl;

            for (int i = 0; i < _Requests.size(); i++) {
                _Requests.getItem(i).Print();
            }
        }

        cout << "\nPress any key to go back...";
        system("pause>0");
    }

    static void ShowAcademicRequestScreen() {
        system("cls");
        cout << "=============================" << endl;
        cout << "   Academic Book Request     " << endl;
        cout << "=============================" << endl << endl;

        int id = inputs::readIntNumber("Enter Book ID to request as academic: ");
        clsBook* book = DataLayer::DbBooks::FindById(id);

        if (book == nullptr) {
            cout << "-> Book not found :(\n";
        }
        else if (_IsBookAlreadyRequested(id)) {
            cout << "-> This book has already been requested!\n";
        }
        else {
            _Requests.insertAtFront(clsBookRequest(*book, true));
            cout << "-> Academic book request added with priority :)\n";
        }

        cout << "\nPress any key to go back...";
        system("pause>0");
    }
};

clsMyQueue<clsBookRequest> userModel3::_Requests;
