#pragma once
#pragma once
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include "TargetData.h"

using namespace std;

class Validator
{
public:

	Validator();

	Validator(vector<TargetData> &base_data, vector<TargetData> &check_data);

	void validate();

	void show_result();

	map<string, TargetData> base_data;

	map<string, TargetData> check_data;

	vector<map<string, string>> validate_result;
};

