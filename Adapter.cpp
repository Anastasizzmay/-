#include"Adapter.h"

Adapter::Adapter()
{
	this->InternalComplete::InternalComplete();
	LC = 0;
	SC = 0;
	SFP = 0;
	strcpy_s(connect, CH_CONNECT_SIZE, "default");
}

void Adapter::setLC(long long int a)
{
	LC = a;
}

void Adapter::setSC(long long int a)
{
	SC = a;
}

void Adapter::setSFP(long long int b)
{
	SFP = b;
}

void Adapter::setConnect(const char G[CH_CONNECT_SIZE])
{
	strcpy_s(connect, CH_CONNECT_SIZE, G);
}

long long int Adapter::getLC()
{
	return LC;
}

long long int Adapter::getSC()
{
	return SC;
}

long long int Adapter::getSFP()
{
	return SFP;
}

char* Adapter::getConnect()
{
	return connect;
}

void Adapter::header()
{
	int line = 20 + CH_NOM_SIZE + CH_DESIGNATIONIn_SIZE + CH_CONNECT_SIZE + 9;
	for (int i = 0; i < line; i++) cout << "-"; cout << endl;
	cout << "| �|" << setw(17) << "�������" << "|" << setw(CH_NOM_SIZE) << "������������" << setw(17) << "���������� �� ������" << "|" << setw(17) << "���� �� �����";
	cout << "|" << setw(17) << "����������" << "|" << setw(CH_DESIGNATIONIn_SIZE) << "������������� ";
	cout << "|" << setw(17) << "������" << "|" << setw(CH_CONNECT_SIZE) << "����������";
	cout << "|" << setw(17) << "LC " << "|" << setw(17) << "SC" << "|" << setw(17) << "SFP" << "|" << endl;
	for (int i = 0; i < line; i++) cout << "-";
	cout << endl;
}

ostream& operator << (ostream& out, Adapter& subscr)
{
	out << dynamic_cast<InternalComplete&>(subscr);
	out << setw(CH_CONNECT_SIZE) << subscr.connect;
	out << "|" << setw(17) << subscr.LC << "|" << setw(17) << subscr.SC << "|" << setw(17) << subscr.SFP << "|" << endl;
	int line = 20 + CH_NOM_SIZE + CH_DESIGNATIONIn_SIZE + CH_CONNECT_SIZE + 9;
	for (int i = 0; i < line; i++) out << "-";
	return out;
}
istream& operator >> (istream& in, Adapter& subscr)
{
	cin.clear();
	cin.ignore(256, '\n');
	cout << "������� ������������: ";
	in.getline(subscr.nomination, CH_NOM_SIZE);
	cout << "������� �������: ";
	in >> subscr.vendor_code;
	cout << "������� ���������� �� ������: ";
	in >> subscr.quantity;
	cout << "������� ���� �� �����: ";
	in >> subscr.price;
	cout << "������� �������������: ";
	in.getline(subscr.producer, CH_DESIGNATIONIn_SIZE);
	cout << "������� ������� ����������: ";
	in >> subscr.freez;
	cout << "������� ����� ������: ";
	in >> subscr.volume;
	cin.clear();
	cin.ignore(256, '\n');
	cout << "������� LC: ";
	in >> subscr.LC;
	cout << "������� SC: ";
	in >> subscr.SC;
	cout << "������� SFP: ";
	in >> subscr.SFP;
	cout << "������� �����: ";
	in.getline(subscr.connect, CH_CONNECT_SIZE);
	return in;
}

