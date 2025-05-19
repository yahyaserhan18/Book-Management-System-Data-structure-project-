#pragma once
#include <iostream>
#include "global.h";
#include "UserModels.h";

class MapFunctionsInUserScreen
{
private:

public:

	static void Start(global::Models choice) {

		switch (choice)
		{
		case global::Models::model1:
			UserModels::clsModel1::Start();
			break;
		case global::Models::model2:
			UserModels::clsModel2::Start();
			break;
		case global::Models::model3:
			UserModels::clsModel3::Start();
			break;
		case global::Models::model4:
			UserModels::clsModel4::Start();
			break;
		case global::Models::model5:
			UserModels::clsModel5::Start();
			break;
		case global::Models::exit:
			global::isGoBackFromUserToMain = true;
			break;
		default:
			break;
		}
	}

};

