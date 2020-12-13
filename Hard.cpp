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
	cout << "| №|" << setw(17) << "Артикул" << "|" << setw(CH_NOM_SIZE) << "Наименование" << setw(17) << "Количество на складе" << "|" << setw(17) << "Цена за штуку";
	cout << "|" << setw(17) << "Охлаждение" << "|" << setw(CH_DESIGNATIONIn_SIZE) << "Производитель ";
	cout << "|" << setw(17) << "Память" << "|" << setw(CH_HARD_SIZE) << "Тип";
	cout << "|" << setw(17) << "Вращения" << "|" << setw(17) << "Время" << "|" << endl;
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
	cout << "Введите вращения: ";
	in >> subscr.round;
	cout << "Введите время: ";
	in >> subscr.time;
	cout << "Введите тип: ";
	in.getline(subscr.hard_type, CH_HARD_SIZE);
	return in;
}

void Hard::searchInstance()
{
	int fate;
	do {
		cout << endl << "\t\tКакие параметры добавить к поиску(изменить их): " << endl << endl;
		cout << endl << "1 - Вращения";
		cout << endl << "2 - Производитель";
		cout << endl << "3 - В ремя";
		cout << endl << "4 - Артикул";
		cout << endl << "5 - Тип";
		cout << endl << "6 - Наименование";
		cout << endl << "7 - Начать поиск по введённым параметрам" << endl;
		cout << endl << "~>> ";
		cin >> fate;

		switch (fate)
		{
		case 1:
		{
			long long int a;
			cout << "Введите вращения: ";
			rewind(stdin);
			cin >> a;
			setRound(a);
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
			cout << "Введите время: ";
			rewind(stdin);
			cin >> b;
			setTime(b);
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
			char oper_type[CH_HARD_SIZE];
			cout << "Интерфейс: ";
			rewind(stdin);
			cin.getline(oper_type, CH_HARD_SIZE, '\n');
			setHardType(oper_type);
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
		cout << "1 - Изменить артикул" << endl;
		cout << "2 - Изменить наименование" << endl;
		cout << "3 - Изменить производителя" << endl;
		cout << "4 - Изменить память" << endl;
		cout << "5 - Изменить наличие охлаждения" << endl;
		cout << "6 - Изменить вращения" << endl;
		cout << "7 - Изменить время" << endl;
		cout << "8 - Изменить тип" << endl;
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
			cout << "Вращения: ";
			rewind(stdin);
			cin >> a;
			setRound(a);
			break;
		}
		case 7:
		{
			long long int b;
			cout << "Время: ";
			rewind(stdin);
			cin >> b;
			setTime(b);
			break;
		}
		case 8:
		{
			char oper_type[CH_HARD_SIZE];
			cout << "Охлаждение: ";
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