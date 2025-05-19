#pragma once
#include <iostream>
#include <iomanip>
#include "clsBook.h";
#include "DataLayer.h";
#include "inputs.h";
#include "global.h"
using namespace std;

static class PrModel1
{
public:
	static void ShowAddBookScreen() {
		system("cls");
		cout << "=============================" << endl;
		cout << "       Add Book Screen       " << endl;
		cout << "=============================" << endl << endl;
		
		int id , publishYear , pagecount;
		string name , author , category;
		bool IsLocalPublisher;
		global::BookLanguages Language;
		id         = inputs::readIntNumber("Enter Book ID       : ");
		name       = inputs::readString   ("Ener Book Name      : ");
		author     = inputs::readString   ("Enter Book Author   : ");
		category   = inputs::readString   ("Enter Book Category : ");
		publishYear= inputs::readIntNumber("Enter  Publish Year : ");
		pagecount  = inputs::readIntNumber("Enter Page Count    : ");
		if (inputs::readNumberInRange(0, 1, "is Local[0] or foreign[1] Publisher ?") == 0)
			IsLocalPublisher = true;
		else
			IsLocalPublisher = false;

		if (inputs::readNumberInRange(1, 2, "What is the language of the book [ Turkish:1 , English:2 ] ?") == 1)
			Language = global::BookLanguages::turkish;
		else
			Language = global::BookLanguages::english;

		
		

		cout << endl << "=============================" << endl << endl;

		clsBook newBook(id, name, author, category, publishYear, pagecount,IsLocalPublisher,Language);

		if (!DataLayer::DbBooks::AddBook(newBook)) {
			cout << "-> The book with id="<<id<<" has already been added, the id is unique" << endl;
		}
		else {
			cout << "-> Book Added by successfully :)\n";
		}
		cout << "Press any Key for back ...";
		system("pause>0");



	}

	static void ShowEditBookByNameScreen() {
		system("cls");
		cout << "=============================" << endl;
		cout << "     Edit Book by Name       " << endl;
		cout << "=============================" << endl << endl;

		string name = inputs::readString("Enter Book Name to Edit: ");

		// doing search
		clsBook* bookToEdit = DataLayer::DbBooks::FindByName(name);

		if (bookToEdit == nullptr) {
			cout << "-> Book with name '" << name << "' not found.\n";
		}
		else {
			cout << "\nFound Book:\n";
			bookToEdit->Print();

			cout << "\nEnter New Data:\n";

			string newName     = inputs::readString   ("New Name         : ");
			string newAuthor   = inputs::readString   ("New Author       : ");
			string newCategory = inputs::readString   ("New Category     : ");
			int newYear        = inputs::readIntNumber("New Publish Year : ");
			int newPages       = inputs::readIntNumber("New Page Count   : ");

			// update Props
			bookToEdit->Name = newName;
			bookToEdit->Author = newAuthor;
			bookToEdit->Category = newCategory;
			bookToEdit->PublishYear = newYear;
			bookToEdit->PageCount = newPages;

			cout << "\n-> Book updated successfully :)\n";
		}

		cout << "\nPress any key to go back...";
		system("pause>0");
	}

	static void ShowDeleteBookByIdScreen() {
		system("cls");
		cout << "=============================" << endl;
		cout << "     Delete Book by ID       " << endl;
		cout << "=============================" << endl << endl;

		int id = inputs::readIntNumber("Enter Book ID to Delete: ");

		clsBook* bookToDelete = DataLayer::DbBooks::FindById(id);

		if (bookToDelete == nullptr) {
			cout << "\n-> Book with ID " << id << " not found.\n";
		}
		else {
			cout << "\n-> Book Found:\n";
			bookToDelete->Print();

			cout << "\nAre you sure you want to delete this book? (y/n): ";
			char confirm;
			cin >> confirm;

			if (tolower(confirm) == 'y') {
				if (DataLayer::DbBooks::DeleteBook(id)) {
					cout << "\n-> Book deleted successfully :)\n";
				}
				else {
					cout << "\n-> Failed to delete the book.\n";
				}
			}
			else {
				cout << "\n-> Deletion canceled.\n";
			}
		}

		cout << "\nPress any key to go back...";
		system("pause>0");
	}


	static void ShowListBooksWithTimestampScreen() {
		system("cls");
		cout << "========================================" << endl;
		cout << "              List Of Books             " << endl;
		cout << "========================================" << endl << endl;

		DataLayer::DbBooks::ListBooksWithTimestamp();

		cout << "\n\nPress any Key for back ...";
		system("pause>0");

	}


