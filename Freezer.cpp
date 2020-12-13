#include"Freezer.h"

Freezer::Freezer()
{
	this->InternalComplete::InternalComplete();
	caliber = 0;
	warm_tube = 0;
	strcpy_s(freezer_type, CH_FREEZER_SIZE, "default");
}

void Freezer::setCaliber(long long int a)
{
	caliber = a;
}

void Freezer::setWarmTube(long long int b)
{
	warm_tube = b;
}

void Freezer::setFreezerType(const char G[CH_FREEZER_SIZE])
{
	strcpy_s(freezer_type, CH_FREEZER_SIZE, G);
}

long long int Freezer::getCaliber()
{
	return caliber;
}

long long int Freezer::getWarmTube()
{
	return warm_tube;
}

char* Freezer::getFreezerType()
{
	return freezer_type;
}

void Freezer::header()
{
	int line = 20 + CH_NOM_SIZE + CH_DESIGNATIONIn_SIZE + CH_FREEZER_SIZE + 9;
	for (int i = 0; i < line; i++) cout << "-"; cout << endl;
	cout << "| №|" << setw(17) << "Артикул" << "|" << setw(CH_NOM_SIZE) << "Наименование" << setw(17) << "Количество на складе" << "|" << setw(17) << "Цена за штуку";
	cout << "|" << setw(17) << "Охлаждение" << "|" << setw(CH_DESIGNATIONIn_SIZE) << "Производитель ";
	cout << "|" << setw(17) << "Память" << "|" << setw(CH_FREEZER_SIZE) << "Охлаждение";
	cout << "|" << setw(17) << "Калибр" << "|" << setw(17) << "Тепловые трубы" << "|" << endl;
	for (int i = 0; i < line; i++) cout << "-";
	cout << endl;
}

ostream& operator << (ostream& out, Freezer& subscr)
{
	out << dynamic_cast<InternalComplete&>(subscr);
	out << setw(CH_FREEZER_SIZE) << subscr.freezer_type;
	out << "|" << setw(17) << subscr.caliber << "|" << setw(17) << subscr.warm_tube << "|" << endl;
	int line = 20 + CH_NOM_SIZE + CH_DESIGNATIONIn_SIZE + CH_FREEZER_SIZE + 9;
	for (int i = 0; i < line; i++) out << "-";
	return out;
}
istream& operator >> (istream& in, Freezer& subscr)
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
	cout << "Введите калибр: ";
	in >> subscr.caliber;
	cout << "Введите тепловые трубки: ";
	in >> subscr.warm_tube;
	cout << "Введите охлаждение: ";
	in.getline(subscr.freezer_type, CH_FREEZER_SIZE);
	return in;
}

void Freezer::searchInstance()
{
	int fate;
	do {
		cout << endl << "\t\tКакие параметры добавить к поиску(изменить их): " << endl << endl;
		cout << endl << "1 - Калибр";
		cout << endl << "2 - Производитель";
		cout << endl << "3 - Тепловые трубки";
		cout << endl << "4 - Артикул";
		cout << endl << "5 - Охлаждение";
		cout << endl << "6 - Наименование";
		cout << endl << "7 - Начать поиск по введённым параметрам" << endl;
		cout << endl << "~>> ";
		cin >> fate;

		switch (fate)
		{
		case 1:
		{
			long long int a;
			cout << "Введите калибр: ";
			rewind(stdin);
			cin >> a;
			setCaliber(a);
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
			cout << "Введите Тепловые трубки: ";
			rewind(stdin);
			cin >> b;
			setWarmTube(b);
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
			char oper_type[CH_FREEZER_SIZE];
			cout << "Охлаждение: ";
			rewind(stdin);
			cin.getline(oper_type, CH_FREEZER_SIZE, '\n');
			setFreezerType(oper_type);
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

bool Freezer::operator > (Freezer& ext)
{
	if (strcmp(freezer_type, ext.freezer_type) > 0)
		return true;
	return false;
}

/*bool Freezer::operator < (Freezer& ext)
{
	if (strcmp(chip, ext.chip) > 0)
		return true;
	return false;
}*/

bool Freezer::operator == (Freezer& ext)
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
	if (strcmp(freezer_type, "default") != 0)
		if (strcmp(freezer_type, ext.freezer_type) == 0)
			count++;
		else
			return false;
	return match;
}

void Freezer::edit()
{
	int choice;
	do {
		cout << "1 - Изменить артикул" << endl;
		cout << "2 - Изменить наименование" << endl;
		cout << "3 - Изменить производителя" << endl;
		cout << "4 - Изменить память" << endl;
		cout << "5 - Изменить наличие охлаждения" << endl;
		cout << "6 - Изменить калибр" << endl;
		cout << "7 - Изменить тепловые трубки" << endl;
		cout << "8 - Изменить охлаждение" << endl;
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
			cout << "Калибр: ";
			rewind(stdin);
			cin >> a;
			setCaliber(a);
			break;
		}
		case 7:
		{
			long long int b;
			cout << "Тепловые трубки: ";
			rewind(stdin);
			cin >> b;
			setWarmTube(b);
			break;
		}
		case 8:
		{
			char oper_type[CH_FREEZER_SIZE];
			cout << "Охлаждение: ";
			rewind(stdin);
			cin.getline(oper_type, CH_FREEZER_SIZE, '\n');
			setFreezerType(oper_type);
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

ofstream& operator << (ofstream& out, Freezer& subscr)
{
	out << dynamic_cast<InternalComplete&>(subscr);
	out << subscr.caliber << '|' << subscr.warm_tube << '|' << subscr.freezer_type << '|';
	return out;
}

ifstream& operator >> (ifstream& in, Freezer& subscr)
{
	in >> dynamic_cast<InternalComplete&>(subscr);
	in >> subscr.caliber;
	in >> subscr.warm_tube;
	in.getline(subscr.freezer_type, CH_FREEZER_SIZE, '|');
	return in;
}