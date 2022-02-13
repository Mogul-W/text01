#pragma once //防止头文件重复包含

#include<iostream>
#include<string>
#include<Windows.h>	//	控制台函数
#include<stdlib.h>	//改色
#include<conio.h>	//getch()函数
#include<fstream>	//文件读写
#define FILENAME "成员表.txt"

#include"Person.h"
#include"manager.h"
#include"employee.h"
using namespace std;

//用于控制的类，整个功能的调用全在这
class Control	
{
public:
	Control();
	~Control();
	void Login();		//登录函数
	void Show_Menu();	//展示菜单
	void add_Person();	//增加新人
	void set_title(LPCSTR lpTitle);	//控制台名字
	void save();		//存文件
	void Show_All();	//展示所有人的信息
	int get_Empty();	//读文件并且展示员工人数
	void init_Emp();	//初始化员工
	void Del_Emp();		//按编号删除职工	逻辑删除：数据覆盖
	int Is_Exist(int id);	//判断员工是否存在
	void Mod_Emp();		//修改职工
	void Find_Emp();	//查找员工
	void Sort_Emp();	//给员工排序
	void Clean();		//清空文件
	void Sta_Data();	//统计平均年龄，身高，体重，最高与最低

	
	//用于存员工的数组		//数组名就是数组的地址，**指向指针的指针
	Person ** person_Array;
	//记录数组中实际保存的员工的数量
	int num=0;
	//判断文件是否为空的标志
	bool File_Empty;

private:

};



