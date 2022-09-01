#include "DataLoader.h"

DataLoader::DataLoader()
{

}

DataLoader::DataLoader(string file_path)
{
	this->file_path = file_path;
}

// 读取 文件
void DataLoader::Load()
{
	ifstream ifs(this->file_path, ostream::in);
	
	string lineStr;
	vector<vector<string>> strArray;
	// 将csv数据读取到 vector
	while (getline(ifs, lineStr)) {
		//cout << lineStr << endl;
		stringstream ss(lineStr);
		string str;
		vector<string> lineArray;
		while (getline(ss, str, ',')) {
			lineArray.push_back(str);
		}
		strArray.push_back(lineArray);
	}

	vector<vector<string>>::iterator it0 = strArray.begin();
	for (vector<vector<string>>::iterator it = strArray.begin() + 1; it != strArray.end(); it++)
	{
		int index = 0;
		for (vector<string>::iterator it1 = it->begin(); it1 != it->end(); it1++)
		{
			//cout << "key: " << *(it0->begin() + index) << " value: " << *it1 << endl;
			map<string, vector<string>>::iterator pos = this->data.find(*(it0->begin() + index));
			if (pos != this->data.end())
			{
				pos->second.push_back(*it1);
			}
			else
			{
				vector<string> c;
				c.push_back(*it1);
				this->data.insert(pair<string, vector<string>>(*(it0->begin() + index), c));
			}
			
			index++;
		}
	}
}
