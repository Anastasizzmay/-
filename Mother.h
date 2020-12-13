#pragma once
#include "InternalComplete.h"
const int CH_FACTOR_SIZE = 15;
const int CH_SOKET_SIZE = 20;
const int CH_CHIP_SIZE = 15;
class Mother : public InternalComplete
{
public:
	void header();
protected:
	char factor[CH_FACTOR_SIZE];
	char soket[CH_SOKET_SIZE];
	char chip[CH_CHIP_SIZE];
public:
	Mother();
	void searchInstance();
	void setFactor(const char[CH_FACTOR_SIZE]);
	void setSoket(const char[CH_SOKET_SIZE]);
	void setChip(const char[CH_CHIP_SIZE]);
	char* getFactor();
	char* getSoket();
	char* getChip();
	void edit();

	bool operator > (Mother& ext);
	bool operator < (Mother& ext);
	bool operator == (Mother& ext);

	friend ostream& operator << (ostream& out, Mother& subscr);
	friend istream& operator >> (istream& in, Mother& subscr);

	friend ofstream& operator << (ofstream& out, Mother& subscr);
	friend ifstream& operator >> (ifstream& in, Mother& subscr);

	~Mother() {}
};