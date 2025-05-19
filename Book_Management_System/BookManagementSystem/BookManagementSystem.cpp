#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "clsMainScreen.h"
#include "global.h"
bool global::isGoBackFromUserToMain = false;
bool global::isGoBackFromPersonnelToMain = false;
bool global::PersonalCollectionIsCreated  = false;
using namespace std;



int main()
{
	clsMainScreen::Start();
}
