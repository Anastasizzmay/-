#pragma once
#include"InternalComplete.h"
const int CH_POW_SIZE = 15;

class Power : public InternalComplete
{
public:
	void header();
protected:
	long long int KPD;
	long long int BlockPow;
	char pow_mother[CH_POW_SIZE];
public:
	Power();
	void searchInstance();
	void setKPD(long long int);
	void setBlockPow(long long int);
	void setPowMother(const char[CH_POW_SIZE]);
	long long int getKPD();
	long long int getBlockPow();
	char* getPowMother();
	void edit();

	bool operator > (Power& ext);
	bool operator < (Power& ext);
	bool operator == (Power& ext);

	friend ostream& operator << (ostream& out, Power& subscr);
	friend istream& operator >> (istream& in, Power& subscr);

	friend ofstream& operator << (ofstream& out, Power& subscr);
	friend ifstream& operator >> (ifstream& in, Power& subscr);

	~Power() {}
};