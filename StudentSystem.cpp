/*
1.����
2.���ݽṹ���
3.����
*/
#include<iostream>
#include"studentlist.h"
using namespace std;
//�˵����
void menu()
{
	cout << "��ѧ����Ϣ����ϵͳ��" << endl;
	cout << "-------------------" << endl;
	cout << "0.�˳�ϵͳ" << endl;
	cout << "1.¼����Ϣ" << endl;
	cout << "2.�����Ϣ" << endl;
	cout << "3.ɾ����Ϣ" << endl;
	cout << "4.������Ϣ" << endl;
	cout << "5.�޸���Ϣ" << endl;
	cout << "-------------------" << endl;
}
struct Node* list = createList();
void insertInfo()
{
	Student data;
	cout << "������ѧ����������ѧ�ţ��Ա����䣬�绰:" << endl;
	cin >> data.name >>data.id>> data.sex >> data.age >> data.tel;
	insertNode(list, data);
}
void deleteInfo()
{
	Student data;
	cout << "������ɾ��ѧ����ѧ��:" << endl;
	cin >> data.id;
	deleteNode(list, data);
}
void searchstu()
{
	Student data;
	cout << "������Ҫ���ҵ�ѧ��ѧ��:" << endl;
	cin >> data.id;
	struct Node* pMove = searchInfo(list, data);
	if (pMove == NULL)
	{
		cout << "δ�ҵ������Ϣ��" << endl;
	}
	else
	{
		cout << "����\tѧ��\t�Ա�\t����\t�绰" << endl;
		cout << pMove->data.name << "\t" << pMove->data.id << "\t" << pMove->data.sex << "\t" << pMove->data.age << "\t" << pMove->data.tel << endl;
	}
}
void changeInfo()
{
	Student data;
	cout << "������Ҫ�޸�ѧ����ѧ��:" << endl;
	cin >> data.id;
	struct Node* pMove = searchInfo(list, data);
	if (pMove == NULL)
	{
		cout << "δ�ҵ������Ϣ��" << endl;
	}
	else
	{
		cout << "�������ѧ���µ���Ϣ:"<<endl;
		cin>> pMove->data.name >> pMove->data.id >> pMove->data.sex >> pMove->data.age >>pMove->data.tel ;
		cout<<"�޸ĳɹ���" << endl;
	}
}
//�û�����
void foruser()
{
	int choice = 0;
	cin >> choice;
	switch (choice) {
	case 0:
		cout << "�����˳�" << endl;
		system("pause");
		exit(0);
		break;
	case 1:
		cout << "��¼����Ϣ��" << endl;
		insertInfo();//������Ϣ
		break;
	case 2:
		cout << "�������Ϣ��" << endl;
		printList(list);//��ӡ����
		break;
	case 3:
		cout << "��ɾ����Ϣ��" << endl;
		deleteInfo();//ɾ����Ϣ
		break;
	case 4:
		cout << "��������Ϣ��" << endl;
		searchstu();//������Ϣ
		break;
	case 5:
		cout << "���޸���Ϣ��" << endl;
		changeInfo();//�޸���Ϣ
		break;
	default:
		cout << "ѡ�������������" << endl;
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