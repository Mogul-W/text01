#include"控制类.h"
#include<iostream>
using namespace std;
Control::Control() {
//1.文件不存在时
	ifstream ifs;
	ifs.open(FILENAME,ios::in);		//读文件
	if (!ifs.is_open()) {
		system("cls");
		cout << "\t***************************************************\t" << endl;
		cout << "\t********************员工管理系统*******************\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t文件不存在！	\t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***************************************************\t" << endl;
		system("pause");
		system("cls");
		//初始化属性
		//初始化记录人数
		this->num = 0;
		//初始化数组指针
		this->person_Array = NULL;
		//初始化文件是否为空  文件为空，TRUE
		File_Empty = true;
		ifs.close();
		return;
	}
	//2.文件存在但数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		system("cls");
		cout << "\t***************************************************\t" << endl;
		cout << "\t********************员工管理系统*******************\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t文件为空！  	\t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***************************************************\t" << endl;
		system("pause");
		system("cls");
		//初始化记录人数
		this->num = 0;
		//初始化数组指针
		this->person_Array = NULL;
		//初始化文件是否为空  文件为空，TRUE
		File_Empty = true;
		ifs.close();
		return;
	}
	//3.文件存在且有数据
	int num1 = this->get_Empty();
	cout << "职工人数为：" << num1 << endl;
	this->num = num1;
	//开辟空间
	this->person_Array = new Person * [num];
	//将文件里的数据存到数组中，方便显示
	this->init_Emp();
}
Control::~Control() {
	//手动释放空间
	if (person_Array != NULL) {
		for (int i = 0; i < num; i++) {		//把每个对象都给释放干净，再把数组给清空
			if (person_Array[i]!=NULL)		//每个对象是不是存在
			{
				delete this->person_Array[i];
			}
		}
		delete[]this->person_Array;
		this->person_Array = NULL;
	}

}

void Control::set_title(LPCSTR lpTitle) {
	SetConsoleTitle(lpTitle);
}


