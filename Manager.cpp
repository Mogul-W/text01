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
	cout << "* �����ţ�" << this->id <<"\t\t\t\t*" << endl;
	cout << "* ����������" << this->name << "\t\t\t\t*" << endl;
	cout << "* ��λ��" << this->position << "\t\t\t*" << endl;
	cout << "* ���䣺" << this->age << "��\t\t\t\t*" << endl;
	cout << "* ��ߣ�" << this->height << "����\t\t\t\t*" << endl;
	cout << "* ���أ�" << this->weight << "��\t\t\t\t*" << endl;
	cout << "*****************************************" << endl;
}
string Manager::get_position() {
	return this->position;
}
//�������еķ���
void Manager::assign() {
	cout << this->name << "�߻������ƻ���ָ�ɸ�Ա��ִ�С�" << endl;
}