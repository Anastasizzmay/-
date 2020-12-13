#include"Sound.h"

Sound::Sound()
{
	this->InternalComplete::InternalComplete();
	USB = 0;
	Chanel = 0;
	strcpy_s(colours, CH_COLOURS_SIZE, "default");
}

void Sound::setUSB(long long int a)
{
	USB = a;
}

void Sound::setChanel(long long int b)
{
	Chanel = b;
}

void Sound::setColours(const char G[CH_COLOURS_SIZE])
{
	strcpy_s(colours, CH_COLOURS_SIZE, G);
}

long long int Sound::getUSB()
{
	return USB;
}

long long int Sound::getChanel()
{
	return Chanel;
}

char* Sound::getColours()
{
	return colours;
}

void Sound::header()
{
	int line = 20 + CH_NOM_SIZE + CH_DESIGNATIONIn_SIZE + CH_COLOURS_SIZE + 9;
	for (int i = 0; i < line; i++) cout << "-"; cout << endl;
	cout << "| �|" << setw(17) << "�������" << "|" << setw(CH_NOM_SIZE) << "������������" << setw(17) << "���������� �� ������" << "|" << setw(17) << "���� �� �����";
	cout << "|" << setw(17) << "����������" << "|" << setw(CH_DESIGNATIONIn_SIZE) << "������������� ";
	cout << "|" << setw(17) << "������" << "|" << setw(CH_COLOURS_SIZE) << "����";
	cout << "|" << setw(17) << "USB " << "|" << setw(17) << "������" << "|" << endl;
	for (int i = 0; i < line; i++) cout << "-";
	cout << endl;
}

ostream& operator << (ostream& out, Sound& subscr)
{
	out << dynamic_cast<InternalComplete&>(subscr);
	out << setw(CH_COLOURS_SIZE) << subscr.colours;
	out << "|" << setw(17) << subscr.USB << "|" << setw(17) << subscr.Chanel << "|" << endl;
	int line = 20 + CH_NOM_SIZE + CH_DESIGNATIONIn_SIZE + CH_COLOURS_SIZE + 9;
	for (int i = 0; i < line; i++) out << "-";
	return out;
}
istream& operator >> (istream& in, Sound& subscr)
{
	cin.clear();
	cin.ignore(256, '\n');
	cout << "������� ������������: ";
	in.getline(subscr.nomination, CH_NOM_SIZE);
	cout << "������� �������: ";
	in >> subscr.vendor_code;
	cout << "������� ���������� �� ������: ";
	in >> subscr.quantity;
	cout << "������� ���� �� �����: ";
	in >> subscr.price;
	cout << "������� �������������: ";
	in.getline(subscr.producer, CH_DESIGNATIONIn_SIZE);
	cout << "������� ������� ����������: ";
	in >> subscr.freez;
	cout << "������� ����� ������: ";
	in >> subscr.volume;
	cin.clear();
	cin.ignore(256, '\n');
	cout << "������� USB: ";
	in >> subscr.USB;
	cout << "������� ������: ";
	in >> subscr.Chanel;
	cout << "������� ����: ";
	in.getline(subscr.colours, CH_COLOURS_SIZE);
	return in;
}