void Control::Show_Menu() {

	cout << "\t***************************************************\t" << endl;
	cout << "\t********************员工管理系统*******************\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***\t\t\t1.添加\t\t\t***\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***\t\t\t2.显示\t\t\t***\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***\t\t\t3.删除\t\t\t***\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***\t\t\t4.修改\t\t\t***\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***\t\t\t5.排序\t\t\t***\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***\t\t\t6.查询\t\t\t***\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***\t\t\t7.清空\t\t\t***\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***\t\t\t8.统计\t\t\t***\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***\t\t\t0.退出\t\t\t***\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***************************************************\t" << endl;
}
void Control::add_Person() {
	//批量添加，一次可以添加多条员工的信息
	system("cls");
	cout << "\t***************************************************\t" << endl;
	cout << "\t********************员工管理系统*******************\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***\t\t\t      \t\t\t***\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***\t\t\t      \t\t\t***\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***\t请输入要添加的员工数量：\t\t***\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***\t\t\t      \t\t\t***\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***\t\t\t      \t\t\t***\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***\t\t\t      \t\t\t***\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***\t\t\t      \t\t\t***\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***************************************************\t" << endl;
	int add_Num = 0;
	cin >> add_Num;

	//容错处理
	if (add_Num <= 0) {
		system("cls");
		cout << "\t***************************************************\t" << endl;
		cout << "\t********************员工管理系统*******************\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t待添加的员工数必须大于0!\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***************************************************\t" << endl;
		return;
	}
	//计算待添加元素所占用的空间的大小
	long newSize = 0;
	newSize = this->num + add_Num;
	//再创建 新的数组，以保存添加的新的员工		**指向指针的指针，new返回一个指针
	Person ** newSpace = new Person * [newSize];
	//将原来数组中的员工转存到 newSpace 中
	if (this->person_Array != NULL && this->num > 0) {
		//循环这个数组中的每个元素
		for (int i = 0; i < this->num; i++) {
			newSpace[i] = this->person_Array[i];
		}
	}
	//循环 add_Num 次，提示用户输入新用户的信息，创建对象后存放到 newSpace 数组中
		for (int i = 0; i < add_Num; i++) {
			int id=0;
			string name="";
			string position="";
			float age=0;
			float height=0;
			float weight=0;

			system("cls");
			cout << "\t***************************************************\t" << endl;
			cout << "\t********************员工管理系统*******************\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t请输入第" << (i + 1) << "个新员工的信息（编号）：\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***************************************************\t" << endl;

			cin >> id;

			system("cls");
			cout << "\t***************************************************\t" << endl;
			cout << "\t********************员工管理系统*******************\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t请输入第" << (i + 1) << "个新员工的信息（姓名）：\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***************************************************\t" << endl;

			cin >>name;

			system("cls");
			cout << "\t***************************************************\t" << endl;
			cout << "\t********************员工管理系统*******************\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t请输入第" << (i + 1) << "个新员工的信息（职位）：\t***\t" << endl;
			cout << "\t***	 1.普通员工				***\t" << endl;
			cout << "\t***	 2.部门经理				***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***************************************************\t" << endl;

			int ch;
			cin >> ch;

			//面向对象的多态性：使用基类（Person)来代替具体的子类（Employee)或（Manager）
			Person* person = NULL;
			if (ch == 1) {
				system("cls");
				cout << "\t***************************************************\t" << endl;
				cout << "\t********************员工管理系统*******************\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t请输入第" << (i + 1) << "个新员工的信息（年龄）：\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***************************************************\t" << endl;

				cin >> age;
				system("cls");
				cout << "\t***************************************************\t" << endl;
				cout << "\t********************员工管理系统*******************\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t请输入第" << (i + 1) << "个新员工的信息（身高）：\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***************************************************\t" << endl;

				cin >> height;

				system("cls");
				cout << "\t***************************************************\t" << endl;
				cout << "\t********************员工管理系统*******************\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t请输入第" << (i + 1) << "个新员工的信息（体重）：\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***************************************************\t" << endl;

				cin >> weight;

				person = new Employee(id, name, "普通员工",age,height,weight);
			}
			else if (ch == 2) {
				system("cls");
				cout << "\t***************************************************\t" << endl;
				cout << "\t********************员工管理系统*******************\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t请输入第" << (i + 1) << "个新员工的信息（年龄）：\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***************************************************\t" << endl;

				cin >> age;
				system("cls");
				cout << "\t***************************************************\t" << endl;
				cout << "\t********************员工管理系统*******************\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t请输入第" << (i + 1) << "个新员工的信息（身高）：\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***************************************************\t" << endl;

				cin >> height;

				system("cls");
				cout << "\t***************************************************\t" << endl;
				cout << "\t********************员工管理系统*******************\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t请输入第" << (i + 1) << "个新员工的信息（体重）：\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***************************************************\t" << endl;

				cin >> weight;
				person = new Manager(id, name, "部门经理",age,height,weight);
			}
			else {
				system("cls");
				cout << "\t***************************************************\t" << endl;
				cout << "\t********************员工管理系统*******************\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t没有这种类型的员工，本次输入无效\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***************************************************\t" << endl;
				system("pause");
					i--;		//让此次循环无效
					continue;
			}
			
			//添加到 newSpace 数组中
			 newSpace[this->num + i] = person;
		}
	//释放原来 person_Array 的空间		释放的是一个数组所以用[]
		delete[]this->person_Array;
	//将 newSpace 空间放入
		this->person_Array = newSpace;
	//修改num的值，即数组新的长度
		this->num = newSize;
		system("cls");
		cout << "\t***************************************************\t" << endl;
		cout << "\t********************员工管理系统*******************\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t添加" << add_Num << "个新员工成功。\t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***************************************************\t" << endl;
}
void Control::save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);	//用输出的方式打开文件--写文件
	//将每个人的数据写到文件中
	for (int i = 0; i < this->num; i++) {
		ofs << this->person_Array[i]->id << " " 
			<< this->person_Array[i]->name << " " 
			<< this->person_Array[i]->position << " "
			<< this->person_Array[i]->age << " "
			<< this->person_Array[i]->height << " "
			<< this->person_Array[i]->weight << " "
			<< endl;
	}
	//更新:文件是否不存在  FALSE
	File_Empty = false;
	//关闭文件
	ofs.close();
}
int Control::get_Empty() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	string position;
	float age;
	float height;
	float weight;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> position && ifs >> age && ifs >> height && ifs >> weight) {
		//统计人数变量
		num++;
	}
	return num;
}
void Control::init_Emp() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	string position;
	float age;
	float height;
	float weight;
	int index = 0;		//数组的索引下标
	while (ifs >> id && ifs >> name && ifs >> position && ifs >> age && ifs >> height && ifs >> weight) {
		Person* person = NULL;
		if (position == "普通员工") {
			person = new Employee(id, name, position,age,height,weight);
		}
		else if (position == "部门经理") {
			person = new Manager(id, name, position, age, height, weight);
		}
		this->person_Array [index]= person;
		index++;
	}
	ifs.close();
}
void Control::Show_All() {
	//判断文件是否为空
	if (this->File_Empty) {
		system("cls");
		cout << "\t***************************************************\t" << endl;
		cout << "\t********************员工管理系统*******************\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t文件不存在或文件为空\t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***************************************************\t" << endl;
		system("pause");
		system("cls");
		return;
	}
	system("cls");
		for (int i = 0; i < num; i++) {
			//利用多态调用程序接口
			Person* person=this->person_Array[i];
			person->show();
			//调用特有方法
			//typeid(*对象名或 类名)->类型ID
			//JAVA:a instanceof Person
			//	(Person) a;
			if (typeid(*person) == typeid(Employee)) {		//判断person是否是Employee
				//类型转换
				Employee* e = (Employee*)person;
				e->work();
			}
			else if (typeid(*person) == typeid(Manager)) {
				Manager* m = (Manager*)person;
				m->assign();
			}
		}
	system("pause");
	system("cls");
}
int Control::Is_Exist(int id) {
	int index=-1;		//不存在返回-1，存在的话返回在数组中的位置
	for (int i = 0; i < this->num; i++) {
		if(this->person_Array[i]->id==id){
			index =i;
			break;		//找到后退出循环
		}
	}
	return index;
}
void Control::Del_Emp() {
	if (this->File_Empty) {
		system("cls");
		cout << "\t***************************************************\t" << endl;
		cout << "\t********************员工管理系统*******************\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t文件不存在或文件为空\t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***************************************************\t" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "请输入想要删除的职工的编号：";
	int id;
	cin >> id;
	int index = this->Is_Exist(id);
	if (index != -1) {		//找到人了
		for (int i = 0; i < num - 1; i++) {
			this->person_Array[i] = this->person_Array[i + 1];		//数据前移
		}
		this->num--;	//更新数组中的人数
		this->save();	//数据更新到文件中
		system("cls");
		cout << "\t***************************************************\t" << endl;
		cout << "\t********************员工管理系统*******************\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t删除成功！  	\t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***************************************************\t" << endl;
		system("pause");
		return;
	}
	system("cls");
	cout << "\t***************************************************\t" << endl;
	cout << "\t********************员工管理系统*******************\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***\t\t\t      \t\t\t***\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***\t\t\t      \t\t\t***\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***\t删除失败，未找到该职工!\t\t\t***\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***\t\t\t      \t\t\t***\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***\t\t\t      \t\t\t***\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***\t\t\t      \t\t\t***\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***\t\t\t      \t\t\t***\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***************************************************\t" << endl;
	system("pause");
}
void Control::Mod_Emp() {
	if (this->File_Empty) {
		system("cls");
		cout << "\t***************************************************\t" << endl;
		cout << "\t********************员工管理系统*******************\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t文件不存在或文件为空\t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***************************************************\t" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "请输入想要修改的职工的编号：" << endl;
	int id;
	cin >> id;
	int index = this->Is_Exist(id);
	if (index != -1) {		//找到人了
		
		system("cls");
		cout << "\t***************************************************\t" << endl;
		cout << "\t********************员工管理系统*******************\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t找到"<<id<<"号员工,确认要修改么？\t\t***\t" << endl;
		cout << "\t***1.确认				\t***\t" << endl;
		cout << "\t***2.取消      \t\t\t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***************************************************\t" << endl;
		int choose=0;
		cin >> choose;
		if (choose == 1) 
		{
			delete this->person_Array[index];		//释放原来的空间
			int newID = 0;
			string newName = "";
			string newPo = "";
			float age = 0;
			float height = 0;
			float weight = 0;
			system("cls");
			cout << "\t***************************************************\t" << endl;
			cout << "\t********************员工管理系统*******************\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t请输入新的职工号： \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***************************************************\t" << endl;
			cin >> newID;
			system("cls");
			cout << "\t***************************************************\t" << endl;
			cout << "\t********************员工管理系统*******************\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t请输入新的职工姓名：\t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***************************************************\t" << endl;
			cin >> newName;
			system("cls");
			cout << "\t***************************************************\t" << endl;
			cout << "\t********************员工管理系统*******************\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t请输入新的职工职务：\t\t\t***\t" << endl;
			cout << "\t***1.普通员工			\t\t***\t" << endl;
			cout << "\t***2.部门经理\t\t\t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***************************************************\t" << endl;
			int ch;
			cin >> ch;

			Person* person = NULL;
			if (ch == 1) {
				system("cls");
				cout << "\t***************************************************\t" << endl;
				cout << "\t********************员工管理系统*******************\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t请输入新的职工年龄：\t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***************************************************\t" << endl;
				cin >> age;
				system("cls");
				cout << "\t***************************************************\t" << endl;
				cout << "\t********************员工管理系统*******************\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t请输入新的职工身高：\t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***************************************************\t" << endl;
				cin >> height;
				system("cls");
				cout << "\t***************************************************\t" << endl;
				cout << "\t********************员工管理系统*******************\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t请输入新的职工体重：\t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***************************************************\t" << endl;
				cin >> weight;
				this->person_Array[index] = new Employee(newID, newName, "普通员工",age,height,weight);
				this->save();	//更新到文件中
			}
			else if (ch == 2) {
				system("cls");
				cout << "\t***************************************************\t" << endl;
				cout << "\t********************员工管理系统*******************\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t请输入新的职工年龄：\t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***************************************************\t" << endl;
				cin >> age;
				system("cls");
				cout << "\t***************************************************\t" << endl;
				cout << "\t********************员工管理系统*******************\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t请输入新的职工身高：\t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***************************************************\t" << endl;
				cin >> height;
				system("cls");
				cout << "\t***************************************************\t" << endl;
				cout << "\t********************员工管理系统*******************\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t请输入新的职工体重：\t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***************************************************\t" << endl;
				cin >> weight;
				this->person_Array[index] = new Employee(newID, newName, "部门经理", age, height, weight);
				this->save();
			}
			else {
				system("cls");
				cout << "\t***************************************************\t" << endl;
				cout << "\t********************员工管理系统*******************\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t没有这种类型的员工，本次输入无效\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***************************************************\t" << endl;
				system("pause");
				return;

			}
			system("cls");
			cout << "\t***************************************************\t" << endl;
			cout << "\t********************员工管理系统*******************\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t修改成功！  	\t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***************************************************\t" << endl;
			system("pause");
			return;
		}
		else if (choose == 2) 
		{
			return;
		}
		else 
		{
			system("cls");
			cout << "\t***************************************************\t" << endl;
			cout << "\t********************员工管理系统*******************\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t输入错误，请重新输入\t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***************************************************\t" << endl;
			system("pause");
			system("cls");
			return;
		}
		
		
		system("cls");
		cout << "\t***************************************************\t" << endl;
		cout << "\t********************员工管理系统*******************\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t修改成功！  	\t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***************************************************\t" << endl;
		return;
	}
	else {
		system("cls");
		cout << "\t***************************************************\t" << endl;
		cout << "\t********************员工管理系统*******************\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t修改失败，未找到该职工!\t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***************************************************\t" << endl;
	}
}
void Control::Find_Emp() {
	if (this->File_Empty) {
		system("cls");
		cout << "\t***************************************************\t" << endl;
		cout << "\t********************员工管理系统*******************\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t文件不存在或文件为空\t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***************************************************\t" << endl;
		system("pause");
		system("cls");
		return;
	}
	system("cls");
	cout << "\t***************************************************\t" << endl;
	cout << "\t********************员工管理系统*******************\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***\t\t\t      \t\t\t***\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***\t\t\t      \t\t\t***\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***\t请输入查找的方式:   \t\t\t***\t" << endl;
	cout << "\t***1.编号查找			\t\t***\t" << endl;
	cout << "\t***2.姓名查找\t\t\t\t\t***\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***\t\t\t      \t\t\t***\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***\t\t\t      \t\t\t***\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***\t\t\t      \t\t\t***\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***************************************************\t" << endl;
	int ch;
	cin >> ch;
	if (ch == 1) {
		system("cls");
		cout << "\t***************************************************\t" << endl;
		cout << "\t********************员工管理系统*******************\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t请输入职工编号：    \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***************************************************\t" << endl;
		int id=0;
		cin >> id;
		int ret = this->Is_Exist(id);
		if (ret == -1) {
			system("cls");
			cout << "\t***************************************************\t" << endl;
			cout << "\t********************员工管理系统*******************\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t查找失败，查无此人！\t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***************************************************\t" << endl;
			system("pause");
			return;
		}
		cout << "查询到：\n编号为 " << this->person_Array[ret]->id << endl;
		cout << "姓名为 " << this->person_Array[ret]->name << endl;
		cout << "职位为 " << this->person_Array[ret]->position << endl;
		cout << "年龄为 " << this->person_Array[ret]->age << endl;
		cout << "身高为 " << this->person_Array[ret]->height << endl;
		cout << "体重为 " << this->person_Array[ret]->weight << endl;
		system("pause");
	}
	else if (ch == 2) {
		system("cls");
		cout << "\t***************************************************\t" << endl;
		cout << "\t********************员工管理系统*******************\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t请输入职工姓名：    \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***************************************************\t" << endl;
		string name="";
		cin >> name;
		for (int i = 0; i < this->num;i++) {
			if (name == this->person_Array[i]->name) {
				cout << "查找到：" << endl;
				cout << "编号为：" << this->person_Array[i]->id << endl;
				cout <<"姓名为："<< this->person_Array[i]->name << endl;
				cout << "职位为：" << this->person_Array[i]->position << endl;
				cout << "年龄为 " << this->person_Array[i]->age << endl;
				cout << "身高为 " << this->person_Array[i]->height << endl;
				cout << "体重为 " << this->person_Array[i]->weight << endl;
				system("pause");
				break;
			}
			system("cls");
			cout << "\t***************************************************\t" << endl;
			cout << "\t********************员工管理系统*******************\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t查找失败，查无此人！\t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***************************************************\t" << endl;
		}
	}
}
void Control::Sort_Emp() {
	if (this->File_Empty) {
		system("cls");
		cout << "\t***************************************************\t" << endl;
		cout << "\t********************员工管理系统*******************\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t文件不存在或文件为空\t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***************************************************\t" << endl;
		system("pause");
		system("cls");
		return;
	}
	system("cls");
	cout << "\t***************************************************\t" << endl;
	cout << "\t********************员工管理系统*******************\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***\t\t\t      \t\t\t***\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***\t\t\t      \t\t\t***\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***\t请输入排序的方式:   \t\t\t***\t" << endl;
	cout << "\t***1.按职工号升序		\t\t***\t" << endl;
	cout << "\t***2.按职工号降序\t\t\t\t***\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***\t\t\t      \t\t\t***\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***\t\t\t      \t\t\t***\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***\t\t\t      \t\t\t***\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***************************************************\t" << endl;
	int ch=0;
	cin >> ch;
	
	
		for (int i = 0; i < this->num; i++) {
			int MinOrMax = i;		//最大值或者最小值的下标，现在只是拟订的
			for (int j = i + 1; j < this->num; j++) {
				if (ch != 1 && ch != 2) {
					system("cls");
					cout << "\t***************************************************\t" << endl;
					cout << "\t********************员工管理系统*******************\t" << endl;
					cout << "\t***						***\t" << endl;
					cout << "\t***\t\t\t      \t\t\t***\t" << endl;
					cout << "\t***						***\t" << endl;
					cout << "\t***\t\t\t      \t\t\t***\t" << endl;
					cout << "\t***						***\t" << endl;
					cout << "\t***\t输入错误，请重新输入!  \t\t\t***\t" << endl;
					cout << "\t***						***\t" << endl;
					cout << "\t***\t\t\t      \t\t\t***\t" << endl;
					cout << "\t***						***\t" << endl;
					cout << "\t***\t\t\t      \t\t\t***\t" << endl;
					cout << "\t***						***\t" << endl;
					cout << "\t***\t\t\t      \t\t\t***\t" << endl;
					cout << "\t***						***\t" << endl;
					cout << "\t***\t\t\t      \t\t\t***\t" << endl;
					cout << "\t***						***\t" << endl;
					cout << "\t***************************************************\t" << endl;
					return;
				}
				else if (ch == 1) {		//升序
					if (person_Array[MinOrMax]->id > person_Array[j]->id) {
						MinOrMax = j;	//此时是最小值的下标
					}
				}
				else if(ch==2){
					if (person_Array[MinOrMax]->id < person_Array[j]->id) {
						MinOrMax = j;	//此时是最大值的下标
					}
				}
				if (i != MinOrMax) {		//交换对象数据
					Person* p;
					p = this->person_Array[i];
					person_Array[i] = person_Array[MinOrMax];
					person_Array[MinOrMax] = p;
				
				}
			}
		}
		cout << "排序成功" << endl;
		system("cls");
		this->save();
		this->Show_All();
}
void Control::Clean() {
	system("cls");
	cout << "\t***************************************************\t" << endl;
	cout << "\t********************员工管理系统*******************\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***\t\t\t      \t\t\t***\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***\t\t\t      \t\t\t***\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***\t您确定要清空文件么？   \t\t\t***\t" << endl;
	cout << "\t***1.确认        		\t\t***\t" << endl;
	cout << "\t***2.取消        \t\t\t\t***\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***\t\t\t      \t\t\t***\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***\t\t\t      \t\t\t***\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***\t\t\t      \t\t\t***\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***************************************************\t" << endl;
	int ch=0;
	cin >> ch;
	if (ch != 1 && ch != 2) {
		system("cls");
		cout << "\t***************************************************\t" << endl;
		cout << "\t********************员工管理系统*******************\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t输入错误，请重新输入!  \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***************************************************\t" << endl;
		return;
	}
	else if (ch == 1) {
		//打开模式： ios
		ofstream ofs(FILENAME, ios::trunc);	//删除文件后重新创建
		ofs.close();
		if (this->person_Array != NULL) {
			for (int i = 0; i < num; i++) {		//删除每个对象
				if (person_Array!=NULL) {
					delete person_Array[i]; 
					person_Array[i] = NULL;
				}
			}
			delete[] person_Array;			//删除数组，重置指针，清空人数num，重置文件是否存在的标志
			person_Array = NULL;
			num = 0;
			this->File_Empty = true;
		}
		cout << "清空成功！";
		system("pause");
		system("cls");
	}
	else if (ch == 2) {
		return;
	}
}
void Control::Login() {
	while (1) {
		system("cls");
		cout << "\t***************************************************\t" << endl;
		cout << "\t********************员工管理系统*******************\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t请输入您的账号与密码：  \t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***************************************************\t" << endl;
		string Account = "123";
		char input, password[20]="";
		int i = 0, flag = 0;
		string Password = "abc123";
		string account;
		cout << "账号：";
		cin >> account;
		cout << "密码：";
		while (1) {
			if ((input = _getch()) != '\r') {		//	\r代表换行符，这是结束条件
				if (input != '\b') {				//	\b代表退格
					*(password + i++) = input;		//通过指针给数组赋值
					cout << "*";					//回显*号
					fflush(stdin);
					flag++;
				}
				if (input == '\b' && flag != 0) {	//为了不让\b \b删除掉输入密码前的提示文字（密码：）
					flag--;							//如果用户想要backspace，那么flag自减
					i--;							//使指针前移
					cout << "\b \b";
				}
			}
			else {
				*(password + i) = '\0';				//字符串末尾的的0不能忘
				fflush(stdin);
				cout << endl;
				break;
			}
		}
		if (account == Account && password == Password) {
			system("cls");
			cout << "\t***************************************************\t" << endl;
			cout << "\t********************员工管理系统*******************\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t登录成功！                       \t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***************************************************\t" << endl;
			system("pause");
			system("cls");
			break;
		}
		system("cls");
		cout << "\t***************************************************\t" << endl;
		cout << "\t********************员工管理系统*******************\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t账号或密码输入错误，请重新输入!  \t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***************************************************\t" << endl;
		system("pause");
	}

}
void Control::Sta_Data() {
	if (this->File_Empty) {
		system("cls");
		cout << "\t***************************************************\t" << endl;
		cout << "\t********************员工管理系统*******************\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t文件不存在或文件为空\t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***************************************************\t" << endl;
		system("pause");
		system("cls");
		return;
	}
	float S_age = 0;
	float S_height = 0;
	float S_weight = 0;
	int Max1=0,Min1=0,Max2=0,Min2=0,Max3=0,Min3=0;			//最大值和最小值的下标

	for (int i = 0; i < this->num; i++) {	//平均年龄，身高，体重
		S_age = this->person_Array[i]->age + S_age;
		S_height = this->person_Array[i]->height + S_height;
		S_weight = this->person_Array[i]->weight + S_weight;
		if (this->person_Array[i]->age >=this->person_Array[Max1]->age) {
			Max1 = i;
		}
		if (this->person_Array[i]->age <= this->person_Array[Min1]->age) {
			Min1 = i;
		}
		if (this->person_Array[i]->height >= this->person_Array[Max2]->height) {
			Max2 = i;
		}
		if (this->person_Array[i]->height <= this->person_Array[Min2]->height) {
			Min2 = i;
		}
		if (this->person_Array[i]->weight >= this->person_Array[Max3]->weight) {
			Max3 = i;
		}
		if (this->person_Array[i]->weight <= this->person_Array[Min3]->weight) {
			Min3 = i;
		}
	}
	system("cls");
	cout << "统计结果完毕！" << endl;
	cout << "平均年龄：" << (S_age / this->num) << endl;
	cout << "平均身高：" << (S_height / this->num) << endl;
	cout << "平均体重：" << (S_weight / this->num) << endl;
	cout << "年龄最高者：" << this->person_Array[Max1]->id << " " << this->person_Array[Max1]->name << " " << this->person_Array[Max1]->position << " " << this->person_Array[Max1]->age << " " << this->person_Array[Max1]->height << " " << this->person_Array[Max1]->weight << endl;
	cout << "年龄最低者：" << this->person_Array[Min1]->id << " " << this->person_Array[Min1]->name << " " << this->person_Array[Min1]->position << " " << this->person_Array[Min1]->age << " " << this->person_Array[Min1]->height << " " << this->person_Array[Min1]->weight << endl;
	cout << "身高最高者：" << this->person_Array[Max2]->id << " " << this->person_Array[Max2]->name << " " << this->person_Array[Max2]->position << " " << this->person_Array[Max2]->age << " " << this->person_Array[Max2]->height << " " << this->person_Array[Max2]->weight << endl;
	cout << "身高最低者：" << this->person_Array[Min2]->id << " " << this->person_Array[Min2]->name << " " << this->person_Array[Min2]->position << " " << this->person_Array[Min2]->age << " " << this->person_Array[Min2]->height << " " << this->person_Array[Min2]->weight << endl;
	cout << "体重最高者：" << this->person_Array[Max3]->id << " " << this->person_Array[Max3]->name << " " << this->person_Array[Max3]->position << " " << this->person_Array[Max3]->age << " " << this->person_Array[Max3]->height << " " << this->person_Array[Max3]->weight << endl;
	cout << "体重最低者：" << this->person_Array[Min3]->id << " " << this->person_Array[Min3]->name << " " << this->person_Array[Min3]->position << " " << this->person_Array[Min3]->age << " " << this->person_Array[Min3]->height << " " << this->person_Array[Min3]->weight << endl;
	system("pause");
}