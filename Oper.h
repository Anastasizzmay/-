#pragma once
#include"InternalComplete.h"
const int CH_OPER_SIZE = 15;

class Oper : public InternalComplete
{
public:
	void header();
protected:
	long long int modul;
	long long int period;
	char oper_type[CH_OPER_SIZE];
public:
	Oper();
	void searchInstance();
	void setModul(long long int);
	void setPeriod(long long int);
	void setOperType(const char[CH_OPER_SIZE]);
	long long int getModul();
	long long int getPeriod();
	char* getOperType();
	void edit();

	bool operator > (Oper& ext);
	bool operator < (Oper& ext);
	bool operator == (Oper& ext);

	friend ostream& operator << (ostream& out, Oper& subscr);
	friend istream& operator >> (istream& in, Oper& subscr);

	friend ofstream& operator << (ofstream& out, Oper& subscr);
	friend ifstream& operator >> (ifstream& in, Oper& subscr);

	~Oper() {}
};