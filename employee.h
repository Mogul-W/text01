//Ա���ࣨ�˵����ࣩ
#include"Person.h"

class Employee:public Person
{
public:
	Employee(int, string, string, float, float, float);
	~Employee();

	void show();
	string get_position();

	void work();	//���еķ���
};
