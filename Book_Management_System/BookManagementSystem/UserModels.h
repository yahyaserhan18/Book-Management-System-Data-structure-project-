#pragma once
#include <iostream>;
#include "inputs.h";
#include "userModel1.h"
#include "userModel2.h"
#include "userModel3.h"
#include "userModel4.h"
#include "userModel5.h"

namespace UserModels {

	class clsModel1 {
	private:
		static void _ShowModle1Screen() {
			cout << "+--------------------------------------------------------+" << endl;
			cout << "|              User Menu - Module 1                      |" << endl;
			cout << "+--------------------------------------------------------+" << endl;
			cout << "| 1) Add Comment to Book by ID                           |" << endl;
			cout << "| 2) List Comments for Book by ID                        |" << endl;
			cout << "| 3) Create Personal Collection                          |" << endl;
			cout << "| 4) Add Book to Collection                              |" << endl;
			cout << "| 5) Mark Book as Read/Unread                            |" << endl;
			cout << "| 6) Remove Book from Collection by ID                   |" << endl;
			cout << "| 7) Print Personal Collection                           |" << endl;
			cout << "| 8) Exit                                                |" << endl;
			cout << "+--------------------------------------------------------+" << endl;

		}
		static void _MapFunctions(global::UserModel1Options choice) {
			switch (choice)
			{
			case global::UserModel1Options::AddCommentToBookByID:
				userModel1::ShowAddCommentToBookByIDScreen();
				Start();
				break;
			case global::UserModel1Options::ListCommentsToBookByID:
				userModel1::ShowListCommentsToBookByIDScreen();
				Start();
				break;
			case global::UserModel1Options::CreateCollection:
				userModel1::ShowCreateCollectionScreen();
				Start();
				break;
			case global::UserModel1Options::AddBookToCollection:
				userModel1::ShowAddBookToCollectionScreen();
				Start();
				break;
			case global::UserModel1Options::MarkReadUnread:
				userModel1::ShowMarkReadUnreadScreen();
				Start();
				break;
			case global::UserModel1Options::RemoveBookFromCollectionByID:
				userModel1::ShowRemoveBookFromCollectionByIDScreen();
				Start();
				break;
			case global::UserModel1Options::PrintCollection:
				userModel1::ShowPrintCollectionScreen();
				Start();
				break;
			case global::UserModel1Options::Exit:
				break;
			default:
				break;
			}
		}

	public:
		static void Start() {
			system("cls");
			_ShowModle1Screen();

			int x = inputs::readNumberInRange(1, 8, "Choose a Function Between [1,8] : ");

			global::UserModel1Options choice = (global::UserModel1Options)x;

			_MapFunctions(choice);
		}
	};

	class clsModel2 {
	private:
		static void _ShowModle2Screen() {
			cout << "+---------------------------------------------+" << endl;
			cout << "|           User Menu - Module 2 (Stack)      |" << endl;
			cout << "+---------------------------------------------+" << endl;
			cout << "| 1) Borrow Book                              |" << endl;
			cout << "| 2) List Borrowed Books                      |" << endl;
			cout << "| 3) Return Borrowed Book                     |" << endl;
			cout << "| 4) List Returned Books                      |" << endl;
			cout << "| 5) Exit                                     |" << endl;
			cout << "+---------------------------------------------+" << endl;

		}
		static void _MapFunctions(global::UserModel2Options choice) {
			switch (choice)
			{
			case global::UserModel2Options::BorrowBook:
				userModel2::ShowBorrowBookScreen();
				Start();
				break;
			case global::UserModel2Options::ListBorrowedBooks:
				userModel2::ShowListBorrowedBooksScreen();
				Start();
				break;
			case global::UserModel2Options::ReturnBook:
				userModel2::ShowReturnBookScreen();
				Start();
				break;
			case global::UserModel2Options::ListReturnedBooks:
				userModel2::ShowListReturnedBooksScreen();
				Start();
				break;
			case global::UserModel2Options::Exit:
				break;
			default:
				break;
			}
		}

	public:
		static void Start() {
			system("cls");
			_ShowModle2Screen();

			int x = inputs::readNumberInRange(1, 5, "Choose a Function Between [1,5] : ");

			global::UserModel2Options choice = (global::UserModel2Options)x;
			_MapFunctions(choice);
		}
	};

