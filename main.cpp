#include "DataLoader.h"
#include "DataFormat.h"
#include "Validator.h"

using namespace std;


int main(int argc, char** argv)
{       
	//string base_path = argv[1];
	//string check_path = argv[2];
	string base_path = "D:/target_data.csv";
	string check_path = "D:/target_data2.csv";
	DataLoader loader1(base_path);
	loader1.Load();
        // 读取文件1
	DataLoader loader2(check_path);
	loader2.Load();
        // 定义文件1各列的数据类型
	DataFormat formater(loader1.data);
	formater.define_column_type("column_1", "int");
	formater.define_column_type("column_2", "str");
	formater.define_column_type("column_3", "int");
	formater.define_column_type("column_4", "double");

	formater.format();

	DataFormat formater2(loader2.data);
	formater2.define_column_type("column_1", "int");
	formater2.define_column_type("column_2", "str");
	formater2.define_column_type("column_3", "int");
	formater2.define_column_type("column_4", "double");

	formater2.format();
        // 进行数据对比
	Validator valider(formater.result, formater2.result);
	valider.validate();
	valider.show_result();
	cout << endl << "finish data diff" << endl;
	system("pause");

	return 0;
}
