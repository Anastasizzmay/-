#include"SSD.h"

SSD::SSD()
{
	this->InternalComplete::InternalComplete();
	speed = 0;
	buf = 0;
	strcpy_s(interf, CH_INTERF_SIZE, "default");
}

void SSD::setSpeed(long long int a)
{
	speed = a;
}

void SSD::setBuf(long long int b)
{
	buf = b;
}

void SSD::setInterf(const char G[CH_INTERF_SIZE])
{
	strcpy_s(interf, CH_INTERF_SIZE, G);
}

long long int SSD::getSpeed()
{
	return speed;
}

long long int SSD::getBuf()
{
	return buf;
}

char* SSD::getInterf()
{
	return interf;
}

void SSD::header()
{
	int line = 20 + CH_NOM_SIZE + CH_DESIGNATIONIn_SIZE + CH_INTERF_SIZE + 9;
	for (int i = 0; i < line; i++) cout << "-"; cout << endl;
	cout << "| №|" << setw(17) << "Артикул" << "|" << setw(CH_NOM_SIZE) << "Наименование" << setw(17) << "Количество на складе" << "|" << setw(17) << "Цена за штуку";
	cout << "|" << setw(17) << "Охлаждение" << "|" << setw(CH_DESIGNATIONIn_SIZE) << "Производитель ";
	cout << "|" << setw(17) << "Память" << "|" << setw(CH_INTERF_SIZE) << "Интерфейс";
	cout << "|" << setw(17) << "Скорость" << "|" << setw(17) << "Буфер" << "|" << endl;
	for (int i = 0; i < line; i++) cout << "-";
	cout << endl;
}

ostream& operator << (ostream& out, SSD& subscr)
{
	out << dynamic_cast<InternalComplete&>(subscr);
	out << setw(CH_INTERF_SIZE) << subscr.interf;
	out << "|" << setw(17) << subscr.speed << "|" << setw(17) << subscr.buf << "|" << endl;
	int line = 20 + CH_NOM_SIZE + CH_DESIGNATIONIn_SIZE + CH_INTERF_SIZE + 9;
	for (int i = 0; i < line; i++) out << "-";
	return out;
}
istream& operator >> (istream& in, SSD& subscr)
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
	cout << "Введите скорость: ";
	in >> subscr.speed;
	cout << "Введите буфер: ";
	in >> subscr.buf;
	cout << "Введите интерфейс: ";
	in.getline(subscr.interf, CH_INTERF_SIZE);
	return in;
}

void SSD::searchInstance()
{
	int fate;
	do {
		cout << endl << "\t\tКакие параметры добавить к поиску(изменить их): " << endl << endl;
		cout << endl << "1 - Скорость";
		cout << endl << "2 - Производитель";
		cout << endl << "3 - Буфер";
		cout << endl << "4 - Артикул";
		cout << endl << "5 - Интерфейс";
		cout << endl << "6 - Наименование";
		cout << endl << "7 - Начать поиск по введённым параметрам" << endl;
		cout << endl << "~>> ";
		cin >> fate;

		switch (fate)
		{
		case 1:
		{
			long long int a;
			cout << "Введите скорость: ";
			rewind(stdin);
			cin >> a;
			setSpeed(a);
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
			cout << "Введите буфер: ";
			rewind(stdin);
			cin >> b;
			setBuf(b);
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
			char oper_type[CH_INTERF_SIZE];
			cout << "Интерфейс: ";
			rewind(stdin);
			cin.getline(oper_type, CH_INTERF_SIZE, '\n');
			setInterf(oper_type);
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

bool SSD::operator > (SSD& ext)
{
	if (strcmp(interf, ext.interf) > 0)
		return true;
	return false;
}

/*bool SSD::operator < (SSD& ext)
{
	if (strcmp(chip, ext.chip) > 0)
		return true;
	return false;
}*/

bool SSD::operator == (SSD& ext)
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
	if (strcmp(interf, "default") != 0)
		if (strcmp(interf, ext.interf) == 0)
			count++;
		else
			return false;
	return match;
}

void SSD::edit()
{
	int choice;
	do {
		cout << "1 - Изменить артикул" << endl;
		cout << "2 - Изменить наименование" << endl;
		cout << "3 - Изменить производителя" << endl;
		cout << "4 - Изменить память" << endl;
		cout << "5 - Изменить наличие охлаждения" << endl;
		cout << "6 - Изменить cкорость" << endl;
		cout << "7 - Изменить буфер" << endl;
		cout << "8 - Изменить интерфейс" << endl;
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
			cout << "Скорость: ";
			rewind(stdin);
			cin >> a;
			setSpeed(a);
			break;
		}
		case 7:
		{
			long long int b;
			cout << "Буфер: ";
			rewind(stdin);
			cin >> b;
			setBuf(b);
			break;
		}
		case 8:
		{
			char oper_type[CH_INTERF_SIZE];
			cout << "Охлаждение: ";
			rewind(stdin);
			cin.getline(oper_type, CH_INTERF_SIZE, '\n');
			setInterf(oper_type);
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

ofstream& operator << (ofstream& out, SSD& subscr)
{
	out << dynamic_cast<InternalComplete&>(subscr);
	out << subscr.speed << '|' << subscr.buf << '|' << subscr.interf << '|';
	return out;
}

ifstream& operator >> (ifstream& in, SSD& subscr)
{
	in >> dynamic_cast<InternalComplete&>(subscr);
	in >> subscr.speed;
	in >> subscr.buf;
	in.getline(subscr.interf, CH_INTERF_SIZE, '|');
	return in;
}