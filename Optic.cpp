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
	cout << "| №|" << setw(17) << "Артикул" << "|" << setw(CH_NOM_SIZE) << "Наименование" << setw(17) << "Количество на складе" << "|" << setw(17) << "Цена за штуку";
	cout << "|" << setw(17) << "Охлаждение" << "|" << setw(CH_DESIGNATIONIn_SIZE) << "Производитель ";
	cout << "|" << setw(17) << "Память" << "|" << setw(CH_METH_SIZE) << "Механизм";
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
	cout << "Введите наименование: ";
	in.getline(subscr.nomination, CH_NOM_SIZE);
	cout << "Введите артикул: ";
	in >> subscr.vendor_code;
	cout << "Введите количество на складе: ";
	in >> subscr.quantity;
	cout << "Введите цену за штуку: ";
	in >> subscr.price;
	cout << "Введите производителя: ";
	in.getline(subscr.producer, CH_DESIGNATIONIn_SIZE);
	cout << "Введите наличие охлаждения: ";
	in >> subscr.freez;
	cout << "Введите объем памяти: ";
	in >> subscr.volume;
	cin.clear();
	cin.ignore(256, '\n');
	cout << "Введите BDXL: ";
	in >> subscr.BDXL;
	cout << "Введите BD: ";
	in >> subscr.BD;
	cout << "Введите механизм: ";
	in.getline(subscr.meth, CH_METH_SIZE);
	return in;
}

void Optic::searchInstance()
{
	int fate;
	do {
		cout << endl << "\t\tКакие параметры добавить к поиску(изменить их): " << endl << endl;
		cout << endl << "1 - BDXL ";
		cout << endl << "2 - Производитель";
		cout << endl << "3 - BD";
		cout << endl << "4 - Артикул";
		cout << endl << "5 - Механизм";
		cout << endl << "6 - Наименование";
		cout << endl << "7 - Начать поиск по введённым параметрам" << endl;
		cout << endl << "~>> ";
		cin >> fate;

		switch (fate)
		{
		case 1:
		{
			long long int a;
			cout << "Введите BDXL : ";
			rewind(stdin);
			cin >> a;
			setBDXL(a);
			break;
		}
		case 2:
		{
			char name[CH_DESIGNATIONIn_SIZE];
			cout << "Введите производителя: ";
			rewind(stdin);
			cin.getline(name, CH_DESIGNATIONIn_SIZE);
			setProducer(name);
			break;
		}
		case 3:
		{
			long long int b;
			cout << "Введите BD: ";
			rewind(stdin);
			cin >> b;
			setBD(b);
			break;
		}
		case 4:
		{
			long long int patronymic;
			cout << "Артикул: ";
			rewind(stdin);
			cin >> patronymic;
			setVendorCode(patronymic);
			break;
		}
		case 5:
		{
			char oper_type[CH_METH_SIZE];
			cout << "Механизм: ";
			rewind(stdin);
			cin.getline(oper_type, CH_METH_SIZE, '\n');
			setMeth(oper_type);
			break;
		}
		case 6:
		{
			char date[CH_NOM_SIZE];
			cout << "Наименование: ";
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
		cout << "1 - Изменить артикул" << endl;
		cout << "2 - Изменить наименование" << endl;
		cout << "3 - Изменить производителя" << endl;
		cout << "4 - Изменить память" << endl;
		cout << "5 - Изменить наличие охлаждения" << endl;
		cout << "6 - Изменить BDXL " << endl;
		cout << "7 - Изменить BD" << endl;
		cout << "8 - Изменить механизм" << endl;
		cout << "9 - Выход" << endl;
		cout << "~>> ";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			long long int number;
			cout << "Введите новый артикул: ";
			cin >> number;
			setVendorCode(number);
			break;
		}
		case 2:
		{
			char addr[CH_NOM_SIZE];
			cout << "Введите новое наименование: ";
			rewind(stdin);
			cin.getline(addr, CH_NOM_SIZE, '\n');
			setNomination(addr);
			break;
		}
		case 3:
		{
			char name[CH_DESIGNATIONIn_SIZE];
			cout << "Введите нового производителя: ";
			rewind(stdin);
			cin.getline(name, CH_DESIGNATIONIn_SIZE);
			setProducer(name);
			break;
		}
		case 4:
		{
			long long int volume;
			cout << "Введите память: ";
			rewind(stdin);
			cin >> volume;
			setVolume(volume);
			break;
		}
		case 5:
		{
			bool freez;
			cout << "Введите наличие охлаждения: ";
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
			cout << "Механизм: ";
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