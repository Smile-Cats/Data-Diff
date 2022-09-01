#pragma once
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <iostream>
#include<sstream>

#include "TargetData.h"

using namespace std;

// 读取数据类
class DataLoader
{
public:

	DataLoader();

	DataLoader(string file_path);

	void Load();

	map<string, vector<string>> data;

	string file_path;

	
};

