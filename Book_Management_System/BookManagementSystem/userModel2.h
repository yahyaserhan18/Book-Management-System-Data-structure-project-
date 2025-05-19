#pragma once
#include <iostream>
#include <iomanip>
#include "clsBook.h";
#include "DataLayer.h";
#include "inputs.h";
#include "global.h"
#include "clsMyStack.h"
#include "clsBorrowedBook.h"
using namespace std;

static class userModel2
{
private:
	static clsMyStack<clsBorrowedBook> _BorrowedBooks;
	static clsMyStack<clsBorrowedBook> _ReturnedBooks;

public:
	static clsMyStack<clsBorrowedBook>& BorrowedBooks() {
		return _BorrowedBooks;
	}

	static clsMyStack<clsBorrowedBook>& ReturnedBooks() {
		return _ReturnedBooks;
	}

	// /////////////
	static void ShowBorrowBookScreen() {
		system("cls");
		cout << "=====================================" << endl;
		cout << "           Borrow Book Screen        " << endl;
		cout << "=====================================" << endl << endl;

		int id = inputs::readIntNumber("Enter Book ID to borrow: ");
		clsBook* book = DataLayer::DbBooks::FindById(id);

		if (book == nullptr) {
			cout << "-> Book not found :(\n";
		}
		else {
			//proje için kullancıdan ödünç süresi istiyorum
			int BorrowDuration = inputs::readIntNumber("Enter the borrow duration  as a number of days : ");
			clsBorrowedBook borrowed(*book);
			borrowed.BorrowDuration = BorrowDuration;
			_BorrowedBooks.push(borrowed);
			cout << "-> Book borrowed successfully :)\n";
		}

		cout << "\nPress any key to go back...";
		system("pause>0");
	}

	static void ShowListBorrowedBooksScreen() {
		system("cls");
		cout << "=====================================" << endl;
		cout << "         Borrowed Books List         " << endl;
		cout << "=====================================" << endl << endl;

		if (_BorrowedBooks.size()==0) {
			cout << "-> No borrowed books yet :(\n";
		}
		else {
			cout << left
				<< setw(6) << "ID"
				<< "| " << setw(20) << "Name"
				<< "| " << setw(25) << "Borrow Date"
				<< "| " << setw(25) << "Return Date"
				<< endl;
			cout << string(85, '-') << endl;

			for (int i = 0; i < _BorrowedBooks.size(); i++) {
				_BorrowedBooks.getItem(i).Print();
			}
			cout << string(85, '-') << endl;
		}

		cout << "\nPress any key to go back...";
		system("pause>0");
	}

	static void ShowReturnBookScreen() {
		system("cls");
		cout << "=============================" << endl;
		cout << "       Return Book Screen    " << endl;
		cout << "=============================" << endl << endl;

		int id = inputs::readIntNumber("Enter Book ID to return: ");

		// Ödünç alınan kitaplar listesinde kitabı arama
		for (int i = 0; i < _BorrowedBooks.size(); i++) {
			clsBorrowedBook book = _BorrowedBooks.getItem(i);
			if (book.Book.ID == id && !book.isReturned) {
				book.SetReturnedNow(); 
				_ReturnedBooks.push(book); 
				_BorrowedBooks.deleteNode(_BorrowedBooks.getNodeByIndex(i));

				cout << "\n-> Book returned successfully :)\n";
				cout << "Returned Book Info:\n";

				
				cout << left
					<< setw(6) << "ID"
					<< "| " << setw(20) << "Name"
					<< "| " << setw(25) << "Borrow Date"
					<< "| " << setw(25) << "Return Date" << endl;

				cout << string(85, '-') << endl;

				book.Print();

				cout << "\nPress any key to go back...";
				system("pause>0");
				return;
			}
		}

		//Kitap bulunamazsa
		cout << "-> Book with ID " << id << " not found in your borrowed list.\n";
		cout << "\nPress any key to go back...";
		system("pause>0");
	}


	static void ShowListReturnedBooksScreen() {
		system("cls");
		cout << "=============================" << endl;
		cout << "     Returned Books Screen   " << endl;
		cout << "=============================" << endl << endl;

		if (_ReturnedBooks.isEmpty()) {
			cout << "-> No returned books yet :(\n";
		}
		else {
			// Tablo başlığını görüntüle
			cout << left
				<< setw(6) << "ID"
				<< "| " << setw(20) << "Name"
				<< "| " << setw(25) << "Borrow Date"
				<< "| " << setw(25) << "Return Date" << endl;
			cout << string(85, '-') << endl;

			for (int i = 0; i < _ReturnedBooks.size(); i++) {
				clsBorrowedBook book = _ReturnedBooks.getItem(i);
				book.Print();
			}
		}

		cout << "\nPress any key to go back...";
		system("pause>0");
	}

};

clsMyStack<clsBorrowedBook> userModel2::_BorrowedBooks;
clsMyStack<clsBorrowedBook> userModel2::_ReturnedBooks;
