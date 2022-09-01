#pragma once
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include "Utils.h"
#include "TargetData.h"

using namespace std;

class DataFormat
{
public:

	DataFormat();

	DataFormat(map<string, vector<string>> data);

	void format(); // ��������ת��

	void define_column_type(string column_name, string type_name); // ����ÿ������

	map<string, vector<string>> data;  // ԭʼ����

	map<string, string> column_type; // ÿ����������

	Utils util;  // ��������ת���Ĺ���

	vector<TargetData> result;
};

