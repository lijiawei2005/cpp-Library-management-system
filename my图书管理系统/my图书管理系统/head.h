#pragma once
#include<iostream>
#include<string>
using namespace std;
class Book {
public:
	int ISBN;//���
	string Bookname;//����
	string  writer;//����
	int price;//ͼ��۸�
	int cangku;//�ɽ���
	int  extant;//�ִ���
	Book* next;//ָ����
	Book() {
		ISBN = 0;
		Bookname = "";
		writer = "";
		price = 0;
		extant = 0;
		cangku = 0;
		next = NULL;
	}
};
class BookList {
public:
	Book* head;//ͷָ��
	BookList() {
		head = NULL;
	}
	//  ����ͼ�飬������ͼ����Ϣ
	void addBook() {
		Book* p = new Book;
		cout << "��������ţ�" << endl;
		cin >> p->ISBN;
		cout << "������������" << endl;
		cin >> p->Bookname;
		cout << "���������ߣ�" << endl;
		cin >> p->writer;
		cout << "������ͼ��۸�" << endl;
		cin >> p->price;
		cout << "Ҫ�Ӷ��ٱ���" << endl;
		cin >> p->extant;
		if (head == NULL)
		{
			head = p;

		}
		else
		{
			Book* cur = head;
			while (cur->next != NULL)
			{
				cur = cur->next;
			}
			cur->next = p;
		}
		cout << "��ӳɹ�" << endl;
	}
	//ɾ��������ŵ�ͼ��
	void DeleteBook(int a) {
		Book* p = head;
		while (p->next->ISBN != a && p->next != NULL)
		{
			p = p->next;
		}
		Book* tp = p->next;
		p->next = tp->next;
		delete  tp;
	}
	//��
	void ChangeBook(int a) {
		Book* p = head;
		while (p->next->ISBN != a && p->next != NULL)
		{
			p = p->next;
		}
		while (true)
		{
			cout << "1Ϊ����ţ�2Ϊ��������3�����ߣ�4��ͼ��۸�" << endl;
			int choice;
			cin >> choice;
			switch (choice)
			{
			case 1:
				cin >> p->next->ISBN; break;
			case 2:
				cin >> p->next->Bookname; break;
			case 3:
				cin >> p->next->writer; break;
			case 4:
				cin >> p->next->price; break;
			default:cout << "���������������" << endl;
				break;
			}
			cout << "�Ƿ�����޸�,��0������0����" << endl;
			int out = 0;
			cin >> out;
			if (out == 0)
				break;

		}
	}
	//��
	void FindBook(int a) {
		Book* p = head;
		while (p->next->ISBN != a && p->next != NULL)
		{
			p = p->next;
		}if (p->next == NULL)
		{
			cout << "�Ҳ�������" << endl;
			return;
		}
		cout << "����Ϊ��" << p->next->Bookname << endl;//����
		cout << "�ɽ�����" << p->next->cangku << endl;//�ɽ���
		cout << "�ִ�����" << p->next->extant << endl;//�ִ���
		cout << "�۸�Ϊ��" << p->next->price << endl;//�۸�
		cout << "������:" << p->next->writer << endl;//����
	}
};

class BookManager :public BookList {
private:
	string ManagerName;//����
	int password;//����
public:
	BookManager(string a, int _password)
	{
		ManagerName = a;
		password = _password;
	}
	//��¼����
	void SignIn(BookManager bookmanager) {
		int dl = -1;
		while (dl)
		{


			cout << "�������˺�" << endl;
			string s;
			cin >> s;
			cout << "����������" << endl;
			int mima;
			cin >> mima;
			if (s == bookmanager.ManagerName && mima == bookmanager.password)

			{
				cout << "��¼�ɹ�" << endl; dl++;
			}
			else
				cout << "�˺Ż��������,������" << endl;
		}
	}
	void BrrowBook() {
		cout << "��Ҫ������������Ϊ:" << endl;
		string s;
		cin >> s;
		int w;
		cin >> w;
		Book* p = head;
		while (p->next->Bookname != s && p->next != NULL && p->next->ISBN != w)
		{
			p = p->next;
		}
		cout << "ʣ��" << p->next->cangku << "���ɽ�" << endl;
		if (p->next->cangku > 1) {
			p->next->cangku--;
			cout << "����ɹ�" << endl;
		}
		else
		{
			cout << "����ʧ��" << endl;
		}
	}
};
class Reader :public BookList {
private:
	string Readname;
	int password;
public:
	Reader(string a, int _password) {
		Readname = a;
		password = _password;
	}
	void SignIn(Reader red) {
		int dl = -1;
		while (dl)
		{


			cout << "�������˺�" << endl;
			string s;
			cin >> s;
			cout << "����������" << endl;
			int mima;
			cin >> mima;
			if (s == red.Readname && mima == red.password)

			{
				cout << "��¼�ɹ�" << endl; dl++;
			}
			else
				cout << "�˺Ż��������,������" << endl;
		}
	}
	void BrrowBook() {
		cout << "��Ҫ������������Ϊ:" << endl;
		string s;
		cin >> s;
		int w;
		cin >> w;
		Book* p = head;
		while (p->next->Bookname != s && p->next != NULL && p->next->ISBN != w)
		{
			p = p->next;
		}
		cout << "ʣ��" << p->next->cangku << "���ɽ�" << endl;
		if (p->next->cangku > 1) {
			p->next->cangku--;
			cout << "����ɹ�" << endl;
		}
		else
		{
			cout << "����ʧ��" << endl;
		}
	}

};
