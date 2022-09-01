#pragma once
#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

class TargetData
{
public:

	int column_1;

	string column_2;

	int column_3;

	double column_4;

	void set_data(string column_name, int value);

	void set_data(string column_name, double value);

	void set_data(string column_name, string value);

	map<string,string> equal(TargetData &data);
};

