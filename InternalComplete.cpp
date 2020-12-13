#include "InternalComplete.h"

InternalComplete::InternalComplete()
{
	volume = 0;
	strcpy_s(producer, CH_DESIGNATIONIn_SIZE, "default");
}

InternalComplete::InternalComplete(long long int  externalDist,
	const char externalDesign[CH_DESIGNATIONIn_SIZE])
{
	volume = externalDist;
	strcpy_s(producer, CH_DESIGNATIONIn_SIZE, externalDesign);
}

void InternalComplete::setVolume(long long int externalDist)
{
	volume = externalDist;
}

void InternalComplete::setFreez(bool externalDist)
{
	freez = externalDist;
}

void InternalComplete::setProducer(const char externalDesign[CH_DESIGNATIONIn_SIZE])
{
	strcpy_s(producer, CH_DESIGNATIONIn_SIZE, externalDesign);
}

long long int InternalComplete::getVolume()
{
	return volume;
}

bool InternalComplete::getFreez()
{
	return freez;
}

char* InternalComplete::getProducer()
{
	return producer;
}


ostream& operator << (ostream& out, InternalComplete& subscr)
{
	out << dynamic_cast<complete&>(subscr);
	out << setw(CH_DESIGNATIONIn_SIZE) << subscr.producer << "|" << setw(17) << subscr.volume;
	return out;
}
istream& operator >> (istream& in, InternalComplete& subscr)
{

	in >> dynamic_cast<complete&>(subscr);
	rewind(stdin);
	cout << "Введите район расположения юридического лица: ";
	cin.clear();
	cin.ignore(256, '\n');
	in >> subscr.volume;
	cout << "Введите наименование юридического лица: ";
	in.getline(subscr.producer, CH_DESIGNATIONIn_SIZE);
	return in;
}

ofstream& operator << (ofstream& out, InternalComplete& subscr)
{
	out << dynamic_cast<complete&>(subscr);
	out << subscr.producer << '|' << subscr.volume << '|';
	return out;
}

ifstream& operator >> (ifstream& in, InternalComplete& subscr)
{
	in >> dynamic_cast<complete&>(subscr);
	in.getline(subscr.producer, CH_DESIGNATIONIn_SIZE, '|');
	in >> subscr.volume;
	return in;
}