#pragma once
#include <iostream>
#include <iomanip>
#include "clsBook.h";
#include "DataLayer.h";
#include "inputs.h";
#include "clsDoublyCircularLinkedList.h"
#include "global.h"
using namespace std;

static class userModel1
{
public:
	static void ShowAddCommentToBookByIDScreen() {
		system("cls");
		cout << "=============================" << endl;
		cout << "       Add Comment Screen    " << endl;
		cout << "=============================" << endl << endl;

		int id;
		string comment;
		id = inputs::readIntNumber("Enter Book ID : ");

		if (DataLayer::DbBooks::FindById(id) == nullptr)
		{
			cout << "-> Book not found :(\n";
		}
		else {
			comment = inputs::readString("Enter Comment : ");
			DataLayer::DbModel1ForUser::AddCommentToBookByID(id, comment);
			cout << "-> Comment Added by successfully :)\n";
		}
	   
		cout << "Press any Key for back ...";
		system("pause>0");
	}

	static void ShowListCommentsToBookByIDScreen() {
		system("cls");
		cout << "=============================" << endl;
		cout << "      Comment List Screen    " << endl;
		cout << "=============================" << endl << endl;

		int id;
		id = inputs::readIntNumber("Enter Book ID       : ");
		clsBook* book = DataLayer::DbBooks::FindById(id);

		if (book == nullptr)
		{
			cout << "-> Book not found :(\n";
		}
		else {
			for (int i = 0; i < book->Comments.size();i++) {
				cout << "Comment " << i + 1 << " : " << book->Comments.getItemByIndex(i) << endl;
			}
		}

		cout << endl;
		cout << "Press any Key for back ...";
		system("pause>0");
	}

	static void ShowCreateCollectionScreen() {
		system("cls");
		cout << "=============================" << endl;
		cout << "   Create Collection Screen  " << endl;
		cout << "=============================" << endl << endl;


		if (inputs::readNumberInRange(0, 1, "Are you sure you want to create a personal Collection (Yes:1, No:0)?")) {
			if (!DataLayer::DbModel1ForUser::CreatPersonalCollection())
				cout << "-> You have already Personal Collection ." << endl << endl;
			else {
				cout << "-> Your Personal Collection Added by successfully :)\n";
			}
		}
		cout << "Press any Key for back ...";
		system("pause>0");
	}

	static void ShowAddBookToCollectionScreen() {
		bool isCreated = false;
		system("cls");
		cout << "=============================" << endl;
		cout << " Add Book To Collection Screen " << endl;
		cout << "=============================" << endl << endl;

		int id = inputs::readIntNumber("Enter Book ID to add: ");
		clsBook* book = DataLayer::DbBooks::FindById(id);

		if (book == nullptr) {
			cout << "-> Book not found :(\n";
		}
		else {
	
			if (DataLayer::DbModel1ForUser::AddBookToCollection(*book,isCreated)) {
				if (isCreated) {
					cout << "-> The book was not added because the book is already in the collection." << endl;
					isCreated = false;
					
				}
				else
				cout << "-> Book added to your collection successfully :)\n";
			}
			else {
				cout << "-> You don't have a personal collection yet. Please create one first.\n";
			}
		}

		cout << "Press any Key for back ...";
		system("pause>0");
	}

	static void ShowMarkReadUnreadScreen() {
		system("cls");
		cout << "=================================" << endl;
		cout << "     Mark Book as Read/Unread    " << endl;
		cout << "=================================" << endl << endl;

		int id = inputs::readIntNumber("Enter Book ID to mark: ");
		int state = inputs::readNumberInRange(0, 1, "Set status (Read:1, Unread:0): ");

		if (DataLayer::DbModel1ForUser::MarkBookReadStatus(id, state)) {
			cout << "-> Book status updated successfully :)\n";
		}
		else {
			cout << "-> Book not found in your collection :(\n";
		}

		cout << "Press any Key for back ...";
		system("pause>0");
	}


	static void ShowRemoveBookFromCollectionByIDScreen() {
		system("cls");
		cout << "=================================" << endl;
		cout << "     Remove Book From Collection " << endl;
		cout << "=================================" << endl << endl;

		int id = inputs::readIntNumber("Enter Book ID to remove: ");

		if (DataLayer::DbModel1ForUser::RemoveBookFromCollection(id)) {
			cout << "-> Book removed from your collection successfully :)\n";
		}
		else {
			cout << "-> Book not found in your collection :(\n";
		}

		cout << "Press any Key for back ...";
		system("pause>0");
	}

	static void ShowPrintCollectionScreen() {
		system("cls");
		cout << "=================================" << endl;
		cout << "       Your Book Collection      " << endl;
		cout << "=================================" << endl << endl;

		
		if(!global::PersonalCollectionIsCreated) {
			cout << "-> You don't have a collection :(\n";
		}
		else if (DataLayer::DbModel1ForUser::GetPersonalCollection().size() == 0) {
			cout << "-> Your collection is empty :(\n";
		}
		else {
			cout << left
				<< setw(6) << "ID"
				<< "| " << setw(20) << "Name"
				<< "| " << setw(15) << "Author"
				<< "| " << setw(15) << "Category"
				<< "| " << setw(6) << "Year"
				<< "| " << setw(6) << "Pages"
				<< "| " << setw(10) << "Status"
				<< endl;
			cout << string(100, '-') << endl;

			for (int i = 0; i < DataLayer::DbModel1ForUser::GetPersonalCollection().size(); i++) {
				clsBook b = DataLayer::DbModel1ForUser::GetPersonalCollection().getItemByIndex(i);
				cout << left
					<< setw(6) << b.ID
					<< "| " << setw(20) << b.Name
					<< "| " << setw(15) << b.Author
					<< "| " << setw(15) << b.Category
					<< "| " << setw(6) << b.PublishYear
					<< "| " << setw(6) << b.PageCount
					<< "| " << setw(10) << (b.isReaded ? "Read" : "Unread")
					<< endl;
			}
			cout << string(100, '-') << endl;
		}

		cout << "\nPress any Key for back ...";
		system("pause>0");
	}
};

