#include<iostream>
#include<string>
#include"head.h"
using namespace std;
int main() {
	BookManager manager("孙悟空", 123456);
	Reader reader("唐僧", 2005);
	cout << "1管理人员登陆" << endl;
	cout << "2读者登陆" << endl;
	int choice = 0;
	cin >> choice;
	switch (choice)
	{
	case  1:manager.SignIn(manager);
		
		while (true)
		{


			cout << "1为添加图书，2为删除图书，3为修改图书，4为查找图书" << endl;
			int managerchoice; cin >> managerchoice;
			switch (managerchoice)
			{

			case 1:cout << "要执行添加图书多少次" << endl;
				int t1; cin >> t1;
				while (t1)
				{
					manager.addBook();
					t1--;
				}
				break;
			case 2:cout << "输入要删除的书号" << endl;
				int t2; cin >> t2;
				manager.DeleteBook(t2);
				break;
			case 3:cout << "输入要修改图书的书号" << endl;
				int t3; cin >> t3;
				manager.ChangeBook(t3);
				break;
			case 4:
				cout << "需要查找的书号" << endl;
				int t4; cin >> t4;
				manager.FindBook(t4);
				break;
			
			}
			cout << "是否继续上述操作? " << endl;
			cout << "1为继续,其它为跳过" << endl;
			int jixu = 0;
			cin >> jixu;
			if (jixu != 1)
				break;
			
		}
		break;
	case 2:
		reader.SignIn(reader);
		reader.BrrowBook();
		break;


	}

}