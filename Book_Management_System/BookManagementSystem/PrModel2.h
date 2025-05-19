#pragma once
#include <iostream>
#include <iomanip>
#include "clsBook.h";
#include "DataLayer.h";
#include "inputs.h";
#include "clsBorrowedBook.h"
#include "clsCircularLinkedList.h"
#include "userModel2.h"
using namespace std;

static class PrModel2 {
private:
	static clsCircularLinkedList<clsBorrowedBook> _BorrowedList;
	static clsCircularLinkedList<clsBorrowedBook> _ReturnedList;
	static clsCircularLinkedList<clsBorrowedBook> _AvailableList;

	static void _LoadBorrowedFromStack() {
		_BorrowedList.clear();
		for (int i = userModel2::BorrowedBooks().size() - 1; i >= 0; i--) {
			_BorrowedList.insertAtEnd(userModel2::BorrowedBooks().getItem(i));
		}
	}

	static void _LoadReturnedFromStack() {
		_ReturnedList.clear();
		for (int i = userModel2::ReturnedBooks().size() - 1; i >= 0; i--) {
			_ReturnedList.insertAtEnd(userModel2::ReturnedBooks().getItem(i));
		}
	}

	static void _LoadAvailableBooks() {
		_AvailableList.clear();
		for (int i = 0; i < DataLayer::DbBooks::Count(); i++) {
			clsBook book = DataLayer::DbBooks::GetItemByIndex(i); 

			bool isBorrowed = false;

			for (int j = 0; j < userModel2::BorrowedBooks().size(); j++) {
				if (userModel2::BorrowedBooks().getItem(j).Book.ID == book.ID && !userModel2::BorrowedBooks().getItem(j).isReturned) {
					isBorrowed = true;
					break;
				}
			}

			if (!isBorrowed) {
				clsBorrowedBook b(book);
				b.isReturned = true;
				_AvailableList.insertAtEnd(b);
			}
		}
	}

	static void _PrintHeader() {
		cout << left
			<< setw(6) << "ID"
			<< "| " << setw(20) << "Name"
			<< "| " << setw(25) << "Borrow Date"
			<< "| " << setw(25) << "Return Date" << endl;
		cout << string(85, '-') << endl;
	}

public:
	static clsCircularLinkedList<clsBorrowedBook> & BorrowedList() {
			_LoadBorrowedFromStack(); 

		return _BorrowedList;
	}




	static void ShowGenerateBorrowedBokkReport() {
		system("cls");
		cout << "==============================================" << endl;
		cout << "         Borrowed Books Report Screen         " << endl;
		cout << "==============================================" << endl << endl;
		_LoadBorrowedFromStack();

		_PrintHeader();
		_BorrowedList.print();
		cout << "\nPress any key to go back...";
		system("pause>0");
	}

	static void ShowGenerateReturnedBookReport() {
		system("cls");
		cout << "==============================================" << endl;
		cout << "         Returned Books Report Screen         " << endl;
		cout << "==============================================" << endl << endl;
		_LoadReturnedFromStack();

		_PrintHeader();
		_ReturnedList.print();
		cout << "\nPress any key to go back...";
		system("pause>0");
	}

	static void ShowListAvailableBooks() {
		system("cls");
		cout << "==============================================" << endl;
		cout << "         Available Books Report Screen        " << endl;
		cout << "==============================================" << endl << endl;
		_LoadAvailableBooks();

		_PrintHeader();
		_AvailableList.print();
		cout << "\nPress any key to go back...";
		system("pause>0");
	}
};

clsCircularLinkedList<clsBorrowedBook> PrModel2::_BorrowedList;
clsCircularLinkedList<clsBorrowedBook> PrModel2::_ReturnedList;
clsCircularLinkedList<clsBorrowedBook> PrModel2::_AvailableList;