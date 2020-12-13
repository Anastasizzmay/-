#pragma once
#include "complete.h"

const int CH_DESIGNATIONIn_SIZE = 30;


class InternalComplete : public complete
{
protected:
	long long int volume;
	char producer[CH_DESIGNATIONIn_SIZE];
	bool freez;
public:
	InternalComplete();
	InternalComplete(long long int, const char[CH_DESIGNATIONIn_SIZE]);
	void setVolume(long long int);
	void setProducer(const char[CH_DESIGNATIONIn_SIZE]);
	void setFreez(bool);
	long long int  getVolume();
	char* getProducer();
	bool getFreez(); 
	friend ostream& operator << (ostream& out, InternalComplete& subscr);
	friend istream& operator >> (istream& in, InternalComplete& subscr);

	friend ofstream& operator << (ofstream& out, InternalComplete& subscr);
	friend ifstream& operator >> (ifstream& in, InternalComplete& subscr);

	~InternalComplete() {}
};
