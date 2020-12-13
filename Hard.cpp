#include"Hard.h"

Hard::Hard()
{
	this->InternalComplete::InternalComplete();
	round = 0;
	time = 0;
	strcpy_s(hard_type, CH_HARD_SIZE, "default");
}

void Hard::setRound(long long int a)
{
	round = a;
}

void Hard::setTime(long long int b)
{
	time = b;
}

void Hard::setHardType(const char G[CH_HARD_SIZE])
{
	strcpy_s(hard_type, CH_HARD_SIZE, G);
}

long long int Hard::getRound()
{
	return round;
}

long long int Hard::getTime()
{
	return time;
}

char* Hard::getHardType()
{
	return hard_type;
}

void Hard::header()
{
	int line = 20 + CH_NOM_SIZE + CH_DESIGNATIONIn_SIZE + CH_HARD_SIZE + 9;
	for (int i = 0; i < line; i++) cout << "-"; cout << endl;
	cout << "| �|" << setw(17) << "�������" << "|" << setw(CH_NOM_SIZE) << "������������" << setw(17) << "���������� �� ������" << "|" << setw(17) << "���� �� �����";
	cout << "|" << setw(17) << "����������" << "|" << setw(CH_DESIGNATIONIn_SIZE) << "������������� ";
	cout << "|" << setw(17) << "������" << "|" << setw(CH_HARD_SIZE) << "���";
	cout << "|" << setw(17) << "��������" << "|" << setw(17) << "�����" << "|" << endl;
	for (int i = 0; i < line; i++) cout << "-";
	cout << endl;
}

ostream& operator << (ostream& out, Hard& subscr)
{
	out << dynamic_cast<InternalComplete&>(subscr);
	out << setw(CH_HARD_SIZE) << subscr.hard_type;
	out << "|" << setw(17) << subscr.round << "|" << setw(17) << subscr.time << "|" << endl;
	int line = 20 + CH_NOM_SIZE + CH_DESIGNATIONIn_SIZE + CH_HARD_SIZE + 9;
	for (int i = 0; i < line; i++) out << "-";
	return out;
}
istream& operator >> (istream& in, Hard& subscr)
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
	cout << "������� ��������: ";
	in >> subscr.round;
	cout << "������� �����: ";
	in >> subscr.time;
	cout << "������� ���: ";
	in.getline(subscr.hard_type, CH_HARD_SIZE);
	return in;
}

void Hard::searchInstance()
{
	int fate;
	do {
		cout << endl << "\t\t����� ��������� �������� � ������(�������� ��): " << endl << endl;
		cout << endl << "1 - ��������";
		cout << endl << "2 - �������������";
		cout << endl << "3 - � ����";
		cout << endl << "4 - �������";
		cout << endl << "5 - ���";
		cout << endl << "6 - ������������";
		cout << endl << "7 - ������ ����� �� �������� ����������" << endl;
		cout << endl << "~>> ";
		cin >> fate;

		switch (fate)
		{
		case 1:
		{
			long long int a;
			cout << "������� ��������: ";
			rewind(stdin);
			cin >> a;
			setRound(a);
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
			cout << "������� �����: ";
			rewind(stdin);
			cin >> b;
			setTime(b);
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
			char oper_type[CH_HARD_SIZE];
			cout << "���������: ";
			rewind(stdin);
			cin.getline(oper_type, CH_HARD_SIZE, '\n');
			setHardType(oper_type);
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

bool Hard::operator > (Hard& ext)
{
	if (strcmp(hard_type, ext.hard_type) > 0)
		return true;
	return false;
}

/*bool SSD::operator < (SSD& ext)
{
	if (strcmp(chip, ext.chip) > 0)
		return true;
	return false;
}*/

bool Hard::operator == (Hard& ext)
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
	if (strcmp(hard_type, "default") != 0)
		if (strcmp(hard_type, ext.hard_type) == 0)
			count++;
		else
			return false;
	return match;
}

void Hard::edit()
{
	int choice;
	do {
		cout << "1 - �������� �������" << endl;
		cout << "2 - �������� ������������" << endl;
		cout << "3 - �������� �������������" << endl;
		cout << "4 - �������� ������" << endl;
		cout << "5 - �������� ������� ����������" << endl;
		cout << "6 - �������� ��������" << endl;
		cout << "7 - �������� �����" << endl;
		cout << "8 - �������� ���" << endl;
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
			cout << "��������: ";
			rewind(stdin);
			cin >> a;
			setRound(a);
			break;
		}
		case 7:
		{
			long long int b;
			cout << "�����: ";
			rewind(stdin);
			cin >> b;
			setTime(b);
			break;
		}
		case 8:
		{
			char oper_type[CH_HARD_SIZE];
			cout << "����������: ";
			rewind(stdin);
			cin.getline(oper_type, CH_HARD_SIZE, '\n');
			setHardType(oper_type);
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

ofstream& operator << (ofstream& out, Hard& subscr)
{
	out << dynamic_cast<InternalComplete&>(subscr);
	out << subscr.round << '|' << subscr.time << '|' << subscr.hard_type << '|';
	return out;
}

ifstream& operator >> (ifstream& in, Hard& subscr)
{
	in >> dynamic_cast<InternalComplete&>(subscr);
	in >> subscr.round;
	in >> subscr.time;
	in.getline(subscr.hard_type, CH_HARD_SIZE, '|');
	return in;
}