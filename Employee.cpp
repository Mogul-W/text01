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
	cout << "* Ա����ţ�" << this->id << "\t\t\t\t*" << endl;
	cout << "* Ա��������" << this->name << "\t\t\t\t*" << endl;
	cout << "* Ա����λ��" << this->position << "\t\t\t*" << endl;
	cout << "* ���䣺" << this->age << "��\t\t\t\t*" << endl;
	cout << "* ��ߣ�" << this->height << "����\t\t\t\t*" << endl;
	cout << "* ���أ�" << this->weight << "��\t\t\t\t*" << endl;
	cout << "*****************************************" << endl;
}
string Employee::get_position() {
	return this->position;
}
//�������еķ���
void Employee::work() {
	cout << this->name << "��ʼ��ˮ..." << endl;
}