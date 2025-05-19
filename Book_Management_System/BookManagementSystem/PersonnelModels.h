#pragma once
#include <iostream>
#include "inputs.h";
#include "DataLayer.h";
#include "PrModel1.h";
#include "PrModel2.h";
#include "PrModel3.h"
#include "PrModel4.h"
#include "PrModel5.h"

namespace PersonnelModels {

	class clsModel1 {
	private:
		static void _ShowModle1Screen() {
			cout << "+-----------------------------------------------+" << endl;
			cout << "|           Personnel Menu - Module 1           |" << endl;
			cout << "+-----------------------------------------------+" << endl;
			cout << "| 1)  Add Book                                  |" << endl;
			cout << "| 2)  Edit Book by Name                         |" << endl;
			cout << "| 3)  Delete Book by ID                         |" << endl;
			cout << "| 4)  List Books with Timestamp                 |" << endl;
			cout << "| 5)  Search Book by ID                         |" << endl;
			cout << "| 6)  Show Total Book Count                     |" << endl;
			cout << "| 7)  Sort Books by Page Count                  |" << endl;
			cout << "| 8)  Show Oldest 5 Books                       |" << endl;
			cout << "| 9)  Add Damage Note to Book                   |" << endl;
			cout << "| 10) Print Damaged Books                       |" << endl;
			cout << "| 11) Exit                                      |" << endl;
			cout << "+-----------------------------------------------+" << endl;

		}

		static void _MapFunctions(global::PersonnelModel1Options choice) {
			switch (choice)
			{
			case global::PersonnelModel1Options::AddBook:
				PrModel1::ShowAddBookScreen();
				Start();
				break;
			case global::PersonnelModel1Options::EditBookByName:
				PrModel1::ShowEditBookByNameScreen();
				Start();
				break;
			case global::PersonnelModel1Options::DeleteBookById:
				PrModel1::ShowDeleteBookByIdScreen();
				Start();
				break;
			case global::PersonnelModel1Options::ListBooksWithTimestamp:
				PrModel1::ShowListBooksWithTimestampScreen();
				Start();
				break;
			case global::PersonnelModel1Options::SearchBookById:
				PrModel1::ShowSearchBookByIdScreen();
				Start();
				break;
			case global::PersonnelModel1Options::GetTotalBookCount:
				PrModel1::ShowGetTotalBookCountScreen();
				Start();
				break;
			case global::PersonnelModel1Options::SortBooksByPageCount:
				PrModel1::ShowSortBooksByPageCountScreen();
				Start();
				break;
			case global::PersonnelModel1Options::ShowOldest5Books:
				PrModel1::ShowOldest5BooksScreen();
				Start();
				break;
			case global::PersonnelModel1Options::AddDamageNote:
				PrModel1::ShowAddDamageNoteScreen();
				Start();
				break;
			case global::PersonnelModel1Options::PrintDamagedBooks:
				PrModel1::ShowListDamagedBooksScreen();
				Start();
				break;
			case global::PersonnelModel1Options::Exit:
				break;
			default:
				break;
			}
		}

	public:

		static void Start() {
			system("cls");
			_ShowModle1Screen();

			int x = inputs::readNumberInRange(1, 11, "Choose a Function Between [1,11] : ");

			global::PersonnelModel1Options choice = (global::PersonnelModel1Options)x;

			_MapFunctions(choice);

		}
	};

	class clsModel2 {
	private:
		static void _ShowModle2Screen() {
			cout << "+------------------------------------------------------------+" << endl;
			cout << "|    Personnel Menu - Module 2 (Singly Circular Linked List) |" << endl;
			cout << "+------------------------------------------------------------+" << endl;
			cout << "| 1) Generate Borrowed Book Report                           |" << endl;
			cout << "| 2) Generate Returned Book Report                           |" << endl;
			cout << "| 3) List Available Books                                    |" << endl;
			cout << "| 4) Exit                                                    |" << endl;
			cout << "+------------------------------------------------------------+" << endl;

		}

		static void _MapFunctions(global::PersonnelModel2Options choice) {

			switch (choice)
			{
			case global::PersonnelModel2Options::ReportBorrowedBooks:
				PrModel2::ShowGenerateBorrowedBokkReport();
				Start();
				break;
			case global::PersonnelModel2Options::ReportReturnedBooks:
				PrModel2::ShowGenerateReturnedBookReport();
				Start();
				break;
			case global::PersonnelModel2Options::ListAvailableBooks:
				PrModel2::ShowListAvailableBooks();
				Start();
				break;
			case global::PersonnelModel2Options::Exit:
				break;
			default:
				break;
			}
		}

