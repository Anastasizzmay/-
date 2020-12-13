#pragma once
#include "InternalComplete.h"
const int CH_MODEL_SIZE = 20;
const int CH_STAND_SIZE = 20;
class Processors : public InternalComplete
{
public:
	void header();
protected:
	char model[CH_MODEL_SIZE];
	long long int core;
	char stand[CH_STAND_SIZE];
public:
	Processors();
	void searchInstance();
	void setModel(const char[CH_MODEL_SIZE]);
	void setCore(long long int);
	void setStand(const char[CH_STAND_SIZE]);
	char* getModel();
	long long int getCore();
	char* getStand();
	void edit();

	bool operator > (Processors& ext);
	bool operator < (Processors& ext);
	bool operator == (Processors& ext);

	friend ostream& operator << (ostream& out, Processors& subscr);
	friend istream& operator >> (istream& in, Processors& subscr);

	friend ofstream& operator << (ofstream& out, Processors& subscr);
	friend ifstream& operator >> (ifstream& in, Processors& subscr);

	~Processors() {}
};