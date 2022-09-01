#include "Utils.h"

int Utils::to_int(string i)
{
	return atoi(i.c_str());
}

double Utils::to_double(string i)
{
	//atof(i.c_str());
	//cout << i << atof(i.c_str())<< "   " << endl;
	return atof(i.c_str());
}

string Utils::to_str(string i)
{
	return i;
}

void Utils::call_func(vector<string>& col_data, vector<int>& col_data_result)
{
	col_data_result.resize(col_data.size());
	transform(col_data.begin(), col_data.end(), col_data_result.begin(), to_int);
}

void Utils::call_func(vector<string>& col_data, vector<double>& col_data_result)
{
	col_data_result.resize(col_data.size());
	transform(col_data.begin(), col_data.end(), col_data_result.begin(), to_double);
}

void Utils::call_func(vector<string>& col_data, vector<string>& col_data_result)
{
	col_data_result.resize(col_data.size());
	transform(col_data.begin(), col_data.end(), col_data_result.begin(), to_str);
}