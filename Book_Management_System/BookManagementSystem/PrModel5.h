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
#include "userModel5.h"


using namespace std;


static class PrModel5
{
public:
    static void ShowAddRatingsAndListScreen() {
        system("cls");
        cout << "=============================================\n";
        cout << "  Add Book Ratings and List High Rated Books\n";
        cout << "=============================================\n\n";

        vector<clsBorrowedBook> ratedBooks = userModel5::getRatedBooks();

        if (ratedBooks.empty()) {
            cout << "-> No rated books found.\n";
            cout << "\nPress any key to go back...";
            system("pause>0");
            return;
        }

        // Map<book ID, vector of ratings>
        map<int, vector<int>> ratingMap;

        for (const auto& book : ratedBooks) {
            ratingMap[book.Book.ID].push_back(book.Rating);
        }

        // Display Header
        cout << left
            << setw(6) << "ID"
            << "| " << setw(25) << "Book Name"
            << "| " << setw(10) << "Avg Rating"
            << "| " << setw(10) << "Count" << endl;
        cout << string(60, '-') << endl;

        bool found = false;

        for (const auto& entry : ratingMap) {
            int id = entry.first;
            const vector<int>& ratings = entry.second;

            float sum = 0;
            for (int r : ratings) sum += r;
            float avg = (float)(sum / ratings.size());

            if (avg >= 4.0f) {
                found = true;
                clsBook* book = DataLayer::DbBooks::FindById(id);
                if (book != nullptr) {
                    cout << left
                        << setw(6) << book->ID
                        << "| " << setw(25) << book->Name
                        << "| " << setw(10) << fixed << setprecision(2) << avg
                        << "| " << setw(10) << ratings.size()
                        << endl;
                }
            }
        }

        if (!found)
            cout << "-> No books with average rating >= 4 found.\n";

        cout << "\nPress any key to go back...";
        system("pause>0");
    }


};

