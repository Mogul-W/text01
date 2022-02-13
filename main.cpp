#include"控制类.h"
#include<iostream>
using namespace std;

int main(void) {

	system("color 3f");		//颜色：蓝色
	system("mode con cols=68 lines=30");	//宽68，长30
	
	bool flag = 1;
	Control con;

	con.set_title("     ***C++ 员工管理系统--由王晓宇，夏嘉唯，高同哲制作***");		//设置控制台的名字
	con.Login();	//登录
	
	int close=0;	//选项

	while (flag) {

		con.Show_Menu();
		cout << "请输入选项：" << endl;
		cin >> close;
		switch (close) {
		case 1:			//添加成员并存到文件里
			con.add_Person();
			con.save();
			break;
		case 2:			//显示
			con.Show_All();
			break;
		case 3:			//删除
			con.Del_Emp();
			break;
		case 4:			//修改
			con.Mod_Emp();
			break;
		case 5:			//排序
			con.Sort_Emp();
			break;
		case 6:			//查询
			con.Find_Emp();
			break;
		case 7:			//清空
			con.Clean();
			break;
		case 8:			//统计
			con.Sta_Data();
			break;
		case 0:			//退出
			flag = 0;
			break;
		default:
			cout << "输入错误，请重新输入!" << endl;
		}
		system("cls");
	}
	cout << "\t***************************************************\t" << endl;
	cout << "\t********************员工管理系统*******************\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***\t\t\t      \t\t\t***\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***\t\t\t      \t\t\t***\t" << endl;
	cout << "\t***						***\t" << endl;
	cout << "\t***\t\t  退出程序成功！       \t\t***\t" << endl;
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