	class clsModel3 {
	private:
		static void _ShowModle3Screen() {
			cout << "+--------------------------------------------+" << endl;
			cout << "|          User Menu - Module 3 (Queue)      |" << endl;
			cout << "+--------------------------------------------+" << endl;
			cout << "| 1) Request Book Not in Library             |" << endl;
			cout << "| 2) View Book Requests                      |" << endl;
			cout << "| 3) Academic Request (With Priority)        |" << endl;
			cout << "| 4) Exit                                    |" << endl;
			cout << "+--------------------------------------------+" << endl;

		}
		static void _MapFunctions(global::UserModel3Options choice) {
			switch (choice)
			{
			case global::UserModel3Options::RequestBook:
				userModel3::ShowRequestBookScreen();
				Start();
				break;
			case global::UserModel3Options::ViewRequests:
				userModel3::ShowViewRequestsScreen();
				Start();
				break;
			case global::UserModel3Options::AcademicRequest:
				userModel3::ShowAcademicRequestScreen();
				Start();
				break;
			case global::UserModel3Options::Exit:
				break;
			default:
				break;
			}
		}

	public:
		static void Start() {
			system("cls");
			_ShowModle3Screen();

			int x = inputs::readNumberInRange(1, 4, "Choose a Function Between [1,4] : ");

			global::UserModel3Options choice = (global::UserModel3Options)x;
			_MapFunctions(choice);
		}
	};

	class clsModel4 {
	private:
		static void _ShowModle4Screen() {
			cout << "+----------------------------------------------------------+" << endl;
			cout << "|         User Menu - Module 4 (Tree Filtering)            |" << endl;
			cout << "+----------------------------------------------------------+" << endl;
			cout << "| 1) Filter by Publisher (Local vs. Foreign)               |" << endl;
			cout << "| 2) Filter by Language (English/Turkish)                  |" << endl;
			cout << "| 3) Filter by Page Count (< or > 1000 pages)              |" << endl;
			cout << "| 4) Exit                                                  |" << endl;
			cout << "+----------------------------------------------------------+" << endl;

		}
		static void _MapFunctions(global::UserModel4Options choice) {
			
			switch (choice)
			{
			case global::UserModel4Options::FilterByPublisher:
				userModel4::ShowFilterByPublisherScreen();
				Start();
				break;
			case global::UserModel4Options::FilterByLanguage:
				userModel4::ShowFilterByLanguageScreen();
				Start();
				break;
			case global::UserModel4Options::FilterByPageCount:
				userModel4::ShowFilterByPageCountScreen();
				Start();
				break;
			case global::UserModel4Options::Exit:
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

			global::UserModel4Options choice = (global::UserModel4Options)x;
			_MapFunctions(choice);
		}
	};

	class clsModel5 {
	private:
		static void _ShowModle5Screen() {
			cout << "+------------------------------------------------------+" << endl;
			cout << "|         User Menu - Module 5 (Hash Table)            |" << endl;
			cout << "+------------------------------------------------------+" << endl;
			cout << "| 1) Recommend Similar Books Based on Category         |" << endl;
			cout << "| 2) Rate Borrowed Books (1 to 5) and List Them        |" << endl;
			cout << "| 3) Exit                                              |" << endl;
			cout << "+------------------------------------------------------+" << endl;

		}
		static void _MapFunctions(global::UserModel5Options choice) {

			switch (choice)
			{
			case global::UserModel5Options::RecommendSimilarBooks:
				userModel5::ShowRecommendSimilarBooksScreen();
				Start();
				break;
			case global::UserModel5Options::RateBooksAndList:
				userModel5::ShowRateBooksAndListScreen();
				Start();
				break;
			case global::UserModel5Options::Exit:
				break;
			default:
				break;
			}
		}

	public:
		static void Start() {
			system("cls");
			_ShowModle5Screen();

			int x = inputs::readNumberInRange(1, 3, "Choose a Function Between [1,3] : ");

			global::UserModel5Options choice = (global::UserModel5Options)x;
			_MapFunctions(choice);
		}
	};
}
