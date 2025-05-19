#pragma once
#include <iostream>
#include "global.h";
#include "PersonnelModels.h";

class MapFunctionsInPersonnelScreen
{
private:

public:
	static void Start(global::Models choice) {
		switch (choice)
		{
		case global::Models::model1:
			PersonnelModels::clsModel1::Start();
			break;
		case global::Models::model2:
			PersonnelModels::clsModel2::Start();
			break;
		case global::Models::model3:
			PersonnelModels::clsModel3::Start();
			break;
		case global::Models::model4:
			PersonnelModels::clsModel4::Start();
			break;
		case global::Models::model5:
			PersonnelModels::clsModel5::Start();
			break;
		case global::Models::exit:
			global::isGoBackFromPersonnelToMain = true;
			break;
		default:
			break;
		}
	}
};

