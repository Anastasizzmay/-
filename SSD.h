#pragma once
#include"InternalComplete.h"
const int CH_INTERF_SIZE = 15;

class SSD : public InternalComplete
{
public:
	void header();
protected:
	long long int speed;
	long long int buf;
	char interf[CH_INTERF_SIZE];
public:
	SSD();
	void searchInstance();
	void setSpeed(long long int);
	void setBuf(long long int);
	void setInterf(const char[CH_INTERF_SIZE]);
	long long int getSpeed();
	long long int getBuf();
	char* getInterf();
	void edit();

	bool operator > (SSD& ext);
	bool operator < (SSD& ext);
	bool operator == (SSD& ext);

	friend ostream& operator << (ostream& out, SSD& subscr);
	friend istream& operator >> (istream& in, SSD& subscr);

	friend ofstream& operator << (ofstream& out, SSD& subscr);
	friend ifstream& operator >> (ifstream& in, SSD& subscr);

	~SSD() {}
};