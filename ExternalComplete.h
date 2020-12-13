#pragma once
#include "complete.h"

const int CH_DESIGNATION_SIZE = 30;
const int CH_TYPEEX_SIZE = 25;
/*Внешние комплектующие*/
class ExternalComplete : public complete
{
protected:
	long long int weight; // вес
	char producer[CH_DESIGNATION_SIZE]; // название производителя
	char type [CH_TYPEEX_SIZE];
public:
	ExternalComplete();
	ExternalComplete(long long int, const char[CH_DESIGNATION_SIZE], const char[CH_TYPEEX_SIZE]);
	void setWeight(long long int);
	void setProducer(const char[CH_DESIGNATION_SIZE]);
	void setType(const char[CH_TYPEEX_SIZE]);
	long long int  getWeight();
	char* getProducer();
	char* getType();
	friend ostream& operator << (ostream& out, ExternalComplete& subscr);
	friend istream& operator >> (istream& in, ExternalComplete& subscr);

	friend ofstream& operator << (ofstream& out, ExternalComplete& subscr);
	friend ifstream& operator >> (ifstream& in, ExternalComplete& subscr);

	~ExternalComplete() {}
};
