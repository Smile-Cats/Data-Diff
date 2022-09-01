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

	void format(); // 数据类型转换

	void define_column_type(string column_name, string type_name); // 定义每列类型

	map<string, vector<string>> data;  // 原始数据

	map<string, string> column_type; // 每列数据类型

	Utils util;  // 数据类型转换的工具

	vector<TargetData> result;
};

