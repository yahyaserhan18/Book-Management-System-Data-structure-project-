#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include "inputs.h";
#include "global.h";
#include "MapFunctionsInPersonnelScreen.h";
#include "MapFunctionsInUserScreen.h";

using namespace std;


class LoginScreens
{
private:

	static void _ShowPersonnelScreen() {
        cout << "=============================================" << endl;
        cout << "              Personnel Screen               " << endl;
        cout << "=============================================" << endl<<endl;

        cout << "[1] Modele 1 (Singly Linked List)\n";
        cout << "[2] Module 2 (Singly Circular Linked List)\n";
        cout << "[3] Modele 3 (Queue)\n";
        cout << "[4] Modele 4 (Tree)\n";
        cout << "[5] Modele 5 (Hash Table)\n";
        cout << "[6] Exit\n";

        cout << "\n=============================================" << endl;

     
	}

    static void _ShowUserScreen() {
        cout << "=============================================" << endl;
        cout << "               User Screen                   " << endl;
        cout << "=============================================" << endl<<endl;

        cout << "[1] Modele 1 (Doubly Circular Linked List)\n";
        cout << "[2] Module 2 (Stack)\n";
        cout << "[3] Modele 3 (Queue)\n";
        cout << "[4] Modele 4 (Tree)\n";
        cout << "[5] Modele 5 (Hash Table)\n";
        cout << "[6] Exit\n";

        cout << "\n=============================================" << endl;

    }


public:

	static void PersonnelScreen() {
        system("cls");
        _ShowPersonnelScreen();

        int x = inputs::readNumberInRange(1, 6, "Choose a Model Between [1,5] or exit[6] : ");

        global::Models choice = (global::Models)x;

        MapFunctionsInPersonnelScreen::Start(choice);

        if (!global::isGoBackFromPersonnelToMain)
            PersonnelScreen();// if return;

        global::isGoBackFromPersonnelToMain = false;        
	};

	static void UserScreen() {
        system("cls");
        _ShowUserScreen();

        int x = inputs::readNumberInRange(1, 6, "Choose a Model between [1,5] or exit[6] : ");

        global::Models choice = (global::Models)x;

        MapFunctionsInUserScreen::Start(choice);

        if(!global::isGoBackFromUserToMain)
            UserScreen();// if return;

        global::isGoBackFromUserToMain = false;

	};

	static void ExitScreen() {
		 system("cls");
		 cout << "-> Program is End ...";
		 system("Pause>0");
	};
};

