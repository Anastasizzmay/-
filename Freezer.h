#pragma once
#include"InternalComplete.h"
const int CH_FREEZER_SIZE = 15;

class Freezer : public InternalComplete
{
public:
	void header();
protected:
	long long int caliber;
	long long int warm_tube;
	char freezer_type[CH_FREEZER_SIZE];
public:
	Freezer();
	void searchInstance();
	void setCaliber(long long int);
	void setWarmTube(long long int);
	void setFreezerType(const char[CH_FREEZER_SIZE]);
	long long int getCaliber();
	long long int getWarmTube();
	char* getFreezerType();
	void edit();

	bool operator > (Freezer& ext);
	bool operator < (Freezer& ext);
	bool operator == (Freezer& ext);

	friend ostream& operator << (ostream& out, Freezer& subscr);
	friend istream& operator >> (istream& in, Freezer& subscr);

	friend ofstream& operator << (ofstream& out, Freezer& subscr);
	friend ifstream& operator >> (ifstream& in, Freezer& subscr);

	~Freezer() {}
};