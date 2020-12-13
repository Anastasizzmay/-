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
	cout << "| №|" << setw(17) << "Артикул" << "|" << setw(CH_NOM_SIZE) << "Наименование" << setw(17) << "Количество на складе" << "|" << setw(17) << "Цена за штуку";
	cout << "|" << setw(17) << "Охлаждение" << "|" << setw(CH_DESIGNATIONIn_SIZE) << "Производитель ";
	cout << "|" << setw(17) << "Память" << "|" << setw(CH_CONNECT_SIZE) << "Соединение";
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
	cout << "Введите LC: ";
	in >> subscr.LC;
	cout << "Введите SC: ";
	in >> subscr.SC;
	cout << "Введите SFP: ";
	in >> subscr.SFP;
	cout << "Введите связь: ";
	in.getline(subscr.connect, CH_CONNECT_SIZE);
	return in;
}

void Adapter::searchInstance()
{
	int fate;
	do {
		cout << endl << "\t\tКакие параметры добавить к поиску(изменить их): " << endl << endl;
		cout << endl << "1 - LC ";
		cout << endl << "2 - Производитель";
		cout << endl << "3 - SFP";
		cout << endl << "4 - Артикул";
		cout << endl << "5 - Связь";
		cout << endl << "6 - Наименование";
		cout << endl << "7 - Начать поиск по введённым параметрам" << endl;
		cout << endl << "~>> ";
		cin >> fate;

		switch (fate)
		{
		case 1:
		{
			long long int a;
			cout << "Введите LC : ";
			rewind(stdin);
			cin >> a;
			setLC(a);
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
			cout << "Введите SFP: ";
			rewind(stdin);
			cin >> b;
			setSFP(b);
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
			char oper_type[CH_CONNECT_SIZE];
			cout << "Связь: ";
			rewind(stdin);
			cin.getline(oper_type, CH_CONNECT_SIZE, '\n');
			setConnect(oper_type);
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
		cout << "1 - Изменить артикул" << endl;
		cout << "2 - Изменить наименование" << endl;
		cout << "3 - Изменить производителя" << endl;
		cout << "4 - Изменить память" << endl;
		cout << "5 - Изменить наличие охлаждения" << endl;
		cout << "6 - Изменить LC" << endl;
		cout << "7 - Изменить SFP" << endl;
		cout << "8 - Изменить соединение" << endl;
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
			cout << "Соединение: ";
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