void Adapter::searchInstance()
{
	int fate;
	do {
		cout << endl << "\t\t����� ��������� �������� � ������(�������� ��): " << endl << endl;
		cout << endl << "1 - LC ";
		cout << endl << "2 - �������������";
		cout << endl << "3 - SFP";
		cout << endl << "4 - �������";
		cout << endl << "5 - �����";
		cout << endl << "6 - ������������";
		cout << endl << "7 - ������ ����� �� �������� ����������" << endl;
		cout << endl << "~>> ";
		cin >> fate;

		switch (fate)
		{
		case 1:
		{
			long long int a;
			cout << "������� LC : ";
			rewind(stdin);
			cin >> a;
			setLC(a);
			break;
		}
		case 2:
		{
			char name[CH_DESIGNATIONIn_SIZE];
			cout << "������� �������������: ";
			rewind(stdin);
			cin.getline(name, CH_DESIGNATIONIn_SIZE);
			setProducer(name);
			break;
		}
		case 3:
		{
			long long int b;
			cout << "������� SFP: ";
			rewind(stdin);
			cin >> b;
			setSFP(b);
			break;
		}
		case 4:
		{
			long long int patronymic;
			cout << "�������: ";
			rewind(stdin);
			cin >> patronymic;
			setVendorCode(patronymic);
			break;
		}
		case 5:
		{
			char oper_type[CH_CONNECT_SIZE];
			cout << "�����: ";
			rewind(stdin);
			cin.getline(oper_type, CH_CONNECT_SIZE, '\n');
			setConnect(oper_type);
			break;
		}
		case 6:
		{
			char date[CH_NOM_SIZE];
			cout << "������������: ";
			rewind(stdin);
			cin.getline(date, CH_NOM_SIZE, '\n');
			setNomination(date);
			break;
		}

		case 7:
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

bool Adapter::operator > (Adapter& ext)
{
	if (strcmp(connect, ext.connect) > 0)
		return true;
	return false;
}

/*bool SSD::operator < (SSD& ext)
{
	if (strcmp(chip, ext.chip) > 0)
		return true;
	return false;
}*/

bool Adapter::operator == (Adapter& ext)
{
	bool match = true;
	int count = 0;
	if (strcmp(producer, "default") != 0)
		if (strcmp(producer, ext.producer) == 0)
			count++;
		else
			return false;
	if (strcmp(nomination, "default") != 0)
		if (strcmp(nomination, ext.nomination) == 0)
			count++;
		else
			return false;
	if (strcmp(connect, "default") != 0)
		if (strcmp(connect, ext.connect) == 0)
			count++;
		else
			return false;
	return match;
}

void Adapter::edit()
{
	int choice;
	do {
		cout << "1 - �������� �������" << endl;
		cout << "2 - �������� ������������" << endl;
		cout << "3 - �������� �������������" << endl;
		cout << "4 - �������� ������" << endl;
		cout << "5 - �������� ������� ����������" << endl;
		cout << "6 - �������� LC" << endl;
		cout << "7 - �������� SFP" << endl;
		cout << "8 - �������� ����������" << endl;
		cout << "9 - �����" << endl;
		cout << "~>> ";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			long long int number;
			cout << "������� ����� �������: ";
			cin >> number;
			setVendorCode(number);
			break;
		}
		case 2:
		{
			char addr[CH_NOM_SIZE];
			cout << "������� ����� ������������: ";
			rewind(stdin);
			cin.getline(addr, CH_NOM_SIZE, '\n');
			setNomination(addr);
			break;
		}
		case 3:
		{
			char name[CH_DESIGNATIONIn_SIZE];
			cout << "������� ������ �������������: ";
			rewind(stdin);
			cin.getline(name, CH_DESIGNATIONIn_SIZE);
			setProducer(name);
			break;
		}
		case 4:
		{
			long long int volume;
			cout << "������� ������: ";
			rewind(stdin);
			cin >> volume;
			setVolume(volume);
			break;
		}
		case 5:
		{
			bool freez;
			cout << "������� ������� ����������: ";
			rewind(stdin);
			cin >> freez;
			setFreez(freez);
			break;
		}
		case 6:
		{
			long long int a;
			cout << "LC  : ";
			rewind(stdin);
			cin >> a;
			setLC(a);
			break;
		}
		case 7:
		{
			long long int b;
			cout << "SFP: ";
			rewind(stdin);
			cin >> b;
			setSFP(b);
			break;
		}
		case 8:
		{
			char oper_type[CH_CONNECT_SIZE];
			cout << "����������: ";
			rewind(stdin);
			cin.getline(oper_type, CH_CONNECT_SIZE, '\n');
			setConnect(oper_type);
			break;
		}
		case 9:
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

ofstream& operator << (ofstream& out, Adapter& subscr)
{
	out << dynamic_cast<InternalComplete&>(subscr);
	out << subscr.LC << '|' << subscr.SC << '|' << subscr.SFP << '|' << subscr.connect << '|';
	return out;
}

ifstream& operator >> (ifstream& in, Adapter& subscr)
{
	in >> dynamic_cast<InternalComplete&>(subscr);
	in >> subscr.LC;
	in >> subscr.SC;
	in >> subscr.SFP;
	in.getline(subscr.connect, CH_CONNECT_SIZE, '|');
	return in;
}