	public:
		static void Start() {
			system("cls");
			_ShowModle2Screen();

			int x = inputs::readNumberInRange(1, 4, "Choose a Function Between [1,4] : ");

			global::PersonnelModel2Options choice = (global::PersonnelModel2Options)x;

			_MapFunctions(choice);
		}
	};

	class clsModel3 {
	private:
		static void _ShowModle3Screen() {
			cout << "+-----------------------------------------------------+" << endl;
			cout << "|     Personnel Menu - Module 3 (Queue)               |" << endl;
			cout << "+-----------------------------------------------------+" << endl;
			cout << "| 1) Add Supplied Book from Request Queue             |" << endl;
			cout << "| 2) Exit                                             |" << endl;
			cout << "+-----------------------------------------------------+" << endl;

		}

		static void _MapFunctions(global::PersonnelModel3Options choice) {
			
			switch (choice)
			{
			case global::PersonnelModel3Options::AddSuppliedBook:
				PrModel3::ShowAddSuppliedBookScreen();
				Start();
				break;
			case global::PersonnelModel3Options::Exit:
				break;
			default:
				break;
			}
		}

	public:
		static void Start() {
			system("cls");
			_ShowModle3Screen();

			int x = inputs::readNumberInRange(1, 2, "Choose a Function Between [1,2] : ");

			global::PersonnelModel3Options choice = (global::PersonnelModel3Options)x;

			_MapFunctions(choice);
		}
	};

	class clsModel4 {
	private:
		static void _ShowModle4Screen() {
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "|        Personnel Menu - Module 4 (Tree Structure)           |" << endl;
			cout << "+-------------------------------------------------------------+" << endl;
			cout << "| 1) Analyze Borrow Duration (< / > 30 days)                  |" << endl;
			cout << "| 2) Filter by Publish Year (before/after 1950)               |" << endl;
			cout << "| 3) Books Before 1950 & Borrow Duration > 30 Days            |" << endl;
			cout << "| 4) Exit                                                     |" << endl;
			cout << "+-------------------------------------------------------------+" << endl;

		}

		static void _MapFunctions(global::PersonnelModel4Options choice) {
			
			switch (choice)
			{
			case global::PersonnelModel4Options::AnalyzeBorrowDuration:
				PrModel4::ShowAnalyzeBorrowDurationScreen();
				Start();
				break;
			case global::PersonnelModel4Options::FilterByPublishYear:
				PrModel4::ShowFilterByPublishYearScreen();
				Start();
				break;
			case global::PersonnelModel4Options::FilterOldBooksLongBorrow:
				PrModel4::ShowFilterOldBooksLongBorrowScreen();
				Start();
				break;
			case global::PersonnelModel4Options::Exit:
				break;
			default:
				break;
			}
		}

	public:
		static void Start() {
			system("cls");
			_ShowModle4Screen();

			int x = inputs::readNumberInRange(1, 4, "Choose a Function Between [1,4] : ");

			global::PersonnelModel4Options choice = (global::PersonnelModel4Options)x;

			_MapFunctions(choice);
		}
	};

	class clsModel5 {
	private:
		static void _ShowModle5Screen() {
			cout << "+--------------------------------------------------+" << endl;
			cout << "|       Personnel Menu - Module 5 (Hash Table)     |" << endl;
			cout << "+--------------------------------------------------+" << endl;
			cout << "| 1) Add Ratings for Borrowed Books                |" << endl;
			cout << "|    -> List Books with Average Score >= 4          |" << endl;
			cout << "| 2) Exit                                          |" << endl;
			cout << "+--------------------------------------------------+" << endl;

		}

		static void _MapFunctions(global::PersonnelModel5Options choice) {
			
			switch (choice)
			{
			case global::PersonnelModel5Options::AddRatingsAndList:
				PrModel5::ShowAddRatingsAndListScreen();
				Start();
				break;
			case global::PersonnelModel5Options::Exit:
				break;
			default:
				break;
			}
		}

	public:
		static void Start() {
			system("cls");
			_ShowModle5Screen();

			int x = inputs::readNumberInRange(1, 2, "Choose a Function Between [1,2] : ");

			global::PersonnelModel5Options choice = (global::PersonnelModel5Options)x;

			_MapFunctions(choice);
		}
	};
}