#include<iostream>
#include<string>
#include"head.h"
using namespace std;
int main() {
	BookManager manager("�����", 123456);
	Reader reader("��ɮ", 2005);
	cout << "1������Ա��½" << endl;
	cout << "2���ߵ�½" << endl;
	int choice = 0;
	cin >> choice;
	switch (choice)
	{
	case  1:manager.SignIn(manager);
		
		while (true)
		{


			cout << "1Ϊ���ͼ�飬2Ϊɾ��ͼ�飬3Ϊ�޸�ͼ�飬4Ϊ����ͼ��" << endl;
			int managerchoice; cin >> managerchoice;
			switch (managerchoice)
			{

			case 1:cout << "Ҫִ�����ͼ����ٴ�" << endl;
				int t1; cin >> t1;
				while (t1)
				{
					manager.addBook();
					t1--;
				}
				break;
			case 2:cout << "����Ҫɾ�������" << endl;
				int t2; cin >> t2;
				manager.DeleteBook(t2);
				break;
			case 3:cout << "����Ҫ�޸�ͼ������" << endl;
				int t3; cin >> t3;
				manager.ChangeBook(t3);
				break;
			case 4:
				cout << "��Ҫ���ҵ����" << endl;
				int t4; cin >> t4;
				manager.FindBook(t4);
				break;
			
			}
			cout << "�Ƿ������������? " << endl;
			cout << "1Ϊ����,����Ϊ����" << endl;
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