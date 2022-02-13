#include"employee.h"
#include<iostream>
using namespace std;
Employee::Employee(int id, string name, string position,float age,float height,float weight)
{
	this->id = id;
	this->name = name;
	this->position = position;
	this->age = age;
	this->height = height;
	this->weight = weight;
}

void Employee::show() {
	cout << "*****************************************" << endl;
	cout << "* 员工编号：" << this->id << "\t\t\t\t*" << endl;
	cout << "* 员工姓名：" << this->name << "\t\t\t\t*" << endl;
	cout << "* 员工岗位：" << this->position << "\t\t\t*" << endl;
	cout << "* 年龄：" << this->age << "岁\t\t\t\t*" << endl;
	cout << "* 身高：" << this->height << "厘米\t\t\t\t*" << endl;
	cout << "* 体重：" << this->weight << "斤\t\t\t\t*" << endl;
	cout << "*****************************************" << endl;
}
string Employee::get_position() {
	return this->position;
}
//子类特有的方法
void Employee::work() {
	cout << this->name << "开始划水..." << endl;
}