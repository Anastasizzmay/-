#pragma once
#include"InternalComplete.h"
const int CH_METH_SIZE = 15;

class Optic : public InternalComplete
{
public:
	void header();
protected:
	long long int BDXL;
	long long int BD;
	char meth[CH_METH_SIZE];
public:
	Optic();
	void searchInstance();
	void setBDXL(long long int);
	void setBD(long long int);
	void setMeth(const char[CH_METH_SIZE]);
	long long int getBDXL();
	long long int getBD();
	char* getMeth();
	void edit();

	bool operator > (Optic& ext);
	bool operator < (Optic& ext);
	bool operator == (Optic& ext);

	friend ostream& operator << (ostream& out, Optic& subscr);
	friend istream& operator >> (istream& in, Optic& subscr);

	friend ofstream& operator << (ofstream& out, Optic& subscr);
	friend ifstream& operator >> (ifstream& in, Optic& subscr);

	~Optic() {}
};