void Sound::searchInstance()
{
	int fate;
	do {
		cout << endl << "\t\t����� ��������� �������� � ������(�������� ��): " << endl << endl;
		cout << endl << "1 - USB ";
		cout << endl << "2 - �������������";
		cout << endl << "3 - ������";
		cout << endl << "4 - �������";
		cout << endl << "5 - ����";
		cout << endl << "6 - ������������";
		cout << endl << "7 - ������ ����� �� �������� ����������" << endl;
		cout << endl << "~>> ";
		cin >> fate;

		switch (fate)
		{
		case 1:
		{
			long long int a;
			cout << "������� USB : ";
			rewind(stdin);
			cin >> a;
			setUSB(a);
			break;
		}
		case 2:
		{
			char name[CH_DESIGNATIONIn_SIZE];
			cout << "������� �������������: ";
			rewind(stdin);
			cin.getline(name, CH_DESIGNATIONIn_SIZE);
			setProducer(name);
			break;
		}
		case 3:
		{
			long long int b;
			cout << "������� ��������: ";
			rewind(stdin);
			cin >> b;
			setChanel(b);
			break;
		}
		case 4:
		{
			long long int patronymic;
			cout << "�������: ";
			rewind(stdin);
			cin >> patronymic;
			setVendorCode(patronymic);
			break;
		}
		case 5:
		{
			char oper_type[CH_COLOURS_SIZE];
			cout << "����: ";
			rewind(stdin);
			cin.getline(oper_type, CH_COLOURS_SIZE, '\n');
			setColours(oper_type);
			break;
		}
		case 6:
		{
			char date[CH_NOM_SIZE];
			cout << "������������: ";
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

bool Sound::operator > (Sound& ext)
{
	if (strcmp(colours, ext.colours) > 0)
		return true;
	return false;
}

/*bool SSD::operator < (SSD& ext)
{
	if (strcmp(chip, ext.chip) > 0)
		return true;
	return false;
}*/

bool Sound::operator == (Sound& ext)
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
	if (strcmp(colours, "default") != 0)
		if (strcmp(colours, ext.colours) == 0)
			count++;
		else
			return false;
	return match;
}

void Sound::edit()
{
	int choice;
	do {
		cout << "1 - �������� �������" << endl;
		cout << "2 - �������� ������������" << endl;
		cout << "3 - �������� �������������" << endl;
		cout << "4 - �������� ������" << endl;
		cout << "5 - �������� ������� ����������" << endl;
		cout << "6 - �������� USB " << endl;
		cout << "7 - �������� ������" << endl;
		cout << "8 - �������� ����" << endl;
		cout << "9 - �����" << endl;
		cout << "~>> ";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			long long int number;
			cout << "������� ����� �������: ";
			cin >> number;
			setVendorCode(number);
			break;
		}
		case 2:
		{
			char addr[CH_NOM_SIZE];
			cout << "������� ����� ������������: ";
			rewind(stdin);
			cin.getline(addr, CH_NOM_SIZE, '\n');
			setNomination(addr);
			break;
		}
		case 3:
		{
			char name[CH_DESIGNATIONIn_SIZE];
			cout << "������� ������ �������������: ";
			rewind(stdin);
			cin.getline(name, CH_DESIGNATIONIn_SIZE);
			setProducer(name);
			break;
		}
		case 4:
		{
			long long int volume;
			cout << "������� ������: ";
			rewind(stdin);
			cin >> volume;
			setVolume(volume);
			break;
		}
		case 5:
		{
			bool freez;
			cout << "������� ������� ����������: ";
			rewind(stdin);
			cin >> freez;
			setFreez(freez);
			break;
		}
		case 6:
		{
			long long int a;
			cout << "USB : ";
			rewind(stdin);
			cin >> a;
			setUSB(a);
			break;
		}
		case 7:
		{
			long long int b;
			cout << "������: ";
			rewind(stdin);
			cin >> b;
			setChanel(b);
			break;
		}
		case 8:
		{
			char oper_type[CH_COLOURS_SIZE];
			cout << "����: ";
			rewind(stdin);
			cin.getline(oper_type, CH_COLOURS_SIZE, '\n');
			setColours(oper_type);
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

ofstream& operator << (ofstream& out, Sound& subscr)
{
	out << dynamic_cast<InternalComplete&>(subscr);
	out << subscr.USB << '|' << subscr.Chanel << '|' << subscr.colours << '|';
	return out;
}

ifstream& operator >> (ifstream& in, Sound& subscr)
{
	in >> dynamic_cast<InternalComplete&>(subscr);
	in >> subscr.USB;
	in >> subscr.Chanel;
	in.getline(subscr.colours, CH_COLOURS_SIZE, '|');
	return in;
}
