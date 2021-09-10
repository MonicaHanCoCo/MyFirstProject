/*
1.界面
2.数据结构设计
3.交互
*/
#include<iostream>
#include"studentlist.h"
using namespace std;
//菜单设计
void menu()
{
	cout << "【学生信息管理系统】" << endl;
	cout << "-------------------" << endl;
	cout << "0.退出系统" << endl;
	cout << "1.录入信息" << endl;
	cout << "2.浏览信息" << endl;
	cout << "3.删除信息" << endl;
	cout << "4.查找信息" << endl;
	cout << "5.修改信息" << endl;
	cout << "-------------------" << endl;
}
struct Node* list = createList();
void insertInfo()
{
	Student data;
	cout << "请输入学生的姓名，学号，性别，年龄，电话:" << endl;
	cin >> data.name >>data.id>> data.sex >> data.age >> data.tel;
	insertNode(list, data);
}
void deleteInfo()
{
	Student data;
	cout << "请输入删除学生的学号:" << endl;
	cin >> data.id;
	deleteNode(list, data);
}
void searchstu()
{
	Student data;
	cout << "请输入要查找的学生学号:" << endl;
	cin >> data.id;
	struct Node* pMove = searchInfo(list, data);
	if (pMove == NULL)
	{
		cout << "未找到相关信息！" << endl;
	}
	else
	{
		cout << "姓名\t学号\t性别\t年龄\t电话" << endl;
		cout << pMove->data.name << "\t" << pMove->data.id << "\t" << pMove->data.sex << "\t" << pMove->data.age << "\t" << pMove->data.tel << endl;
	}
}
void changeInfo()
{
	Student data;
	cout << "请输入要修改学生的学号:" << endl;
	cin >> data.id;
	struct Node* pMove = searchInfo(list, data);
	if (pMove == NULL)
	{
		cout << "未找到相关信息！" << endl;
	}
	else
	{
		cout << "请输入该学生新的信息:"<<endl;
		cin>> pMove->data.name >> pMove->data.id >> pMove->data.sex >> pMove->data.age >>pMove->data.tel ;
		cout<<"修改成功！" << endl;
	}
}
//用户交互
void foruser()
{
	int choice = 0;
	cin >> choice;
	switch (choice) {
	case 0:
		cout << "正常退出" << endl;
		system("pause");
		exit(0);
		break;
	case 1:
		cout << "【录入信息】" << endl;
		insertInfo();//插入信息
		break;
	case 2:
		cout << "【浏览信息】" << endl;
		printList(list);//打印链表
		break;
	case 3:
		cout << "【删除信息】" << endl;
		deleteInfo();//删除信息
		break;
	case 4:
		cout << "【查找信息】" << endl;
		searchstu();//查找信息
		break;
	case 5:
		cout << "【修改信息】" << endl;
		changeInfo();//修改信息
		break;
	default:
		cout << "选择错误，重新输入" << endl;
		system("pause");
		break;
	}
}
int main()
{
	while (1)
	{
		menu();
		foruser();
		system("pause");
		system("cls");
	}
	system("pause");
	return 0;
}