	static void ShowSearchBookByIdScreen() {
		system("cls");
		cout << "=============================" << endl;
		cout << "     Search Book by ID       " << endl;
		cout << "=============================" << endl << endl;

		int id = inputs::readIntNumber("Enter Book ID to Search: ");

		clsBook* book = DataLayer::DbBooks::FindById(id);

		if (book == nullptr) {
			cout << "\nBook with ID " << id << " not found.\n\n";
		}
		else {
			cout << "\nBook Found:\n\n";
			book->Print();
		}

		cout << "\nPress any key to go back...";
		system("pause>0");
	}


	static void ShowGetTotalBookCountScreen() {
		system("cls");
		cout << "====================================" << endl;
		cout << "      Total Book Count Screen  " << endl;
		cout << "====================================" << endl << endl;

		int count = DataLayer::DbBooks::Count();

		cout << "-> Total number of books in the system: " << count << endl;

		cout << "\nPress any key to go back...";
		system("pause>0");
	}

	static void ShowSortBooksByPageCountScreen() {
		system("cls");
		cout << "======================================" << endl;
		cout << "     Sort Books By Page Count Screen  " << endl;
		cout << "======================================" << endl << endl;

		// doing sort
		DataLayer::DbBooks::SortByPageCount();

		cout << "-> Books sorted by page count successfully.\n\n";

		// view books after sort
		DataLayer::DbBooks::ListBooks();

		cout << "\nPress any key to go back...";
		system("pause>0");
	}

	static void ShowOldest5BooksScreen() {
		system("cls");
		cout << "==================================" << endl;
		cout << "       Oldest 5 Books Screen      " << endl;
		cout << "==================================" << endl << endl;

		cout << "-> Showing the 5 oldest books by publish year:\n\n";

		DataLayer::DbBooks::ShowOldest5Books();

		cout << "\nPress any key to go back...";
		system("pause>0");
	}

	static void ShowAddDamageNoteScreen() {
		system("cls");
		cout << "===================================" << endl;
		cout << "       Add Damage Note Screen      " << endl;
		cout << "===================================" << endl << endl;

		int id = inputs::readIntNumber("Enter Book ID to add damage note: ");

		clsBook* book = DataLayer::DbBooks::FindById(id);

		if (book == nullptr) {
			cout << "\n-> Book with ID " << id << " not found.\n";
		}
		else {
			cout << "\nBook Found:\n";
			book->Print();

			string note = inputs::readString("\nEnter Damage Note: ");

			if (DataLayer::DbBooks::AddDamageNote(id, note)) {
				cout << "\n-> Damage note added successfully :)\n";
			}
			else {
				cout << "\n-> Failed to add damage note :( \n";
			}
		}

		cout << "\nPress any key to go back...";
		system("pause>0");
	}

	static void ShowListDamagedBooksScreen() {
		system("cls");
		cout << "===================================" << endl;
		cout << "      Damaged Books List Screen    " << endl;
		cout << "===================================" << endl << endl;

		bool found = false;

		// Labels
		cout << left
			<< setw(6) << "ID"
			<< "| " << setw(20) << "Name"
			<< "| " << setw(15) << "Author"
			<< "| " << setw(15) << "Category"
			<< "| " << setw(6) << "Year"
			<< "| " << setw(6) << "Pages"
			<< "| " << setw(25) << "Timestamp"
			<< "| " << setw(20) << "Damage Note"
			<< endl;

		cout << string(135, '-') << endl;

		for (int i = 0; i < DataLayer::DbBooks::Count(); i++) {
			clsBook b = DataLayer::DbBooks::GetItemByIndex(i);
			if (!b.DamageNote.empty()) {
				found = true;

				cout << left
					<< setw(6) << b.ID
					<< "| " << setw(20) << b.Name
					<< "| " << setw(15) << b.Author
					<< "| " << setw(15) << b.Category
					<< "| " << setw(6) << b.PublishYear
					<< "| " << setw(6) << b.PageCount
					<< "| " << setw(25) << b.Timestamp
					<< "| " << setw(20) << b.DamageNote
					<< endl;
			}
		}

		if (!found) {
			cout << "\n-> No damaged books found :(\n";
		}

		cout << "\nPress any key to go back...";
		system("pause>0");
	}


};

