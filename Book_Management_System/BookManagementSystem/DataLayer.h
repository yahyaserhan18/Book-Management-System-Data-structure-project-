
#pragma once
#include <iostream>
#include <iomanip> 
#include <string>
#include <vector>
#include <algorithm>
#include "clsBook.h"
#include "clsSinglyLinkedList.h"
#include "clsCircularLinkedList.h"
#include "global.h"

using namespace std;

namespace DataLayer {

 

    class DbBooks {
    private:
        static clsSinglyLinkedList<clsBook> _Books;

    public:
        static bool AddBook(clsBook book) {
            if (_Books.find(book)) {
                return false;
            }
            _Books.insertAtEnd(book);
            return true;
        }


        static void ListBooks() {
            if (_Books.isEmpty()) {
                cout << "[No books found]\n";
                return;
            }

            // colums headers
            cout << left
                << setw(6) << "ID"
                << "| " << setw(20) << "Name"
                << "| " << setw(15) << "Author"
                << "| " << setw(15) << "Category"
                << "| " << setw(6) << "Year"
                << "| " << setw(6) << "Pages"
                << "| " << setw(25) << "Timestamp"
                << endl;

            cout << string(110, '-') << endl;

            // data
            for (int i = 0; i < _Books.size(); i++) {
                clsBook book = _Books.getItemByIndex(i);

                cout << left
                    << setw(6) << book.ID
                    << "| " << setw(20) << book.Name
                    << "| " << setw(15) << book.Author
                    << "| " << setw(15) << book.Category
                    << "| " << setw(6) << book.PublishYear
                    << "| " << setw(6) << book.PageCount
                    << "| " << setw(25) << book.Timestamp
                    << endl;
            }

            cout << string(110, '-') << endl;
        }


        static void ListBooksWithTimestamp() {
            if (_Books.isEmpty()) {
                cout << "[No books found]\n";
                return;
            }

       

            // view labels
            cout << left << setw(6) << "ID"
                << "| " << setw(25) << "Name"
                << "| " << setw(10) << "Publisher"
                << "| " << setw(10) << "Language"
                << "| " << setw(15) << "Category"
                << "| " << setw(15) << "Page count"
                << "| " << setw(25) << "Timestamp" << endl;//Category
            cout << string(115, '-') << endl;

            //view data
            for (int i = 0; i < _Books.size(); i++) {
                clsBook book = _Books.getItemByIndex(i);

                string publisher = book.IsLocalPublisher ? "Local" : "foreign";
                string language = book.Language == global::BookLanguages::turkish ? "Turkish" : "English";

                cout << left << setw(6) << book.ID
                    << "| " << setw(25) << book.Name
                    << "| " << setw(10) << publisher
                    << "| " << setw(10) << language
                    << "| " << setw(15) << book.Category
                    << "| " << setw(15) << book.PageCount
                    << "| " << setw(25) << book.Timestamp << endl;
            }

            cout << string(115, '-') << endl;
        }


        static int Count() {
            return _Books.size();
        }

        static clsBook* FindById(int id) {
            for (int i = 0; i < _Books.size(); i++) {
                if (_Books.getItemByIndex(i).ID == id)
                    return &_Books.getNodeByIndex(i)->value;
            }
            return nullptr;
        }

        static clsBook GetItemByIndex(int index) {
            return _Books.getItemByIndex(index);
        }

        static bool EditBookByName(string name, clsBook newBookData) {
            for (int i = 0; i < _Books.size(); i++) {
                if (_Books.getItemByIndex(i).Name == name) {
                    _Books.updateItem(i, newBookData);
                    return true;
                }
            }
            return false;
        }

        static bool DeleteBook(int id) {
            for (int i = 0; i < _Books.size(); i++) {
                if (_Books.getItemByIndex(i).ID == id) {
                    _Books.deleteNode(_Books.getNodeByIndex(i));
                    return true;
                }
            }
            return false;
        }

