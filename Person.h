#pragma once //��ֹͷ�ļ��ظ�����
//����	  ��
#include<iostream>
using namespace std;
class Person
{
public:
	int id = 0;
	string name;
	string position;
	float age = 0;
	float height = 0;
	float weight = 0;


	virtual void show() = 0;	//��ʾ������Ϣ
	virtual string get_position() = 0;	//��ȡְλ
};
