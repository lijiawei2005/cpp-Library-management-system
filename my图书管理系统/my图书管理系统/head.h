#pragma once
#include<iostream>
#include<string>
using namespace std;
class Book {
public:
	int ISBN;//书号
	string Bookname;//书名
	string  writer;//作者
	int price;//图书价格
	int cangku;//可借量
	int  extant;//现存量
	Book* next;//指针域
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
	Book* head;//头指针
	BookList() {
		head = NULL;
	}
	//  增加图书，链表储存图书信息
	void addBook() {
		Book* p = new Book;
		cout << "请输入书号：" << endl;
		cin >> p->ISBN;
		cout << "请输入书名：" << endl;
		cin >> p->Bookname;
		cout << "请输入作者：" << endl;
		cin >> p->writer;
		cout << "请输入图书价格：" << endl;
		cin >> p->price;
		cout << "要加多少本：" << endl;
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
		cout << "添加成功" << endl;
	}
	//删除给定书号的图书
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
	//改
	void ChangeBook(int a) {
		Book* p = head;
		while (p->next->ISBN != a && p->next != NULL)
		{
			p = p->next;
		}
		while (true)
		{
			cout << "1为改书号，2为改书名，3改作者，4改图书价格" << endl;
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
			default:cout << "输入错误，重新输入" << endl;
				break;
			}
			cout << "是否继续修改,非0继续，0结束" << endl;
			int out = 0;
			cin >> out;
			if (out == 0)
				break;

		}
	}
	//查
	void FindBook(int a) {
		Book* p = head;
		while (p->next->ISBN != a && p->next != NULL)
		{
			p = p->next;
		}if (p->next == NULL)
		{
			cout << "找不到该书" << endl;
			return;
		}
		cout << "书名为：" << p->next->Bookname << endl;//书名
		cout << "可借量：" << p->next->cangku << endl;//可借量
		cout << "现存量：" << p->next->extant << endl;//现存量
		cout << "价格为：" << p->next->price << endl;//价格
		cout << "作者是:" << p->next->writer << endl;//作者
	}
};

class BookManager :public BookList {
private:
	string ManagerName;//姓名
	int password;//密码
public:
	BookManager(string a, int _password)
	{
		ManagerName = a;
		password = _password;
	}
	//登录功能
	void SignIn(BookManager bookmanager) {
		int dl = -1;
		while (dl)
		{


			cout << "请输入账号" << endl;
			string s;
			cin >> s;
			cout << "请输入密码" << endl;
			int mima;
			cin >> mima;
			if (s == bookmanager.ManagerName && mima == bookmanager.password)

			{
				cout << "登录成功" << endl; dl++;
			}
			else
				cout << "账号或密码错误,请重试" << endl;
		}
	}
	void BrrowBook() {
		cout << "你要借的书名，书号为:" << endl;
		string s;
		cin >> s;
		int w;
		cin >> w;
		Book* p = head;
		while (p->next->Bookname != s && p->next != NULL && p->next->ISBN != w)
		{
			p = p->next;
		}
		cout << "剩余" << p->next->cangku << "本可借" << endl;
		if (p->next->cangku > 1) {
			p->next->cangku--;
			cout << "借书成功" << endl;
		}
		else
		{
			cout << "借书失败" << endl;
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


			cout << "请输入账号" << endl;
			string s;
			cin >> s;
			cout << "请输入密码" << endl;
			int mima;
			cin >> mima;
			if (s == red.Readname && mima == red.password)

			{
				cout << "登录成功" << endl; dl++;
			}
			else
				cout << "账号或密码错误,请重试" << endl;
		}
	}
	void BrrowBook() {
		cout << "你要借的书名，书号为:" << endl;
		string s;
		cin >> s;
		int w;
		cin >> w;
		Book* p = head;
		while (p->next->Bookname != s && p->next != NULL && p->next->ISBN != w)
		{
			p = p->next;
		}
		cout << "剩余" << p->next->cangku << "本可借" << endl;
		if (p->next->cangku > 1) {
			p->next->cangku--;
			cout << "借书成功" << endl;
		}
		else
		{
			cout << "借书失败" << endl;
		}
	}

};
