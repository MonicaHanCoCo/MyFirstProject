#pragma once
#include<iostream>
#include<string>
using namespace std;
//抽象出学生信息的数据类型
typedef struct {
	int id;
	string name;
	int age;
	string sex;
	string tel;
	/*friend ostream& operator<<(ostream &output,const Student &s);*/
	//未使用输入输出重定向
}Student;
//定义结点
typedef struct Node {
	Student data;
	struct Node* next;
}Node,*LinkList;
//创建表
struct Node* createList()
{
	//结构体变量表示表头
	//动态内存申请：指针--->变量
	struct Node* headNode = new Node;
	//表头差异化处理
	headNode->next = NULL; 
	return headNode;
}
//创建结点
struct Node* createNode(Student data)
{
	struct Node* newNode = new Node;
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
//插入结点
void insertNode(struct Node* headNode, Student data)
{
	struct Node* newNode = createNode(data);
	//表头法
	newNode->next = headNode->next;
	headNode->next = newNode;
}
//指定位置删除
void deleteNode(struct Node* headNode,Student posData)
{
	struct Node* posNode = headNode->next;
	struct Node* posFrontNode = headNode;
	if (posNode == NULL)
	{
		cout << "数据为空，无法删除！" << endl;
		return;
	}
	while (posNode->data.id != posData.id)
	{
		posFrontNode = posNode;
		posNode = posFrontNode->next;
		if (posNode == NULL)
		{
			cout << "未找到指定位置，无法删除！" << endl;
			return;
		}
	}
		//找到指定位置
	posFrontNode->next = posNode->next;
	free(posNode);
}
//查找功能
struct Node* searchInfo(struct Node* headNode, Student posData)
{
	struct Node* pMove = headNode->next;
	if (pMove == NULL)
	{
		return NULL;
	}
	while (pMove->data.id != posData.id)
	{
		pMove = pMove->next;
	}
	return pMove;
}
////文件读操作
//void readFromFile(struct Node* headNode, char* filename)
//{
//	//1.打开
//	FILE* fp;
//	Student data;
//	fp = fopen(filename, "r");
//	if (fp == NULL)
//	{
//		fopen(filename, "w+");
//	}
//	//2.读文件
//	while (fscanf(fp, "%s\t%d\t%s\t%d\t%s", data.name, data.id, data.sex, data.age, data.tel) != EOF)
//	{
//		insertNode(headNode, data);
//	}
//	//3.关闭文件
//	fclose(fp);
//}
////文件写操作
//void writeToFile(struct Node* headNode, char* filename)
//{
//	FILE* fp;
//	fp = fopen(filename, "w");
//	Node* pMove = headNode->next;
//	while (pMove)
//	{
//		fprintf(fp, "%s\t%d\t%s\t%d\t%s", pMove->data.name, pMove->data.id, pMove->data.sex, pMove->data.age, pMove->data.tel);
//		pMove = pMove->next;
//	}
//	fclose(fp);
//}
//打印链表
void printList(struct Node* headNode)
{
	struct Node* pMove = headNode->next;
//涉及到数据的处理
	cout << "姓名\t学号\t性别\t年龄\t电话" << endl;
	while (pMove)
	{
		cout << pMove->data.name << "\t" <<pMove->data.id<<"\t"<< pMove->data.sex << "\t" << pMove->data.age << "\t" << pMove->data.tel << endl;
		pMove = pMove->next;
	}
	cout << endl;
}


