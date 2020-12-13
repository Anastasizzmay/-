#include "Monitor.h"
Monitor::Monitor()
{
	this->ExternalComplete::ExternalComplete();
	strcpy_s(matrix, CH_MATRIX_SIZE, "default");
	dimensions_screen = 0;
	light = 0;
}

void Monitor::setMatrix(const char dimension[CH_MATRIX_SIZE])
{
	strcpy_s(matrix, CH_MATRIX_SIZE, dimension);
}

void Monitor::setDimensionsScreen(long long int dimensionsScreen)
{
	dimensions_screen = dimensionsScreen;
}

void Monitor::setLight(long long int Cell)
{
	light = Cell;
}

char* Monitor::getMatrix()
{
	return matrix;
}

long long int Monitor::getDimensionsScreen()
{
	return dimensions_screen;
}

long long int Monitor::getLight()
{
	return light;
}

void Monitor::header()
{
	int line = 20 + CH_NOM_SIZE + CH_TYPEEX_SIZE + CH_DESIGNATION_SIZE + CH_MATRIX_SIZE + 9;
	for (int i = 0; i < line; i++) cout << "-"; cout << endl;
	cout << "| �|" << setw(17) << "�������" << "|" << setw(CH_NOM_SIZE) << "������������" << setw(17) << "���������� �� ������" << "|" << setw(17) << "���� �� �����";
	cout << "|" << setw(CH_TYPEEX_SIZE) << "���" << "|" << setw(CH_DESIGNATION_SIZE) << "������������� ";
	cout << "|" << setw(17) << "���" << "|" << setw(CH_MATRIX_SIZE) << "�������";
	cout << "|" << setw(17) << "�������" << "|" << setw(17) << "��������� ������" << "|" << endl;
	for (int i = 0; i < line; i++) cout << "-";
	cout << endl;
}

ostream& operator << (ostream& out, Monitor& subscr)
{
	out << dynamic_cast<ExternalComplete&>(subscr);
	out << setw(CH_MATRIX_SIZE) << subscr.matrix;
	out << "|" << setw(17) << subscr.dimensions_screen << "|" << setw(17) << subscr.light << "|" << endl;
	int line = 20 + CH_NOM_SIZE + CH_TYPEEX_SIZE + CH_DESIGNATION_SIZE + CH_MATRIX_SIZE +  9;
	for (int i = 0; i < line; i++) out << "-";
	return out;
}
istream& operator >> (istream& in, Monitor& subscr)
{
	cin.clear();
	cin.ignore(256, '\n');
	cout << "������� ������������: ";
	in.getline(subscr.nomination, CH_NOM_SIZE);
	cout << "������� ����� ��������: ";
	in >> subscr.vendor_code;
	cout << "������� ���������� �� ������: ";
	in >> subscr.quantity;
	cout << "������� ���� �� �����: ";
	in >> subscr.price;
	cout << "������� ���: ";
	in.getline(subscr.type, CH_TYPEEX_SIZE);
	cout << "������� �������������: ";
	in.getline(subscr.producer, CH_DESIGNATION_SIZE);
	cout << "������� ���: ";
	in >> subscr.weight;
	cin.clear();
	cin.ignore(256, '\n');
	cout << "������� ��� �������: ";
	in.getline(subscr.matrix, CH_MATRIX_SIZE);
	cout << "������� ��������� ������: ";
	in >> subscr.dimensions_screen;
	cout << "������� �������: ";
	in >> subscr.light;
	return in;
}

bool Monitor::operator > (Monitor& ext)
{
	if (strcmp(producer, ext.producer) > 0)
		return true;
	return false;
}

bool Monitor::operator < (Monitor& ext)
{
	if (strcmp(type, ext.type) > 0)
		return true;
	return false;
}


