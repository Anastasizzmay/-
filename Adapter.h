#pragma once
#include"InternalComplete.h"
const int CH_CONNECT_SIZE = 15;

class Adapter : public InternalComplete
{
public:
	void header();
protected:
	long long int LC;
	long long int SC;
	long long int SFP;
	char connect[CH_CONNECT_SIZE];
public:
	Adapter();
	void searchInstance();
	void setLC(long long int);
	void setSC(long long int);
	void setSFP(long long int);
	void setConnect(const char[CH_CONNECT_SIZE]);
	long long int getLC();
	long long int getSC();
	long long int getSFP();
	char* getConnect();
	void edit();

	bool operator > (Adapter& ext);
	bool operator < (Adapter& ext);
	bool operator == (Adapter& ext);

	friend ostream& operator << (ostream& out, Adapter& subscr);
	friend istream& operator >> (istream& in, Adapter& subscr);

	friend ofstream& operator << (ofstream& out, Adapter& subscr);
	friend ifstream& operator >> (ifstream& in, Adapter& subscr);

	~Adapter() {}
};