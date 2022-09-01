#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Utils
{
public:

	static int to_int(string i);

	static double to_double(string i);

	static string to_str(string i);

	void call_func(vector<string> &col_data, vector<int>& col_data_result);

	void call_func(vector<string>& col_data, vector<double>& col_data_result);

	void call_func(vector<string>& col_data, vector<string>& col_data_result);
};

