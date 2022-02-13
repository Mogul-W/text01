#include"Person.h"

class Manager :public Person
{
public:
	Manager(int, string, string, float, float, float);
	~Manager();
	void show();
	string get_position();

	void assign();

private:
};
