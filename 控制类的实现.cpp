#include"������.h"
#include<iostream>
using namespace std;
Control::Control() {
//1.�ļ�������ʱ
	ifstream ifs;
	ifs.open(FILENAME,ios::in);		//���ļ�
	if (!ifs.is_open()) {
		system("cls");
		cout << "\t***************************************************\t" << endl;
		cout << "\t********************Ա������ϵͳ*******************\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t�ļ������ڣ�	\t\t\t***\t" << endl;
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
		//��ʼ������
		//��ʼ����¼����
		this->num = 0;
		//��ʼ������ָ��
		this->person_Array = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��  �ļ�Ϊ�գ�TRUE
		File_Empty = true;
		ifs.close();
		return;
	}
	//2.�ļ����ڵ�����Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		system("cls");
		cout << "\t***************************************************\t" << endl;
		cout << "\t********************Ա������ϵͳ*******************\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t�ļ�Ϊ�գ�  	\t\t\t***\t" << endl;
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
		//��ʼ����¼����
		this->num = 0;
		//��ʼ������ָ��
		this->person_Array = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��  �ļ�Ϊ�գ�TRUE
		File_Empty = true;
		ifs.close();
		return;
	}
	//3.�ļ�������������
	int num1 = this->get_Empty();
	cout << "ְ������Ϊ��" << num1 << endl;
	this->num = num1;
	//���ٿռ�
	this->person_Array = new Person * [num];
	//���ļ�������ݴ浽�����У�������ʾ
	this->init_Emp();
}
Control::~Control() {
	//�ֶ��ͷſռ�
	if (person_Array != NULL) {
		for (int i = 0; i < num; i++) {		//��ÿ�����󶼸��ͷŸɾ����ٰ���������
			if (person_Array[i]!=NULL)		//ÿ�������ǲ��Ǵ���
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
	cout << "\t********************Ա������ϵͳ*******************\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***\t\t\t1.���\t\t\t***\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***\t\t\t2.��ʾ\t\t\t***\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***\t\t\t3.ɾ��\t\t\t***\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***\t\t\t4.�޸�\t\t\t***\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***\t\t\t5.����\t\t\t***\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***\t\t\t6.��ѯ\t\t\t***\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***\t\t\t7.���\t\t\t***\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***\t\t\t8.ͳ��\t\t\t***\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***\t\t\t0.�˳�\t\t\t***\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***************************************************\t" << endl;
}
void Control::add_Person() {
	//������ӣ�һ�ο�����Ӷ���Ա������Ϣ
	system("cls");
	cout << "\t***************************************************\t" << endl;
	cout << "\t********************Ա������ϵͳ*******************\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***\t\t\t      \t\t\t***\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***\t\t\t      \t\t\t***\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***\t������Ҫ��ӵ�Ա��������\t\t***\t" << endl;
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

	//�ݴ���
	if (add_Num <= 0) {
		system("cls");
		cout << "\t***************************************************\t" << endl;
		cout << "\t********************Ա������ϵͳ*******************\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t����ӵ�Ա�����������0!\t\t***\t" << endl;
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
	//��������Ԫ����ռ�õĿռ�Ĵ�С
	long newSize = 0;
	newSize = this->num + add_Num;
	//�ٴ��� �µ����飬�Ա�����ӵ��µ�Ա��		**ָ��ָ���ָ�룬new����һ��ָ��
	Person ** newSpace = new Person * [newSize];
	//��ԭ�������е�Ա��ת�浽 newSpace ��
	if (this->person_Array != NULL && this->num > 0) {
		//ѭ����������е�ÿ��Ԫ��
		for (int i = 0; i < this->num; i++) {
			newSpace[i] = this->person_Array[i];
		}
	}
	//ѭ�� add_Num �Σ���ʾ�û��������û�����Ϣ������������ŵ� newSpace ������
		for (int i = 0; i < add_Num; i++) {
			int id=0;
			string name="";
			string position="";
			float age=0;
			float height=0;
			float weight=0;

			system("cls");
			cout << "\t***************************************************\t" << endl;
			cout << "\t********************Ա������ϵͳ*******************\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t�������" << (i + 1) << "����Ա������Ϣ����ţ���\t***\t" << endl;
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
			cout << "\t********************Ա������ϵͳ*******************\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t�������" << (i + 1) << "����Ա������Ϣ����������\t***\t" << endl;
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
			cout << "\t********************Ա������ϵͳ*******************\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t�������" << (i + 1) << "����Ա������Ϣ��ְλ����\t***\t" << endl;
			cout << "\t***	 1.��ͨԱ��				***\t" << endl;
			cout << "\t***	 2.���ž���				***\t" << endl;
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

			//�������Ķ�̬�ԣ�ʹ�û��ࣨPerson)�������������ࣨEmployee)��Manager��
			Person* person = NULL;
			if (ch == 1) {
				system("cls");
				cout << "\t***************************************************\t" << endl;
				cout << "\t********************Ա������ϵͳ*******************\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t�������" << (i + 1) << "����Ա������Ϣ�����䣩��\t***\t" << endl;
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
				cout << "\t********************Ա������ϵͳ*******************\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t�������" << (i + 1) << "����Ա������Ϣ����ߣ���\t***\t" << endl;
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
				cout << "\t********************Ա������ϵͳ*******************\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t�������" << (i + 1) << "����Ա������Ϣ�����أ���\t***\t" << endl;
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

				person = new Employee(id, name, "��ͨԱ��",age,height,weight);
			}
			else if (ch == 2) {
				system("cls");
				cout << "\t***************************************************\t" << endl;
				cout << "\t********************Ա������ϵͳ*******************\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t�������" << (i + 1) << "����Ա������Ϣ�����䣩��\t***\t" << endl;
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
				cout << "\t********************Ա������ϵͳ*******************\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t�������" << (i + 1) << "����Ա������Ϣ����ߣ���\t***\t" << endl;
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
				cout << "\t********************Ա������ϵͳ*******************\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t�������" << (i + 1) << "����Ա������Ϣ�����أ���\t***\t" << endl;
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
				person = new Manager(id, name, "���ž���",age,height,weight);
			}
			else {
				system("cls");
				cout << "\t***************************************************\t" << endl;
				cout << "\t********************Ա������ϵͳ*******************\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\tû���������͵�Ա��������������Ч\t***\t" << endl;
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
					i--;		//�ô˴�ѭ����Ч
					continue;
			}
			
			//��ӵ� newSpace ������
			 newSpace[this->num + i] = person;
		}
	//�ͷ�ԭ�� person_Array �Ŀռ�		�ͷŵ���һ������������[]
		delete[]this->person_Array;
	//�� newSpace �ռ����
		this->person_Array = newSpace;
	//�޸�num��ֵ���������µĳ���
		this->num = newSize;
		system("cls");
		cout << "\t***************************************************\t" << endl;
		cout << "\t********************Ա������ϵͳ*******************\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t���" << add_Num << "����Ա���ɹ���\t\t\t***\t" << endl;
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
	ofs.open(FILENAME, ios::out);	//������ķ�ʽ���ļ�--д�ļ�
	//��ÿ���˵�����д���ļ���
	for (int i = 0; i < this->num; i++) {
		ofs << this->person_Array[i]->id << " " 
			<< this->person_Array[i]->name << " " 
			<< this->person_Array[i]->position << " "
			<< this->person_Array[i]->age << " "
			<< this->person_Array[i]->height << " "
			<< this->person_Array[i]->weight << " "
			<< endl;
	}
	//����:�ļ��Ƿ񲻴���  FALSE
	File_Empty = false;
	//�ر��ļ�
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
		//ͳ����������
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
	int index = 0;		//����������±�
	while (ifs >> id && ifs >> name && ifs >> position && ifs >> age && ifs >> height && ifs >> weight) {
		Person* person = NULL;
		if (position == "��ͨԱ��") {
			person = new Employee(id, name, position,age,height,weight);
		}
		else if (position == "���ž���") {
			person = new Manager(id, name, position, age, height, weight);
		}
		this->person_Array [index]= person;
		index++;
	}
	ifs.close();
}
void Control::Show_All() {
	//�ж��ļ��Ƿ�Ϊ��
	if (this->File_Empty) {
		system("cls");
		cout << "\t***************************************************\t" << endl;
		cout << "\t********************Ա������ϵͳ*******************\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t�ļ������ڻ��ļ�Ϊ��\t\t\t***\t" << endl;
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
			//���ö�̬���ó���ӿ�
			Person* person=this->person_Array[i];
			person->show();
			//�������з���
			//typeid(*�������� ����)->����ID
			//JAVA:a instanceof Person
			//	(Person) a;
			if (typeid(*person) == typeid(Employee)) {		//�ж�person�Ƿ���Employee
				//����ת��
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
	int index=-1;		//�����ڷ���-1�����ڵĻ������������е�λ��
	for (int i = 0; i < this->num; i++) {
		if(this->person_Array[i]->id==id){
			index =i;
			break;		//�ҵ����˳�ѭ��
		}
	}
	return index;
}
void Control::Del_Emp() {
	if (this->File_Empty) {
		system("cls");
		cout << "\t***************************************************\t" << endl;
		cout << "\t********************Ա������ϵͳ*******************\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t�ļ������ڻ��ļ�Ϊ��\t\t\t***\t" << endl;
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
	cout << "��������Ҫɾ����ְ���ı�ţ�";
	int id;
	cin >> id;
	int index = this->Is_Exist(id);
	if (index != -1) {		//�ҵ�����
		for (int i = 0; i < num - 1; i++) {
			this->person_Array[i] = this->person_Array[i + 1];		//����ǰ��
		}
		this->num--;	//���������е�����
		this->save();	//���ݸ��µ��ļ���
		system("cls");
		cout << "\t***************************************************\t" << endl;
		cout << "\t********************Ա������ϵͳ*******************\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\tɾ���ɹ���  	\t\t\t***\t" << endl;
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
	cout << "\t********************Ա������ϵͳ*******************\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***\t\t\t      \t\t\t***\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***\t\t\t      \t\t\t***\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***\tɾ��ʧ�ܣ�δ�ҵ���ְ��!\t\t\t***\t" << endl;
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
		cout << "\t********************Ա������ϵͳ*******************\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t�ļ������ڻ��ļ�Ϊ��\t\t\t***\t" << endl;
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
	cout << "��������Ҫ�޸ĵ�ְ���ı�ţ�" << endl;
	int id;
	cin >> id;
	int index = this->Is_Exist(id);
	if (index != -1) {		//�ҵ�����
		
		system("cls");
		cout << "\t***************************************************\t" << endl;
		cout << "\t********************Ա������ϵͳ*******************\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t�ҵ�"<<id<<"��Ա��,ȷ��Ҫ�޸�ô��\t\t***\t" << endl;
		cout << "\t***1.ȷ��				\t***\t" << endl;
		cout << "\t***2.ȡ��      \t\t\t\t\t***\t" << endl;
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
			delete this->person_Array[index];		//�ͷ�ԭ���Ŀռ�
			int newID = 0;
			string newName = "";
			string newPo = "";
			float age = 0;
			float height = 0;
			float weight = 0;
			system("cls");
			cout << "\t***************************************************\t" << endl;
			cout << "\t********************Ա������ϵͳ*******************\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t�������µ�ְ���ţ� \t\t\t***\t" << endl;
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
			cout << "\t********************Ա������ϵͳ*******************\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t�������µ�ְ��������\t\t\t***\t" << endl;
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
			cout << "\t********************Ա������ϵͳ*******************\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t�������µ�ְ��ְ��\t\t\t***\t" << endl;
			cout << "\t***1.��ͨԱ��			\t\t***\t" << endl;
			cout << "\t***2.���ž���\t\t\t\t\t***\t" << endl;
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
				cout << "\t********************Ա������ϵͳ*******************\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t�������µ�ְ�����䣺\t\t\t***\t" << endl;
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
				cout << "\t********************Ա������ϵͳ*******************\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t�������µ�ְ����ߣ�\t\t\t***\t" << endl;
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
				cout << "\t********************Ա������ϵͳ*******************\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t�������µ�ְ�����أ�\t\t\t***\t" << endl;
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
				this->person_Array[index] = new Employee(newID, newName, "��ͨԱ��",age,height,weight);
				this->save();	//���µ��ļ���
			}
			else if (ch == 2) {
				system("cls");
				cout << "\t***************************************************\t" << endl;
				cout << "\t********************Ա������ϵͳ*******************\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t�������µ�ְ�����䣺\t\t\t***\t" << endl;
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
				cout << "\t********************Ա������ϵͳ*******************\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t�������µ�ְ����ߣ�\t\t\t***\t" << endl;
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
				cout << "\t********************Ա������ϵͳ*******************\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t�������µ�ְ�����أ�\t\t\t***\t" << endl;
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
				this->person_Array[index] = new Employee(newID, newName, "���ž���", age, height, weight);
				this->save();
			}
			else {
				system("cls");
				cout << "\t***************************************************\t" << endl;
				cout << "\t********************Ա������ϵͳ*******************\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\t\t\t      \t\t\t***\t" << endl;
				cout << "\t***						***\t" << endl;
				cout << "\t***\tû���������͵�Ա��������������Ч\t***\t" << endl;
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
			cout << "\t********************Ա������ϵͳ*******************\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t�޸ĳɹ���  	\t\t\t***\t" << endl;
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
			cout << "\t********************Ա������ϵͳ*******************\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t�����������������\t\t\t***\t" << endl;
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
		cout << "\t********************Ա������ϵͳ*******************\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t�޸ĳɹ���  	\t\t\t***\t" << endl;
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
		cout << "\t********************Ա������ϵͳ*******************\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t�޸�ʧ�ܣ�δ�ҵ���ְ��!\t\t\t***\t" << endl;
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
		cout << "\t********************Ա������ϵͳ*******************\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t�ļ������ڻ��ļ�Ϊ��\t\t\t***\t" << endl;
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
	cout << "\t********************Ա������ϵͳ*******************\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***\t\t\t      \t\t\t***\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***\t\t\t      \t\t\t***\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***\t��������ҵķ�ʽ:   \t\t\t***\t" << endl;
	cout << "\t***1.��Ų���			\t\t***\t" << endl;
	cout << "\t***2.��������\t\t\t\t\t***\t" << endl;
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
		cout << "\t********************Ա������ϵͳ*******************\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t������ְ����ţ�    \t\t\t***\t" << endl;
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
			cout << "\t********************Ա������ϵͳ*******************\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t����ʧ�ܣ����޴��ˣ�\t\t\t***\t" << endl;
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
		cout << "��ѯ����\n���Ϊ " << this->person_Array[ret]->id << endl;
		cout << "����Ϊ " << this->person_Array[ret]->name << endl;
		cout << "ְλΪ " << this->person_Array[ret]->position << endl;
		cout << "����Ϊ " << this->person_Array[ret]->age << endl;
		cout << "���Ϊ " << this->person_Array[ret]->height << endl;
		cout << "����Ϊ " << this->person_Array[ret]->weight << endl;
		system("pause");
	}
	else if (ch == 2) {
		system("cls");
		cout << "\t***************************************************\t" << endl;
		cout << "\t********************Ա������ϵͳ*******************\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t������ְ��������    \t\t\t***\t" << endl;
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
				cout << "���ҵ���" << endl;
				cout << "���Ϊ��" << this->person_Array[i]->id << endl;
				cout <<"����Ϊ��"<< this->person_Array[i]->name << endl;
				cout << "ְλΪ��" << this->person_Array[i]->position << endl;
				cout << "����Ϊ " << this->person_Array[i]->age << endl;
				cout << "���Ϊ " << this->person_Array[i]->height << endl;
				cout << "����Ϊ " << this->person_Array[i]->weight << endl;
				system("pause");
				break;
			}
			system("cls");
			cout << "\t***************************************************\t" << endl;
			cout << "\t********************Ա������ϵͳ*******************\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t����ʧ�ܣ����޴��ˣ�\t\t\t***\t" << endl;
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
		cout << "\t********************Ա������ϵͳ*******************\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t�ļ������ڻ��ļ�Ϊ��\t\t\t***\t" << endl;
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
	cout << "\t********************Ա������ϵͳ*******************\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***\t\t\t      \t\t\t***\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***\t\t\t      \t\t\t***\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***\t����������ķ�ʽ:   \t\t\t***\t" << endl;
	cout << "\t***1.��ְ��������		\t\t***\t" << endl;
	cout << "\t***2.��ְ���Ž���\t\t\t\t***\t" << endl;
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
			int MinOrMax = i;		//���ֵ������Сֵ���±꣬����ֻ���ⶩ��
			for (int j = i + 1; j < this->num; j++) {
				if (ch != 1 && ch != 2) {
					system("cls");
					cout << "\t***************************************************\t" << endl;
					cout << "\t********************Ա������ϵͳ*******************\t" << endl;
					cout << "\t***						***\t" << endl;
					cout << "\t***\t\t\t      \t\t\t***\t" << endl;
					cout << "\t***						***\t" << endl;
					cout << "\t***\t\t\t      \t\t\t***\t" << endl;
					cout << "\t***						***\t" << endl;
					cout << "\t***\t�����������������!  \t\t\t***\t" << endl;
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
				else if (ch == 1) {		//����
					if (person_Array[MinOrMax]->id > person_Array[j]->id) {
						MinOrMax = j;	//��ʱ����Сֵ���±�
					}
				}
				else if(ch==2){
					if (person_Array[MinOrMax]->id < person_Array[j]->id) {
						MinOrMax = j;	//��ʱ�����ֵ���±�
					}
				}
				if (i != MinOrMax) {		//������������
					Person* p;
					p = this->person_Array[i];
					person_Array[i] = person_Array[MinOrMax];
					person_Array[MinOrMax] = p;
				
				}
			}
		}
		cout << "����ɹ�" << endl;
		system("cls");
		this->save();
		this->Show_All();
}
void Control::Clean() {
	system("cls");
	cout << "\t***************************************************\t" << endl;
	cout << "\t********************Ա������ϵͳ*******************\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***\t\t\t      \t\t\t***\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***\t\t\t      \t\t\t***\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***\t��ȷ��Ҫ����ļ�ô��   \t\t\t***\t" << endl;
	cout << "\t***1.ȷ��        		\t\t***\t" << endl;
	cout << "\t***2.ȡ��        \t\t\t\t***\t" << endl;
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
		cout << "\t********************Ա������ϵͳ*******************\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t�����������������!  \t\t\t***\t" << endl;
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
		//��ģʽ�� ios
		ofstream ofs(FILENAME, ios::trunc);	//ɾ���ļ������´���
		ofs.close();
		if (this->person_Array != NULL) {
			for (int i = 0; i < num; i++) {		//ɾ��ÿ������
				if (person_Array!=NULL) {
					delete person_Array[i]; 
					person_Array[i] = NULL;
				}
			}
			delete[] person_Array;			//ɾ�����飬����ָ�룬�������num�������ļ��Ƿ���ڵı�־
			person_Array = NULL;
			num = 0;
			this->File_Empty = true;
		}
		cout << "��ճɹ���";
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
		cout << "\t********************Ա������ϵͳ*******************\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t�����������˺������룺  \t\t***\t" << endl;
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
		cout << "�˺ţ�";
		cin >> account;
		cout << "���룺";
		while (1) {
			if ((input = _getch()) != '\r') {		//	\r�����з������ǽ�������
				if (input != '\b') {				//	\b�����˸�
					*(password + i++) = input;		//ͨ��ָ������鸳ֵ
					cout << "*";					//����*��
					fflush(stdin);
					flag++;
				}
				if (input == '\b' && flag != 0) {	//Ϊ�˲���\b \bɾ������������ǰ����ʾ���֣����룺��
					flag--;							//����û���Ҫbackspace����ôflag�Լ�
					i--;							//ʹָ��ǰ��
					cout << "\b \b";
				}
			}
			else {
				*(password + i) = '\0';				//�ַ���ĩβ�ĵ�0������
				fflush(stdin);
				cout << endl;
				break;
			}
		}
		if (account == Account && password == Password) {
			system("cls");
			cout << "\t***************************************************\t" << endl;
			cout << "\t********************Ա������ϵͳ*******************\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t\t\t      \t\t\t***\t" << endl;
			cout << "\t***						***\t" << endl;
			cout << "\t***\t��¼�ɹ���                       \t***\t" << endl;
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
		cout << "\t********************Ա������ϵͳ*******************\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t�˺Ż����������������������!  \t***\t" << endl;
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
		cout << "\t********************Ա������ϵͳ*******************\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t\t\t      \t\t\t***\t" << endl;
		cout << "\t***						***\t" << endl;
		cout << "\t***\t�ļ������ڻ��ļ�Ϊ��\t\t\t***\t" << endl;
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
	int Max1=0,Min1=0,Max2=0,Min2=0,Max3=0,Min3=0;			//���ֵ����Сֵ���±�

	for (int i = 0; i < this->num; i++) {	//ƽ�����䣬��ߣ�����
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
	cout << "ͳ�ƽ����ϣ�" << endl;
	cout << "ƽ�����䣺" << (S_age / this->num) << endl;
	cout << "ƽ����ߣ�" << (S_height / this->num) << endl;
	cout << "ƽ�����أ�" << (S_weight / this->num) << endl;
	cout << "��������ߣ�" << this->person_Array[Max1]->id << " " << this->person_Array[Max1]->name << " " << this->person_Array[Max1]->position << " " << this->person_Array[Max1]->age << " " << this->person_Array[Max1]->height << " " << this->person_Array[Max1]->weight << endl;
	cout << "��������ߣ�" << this->person_Array[Min1]->id << " " << this->person_Array[Min1]->name << " " << this->person_Array[Min1]->position << " " << this->person_Array[Min1]->age << " " << this->person_Array[Min1]->height << " " << this->person_Array[Min1]->weight << endl;
	cout << "�������ߣ�" << this->person_Array[Max2]->id << " " << this->person_Array[Max2]->name << " " << this->person_Array[Max2]->position << " " << this->person_Array[Max2]->age << " " << this->person_Array[Max2]->height << " " << this->person_Array[Max2]->weight << endl;
	cout << "�������ߣ�" << this->person_Array[Min2]->id << " " << this->person_Array[Min2]->name << " " << this->person_Array[Min2]->position << " " << this->person_Array[Min2]->age << " " << this->person_Array[Min2]->height << " " << this->person_Array[Min2]->weight << endl;
	cout << "��������ߣ�" << this->person_Array[Max3]->id << " " << this->person_Array[Max3]->name << " " << this->person_Array[Max3]->position << " " << this->person_Array[Max3]->age << " " << this->person_Array[Max3]->height << " " << this->person_Array[Max3]->weight << endl;
	cout << "��������ߣ�" << this->person_Array[Min3]->id << " " << this->person_Array[Min3]->name << " " << this->person_Array[Min3]->position << " " << this->person_Array[Min3]->age << " " << this->person_Array[Min3]->height << " " << this->person_Array[Min3]->weight << endl;
	system("pause");
}