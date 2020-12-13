#include"Oper.h"

Oper::Oper()
{
	this->InternalComplete::InternalComplete();
	modul = 0;
	period = 0;
	strcpy_s(oper_type, CH_OPER_SIZE, "default");
}

void Oper::setModul(long long int a)
{
	modul = a;
}

void Oper::setPeriod(long long int b)
{
	period = b;
}

void Oper::setOperType(const char G[CH_OPER_SIZE])
{
	strcpy_s(oper_type, CH_OPER_SIZE, G);
}

long long int Oper::getModul()
{
	return modul;
}

long long int Oper::getPeriod()
{
	return period;
}

char* Oper::getOperType()
{
	return oper_type;
}

void Oper::header()
{
	int line = 20 + CH_NOM_SIZE + CH_DESIGNATIONIn_SIZE + CH_OPER_SIZE + 9;
	for (int i = 0; i < line; i++) cout << "-"; cout << endl;
	cout << "| №|" << setw(17) << "Артикул" << "|" << setw(CH_NOM_SIZE) << "Наименование" << setw(17) << "Количество на складе" << "|" << setw(17) << "Цена за штуку";
	cout << "|" << setw(17) << "Охлаждение" << "|" << setw(CH_DESIGNATIONIn_SIZE) << "Производитель ";
	cout << "|" << setw(17) << "Память" << "|" << setw(CH_OPER_SIZE) << "Операционка";
	cout << "|" << setw(17) << "Модуль" << "|" << setw(17) << "Период" << "|" << endl;
	for (int i = 0; i < line; i++) cout << "-";
	cout << endl;
}

ostream& operator << (ostream& out, Oper& subscr)
{
	out << dynamic_cast<InternalComplete&>(subscr);
	out << setw(CH_OPER_SIZE) << subscr.oper_type;
	out << "|" << setw(17) << subscr.modul << "|" << setw(17) << subscr.period << "|" << endl;
	int line = 20 + CH_NOM_SIZE + CH_DESIGNATIONIn_SIZE + CH_OPER_SIZE + 9;
	for (int i = 0; i < line; i++) out << "-";
	return out;
}
istream& operator >> (istream& in, Oper& subscr)
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
	cout << "Введите модуль: ";
	in >> subscr.modul;
	cout << "Введите период: ";
	in >> subscr.period;
	cout << "Введите операционку: ";
	in.getline(subscr.oper_type, CH_OPER_SIZE);
	return in;
}

void Oper::searchInstance()
{
	int fate;
	do {
		cout << endl << "\t\tКакие параметры добавить к поиску(изменить их): " << endl << endl;
		cout << endl << "1 - Модуль";
		cout << endl << "2 - Производитель";
		cout << endl << "3 - Период";
		cout << endl << "4 - Артикул";
		cout << endl << "5 - Операцинка";
		cout << endl << "6 - Наименование";
		cout << endl << "7 - Начать поиск по введённым параметрам" << endl;
		cout << endl << "~>> ";
		cin >> fate;

		switch (fate)
		{
		case 1:
		{
			long long int a;
			cout << "Введите модуль: ";
			rewind(stdin);
			cin >> a;
			setModul(a);
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
			cout << "Введите период: ";
			rewind(stdin);
			cin >> b;
			setPeriod(b);
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
			char oper_type[CH_OPER_SIZE];
			cout << "Операционка: ";
			rewind(stdin);
			cin.getline(oper_type, CH_OPER_SIZE, '\n');
			setOperType(oper_type);
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

bool Oper::operator > (Oper& ext)
{
	if (strcmp(oper_type, ext.oper_type) > 0)
		return true;
	return false;
}

/*bool Oper::operator < (Oper& ext)
{
	if (strcmp(chip, ext.chip) > 0)
		return true;
	return false;
}*/

bool Oper::operator == (Oper& ext)
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
	if (strcmp(oper_type, "default") != 0)
		if (strcmp(oper_type, ext.oper_type) == 0)
			count++;
		else
			return false;
	return match;
}

void Oper::edit()
{
	int choice;
	do {
		cout << "1 - Изменить артикул" << endl;
		cout << "2 - Изменить наименование" << endl;
		cout << "3 - Изменить производителя" << endl;
		cout << "4 - Изменить память" << endl;
		cout << "5 - Изменить наличие охлаждения" << endl;
		cout << "6 - Изменить период" << endl;
		cout << "7 - Изменить модуль" << endl;
		cout << "8 - Изменить операционка" << endl;
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
			cout << "Период: ";
			rewind(stdin);
			cin >> a;
			setPeriod(a);
			break;
		}
		case 7:
		{
			long long int b;
			cout << "Модуль: ";
			rewind(stdin);
			cin >> b;
			setModul(b);
			break;
		}
		case 8:
		{
			char oper_type[CH_OPER_SIZE];
			cout << "Чип-сет: ";
			rewind(stdin);
			cin.getline(oper_type, CH_OPER_SIZE, '\n');
			setOperType(oper_type);
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

ofstream& operator << (ofstream& out, Oper& subscr)
{
	out << dynamic_cast<InternalComplete&>(subscr);
	out << subscr.modul << '|' << subscr.period << '|' << subscr.oper_type << '|';
	return out;
}

ifstream& operator >> (ifstream& in, Oper& subscr)
{
	in >> dynamic_cast<InternalComplete&>(subscr);
	in >> subscr.modul;
	in >> subscr.period;
	in.getline(subscr.oper_type, CH_OPER_SIZE, '|');
	return in;
}