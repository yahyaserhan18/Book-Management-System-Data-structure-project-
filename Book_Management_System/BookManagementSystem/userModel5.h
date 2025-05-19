
#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include "clsBook.h"
#include "DataLayer.h"
#include "inputs.h"
#include "global.h"
#include "clsHashTable.h"
#include "clsBorrowedBook.h"
#include "userModel2.h"
#include <map>

using namespace std;

static class userModel5 {
private:
    static clsHashTable<string, vector<clsBorrowedBook>> _CategoryTable;
    static clsHashTable<int, vector<clsBorrowedBook>> _RatingTable;//puanlama tablosu
    static vector<clsBorrowedBook> _RatedBooksStorage;

    static void _LoadDataIntoCategoryTable() {
        for (int i = 0; i < PrModel2::BorrowedList().size(); i++) {
            clsBorrowedBook book = PrModel2::BorrowedList().getItemByIndex(i);
            _CategoryTable.insert(book.Book.Category, { book });
        }
    }

    static void _LoadDataIntoTables() {
        _CategoryTable.clear();
        _RatingTable.clear();

        _LoadDataIntoCategoryTable();

        for (const auto& book : _RatedBooksStorage) {
            if (book.Rating >= 1 && book.Rating <= 5) {
                _RatingTable.insert(book.Rating, book);
            }
        }
    }


public:
    static  clsHashTable<int, vector<clsBorrowedBook>> getRagingTable() {
        return _RatingTable;
    }
    static   vector<clsBorrowedBook> getRatedBooks() {
        return _RatedBooksStorage;
    }
    static void ShowRecommendSimilarBooksScreen() {
        system("cls");
        cout << "===============================\n";
        cout << "   Recommend Similar Books\n";
        cout << "===============================\n\n";

        _LoadDataIntoTables();

        string category = inputs::readString("Enter category to get recommendations: ");

        vector<clsBorrowedBook> result;
        if (_CategoryTable.search(category, result)) {
            cout << "\n\nRecommended Books in category [" << category << "]:\n";
            cout << left << setw(6) << "ID" << "| "
                         << setw(20) << "Name" << "| "
                         << setw(20) << "Category" << endl;
            cout << string(50, '-') << endl;
            for (auto& book : result)
                cout << setw(6) << book.Book.ID << "| "
                     << setw(20) << book.Book.Name << "| "
                     << setw(20) << book.Book.Category << endl;
        }
        else {
            cout << "No borrowed books found in this category.\n";
        }

        cout << "\nPress any key to go back...";
        system("pause>0");
    }


    static void ShowRateBooksAndListScreen() {
        system("cls");
        cout << "===============================\n";
        cout << "      Rate Borrowed Books\n";
        cout << "===============================\n";

         //تقييم الكتب المُستعارة
        for (int i = 0; i < PrModel2::BorrowedList().size(); i++) {
            clsBorrowedBook book = PrModel2::BorrowedList().getItemByIndex(i);
            cout << "\nBook ID: " << book.Book.ID << ", Name: " << book.Book.Name << endl;
            int rating = inputs::readNumberInRange(1, 5, "    -> Rate this book (1-5): ");
            book.Rating = rating;
            _RatedBooksStorage.push_back(book);
        }

        _LoadDataIntoTables();

        cout << "\n===============================\n";
        cout << "     Book Ratings Summary\n";
        cout << "===============================\n\n";

        map<string, vector<int>> bookRatings;
        for (const auto& book : _RatedBooksStorage) {
            bookRatings[book.Book.Name].push_back(book.Rating);
        }

        for (const auto& entry : bookRatings) {
            cout << "Book Name  : " << entry.first << endl;
            cout << "Ratings    : ";
            for (int rate : entry.second)
                cout << rate << " ";
            cout << "\n" << string(40, '-') << "\n";
        }

        cout << "\nPress any key to go back...";
        system("pause>0");
    }
};

clsHashTable<string, vector<clsBorrowedBook>> userModel5::_CategoryTable;
clsHashTable<int, vector<clsBorrowedBook>> userModel5::_RatingTable;
vector<clsBorrowedBook> userModel5::_RatedBooksStorage;
