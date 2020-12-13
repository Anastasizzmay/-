#pragma once
#include"InternalComplete.h"
const int CH_HARD_SIZE = 15;

class Hard : public InternalComplete
{
public:
	void header();
protected:
	long long int round;
	long long int time;
	char hard_type[CH_HARD_SIZE];
public:
	Hard();
	void searchInstance();
	void setRound(long long int);
	void setTime(long long int);
	void setHardType(const char[CH_HARD_SIZE]);
	long long int getRound();
	long long int getTime();
	char* getHardType();
	void edit();

	bool operator > (Hard& ext);
	bool operator < (Hard& ext);
	bool operator == (Hard& ext);

	friend ostream& operator << (ostream& out, Hard& subscr);
	friend istream& operator >> (istream& in, Hard& subscr);

	friend ofstream& operator << (ofstream& out, Hard& subscr);
	friend ifstream& operator >> (ifstream& in, Hard& subscr);

	~Hard() {}
};