#include "Validator.h"

Validator::Validator()
{

}

Validator::Validator(vector<TargetData> &base_data, vector<TargetData> &check_data)
{
	
	for (vector<TargetData>::iterator it = base_data.begin(); it != base_data.end(); it++)
	{
		//cout << it->column_2 << endl;
		this->base_data.insert(pair<string, TargetData>(it->column_2, *it));
	}
	
	for (vector<TargetData>::iterator it = check_data.begin(); it != check_data.end(); it++)
	{
		this->check_data.insert(pair<string, TargetData>(it->column_2, *it));
	}
	
}

void Validator::validate()
{
	for (map<string, TargetData>::iterator it = base_data.begin(); it != base_data.end(); it++)
	{
		map<string, TargetData>::iterator pos = this->check_data.find(it->first);
		if (pos != check_data.end())
		{
			cout << "validate row: " << it->first << endl << endl;;
			validate_result.push_back(it->second.equal(pos->second)); // validate result
		}
		else
		{
			cout << "check data dont have this column: " << it->first << endl;
		}
	}

	
}

void Validator::show_result()
{
	cout << "show validate result: " << endl << endl;;
	vector<map<string, string>>::iterator it0 = validate_result.begin();

	for (map<string, string>::iterator it3 = it0->begin(); it3 != it0->end(); it3++)
	{
		cout << it3->first << ",";
	}
	cout << endl;

	for (vector<map<string, string>>::iterator it = validate_result.begin(); it != validate_result.end(); it++)
	{
		for (map<string, string>::iterator it2 = it->begin(); it2 != it->end(); it2++)
		{
			cout << it2->second << ",";
		}
		cout << endl;
	}
}