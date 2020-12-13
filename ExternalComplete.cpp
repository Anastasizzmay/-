#include "ExternalComplete.h"

ExternalComplete::ExternalComplete()
{
	weight = 0;
	strcpy_s(producer, CH_DESIGNATION_SIZE, "default");
	strcpy_s(type, CH_TYPEEX_SIZE, "default");
}

ExternalComplete::ExternalComplete(long long int  externalDist,
	const char externalDesign[CH_DESIGNATION_SIZE], const char externalEntAddr[CH_TYPEEX_SIZE])
{
	weight = externalDist;
	strcpy_s(producer, CH_DESIGNATION_SIZE, externalDesign);
	strcpy_s(type, CH_TYPEEX_SIZE, externalEntAddr);
}

void ExternalComplete::setWeight(long long int externalDist)
{
     weight = externalDist;
}

void ExternalComplete::setProducer(const char externalDesign[CH_DESIGNATION_SIZE])
{
	strcpy_s(producer, CH_DESIGNATION_SIZE, externalDesign);
}

void ExternalComplete::setType(const char externalEntAddr[CH_TYPEEX_SIZE])
{
	strcpy_s(type, CH_TYPEEX_SIZE, externalEntAddr);
}

long long int ExternalComplete::getWeight()
{
	return weight;
}

char* ExternalComplete::getProducer()
{
	return producer;
}

char* ExternalComplete::getType()
{
	return type;
}

ostream& operator << (ostream& out, ExternalComplete& subscr)
{
	out << dynamic_cast<complete&>(subscr);
	out << setw(CH_DESIGNATION_SIZE) << subscr.producer << "|" << setw(CH_TYPEEX_SIZE) << subscr.weight;
	out << "|" << setw(CH_TYPEEX_SIZE) << subscr.type << "|";
	return out;
}
istream& operator >> (istream& in, ExternalComplete& subscr)
{

	in >> dynamic_cast<complete&>(subscr);
	rewind(stdin);
	cout << "¬ведите вес: ";
	cin.clear();
	cin.ignore(256, '\n');
	in >> subscr.weight;
	cout << "¬ведите производител€: ";
	in.getline(subscr.producer, CH_DESIGNATION_SIZE);
	cout << "¬ведите тип: ";
	in.getline(subscr.type, CH_TYPEEX_SIZE);
	return in;
}

ofstream& operator << (ofstream& out, ExternalComplete& subscr)
{
	out << dynamic_cast<complete&>(subscr);
	out << subscr.producer << '|' << subscr.weight << '|' << subscr.type << '|';
	return out;
}

ifstream& operator >> (ifstream& in, ExternalComplete& subscr)
{
	in >> dynamic_cast<complete&>(subscr);
	in.getline(subscr.producer, CH_DESIGNATION_SIZE, '|');
	in >> subscr.weight;
	in.getline(subscr.type, CH_TYPEEX_SIZE, '|');
	return in;
}