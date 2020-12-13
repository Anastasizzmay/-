#include"Mother.h"

Mother::Mother()
{
	this->InternalComplete::InternalComplete();
	strcpy_s(factor, CH_FACTOR_SIZE, "default");
	strcpy_s(soket, CH_SOKET_SIZE, "default");
	strcpy_s(chip, CH_CHIP_SIZE, "default");
}

void Mother::setFactor(const char fac[CH_FACTOR_SIZE])
{
	strcpy_s(factor, CH_FACTOR_SIZE, fac);
}

void Mother::setSoket(const char sok[CH_SOKET_SIZE])
{
	strcpy_s(soket, CH_SOKET_SIZE, sok);
}

void Mother::setChip(const char G[CH_CHIP_SIZE])
{
	strcpy_s(chip, CH_CHIP_SIZE, G);
}

char* Mother::getFactor()
{
	return factor;
}

char* Mother::getSoket()
{
	return soket;
}

char* Mother::getChip()
{
	return chip;
}

void Mother::header()
{
	int line = 20 + CH_NOM_SIZE + CH_DESIGNATIONIn_SIZE + CH_FACTOR_SIZE + CH_SOKET_SIZE + CH_CHIP_SIZE + 9;
	for (int i = 0; i < line; i++) cout << "-"; cout << endl;
	cout << "| №|" << setw(17) << "Артикул" << "|" << setw(CH_NOM_SIZE) << "Наименование" << setw(17) << "Количество на складе" << "|" << setw(17) << "Цена за штуку";
	cout << "|" << setw(17) << "Охлаждение" << "|" << setw(CH_DESIGNATIONIn_SIZE) << "Производитель ";
	cout << "|" << setw(17) << "Память" << "|" << setw(CH_FACTOR_SIZE) << "Форм-фактор";
	cout << "|" << setw(CH_SOKET_SIZE) << "Сокет" << "|" << setw(CH_CHIP_SIZE) << "Чип" << "|" << endl;
	for (int i = 0; i < line; i++) cout << "-";
	cout << endl;
}

ostream& operator << (ostream& out, Mother& subscr)
{
	out << dynamic_cast<InternalComplete&>(subscr);
	out << setw(CH_FACTOR_SIZE) << subscr.factor;
	out << "|" << setw(CH_SOKET_SIZE) << subscr.soket << "|" << setw(CH_CHIP_SIZE) << subscr.chip << "|" << endl;
	int line = 20 + CH_NOM_SIZE + CH_DESIGNATIONIn_SIZE + CH_FACTOR_SIZE + CH_SOKET_SIZE + CH_CHIP_SIZE + 9;
	for (int i = 0; i < line; i++) out << "-";
	return out;
}
istream& operator >> (istream& in, Mother& subscr)
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
	cout << "Введите форм-фактор: ";
	in.getline(subscr.factor, CH_FACTOR_SIZE);
	cout << "Введите сокет: ";
	in.getline(subscr.soket, CH_SOKET_SIZE);
	cout << "Введите чип-сет: ";
	in.getline(subscr.chip, CH_CHIP_SIZE);
	return in;
}

void Mother::searchInstance()
{
	int fate;
	do {
		cout << endl << "\t\tКакие параметры добавить к поиску(изменить их): " << endl << endl;
		cout << endl << "1 - Форм-фактор";
		cout << endl << "2 - Производитель";
		cout << endl << "3 - Сокет";
		cout << endl << "4 - Артикул";
		cout << endl << "5 - Чип-сет";
		cout << endl << "6 - Наименование";
		cout << endl << "7 - Начать поиск по введённым параметрам" << endl;
		cout << endl << "~>> ";
		cin >> fate;

		switch (fate)
		{
		case 1:
		{
			char factor[CH_FACTOR_SIZE];
			cout << "Введите форм-фактор: ";
			rewind(stdin);
			cin.getline(factor, CH_FACTOR_SIZE);
			setFactor(factor);
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
			char soket[CH_SOKET_SIZE];
			cout << "Введите сокет: ";
			rewind(stdin);
			cin.getline(soket, CH_SOKET_SIZE);
			setSoket(soket);
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
			char g[CH_CHIP_SIZE];
			cout << "Модель: ";
			rewind(stdin);
			cin.getline(g, CH_CHIP_SIZE, '\n');
			setChip(g);
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

bool Mother::operator > (Mother& ext)
{
	if (strcmp(soket, ext.soket) > 0)
		return true;
	return false;
}

bool Mother::operator < (Mother& ext)
{
	if (strcmp(chip, ext.chip) > 0)
		return true;
	return false;
}

bool Mother::operator == (Mother& ext)
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
	if (strcmp(factor, "default") != 0)
		if (strcmp(factor, ext.factor) == 0)
			count++;
		else
			return false;
	if (strcmp(soket, "default") != 0)
		if (strcmp(soket, ext.soket) == 0)
			count++;
		else
			return false;
	if (strcmp(chip, "default") != 0)
		if (strcmp(chip, ext.chip) == 0)
			count++;
		else
			return false;
	return match;
}

void Mother::edit()
{
	int choice;
	do {
		cout << "1 - Изменить артикул" << endl;
		cout << "2 - Изменить наименование" << endl;
		cout << "3 - Изменить производителя" << endl;
		cout << "4 - Изменить память" << endl;
		cout << "5 - Изменить наличие охлаждения" << endl;
		cout << "6 - Изменить форм-фактор" << endl;
		cout << "7 - Изменить сокет" << endl;
		cout << "8 - Изменить чип-сет" << endl;
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
			char factor[CH_FACTOR_SIZE];
			cout << "Форм-фактор: ";
			rewind(stdin);
			cin.getline(factor, CH_FACTOR_SIZE, '\n');
			setFactor(factor);
			break;
		}
		case 7:
		{
			char soket[CH_SOKET_SIZE];
			cout << "Сокет: ";
			rewind(stdin);
			cin.getline(soket, CH_SOKET_SIZE, '\n');
			setSoket(soket);
			break;
		}
		case 8:
		{
			char g[CH_CHIP_SIZE];
			cout << "Чип-сет: ";
			rewind(stdin);
			cin.getline(g, CH_CHIP_SIZE, '\n');
			setChip(g);
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

ofstream& operator << (ofstream& out, Mother& subscr)
{
	out << dynamic_cast<InternalComplete&>(subscr);
	out << subscr.factor << '|' << subscr.soket << '|' << subscr.chip << '|';
	return out;
}

ifstream& operator >> (ifstream& in, Mother& subscr)
{
	in >> dynamic_cast<InternalComplete&>(subscr);
	in.getline(subscr.factor, CH_FACTOR_SIZE, '|');
	in.getline(subscr.soket, CH_SOKET_SIZE, '|');
	in.getline(subscr.chip, CH_CHIP_SIZE, '|');
	return in;
}