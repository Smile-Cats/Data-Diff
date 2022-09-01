#include "DataFormat.h"

DataFormat::DataFormat(map<string, vector<string>> data)
{
	this->data = data; // 导入原数据
	map<string, vector<string>>::iterator pos = data.begin();
	TargetData td;
	this->result.resize(pos->second.size(), td); // 初始化结果vector的容量
}

DataFormat::DataFormat() {}

void DataFormat::define_column_type(string column_name, string type_name)
{
	this->column_type.insert(pair<string, string>(column_name, type_name));
}

void DataFormat::format()
{
	for (map<string, string>::iterator it = column_type.begin(); it != column_type.end(); it++)
	{
		//cout << it->first << "  " << it->second << endl;
		string column_name = it->first;
		string column_type = it->second;
		vector<string> orgin_col_value;

		map<string, vector<string>>::iterator pos = data.find(column_name);
		if (pos != data.end())
		{
			orgin_col_value = pos->second;

			if (column_type == "int")
			{
				vector<int> col_value;
				this->util.call_func(orgin_col_value, col_value);
				int index = 0;
				for (vector<int>::iterator it = col_value.begin(); it != col_value.end(); it++)
				{
					this->result[index].set_data(column_name, *it);
					index++;
				}
			}
			else if (column_type == "double")
			{
				vector<double> col_value;
				this->util.call_func(orgin_col_value, col_value);
				int index = 0;
				for (vector<double>::iterator it = col_value.begin(); it != col_value.end(); it++)
				{
					this->result[index].set_data(column_name, *it);
					index++;
				}
			}
			else
			{
				vector<string> col_value;
				this->util.call_func(orgin_col_value, col_value);
				int index = 0;
				for (vector<string>::iterator it = col_value.begin(); it != col_value.end(); it++)
				{
					this->result[index].set_data(column_name, *it);
					index++;
				}
			}
		}	
	}
	/*
	for (vector<TargetData>::iterator it = result.begin(); it != result.end(); it++)
	{
		
		cout << "column_1: " << it->column_1 << " column_2: " << it->column_2
			<< " column_3: " << it->column_3 << " column_4: " << it->column_4 << endl;
	}
	*/
}
