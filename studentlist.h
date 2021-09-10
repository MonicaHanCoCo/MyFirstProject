#pragma once
#include<iostream>
#include<string>
using namespace std;
//�����ѧ����Ϣ����������
typedef struct {
	int id;
	string name;
	int age;
	string sex;
	string tel;
	/*friend ostream& operator<<(ostream &output,const Student &s);*/
	//δʹ����������ض���
}Student;
//������
typedef struct Node {
	Student data;
	struct Node* next;
}Node,*LinkList;
//������
struct Node* createList()
{
	//�ṹ�������ʾ��ͷ
	//��̬�ڴ����룺ָ��--->����
	struct Node* headNode = new Node;
	//��ͷ���컯����
	headNode->next = NULL; 
	return headNode;
}
//�������
struct Node* createNode(Student data)
{
	struct Node* newNode = new Node;
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
//������
void insertNode(struct Node* headNode, Student data)
{
	struct Node* newNode = createNode(data);
	//��ͷ��
	newNode->next = headNode->next;
	headNode->next = newNode;
}
//ָ��λ��ɾ��
void deleteNode(struct Node* headNode,Student posData)
{
	struct Node* posNode = headNode->next;
	struct Node* posFrontNode = headNode;
	if (posNode == NULL)
	{
		cout << "����Ϊ�գ��޷�ɾ����" << endl;
		return;
	}
	while (posNode->data.id != posData.id)
	{
		posFrontNode = posNode;
		posNode = posFrontNode->next;
		if (posNode == NULL)
		{
			cout << "δ�ҵ�ָ��λ�ã��޷�ɾ����" << endl;
			return;
		}
	}
		//�ҵ�ָ��λ��
	posFrontNode->next = posNode->next;
	free(posNode);
}
//���ҹ���
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
////�ļ�������
//void readFromFile(struct Node* headNode, char* filename)
//{
//	//1.��
//	FILE* fp;
//	Student data;
//	fp = fopen(filename, "r");
//	if (fp == NULL)
//	{
//		fopen(filename, "w+");
//	}
//	//2.���ļ�
//	while (fscanf(fp, "%s\t%d\t%s\t%d\t%s", data.name, data.id, data.sex, data.age, data.tel) != EOF)
//	{
//		insertNode(headNode, data);
//	}
//	//3.�ر��ļ�
//	fclose(fp);
//}
////�ļ�д����
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
//��ӡ����
void printList(struct Node* headNode)
{
	struct Node* pMove = headNode->next;
//�漰�����ݵĴ���
	cout << "����\tѧ��\t�Ա�\t����\t�绰" << endl;
	while (pMove)
	{
		cout << pMove->data.name << "\t" <<pMove->data.id<<"\t"<< pMove->data.sex << "\t" << pMove->data.age << "\t" << pMove->data.tel << endl;
		pMove = pMove->next;
	}
	cout << endl;
}


