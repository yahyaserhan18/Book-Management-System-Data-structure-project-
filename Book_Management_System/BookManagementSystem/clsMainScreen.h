#pragma once
#include <iostream>
#include "inputs.h";
#include "LoginScreens.h";
using namespace std;


class clsMainScreen
{
private:
	 enum LoginOptions{Personnel=1,User,Exit};
	
	 static void _GoBackToMain() {
		 system("cls");
		 Start();
	 }

	static void _Login(LoginOptions choice) {
		switch (choice)
		{
		case LoginOptions::Personnel:
			LoginScreens::PersonnelScreen();
			_GoBackToMain();
			break;
		case LoginOptions::User:
			LoginScreens::UserScreen();
			_GoBackToMain();
			break;
		case LoginOptions::Exit:
			LoginScreens::ExitScreen();
			break;
		default:
			break;
		}
	}
	static void _ShowScreen() {
		cout << "+----------------------------------------+"<<endl;
		cout << "|              Main Screen               |"<<endl;
		cout << "+----------------------------------------+"<<endl;
		cout << "|1. Personnel Login                      |"<<endl;
		cout << "|2. User Login                           |"<<endl;
		cout << "|3. Exit                                 |"<<endl;
		cout << "+----------------------------------------+"<<endl;

		int x = inputs::readNumberInRange(1, 3, "Choose Between [1,3] To Login : ");

		LoginOptions choice = (LoginOptions)x;

		_Login(choice);

	}

public :


	static void Start() {
		_ShowScreen();
	}
};

