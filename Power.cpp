#include"Power.h"

Power::Power()
{
	this->InternalComplete::InternalComplete();
	KPD = 0;
	BlockPow = 0;
	strcpy_s(pow_mother, CH_POW_SIZE, "default");
}

void Power::setKPD(long long int a)
{
	KPD = a;
}

void Power::setBlockPow(long long int b)
{
	BlockPow = b;
}

void Power::setPowMother(const char G[CH_POW_SIZE])
{
	strcpy_s(pow_mother, CH_POW_SIZE, G);
}

long long int Power::getKPD()
{
	return KPD;
}

long long int Power::getBlockPow()
{
	return BlockPow;
}

char* Power::getPowMother()
{
	return pow_mother;
}

void Power::header()
{
	int line = 20 + CH_NOM_SIZE + CH_DESIGNATIONIn_SIZE + CH_POW_SIZE + 9;
	for (int i = 0; i < line; i++) cout << "-"; cout << endl;
	cout << "| �|" << setw(17) << "�������" << "|" << setw(CH_NOM_SIZE) << "������������" << setw(17) << "���������� �� ������" << "|" << setw(17) << "���� �� �����";
	cout << "|" << setw(17) << "����������" << "|" << setw(CH_DESIGNATIONIn_SIZE) << "������������� ";
	cout << "|" << setw(17) << "������" << "|" << setw(CH_POW_SIZE) << "���";
	cout << "|" << setw(17) << "���" << "|" << setw(17) << "��������" << "|" << endl;
	for (int i = 0; i < line; i++) cout << "-";
	cout << endl;
}

ostream& operator << (ostream& out, Power& subscr)
{
	out << dynamic_cast<InternalComplete&>(subscr);
	out << setw(CH_POW_SIZE) << subscr.pow_mother;
	out << "|" << setw(17) << subscr.KPD << "|" << setw(17) << subscr.BlockPow << "|" << endl;
	int line = 20 + CH_NOM_SIZE + CH_DESIGNATIONIn_SIZE + CH_POW_SIZE + 9;
	for (int i = 0; i < line; i++) out << "-";
	return out;
}
istream& operator >> (istream& in, Power& subscr)
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
	cout << "������� ���: ";
	in >> subscr.KPD;
	cout << "������� ��������: ";
	in >> subscr.BlockPow;
	cout << "������� ���: ";
	in.getline(subscr.pow_mother, CH_POW_SIZE);
	return in;
}

void Power::searchInstance()
{
	int fate;
	do {
		cout << endl << "\t\t����� ��������� �������� � ������(�������� ��): " << endl << endl;
		cout << endl << "1 - ���";
		cout << endl << "2 - �������������";
		cout << endl << "3 - ��������";
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
			cout << "������� ���: ";
			rewind(stdin);
			cin >> a;
			setKPD(a);
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
			cout << "������� ��������: ";
			rewind(stdin);
			cin >> b;
			setBlockPow(b);
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
			char oper_type[CH_POW_SIZE];
			cout << "���������: ";
			rewind(stdin);
			cin.getline(oper_type, CH_POW_SIZE, '\n');
			setPowMother(oper_type);
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

bool Power::operator > (Power& ext)
{
	if (strcmp(pow_mother, ext.pow_mother) > 0)
		return true;
	return false;
}

/*bool SSD::operator < (SSD& ext)
{
	if (strcmp(chip, ext.chip) > 0)
		return true;
	return false;
}*/

bool Power::operator == (Power& ext)
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
	if (strcmp(pow_mother, "default") != 0)
		if (strcmp(pow_mother, ext.pow_mother) == 0)
			count++;
		else
			return false;
	return match;
}

void Power::edit()
{
	int choice;
	do {
		cout << "1 - �������� �������" << endl;
		cout << "2 - �������� ������������" << endl;
		cout << "3 - �������� �������������" << endl;
		cout << "4 - �������� ������" << endl;
		cout << "5 - �������� ������� ����������" << endl;
		cout << "6 - �������� ���" << endl;
		cout << "7 - �������� ��������" << endl;
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
			cout << "���: ";
			rewind(stdin);
			cin >> a;
			setKPD(a);
			break;
		}
		case 7:
		{
			long long int b;
			cout << "��������: ";
			rewind(stdin);
			cin >> b;
			setBlockPow(b);
			break;
		}
		case 8:
		{
			char oper_type[CH_POW_SIZE];
			cout << "����������: ";
			rewind(stdin);
			cin.getline(oper_type, CH_POW_SIZE, '\n');
			setPowMother(oper_type);
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

ofstream& operator << (ofstream& out, Power& subscr)
{
	out << dynamic_cast<InternalComplete&>(subscr);
	out << subscr.KPD << '|' << subscr.BlockPow << '|' << subscr.pow_mother << '|';
	return out;
}

ifstream& operator >> (ifstream& in, Power& subscr)
{
	in >> dynamic_cast<InternalComplete&>(subscr);
	in >> subscr.KPD;
	in >> subscr.BlockPow;
	in.getline(subscr.pow_mother, CH_POW_SIZE, '|');
	return in;
}
