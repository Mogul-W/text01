#pragma once //��ֹͷ�ļ��ظ�����

#include<iostream>
#include<string>
#include<Windows.h>	//	����̨����
#include<stdlib.h>	//��ɫ
#include<conio.h>	//getch()����
#include<fstream>	//�ļ���д
#define FILENAME "��Ա��.txt"

#include"Person.h"
#include"manager.h"
#include"employee.h"
using namespace std;

//���ڿ��Ƶ��࣬�������ܵĵ���ȫ����
class Control	
{
public:
	Control();
	~Control();
	void Login();		//��¼����
	void Show_Menu();	//չʾ�˵�
	void add_Person();	//��������
	void set_title(LPCSTR lpTitle);	//����̨����
	void save();		//���ļ�
	void Show_All();	//չʾ�����˵���Ϣ
	int get_Empty();	//���ļ�����չʾԱ������
	void init_Emp();	//��ʼ��Ա��
	void Del_Emp();		//�����ɾ��ְ��	�߼�ɾ�������ݸ���
	int Is_Exist(int id);	//�ж�Ա���Ƿ����
	void Mod_Emp();		//�޸�ְ��
	void Find_Emp();	//����Ա��
	void Sort_Emp();	//��Ա������
	void Clean();		//����ļ�
	void Sta_Data();	//ͳ��ƽ�����䣬��ߣ����أ���������

	
	//���ڴ�Ա��������		//��������������ĵ�ַ��**ָ��ָ���ָ��
	Person ** person_Array;
	//��¼������ʵ�ʱ����Ա��������
	int num=0;
	//�ж��ļ��Ƿ�Ϊ�յı�־
	bool File_Empty;

private:

};



