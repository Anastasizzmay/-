#include "complete.h"

complete::complete()
{
	vendor_code = 0;
	quantity = 0;
	price = 0;
	strcpy_s(nomination, CH_NOM_SIZE, "default");
}

void complete::setNomination(const char address[CH_NOM_SIZE])
{
	strcpy_s(nomination, CH_NOM_SIZE, address);
}

void complete::setVendorCode(long long int number)
{
	vendor_code = number;
}

void complete::setQuantity(long long int number)
{
	quantity = number;
}

void complete::setPrice(long long int number)
{
	price = number;
}

long long int complete::getPrice()
{
	return price;
}

long long int complete::getQuantity()
{
	return quantity;
}

long long int complete::getVendorCode()
{
	return vendor_code;
}

char* complete::getNomination()
{
	return nomination;
}

ostream& operator << (ostream& out, complete& subscr)
{
	out << "|" << setw(17) << subscr.vendor_code << "|" << setw(17) << subscr.quantity << "|" << setw(17) << subscr.price << "|" << setw(CH_NOM_SIZE) << subscr.nomination << "|";
	return out;
}

istream& operator >> (istream& in, complete& subscr)
{
	rewind(stdin);
	cout << "¬ведите наименование детали: ";
	in.getline(subscr.nomination, CH_NOM_SIZE, '\n');
	cout << "¬ведите артикул детали: ";
	in >> subscr.vendor_code;
	cout << "¬ведите количество на складе: ";
	in >> subscr.quantity;
	cout << "¬ведите цену за штуку: ";
	in >> subscr.price;

	return in;
}

ofstream& operator << (ofstream& out, complete& subscr)
{
	out << subscr.vendor_code << " " << subscr.nomination << '|' << subscr.quantity << '|' << subscr.price << '|';
	return out;
}

ifstream& operator >> (ifstream& in, complete& subscr)
{
	in >> subscr.vendor_code;
	char temp[10];
	in.getline(temp, 10, ' ');
	in.getline(subscr.nomination, CH_NOM_SIZE, '|');
	return in;
}