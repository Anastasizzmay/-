#include "interface.h"

template <class T>
void Interface<T>::objectSelectionMenu()
{
	core();
	int choice;
	do {
		system("cls");
		system("color 6");
		cout << "\t\t\t*SHOP*" << endl << endl;
		cout << endl << "\t\t1 - ����������";
		cout << endl << "\t\t2 - ����������";
		cout << endl << "\t\t3 - ����������� �����";
		cout << endl << "\t\t4 - ����������� ������";
		cout << endl << "\t\t5 - ������� ����������";
		cout << endl << "\t\t6 - SSD";
		cout << endl << "\t\t7 - ������� �����";
		cout << endl << "\t\t8 - �������";
		cout << endl << "\t\t9 - ����� �������";
		cout << endl << "\t\t10 - �������� �����";
		cout << endl << "\t\t11- ������� ��������";
		cout << endl << "\t\t12 - ���������� �������";
		cout << endl << "\t\t13 - ��-������ � ����� ������������";
		cout << endl << "\t\t14 - �����";
		cout << endl << "\t~>> ";
		cin >> choice;
		system("color 7");
		switch (choice)
		{
		case 1:
		{
			Interface<Vidiocards> subscr;
			subscr.FileWay = "D://main.cpp/vidiocards.dat";
			subscr.mainLogic();
			break;
		}
		case 2:
		{
			Interface<Processors> subscr;
			subscr.FileWay = "D://main.cpp/pocessor.dat";
			subscr.mainLogic();
			break;
		}
		case 3:
		{
			Interface<Mother> subscr;
			subscr.FileWay = "D://main.cpp/mother.dat";
			subscr.mainLogic();
			break;
		}
		case 4:
		{
			Interface<Oper> subscr;
			subscr.FileWay = "D://main.cpp/oper.dat";
			subscr.mainLogic();
			break;
		}
		case 5:
		{
			Interface<Freezer> subscr;
			subscr.FileWay = "D://main.cpp/freez.dat";
			subscr.mainLogic();
			break;
		}
		case 6:
		{
			Interface<SSD> subscr;
			subscr.FileWay = "D://main.cpp/ssd.dat";
			subscr.mainLogic();
			break;
		}
		case 7:
		{
			Interface<Hard> subscr;
			subscr.FileWay = "D://main.cpp/hard.dat";
			subscr.mainLogic();
			break;
		}
		case 8:
		{
			Interface<ComputerCase> subscr;
			subscr.FileWay = "D://main.cpp/case.dat";
			subscr.mainLogic();
			break;
		}
		case 9:
		{
			Interface<Power> subscr;
			subscr.FileWay = "D://main.cpp/power.dat";
			subscr.mainLogic();
			break;
		}
		case 10:
		{
			Interface<Sound> subscr;
			subscr.FileWay = "D://main.cpp/sound.dat";
			subscr.mainLogic();
			break;
		}
		case 11:
		{
			Interface<Adapter> subscr;
			subscr.FileWay = "D://main.cpp/adapter.dat";
			subscr.mainLogic();
			break;
		}
		case 12:
		{
			Interface<Optic> subscr;
			subscr.FileWay = "D://main.cpp/optic.dat";
			subscr.mainLogic();
			break;

		}
		case 13:
		{
			Interface<Vidio> subscr;
			subscr.FileWay = "D://main.cpp/vidio.dat";
			subscr.mainLogic();
			break;
		}
		case 14:
		{
			return;
		}
		default:
		{
			break;
		}
		}
	} while (true);
}

template <class T>
void Interface<T>::mainLogic()
{
	list<T> List;
	List.read(FileWay);
	int choice;
	system("color 2");
	do {
		cout << endl << "\t\t1 - ��������";
		cout << endl << "\t\t2 - �������";
		cout << endl << "\t\t3 - �����������";
		cout << endl << "\t\t4 - �����";
		cout << endl << "\t\t5 - �������������";
		cout << endl << "\t\t6 - �����";
		cout << endl << "\t~>> ";
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			T subscr;
			cin >> subscr;
			List.push(subscr);
			break;
		}
		case 2:
		{
			int delNumber;
			cout << "\t������� ������� ��� ��������: ";
			cin >> delNumber;
			delNumber--;
			List.deleteCertainNode(delNumber);
			break;
		}
		case 3:
		{
			cout << endl;
			system("color 3");
			T subscr;
			subscr.header();
			List.show();
			break;
		}
		case 4:
		{
			system("cls");
			system("color 5");
			List.search();
			cout << endl << endl << "\t\t����� ��������" << endl << endl;
			break;
		}
		case 5:
		{
			system("cls");
			system("color 3");
			T subscr;
			subscr.header();
			int number;
			List.show();
			cout << endl << "\t������� ������� ��� ��������������: ";
			cin >> number;
			number--;
			List.edit(number);
			List.write(FileWay);
			system("color 7");
			break;
		}
		case 6:
		{
			List.write(FileWay);
			return;
		}
		default:
		{
			break;
		}
		}
	} while (true);
}