void Monitor::searchInstance()
{
	int fate;
	do {
		cout << endl << "\t\t����� ��������� �������� � ������(�������� ��): " << endl << endl;
		cout << endl << "1 - ���";
		cout << endl << "2 - �������������";
		cout << endl << "3 - �������";
		cout << endl << "4 - �������";
		cout << endl << "5 - ��������� ������";
		cout << endl << "6 - ������������";
		cout << endl << "7 - ������ ����� �� �������� ����������" << endl;
		cout << endl << "~>> ";
		cin >> fate;

		switch (fate)
		{
		case 1:
		{
			char addr[CH_TYPEEX_SIZE];
			cout << "������� ���: ";
			rewind(stdin);
			cin.getline(addr, CH_TYPEEX_SIZE, '\n');
			setType(addr);
			break;
		}
		case 2:
		{
			char name[CH_DESIGNATION_SIZE];
			cout << "������� �������������: ";
			rewind(stdin);
			cin.getline(name, CH_DESIGNATION_SIZE);
			setProducer(name);
			break;
		}
		case 3:
		{
			char surname[CH_MATRIX_SIZE];
			cout << "������� ��� �������: ";
			rewind(stdin);
			cin.getline(surname, CH_MATRIX_SIZE, '\n');
			setMatrix(surname);
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
			long long int role;
			cout << "������� ��������� ������: ";
			rewind(stdin);
			cin >> role;
			setDimensionsScreen(role);
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

bool Monitor::operator == (Monitor& ext)
{
	bool match = true;
	int count = 0;
	if (strcmp(nomination, "default") != 0)
		if (strcmp(nomination, ext.nomination) == 0)
			count++;
		else
			return false;
	if (strcmp(type, "default") != 0)
		if (strcmp(type, ext.type) == 0)
			count++;
		else
			return false;
	if (strcmp(producer, "default") != 0)
		if (strcmp(producer, ext.producer) == 0)
			count++;
		else
			return false;
	if (strcmp(matrix, "default") != 0)
		if (strcmp(matrix, ext.matrix) == 0)
			count++;
		else
			return false;
	return match;
}

void Monitor::edit()
{
	int choice;
	do {
		cout << "1 - �������� �������" << endl;
		cout << "2 - �������� ������������" << endl;
		cout << "3 - �������� �������������" << endl;
		cout << "4 - �������� ���" << endl;
		cout << "5 - �������� ���" << endl;
		cout << "6 - �������� ��� �������" << endl;
		cout << "7 - �������� �������" << endl;
		cout << "8 - �������� ��������� ������" << endl;
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
			char name[CH_DESIGNATION_SIZE];
			cout << "������� ������ �������������: ";
			rewind(stdin);
			cin.getline(name, CH_DESIGNATION_SIZE);
			setProducer(name);
			break;
		}
		case 4:
		{
			char surname[CH_TYPEEX_SIZE];
			cout << "������� ����� ���: ";
			rewind(stdin);
			cin.getline(surname, CH_TYPEEX_SIZE, '\n');
			setType(surname);
			break;
		}
		case 5:
		{
			long long int weight;
			cout << "������� ����� ���: ";
			rewind(stdin);
			cin >> weight;
			setWeight(weight);
			break;
		}
		case 6:
		{
			char date[CH_MATRIX_SIZE];
			cout << "������� ����� ��� �������: ";
			rewind(stdin);
			cin.getline(date, CH_MATRIX_SIZE, '\n');
			setMatrix(date);
			break;
		}
		case 7:
		{
			long long int light;
			cout << "������� ����� �������: ";
			rewind(stdin);
			cin >> light;
			setLight(light);
			break;
		}
		case 8:
		{
			long long int cell;
			cout << "������� ����� ��������� ������: ";
			rewind(stdin);
			cin >> cell;
			setDimensionsScreen(cell);
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

ofstream& operator << (ofstream& out, Monitor& subscr)
{
	out << dynamic_cast<ExternalComplete&>(subscr);
	out << subscr.matrix << '|' << subscr.light << '|' << subscr.dimensions_screen << '|';
	return out;
}

ifstream& operator >> (ifstream& in, Monitor& subscr)
{
	in >> dynamic_cast<ExternalComplete&>(subscr);
	in.getline(subscr.matrix, CH_MATRIX_SIZE, '|');
	in >> subscr.light;
	in >> subscr.dimensions_screen;
	return in;
}