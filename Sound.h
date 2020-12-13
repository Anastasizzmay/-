#pragma once
#include"InternalComplete.h"
const int CH_COLOURS_SIZE = 15;

class Sound : public InternalComplete
{
public:
	void header();
protected:
	long long int USB;
	long long int Chanel;
	char colours[CH_COLOURS_SIZE];
public:
	Sound();
	void searchInstance();
	void setUSB(long long int);
	void setChanel(long long int);
	void setColours(const char[CH_COLOURS_SIZE]);
	long long int getUSB();
	long long int getChanel();
	char* getColours();
	void edit();

	bool operator > (Sound& ext);
	bool operator < (Sound& ext);
	bool operator == (Sound& ext);

	friend ostream& operator << (ostream& out, Sound& subscr);
	friend istream& operator >> (istream& in, Sound& subscr);

	friend ofstream& operator << (ofstream& out, Sound& subscr);
	friend ifstream& operator >> (ifstream& in, Sound& subscr);

	~Sound() {}
};