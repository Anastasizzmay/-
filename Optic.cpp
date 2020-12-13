#include"Optic.h"

Optic::Optic()
{
	this->InternalComplete::InternalComplete();
	BDXL = 0;
	BD = 0;
	strcpy_s(meth, CH_METH_SIZE, "default");
}

void Optic::setBDXL(long long int a)
{
	BDXL = a;
}

void Optic::setBD(long long int b)
{
	BD = b;
}

void Optic::setMeth(const char G[CH_METH_SIZE])
{
	strcpy_s(meth, CH_METH_SIZE, G);
}

long long int Optic::getBDXL()
{
	return BDXL;
}

long long int Optic::getBD()
{
	return BD;
}

char* Optic::getMeth()
{
	return meth;
}

void Optic::header()
{
	int line = 20 + CH_NOM_SIZE + CH_DESIGNATIONIn_SIZE + CH_METH_SIZE + 9;
	for (int i = 0; i < line; i++) cout << "-"; cout << endl;
	cout << "| �|" << setw(17) << "�������" << "|" << setw(CH_NOM_SIZE) << "������������" << setw(17) << "���������� �� ������" << "|" << setw(17) << "���� �� �����";
	cout << "|" << setw(17) << "����������" << "|" << setw(CH_DESIGNATIONIn_SIZE) << "������������� ";
	cout << "|" << setw(17) << "������" << "|" << setw(CH_METH_SIZE) << "��������";
	cout << "|" << setw(17) << "BDXL " << "|" << setw(17) << "BD" << "|" << endl;
	for (int i = 0; i < line; i++) cout << "-";
	cout << endl;
}

ostream& operator << (ostream& out, Optic& subscr)
{
	out << dynamic_cast<InternalComplete&>(subscr);
	out << setw(CH_METH_SIZE) << subscr.meth;
	out << "|" << setw(17) << subscr.BDXL << "|" << setw(17) << subscr.BD << "|" << endl;
	int line = 20 + CH_NOM_SIZE + CH_DESIGNATIONIn_SIZE + CH_METH_SIZE + 9;
	for (int i = 0; i < line; i++) out << "-";
	return out;
}
istream& operator >> (istream& in, Optic& subscr)
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
	cout << "������� BDXL: ";
	in >> subscr.BDXL;
	cout << "������� BD: ";
	in >> subscr.BD;
	cout << "������� ��������: ";
	in.getline(subscr.meth, CH_METH_SIZE);
	return in;
}

void Optic::searchInstance()
{
	int fate;
	do {
		cout << endl << "\t\t����� ��������� �������� � ������(�������� ��): " << endl << endl;
		cout << endl << "1 - BDXL ";
		cout << endl << "2 - �������������";
		cout << endl << "3 - BD";
		cout << endl << "4 - �������";
		cout << endl << "5 - ��������";
		cout << endl << "6 - ������������";
		cout << endl << "7 - ������ ����� �� �������� ����������" << endl;
		cout << endl << "~>> ";
		cin >> fate;

		switch (fate)
		{
		case 1:
		{
			long long int a;
			cout << "������� BDXL : ";
			rewind(stdin);
			cin >> a;
			setBDXL(a);
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
			cout << "������� BD: ";
			rewind(stdin);
			cin >> b;
			setBD(b);
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
			char oper_type[CH_METH_SIZE];
			cout << "��������: ";
			rewind(stdin);
			cin.getline(oper_type, CH_METH_SIZE, '\n');
			setMeth(oper_type);
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

bool Optic::operator > (Optic& ext)
{
	if (strcmp(meth, ext.meth) > 0)
		return true;
	return false;
}

/*bool SSD::operator < (SSD& ext)
{
	if (strcmp(chip, ext.chip) > 0)
		return true;
	return false;
}*/

bool Optic::operator == (Optic& ext)
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
	if (strcmp(meth, "default") != 0)
		if (strcmp(meth, ext.meth) == 0)
			count++;
		else
			return false;
	return match;
}

void Optic::edit()
{
	int choice;
	do {
		cout << "1 - �������� �������" << endl;
		cout << "2 - �������� ������������" << endl;
		cout << "3 - �������� �������������" << endl;
		cout << "4 - �������� ������" << endl;
		cout << "5 - �������� ������� ����������" << endl;
		cout << "6 - �������� BDXL " << endl;
		cout << "7 - �������� BD" << endl;
		cout << "8 - �������� ��������" << endl;
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
			cout << "BDXL  : ";
			rewind(stdin);
			cin >> a;
			setBDXL(a);
			break;
		}
		case 7:
		{
			long long int b;
			cout << "BD: ";
			rewind(stdin);
			cin >> b;
			setBD(b);
			break;
		}
		case 8:
		{
			char oper_type[CH_METH_SIZE];
			cout << "��������: ";
			rewind(stdin);
			cin.getline(oper_type, CH_METH_SIZE, '\n');
			setMeth(oper_type);
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

ofstream& operator << (ofstream& out, Optic& subscr)
{
	out << dynamic_cast<InternalComplete&>(subscr);
	out << subscr.BDXL << '|' << subscr.BD << '|' << subscr.meth << '|';
	return out;
}

ifstream& operator >> (ifstream& in, Optic& subscr)
{
	in >> dynamic_cast<InternalComplete&>(subscr);
	in >> subscr.BDXL;
	in >> subscr.BD;
	in.getline(subscr.meth, CH_METH_SIZE, '|');
	return in;
}