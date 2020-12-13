#include"Vidiocards.h"

Vidiocards::Vidiocards()
{
	this->InternalComplete::InternalComplete();
	date = 0;
	DirectX = 0;
	strcpy_s(graf_processor, CH_GRAF_SIZE, "default");
}

void Vidiocards::setDirectX(bool D)
{
	DirectX = D;
}

void Vidiocards::setDate(long long int D)
{
	date = D;
}

void Vidiocards::setGrafProcessor(const char G[CH_GRAF_SIZE])
{
	strcpy_s(graf_processor, CH_GRAF_SIZE, G);
}

bool Vidiocards::getDirectX()
{
	return DirectX;
}

long long int Vidiocards::getDate()
{
	return date;
}

char* Vidiocards::getGrafProcessor()
{
	return graf_processor;
}

void Vidiocards::header()
{
	int line = 20 + CH_NOM_SIZE + CH_DESIGNATIONIn_SIZE + CH_GRAF_SIZE + 9;
	for (int i = 0; i < line; i++) cout << "-"; cout << endl;
	cout << "| №|" << setw(17) << "Артикул" << "|" << setw(CH_NOM_SIZE) << "Наименование" << setw(17) << "Количество на складе" << "|" << setw(17) << "Цена за штуку";
	cout << "|" << setw(17) << "Охлаждение" << "|" << setw(CH_DESIGNATIONIn_SIZE) << "Производитель ";
	cout << "|" << setw(17) << "Память" << "|" << setw(17) << "DirectX";
	cout << "|" << setw(17) << "date" << "|" << setw(CH_GRAF_SIZE) << "graf_processor" << "|" << endl;
	for (int i = 0; i < line; i++) cout << "-";
	cout << endl;
}

ostream& operator << (ostream& out, Vidiocards& subscr)
{
	out << dynamic_cast<InternalComplete&>(subscr);
	out << setw(17) << subscr.DirectX;
	out << "|" << setw(17) << subscr.date << "|" << setw(CH_GRAF_SIZE) << subscr.graf_processor << "|" << endl;
	int line = 20 + CH_NOM_SIZE + CH_DESIGNATIONIn_SIZE + CH_GRAF_SIZE + 9;
	for (int i = 0; i < line; i++) out << "-";
	return out;
}
istream& operator >> (istream& in, Vidiocards& subscr)
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
	cout << "Введите дату выпуска: ";
	in >> subscr.date;
	cout << "Введите наличие DirectX: ";
	in >> subscr.DirectX;
	cout << "Введите тип графического процессора: ";
	in.getline(subscr.graf_processor, CH_GRAF_SIZE);
	return in;
}

void Vidiocards::searchInstance()
{
	int fate;
	do {
		cout << endl << "\t\tКакие параметры добавить к поиску(изменить их): " << endl << endl;
		cout << endl << "1 - Дата выпуска";
		cout << endl << "2 - Производитель";
		cout << endl << "3 - DirectX";
		cout << endl << "4 - Артикул";
		cout << endl << "5 - Тип графического процессора";
		cout << endl << "6 - Наименование";
		cout << endl << "7 - Начать поиск по введённым параметрам" << endl;
		cout << endl << "~>> ";
		cin >> fate;

		switch (fate)
		{
		case 1:
		{
			long long int date;
			cout << "Введите дату выпуска: ";
			rewind(stdin);
			cin >> date;
			setDate(date);
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
			bool DirectX;
			cout << "Введите наличие DirectX: ";
			rewind(stdin);
			cin >> DirectX;
			setDirectX(DirectX);
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
			char g[CH_GRAF_SIZE];
			cout << "Тип графического процессора: ";
			rewind(stdin);
			cin.getline(g, CH_GRAF_SIZE, '\n');
			setGrafProcessor(g);
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

bool Vidiocards::operator > (Vidiocards& ext)
{
	if (strcmp(graf_processor, ext.graf_processor) > 0)
		return true;
	return false;
}

bool Vidiocards::operator == (Vidiocards& ext)
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
	if (strcmp(graf_processor, "default") != 0)
		if (strcmp(graf_processor, ext.graf_processor) == 0)
			count++;
		else
			return false;
	return match;
}

void Vidiocards::edit()
{
	int choice;
	do {
		cout << "1 - Изменить артикул" << endl;
		cout << "2 - Изменить наименование" << endl;
		cout << "3 - Изменить производителя" << endl;
		cout << "4 - Изменить память" << endl;
		cout << "5 - Изменить наличие охлаждения" << endl;
		cout << "6 - Изменить наличие DirectX" << endl;
		cout << "7 - Изменить дату выхода" << endl;
		cout << "8 - Изменить тип графического процессора" << endl;
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
			bool DirectX;
			cout << "Введите DirectX: ";
			rewind(stdin);
			cin >> DirectX;
			setDirectX(DirectX);
			break;
		}
		case 7:
		{
			long long int date;
			cout << "дата: ";
			rewind(stdin);
			cin >> date;
			setDate(date);
			break;
		}
		case 8:
		{
			char g[CH_GRAF_SIZE];
			cout << "Тип графического процессора: ";
			rewind(stdin);
			cin.getline(g, CH_GRAF_SIZE, '\n');
			setGrafProcessor(g);
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

ofstream& operator << (ofstream& out, Vidiocards& subscr)
{
	out << dynamic_cast<InternalComplete&>(subscr);
	out << subscr.DirectX << '|' << subscr.date << '|' << subscr.graf_processor << '|';
	return out;
}

ifstream& operator >> (ifstream& in, Vidiocards& subscr)
{
	in >> dynamic_cast<InternalComplete&>(subscr);
	in >> subscr.DirectX;
	in >> subscr.date;
	in.getline(subscr.graf_processor, CH_GRAF_SIZE, '|');
	return in;
}