        static void SortByPageCount() {
            vector<clsBook> sortedBooks;
            for (int i = 0; i < _Books.size(); i++) {
                sortedBooks.push_back(_Books.getItemByIndex(i));
            }

            sort(sortedBooks.begin(), sortedBooks.end(), [](clsBook a, clsBook b) {
                return a.PageCount < b.PageCount;
                });

            _Books.clear();
            for (clsBook b : sortedBooks) {
                _Books.insertAtEnd(b);
            }
        }

    
        static void ShowOldest5Books() {
            vector<clsBook> books;
            for (int i = 0; i < _Books.size(); i++) {
                books.push_back(_Books.getItemByIndex(i));
            }

            sort(books.begin(), books.end(), [](clsBook a, clsBook b) {
                return a.PublishYear < b.PublishYear;
                });

            cout << "Top 5 Oldest Books:\n\n";

            if ((int)books.size() == 0) {
                cout << "-> No books found :(\n";
                return;
            }

            // print labels
            cout << left
                << setw(6) << "ID"
                << "| " << setw(20) << "Name"
                << "| " << setw(15) << "Author"
                << "| " << setw(15) << "Category"
                << "| " << setw(6) << "Year"
                << "| " << setw(6) << "Pages"
                << "| " << setw(25) << "Timestamp"
                << endl;

            cout << string(110, '-') << endl;

            // print first 5 book
            for (int i = 0; i < min(5, (int)books.size()); i++) {
                clsBook book = books[i];
                cout << left
                    << setw(6) << book.ID
                    << "| " << setw(20) << book.Name
                    << "| " << setw(15) << book.Author
                    << "| " << setw(15) << book.Category
                    << "| " << setw(6) << book.PublishYear
                    << "| " << setw(6) << book.PageCount
                    << "| " << setw(25) << book.Timestamp
                    << endl;
            }

            cout << string(110, '-') << endl;
        }


        static bool AddDamageNote(int id, string note) {
            clsBook* book = FindById(id);
            if (book != nullptr) {
                book->DamageNote = note;
                return true;
            }
            return false;
        }

        static void ListDamagedBooks() {
            bool found = false;
            for (int i = 0; i < _Books.size(); i++) {
                clsBook b = _Books.getItemByIndex(i);
                if (!b.DamageNote.empty()) {
                    b.Print();
                    cout << "---------------------\n";
                    found = true;
                }
            }
            if (!found) cout << "No damaged books found.\n";
        }

        static clsBook* FindByName(string name) {
            for (int i = 0; i < _Books.size(); i++) {
                if (_Books.getItemByIndex(i).Name == name) {
                    return &_Books.getNodeByIndex(i)->value;
                }
            }
            return nullptr;
        }

    };
    clsSinglyLinkedList<clsBook> DbBooks::_Books;



 

    class DbModel1ForUser {
    private:
        static clsDoublyCircularLinkedList<clsBook> _book;
        static void _LoadBooksFromPersonel() {
            for (int i = 0; i < DbBooks::Count();i++) {
                _book.insertAtEnd(DbBooks::GetItemByIndex(i));
            }
        }
        static clsDoublyCircularLinkedList<clsBook> _PersonalCollection;

    public:
        DbModel1ForUser() {
            _LoadBooksFromPersonel();
        }
        static clsDoublyCircularLinkedList<clsBook> GetPersonalCollection() {
            return _PersonalCollection;
        }

        static void AddCommentToBookByID(int id , string comment) {

            clsBook *book = DbBooks::FindById(id);
            book->Comments.insertAtEnd(comment);
        }
        static clsDoublyCircularLinkedList<clsBook> GetListCommentsToBookByID(int id) {
           
            return _book;
           
        }

        static bool CreatPersonalCollection() {

            if (!global::PersonalCollectionIsCreated)
            {
              
                global::PersonalCollectionIsCreated = true;
                
                return true;
            }
            return false;
            
        }

        static bool AddBookToCollection(clsBook book,bool &isCreated) {
            if (global::PersonalCollectionIsCreated) {
                if (_PersonalCollection.Find(book) != NULL)
                {
                    isCreated = true;
                    return true;

                }
                _PersonalCollection.insertAtEnd(book);
                return true;
            }
            return false;
        }

        static bool MarkBookReadStatus(int id, bool isReaded) {
            for (int i = 0; i < _PersonalCollection.size(); i++) {
                if (_PersonalCollection.getItemByIndex(i).ID == id) {
                    _PersonalCollection.getNodeByIndex(i)->value.isReaded = isReaded;
                    return true;
                }
            }
            return false;
        }

        static bool RemoveBookFromCollection(int id) {
            if (_PersonalCollection.size() == 0)
                return false;

            for (int i = 0; i < _PersonalCollection.size(); i++) {
                if (_PersonalCollection.getItemByIndex(i).ID == id) {
                    _PersonalCollection.deleteNode(_PersonalCollection.getNodeByIndex(i));
                    return true;
                }
            }
            return false;
        }

   
     };







    clsDoublyCircularLinkedList<clsBook> DbModel1ForUser::_book;

    clsDoublyCircularLinkedList<clsBook> DbModel1ForUser::_PersonalCollection;

}

