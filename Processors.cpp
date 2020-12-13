#include"Processors.h"

Processors::Processors()
{
	this->InternalComplete::InternalComplete();
	core = 0;
	strcpy_s(model, CH_MODEL_SIZE, "default");
	strcpy_s(stand, CH_STAND_SIZE, "default");
}

void Processors::setCore(long long int D)
{
	core = D;
}

void Processors::setModel(const char mod[CH_MODEL_SIZE])
{
	strcpy_s(model, CH_MODEL_SIZE, mod);
}

void Processors::setStand(const char G[CH_STAND_SIZE])
{
	strcpy_s(stand, CH_STAND_SIZE, G);
}

long long int Processors::getCore()
{
	return core;
}

char* Processors::getModel()
{
	return model;
}

char* Processors::getStand()
{
	return stand;
}

void Processors::header()
{
	int line = 20 + CH_NOM_SIZE + CH_DESIGNATIONIn_SIZE + CH_MODEL_SIZE + CH_STAND_SIZE + 9;
	for (int i = 0; i < line; i++) cout << "-"; cout << endl;
	cout << "| №|" << setw(17) << "Артикул" << "|" << setw(CH_NOM_SIZE) << "Наименование" << setw(17) << "Количество на складе" << "|" << setw(17) << "Цена за штуку";
	cout << "|" << setw(17) << "Охлаждение" << "|" << setw(CH_DESIGNATIONIn_SIZE) << "Производитель ";
	cout << "|" << setw(17) << "Память" << "|" << setw(CH_STAND_SIZE) << "stand";
	cout << "|" << setw(17) << "Ядра" << "|" << setw(CH_MODEL_SIZE) << "модель" << "|" << endl;
	for (int i = 0; i < line; i++) cout << "-";
	cout << endl;
}

ostream& operator << (ostream& out, Processors& subscr)
{
	out << dynamic_cast<InternalComplete&>(subscr);
	out << setw(17) << subscr.core;
	out << "|" << setw(CH_STAND_SIZE) << subscr.model << "|" << setw(CH_STAND_SIZE) << subscr.stand << "|" << endl;
	int line = 20 + CH_NOM_SIZE + CH_DESIGNATIONIn_SIZE + CH_MODEL_SIZE + CH_STAND_SIZE + 9;
	for (int i = 0; i < line; i++) out << "-";
	return out;
}
istream& operator >> (istream& in, Processors& subscr)
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
	cout << "Введите количество ядер: ";
	in >> subscr.core;
	cout << "Введите модель: ";
	in.getline(subscr.model, CH_MODEL_SIZE);
	cout << "Введите stand: ";
	in.getline(subscr.stand, CH_STAND_SIZE);
	return in;
}

void Processors::searchInstance()
{
	int fate;
	do {
		cout << endl << "\t\tКакие параметры добавить к поиску(изменить их): " << endl << endl;
		cout << endl << "1 - stand";
		cout << endl << "2 - Производитель";
		cout << endl << "3 - Кол-во ядер";
		cout << endl << "4 - Артикул";
		cout << endl << "5 - Модель";
		cout << endl << "6 - Наименование";
		cout << endl << "7 - Начать поиск по введённым параметрам" << endl;
		cout << endl << "~>> ";
		cin >> fate;

		switch (fate)
		{
		case 1:
		{
			char stand[CH_STAND_SIZE];
			cout << "Введите stand: ";
			rewind(stdin);
			cin.getline(stand, CH_STAND_SIZE);
			setProducer(stand);
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
			long long int core;
			cout << "Введите кол-во ядер: ";
			rewind(stdin);
			cin >> core;
			setCore(core);
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
			char g[CH_MODEL_SIZE];
			cout << "Модель: ";
			rewind(stdin);
			cin.getline(g, CH_MODEL_SIZE, '\n');
			setModel(g);
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

bool Processors::operator > (Processors& ext)
{
	if (strcmp(model, ext.model) > 0)
		return true;
	return false;
}

bool Processors::operator < (Processors& ext)
{
	if (strcmp(stand, ext.stand) > 0)
		return true;
	return false;
}

bool Processors::operator == (Processors& ext)
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
	if (strcmp(model, "default") != 0)
		if (strcmp(model, ext.model) == 0)
			count++;
		else
			return false;
	if (strcmp(stand, "default") != 0)
		if (strcmp(stand, ext.stand) == 0)
			count++;
		else
			return false;
	return match;
}

void Processors::edit()
{
	int choice;
	do {
		cout << "1 - Изменить артикул" << endl;
		cout << "2 - Изменить наименование" << endl;
		cout << "3 - Изменить производителя" << endl;
		cout << "4 - Изменить память" << endl;
		cout << "5 - Изменить наличие охлаждения" << endl;
		cout << "6 - Изменить кол-во ядер" << endl;
		cout << "7 - Изменить модель" << endl;
		cout << "8 - Изменить stand" << endl;
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
			long long int core;
			cout << "Введите кол-во ядер: ";
			rewind(stdin);
			cin >> core;
			setCore(core);
			break;
		}
		case 7:
		{
			char model[CH_MODEL_SIZE];
			cout << "Модель: ";
			rewind(stdin);
			cin.getline(model, CH_MODEL_SIZE, '\n');
			setModel(model);
			break;
		}
		case 8:
		{
			char g[CH_STAND_SIZE];
			cout << "stand: ";
			rewind(stdin);
			cin.getline(g, CH_STAND_SIZE, '\n');
			setStand(g);
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

ofstream& operator << (ofstream& out, Processors& subscr)
{
	out << dynamic_cast<InternalComplete&>(subscr);
	out << subscr.stand << '|' << subscr.model << '|' << subscr.core << '|';
	return out;
}

ifstream& operator >> (ifstream& in, Processors& subscr)
{
	in >> dynamic_cast<InternalComplete&>(subscr);
	in >> subscr.core;
	in.getline(subscr.model, CH_MODEL_SIZE, '|');
	in.getline(subscr.stand, CH_STAND_SIZE, '|');
	return in;
}