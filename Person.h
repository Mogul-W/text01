#pragma once //防止头文件重复包含
//基类	  人
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


	virtual void show() = 0;	//显示个人信息
	virtual string get_position() = 0;	//获取职位
};
