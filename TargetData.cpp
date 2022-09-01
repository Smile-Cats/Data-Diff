#include "TargetData.h"

void TargetData::set_data(string column_name, int value)
{
	if (column_name == "column_1")
	{
		this->column_1 = value;
	}
	else if (column_name == "column_3")
	{
		this->column_3 = value;
	}
}

void TargetData::set_data(string column_name, double value)
{
	this->column_4 = value;
}

void TargetData::set_data(string column_name, string value)
{
	this->column_2 = value;
}

map<string, string> TargetData::equal(TargetData &data)
{
	map<string, string> result;

	result.insert(pair<string, string>("key_column_2", this->column_2));
	if (this->column_1 == data.column_1)
	{
		result.insert(pair<string, string>("column_1", ""));
	}
	else
	{
		result.insert(pair<string, string>("column_1", to_string(this->column_1) + "/" + to_string(data.column_1)));
	}

	if (this->column_2 == data.column_2)
	{
		result.insert(pair<string, string>("column_2", ""));
	}
	else
	{
		result.insert(pair<string, string>("column_2", this->column_2 + "/" + data.column_2));
	}

	if (this->column_3 == data.column_3)
	{
		result.insert(pair<string, string>("column_3", ""));
	}
	else
	{
		result.insert(pair<string, string>("column_3", to_string(this->column_3) + "/" + to_string(data.column_3)));
	}

	if ((this->column_4==data.column_4))
	{
		//cout << this->column_4 << "  " << data.column_4 << endl;
		result.insert(pair<string, string>("column_4", ""));
	}
	else
	{
		result.insert(pair<string, string>("column_4", to_string(this->column_4) + "/" + to_string(data.column_4)));
	}

	return result;
}