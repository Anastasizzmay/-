#include"SSD.h"

SSD::SSD()
{
	this->InternalComplete::InternalComplete();
	speed = 0;
	buf = 0;
	strcpy_s(interf, CH_INTERF_SIZE, "default");
}

void SSD::setSpeed(long long int a)
{
	speed = a;
}

void SSD::setBuf(long long int b)
{
	buf = b;
}

void SSD::setInterf(const char G[CH_INTERF_SIZE])
{
	strcpy_s(interf, CH_INTERF_SIZE, G);
}

long long int SSD::getSpeed()
{
	return speed;
}

long long int SSD::getBuf()
{
	return buf;
}

char* SSD::getInterf()
{
	return interf;
}

void SSD::header()
{
	int line = 20 + CH_NOM_SIZE + CH_DESIGNATIONIn_SIZE + CH_INTERF_SIZE + 9;
	for (int i = 0; i < line; i++) cout << "-"; cout << endl;
	cout << "| �|" << setw(17) << "�������" << "|" << setw(CH_NOM_SIZE) << "������������" << setw(17) << "���������� �� ������" << "|" << setw(17) << "���� �� �����";
	cout << "|" << setw(17) << "����������" << "|" << setw(CH_DESIGNATIONIn_SIZE) << "������������� ";
	cout << "|" << setw(17) << "������" << "|" << setw(CH_INTERF_SIZE) << "���������";
	cout << "|" << setw(17) << "��������" << "|" << setw(17) << "�����" << "|" << endl;
	for (int i = 0; i < line; i++) cout << "-";
	cout << endl;
}

ostream& operator << (ostream& out, SSD& subscr)
{
	out << dynamic_cast<InternalComplete&>(subscr);
	out << setw(CH_INTERF_SIZE) << subscr.interf;
	out << "|" << setw(17) << subscr.speed << "|" << setw(17) << subscr.buf << "|" << endl;
	int line = 20 + CH_NOM_SIZE + CH_DESIGNATIONIn_SIZE + CH_INTERF_SIZE + 9;
	for (int i = 0; i < line; i++) out << "-";
	return out;
}
istream& operator >> (istream& in, SSD& subscr)
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
	in >> subscr.speed;
	cout << "������� �����: ";
	in >> subscr.buf;
	cout << "������� ���������: ";
	in.getline(subscr.interf, CH_INTERF_SIZE);
	return in;
}

void SSD::searchInstance()
{
	int fate;
	do {
		cout << endl << "\t\t����� ��������� �������� � ������(�������� ��): " << endl << endl;
		cout << endl << "1 - ��������";
		cout << endl << "2 - �������������";
		cout << endl << "3 - �����";
		cout << endl << "4 - �������";
		cout << endl << "5 - ���������";
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
			setSpeed(a);
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
			setBuf(b);
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
			char oper_type[CH_INTERF_SIZE];
			cout << "���������: ";
			rewind(stdin);
			cin.getline(oper_type, CH_INTERF_SIZE, '\n');
			setInterf(oper_type);
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

bool SSD::operator > (SSD& ext)
{
	if (strcmp(interf, ext.interf) > 0)
		return true;
	return false;
}

/*bool SSD::operator < (SSD& ext)
{
	if (strcmp(chip, ext.chip) > 0)
		return true;
	return false;
}*/

bool SSD::operator == (SSD& ext)
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
	if (strcmp(interf, "default") != 0)
		if (strcmp(interf, ext.interf) == 0)
			count++;
		else
			return false;
	return match;
}

void SSD::edit()
{
	int choice;
	do {
		cout << "1 - �������� �������" << endl;
		cout << "2 - �������� ������������" << endl;
		cout << "3 - �������� �������������" << endl;
		cout << "4 - �������� ������" << endl;
		cout << "5 - �������� ������� ����������" << endl;
		cout << "6 - �������� c�������" << endl;
		cout << "7 - �������� �����" << endl;
		cout << "8 - �������� ���������" << endl;
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
			setSpeed(a);
			break;
		}
		case 7:
		{
			long long int b;
			cout << "�����: ";
			rewind(stdin);
			cin >> b;
			setBuf(b);
			break;
		}
		case 8:
		{
			char oper_type[CH_INTERF_SIZE];
			cout << "����������: ";
			rewind(stdin);
			cin.getline(oper_type, CH_INTERF_SIZE, '\n');
			setInterf(oper_type);
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

ofstream& operator << (ofstream& out, SSD& subscr)
{
	out << dynamic_cast<InternalComplete&>(subscr);
	out << subscr.speed << '|' << subscr.buf << '|' << subscr.interf << '|';
	return out;
}

ifstream& operator >> (ifstream& in, SSD& subscr)
{
	in >> dynamic_cast<InternalComplete&>(subscr);
	in >> subscr.speed;
	in >> subscr.buf;
	in.getline(subscr.interf, CH_INTERF_SIZE, '|');
	return in;
}