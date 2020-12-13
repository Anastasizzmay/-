#include "ComputerCase.h"

ComputerCase::ComputerCase()
{
	this->ExternalComplete::ExternalComplete();
	strcpy_s(dimensions, CH_CASE_SIZE, "default");
	strcpy_s(colour, CH_COLOUR_SIZE, "default");
	cell  = 0;
}

void ComputerCase::setDimensions(const char dimension[CH_CASE_SIZE])
{
	strcpy_s(dimensions, CH_CASE_SIZE, dimension);
}

void ComputerCase::setColour(const char externalRole[CH_CASE_SIZE])
{
	strcpy_s(colour, CH_COLOUR_SIZE, externalRole);
}

void ComputerCase::setCell(long long int Cell)
{
    cell= Cell;
}

char* ComputerCase::getDimensions()
{
	return dimensions; 
}

char* ComputerCase::getColour()
{
	return colour;
}

long long int ComputerCase::getCell()
{
	return cell;
}

void ComputerCase::header()
{
	int line = 20 + CH_NOM_SIZE + CH_TYPEEX_SIZE + CH_DESIGNATION_SIZE + CH_CASE_SIZE + CH_COLOUR_SIZE + 9;
	for (int i = 0; i < line; i++) cout << "-"; cout << endl;
	cout << "| �|" << setw(17) << "�������" << "|" << setw(CH_NOM_SIZE) << "������������" << setw(17) << "���������� �� ������" << "|" << setw(17) << "���� �� �����" ;
	cout << "|" << setw(CH_TYPEEX_SIZE) << "���" << "|" << setw(CH_DESIGNATION_SIZE) << "������������� ";
	cout << "|" << setw(17) << "���" << "|" << setw(CH_CASE_SIZE) << "�������";
	cout << "|" << setw(CH_COLOUR_SIZE) << "���� ���������" << "|" << setw(17) << "���������� �������" << "|" << endl;
	for (int i = 0; i < line; i++) cout << "-";
	cout << endl;
}

ostream& operator << (ostream& out, ComputerCase& subscr)
{
	out << dynamic_cast<ExternalComplete&>(subscr);
	out << setw(CH_CASE_SIZE) << subscr.dimensions;
	out << "|" << setw(CH_COLOUR_SIZE) << subscr.colour << "|"  << setw(17) << subscr.cell << "|" << endl;
	int line = 20 + CH_TYPEEX_SIZE + CH_CASE_SIZE + CH_COLOUR_SIZE + CH_CASE_SIZE + CH_COLOUR_SIZE + 9;
	for (int i = 0; i < line; i++) out << "-";
	return out;
}
istream& operator >> (istream& in, ComputerCase& subscr)
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
	cout << "������� ���: ";
	in.getline(subscr.type, CH_TYPEEX_SIZE);
	cout << "������� �������������: ";
	in.getline(subscr.producer, CH_DESIGNATION_SIZE);
	cout << "������� ���: ";
	in >> subscr.weight;
	cin.clear();
	cin.ignore(256, '\n');
	cout << "������� �������: ";
	in.getline(subscr.dimensions, CH_CASE_SIZE);
	cout << "������� ���� ���������: ";
	in.getline(subscr.colour, CH_COLOUR_SIZE);
	cout << "������� ���������� �������: ";
	in >> subscr.cell;
	return in;
}

bool ComputerCase::operator > (ComputerCase& ext)
{
	if (strcmp(colour, ext.colour) > 0)
		return true;
	return false;
}

bool ComputerCase::operator < (ComputerCase& ext)
{
	if (strcmp(type, ext.type) > 0)
		return true;
	return false;
}


void ComputerCase::searchInstance()
{
	int fate;
	do {
		cout << endl << "\t\t����� ��������� �������� � ������(�������� ��): " << endl << endl;
		cout << endl << "1 - ���";
		cout << endl << "2 - �������������";
		cout << endl << "3 - �������";
		cout << endl << "4 - �������";
		cout << endl << "5 - ���� ���������";
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
			char surname[CH_CASE_SIZE];
			cout << "������� �������: ";
			rewind(stdin);
			cin.getline(surname, CH_CASE_SIZE, '\n');
			setDimensions(surname);
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
			char colour[CH_COLOUR_SIZE];
			cout << "���� ���������: ";
			rewind(stdin);
			cin.getline(colour, CH_COLOUR_SIZE, '\n');
			setNomination(colour);
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

bool ComputerCase::operator == (ComputerCase& ext)
{
	bool match = true;
	int count = 0;
	if (strcmp(producer, "default") != 0)
		if (strcmp(producer, ext.producer) == 0)
			count++;
		else
			return false;
	if (strcmp(type, "default") != 0)
		if (strcmp(type, ext.type) == 0)
			count++;
		else
			return false;
	if (strcmp(nomination, "default") != 0)
		if (strcmp(nomination, ext.nomination) == 0)
			count++;
		else
			return false;
	if (strcmp(colour, "default") != 0)
		if (strcmp(colour, ext.colour) == 0)
			count++;
		else
			return false;
	if (strcmp(dimensions, "default") != 0)
		if (strcmp(dimensions, ext.dimensions) == 0)
			count++;
		else
			return false;

	return match;
}

void ComputerCase::edit()
{
	int choice;
	do {
		cout << "1 - �������� �������" << endl;
		cout << "2 - �������� ������������" << endl;
		cout << "3 - �������� �������������" << endl;
		cout << "4 - �������� ���" << endl;
		cout << "5 - �������� ���" << endl;
		cout << "6 - �������� �������" << endl;
		cout << "7 - �������� ���� ���������" << endl;
		cout << "8 - �������� ���������� �������" << endl;
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
			char date[CH_CASE_SIZE];
			cout << "������� ����� �������: ";
			rewind(stdin);
			cin.getline(date, CH_CASE_SIZE, '\n');
			setDimensions(date);
			break;
		}
		case 7:
		{
			char colour[CH_COLOUR_SIZE];
			cout << "������� ����� ���� ���������: ";
			rewind(stdin);
			cin.getline(colour, CH_COLOUR_SIZE, '\n');
			setDimensions(colour);
			break;
		}
		case 8:
		{
			long long int cell;
			cout << "������� ����� ���������� �������: ";
			rewind(stdin);
			cin >> cell;
			setCell(cell);
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

ofstream& operator << (ofstream& out, ComputerCase& subscr)
{
	out << dynamic_cast<ExternalComplete&>(subscr);
	out << subscr.dimensions << '|' << subscr.cell << '|' << subscr.colour << '|';
	return out;
}

ifstream& operator >> (ifstream& in, ComputerCase& subscr)
{
	in >> dynamic_cast<ExternalComplete&>(subscr);
	in.getline(subscr.dimensions, CH_CASE_SIZE, '|');
	in >> subscr.cell;
	in.getline(subscr.colour, CH_COLOUR_SIZE, '|');
	return in;
}