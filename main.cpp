#include"������.h"
#include<iostream>
using namespace std;

int main(void) {

	system("color 3f");		//��ɫ����ɫ
	system("mode con cols=68 lines=30");	//��68����30
	
	bool flag = 1;
	Control con;

	con.set_title("     ***C++ Ա������ϵͳ--��������ļ�Ψ����ͬ������***");		//���ÿ���̨������
	con.Login();	//��¼
	
	int close=0;	//ѡ��

	while (flag) {

		con.Show_Menu();
		cout << "������ѡ�" << endl;
		cin >> close;
		switch (close) {
		case 1:			//��ӳ�Ա���浽�ļ���
			con.add_Person();
			con.save();
			break;
		case 2:			//��ʾ
			con.Show_All();
			break;
		case 3:			//ɾ��
			con.Del_Emp();
			break;
		case 4:			//�޸�
			con.Mod_Emp();
			break;
		case 5:			//����
			con.Sort_Emp();
			break;
		case 6:			//��ѯ
			con.Find_Emp();
			break;
		case 7:			//���
			con.Clean();
			break;
		case 8:			//ͳ��
			con.Sta_Data();
			break;
		case 0:			//�˳�
			flag = 0;
			break;
		default:
			cout << "�����������������!" << endl;
		}
		system("cls");
	}
	cout << "\t***************************************************\t" << endl;
	cout << "\t********************Ա������ϵͳ*******************\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***\t\t\t      \t\t\t***\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***\t\t\t      \t\t\t***\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***\t\t  �˳�����ɹ���       \t\t***\t" << endl;
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
	return 0;
}