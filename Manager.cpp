#include"manager.h"

Manager::Manager(int id, string name, string position,float age, float height, float weight)
{
	this->id = id;
	this->name = name;
	this->position = position;
	this->age = age;
	this->height =height;
	this->weight = weight;
}
void Manager::show() {
	cout << "*****************************************" << endl;
	cout << "* 经理编号：" << this->id <<"\t\t\t\t*" << endl;
	cout << "* 经理姓名：" << this->name << "\t\t\t\t*" << endl;
	cout << "* 岗位：" << this->position << "\t\t\t*" << endl;
	cout << "* 年龄：" << this->age << "岁\t\t\t\t*" << endl;
	cout << "* 身高：" << this->height << "厘米\t\t\t\t*" << endl;
	cout << "* 体重：" << this->weight << "斤\t\t\t\t*" << endl;
	cout << "*****************************************" << endl;
}
string Manager::get_position() {
	return this->position;
}
//子类特有的方法
void Manager::assign() {
	cout << this->name << "策划工作计划，指派给员工执行。" << endl;
}