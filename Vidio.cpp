#include "Vidio.h"

Vidio::Vidio()
{
	this->InternalComplete::InternalComplete();
	HDMI = 0;
	VGA = 0;
	DVI = 0;
}

void Vidio::setHDMI(bool HDMi)
{
	HDMI = HDMi;
}

void Vidio::setVGA(bool VGa)
{
	VGA = VGa;
}

void Vidio::setDVI(bool DVi)
{
	DVI = DVi;
}

bool Vidio::getHDMI()
{
	return HDMI;
}

bool Vidio::getVGA()
{
	return VGA;
}

bool Vidio::getDVI()
{
	return DVI;
}

void Vidio::header()
{
	int line = 20 + CH_NOM_SIZE + CH_DESIGNATIONIn_SIZE + 9;
	for (int i = 0; i < line; i++) cout << "-"; cout << endl;
	cout << "| №|" << setw(17) << "Артикул" << "|" << setw(CH_NOM_SIZE) << "Наименование" << setw(17) << "Количество на складе" << "|" << setw(17) << "Цена за штуку";
	cout << "|" << setw(17) << "Охлаждение" << "|" << setw(CH_DESIGNATIONIn_SIZE) << "Производитель ";
	cout << "|" << setw(17) << "Память" << "|" << setw(17) << "HDMI";
	cout << "|" << setw(17) << "VGA" << "|" << setw(17) << "DVI" << "|" << endl;
	for (int i = 0; i < line; i++) cout << "-";
	cout << endl;
}

ostream& operator << (ostream& out, Vidio& subscr)
{
	out << dynamic_cast<InternalComplete&>(subscr);
	out << setw(17) << subscr.HDMI;
	out << "|" << setw(17) << subscr.VGA << "|" << setw(17) << subscr.DVI << "|" << endl;
	int line = 20 + CH_NOM_SIZE + CH_DESIGNATIONIn_SIZE + 9;
	for (int i = 0; i < line; i++) out << "-";
	return out;
}
istream& operator >> (istream& in, Vidio& subscr)
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
	cout << "Введите наличие HDMI: ";
	in >> subscr.HDMI;
	cout << "Введите наличие VGA: ";
	in >> subscr.VGA;
	cout << "Введите наличие DVI: ";
	in >> subscr.DVI;
	return in;
}

void Vidio::searchInstance()
{
	int fate;
	do {
		cout << endl << "\t\tКакие параметры добавить к поиску(изменить их): " << endl << endl;
		cout << endl << "1 - VGA";
		cout << endl << "2 - Производитель";
		cout << endl << "3 - HDMI";
		cout << endl << "4 - Артикул";
		cout << endl << "5 - DVI";
		cout << endl << "6 - Наименование";
		cout << endl << "7 - Начать поиск по введённым параметрам" << endl;
		cout << endl << "~>> ";
		cin >> fate;

		switch (fate)
		{
		case 1:
		{
			bool VGA;
			cout << "Введите наличие VGA: ";
			rewind(stdin);
			cin >> VGA;
			setVGA(VGA);
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
			bool HDMI;
			cout << "Введите размеры: ";
			rewind(stdin);
			cin >> HDMI;
			setHDMI(HDMI);
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
			bool DVI;
			cout << "Цвет подсветки: ";
			rewind(stdin);
			cin >> DVI;
			setDVI(DVI);
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

bool Vidio::operator == (Vidio& ext)
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
	return match;
}

void Vidio::edit()
{
	int choice;
	do {
		cout << "1 - Изменить артикул" << endl;
		cout << "2 - Изменить наименование" << endl;
		cout << "3 - Изменить производителя" << endl;
		cout << "4 - Изменить память" << endl;
		cout << "5 - Изменить наличие охлаждения" << endl;
		cout << "6 - Изменить HDMI" << endl;
		cout << "7 - Изменить VGA" << endl;
		cout << "8 - Изменить DVI" << endl;
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
			bool HDMI;
			cout << "Введите HDMI: ";
			rewind(stdin);
			cin >> HDMI;
			setHDMI(HDMI);
			break;
		}
		case 7:
		{
			bool VGA;
			cout << "Введите VGA: ";
			rewind(stdin);
			cin >> VGA;
			setVGA(VGA);
			break;
		}
		case 8:
		{
			bool DVI;
			cout << "Введите DVI: ";
			rewind(stdin);
			cin >> DVI;
			setDVI(DVI);
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

ofstream& operator << (ofstream& out, Vidio& subscr)
{
	out << dynamic_cast<InternalComplete&>(subscr);
	out << subscr.HDMI << '|' << subscr.VGA << '|' << subscr.DVI << '|';
	return out;
}

ifstream& operator >> (ifstream& in, Vidio& subscr)
{
	in >> dynamic_cast<InternalComplete&>(subscr);
	in >> subscr.HDMI;
	in >> subscr.VGA;
	in >> subscr.DVI;
	return in;
}