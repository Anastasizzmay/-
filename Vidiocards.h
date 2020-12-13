#pragma once
#include "InternalComplete.h"
const int CH_GRAF_SIZE = 20;
class Vidiocards : public InternalComplete
{
public:
	void header();
protected:
	char graf_processor[CH_GRAF_SIZE];
	long long int date;
	bool DirectX;
public:
	Vidiocards();
	void searchInstance();
	void setGrafProcessor(const char[CH_GRAF_SIZE]);
	void setDate(long long int);
	void setDirectX(bool);
	char* getGrafProcessor();
	long long int getDate();
	bool getDirectX();
	void edit();

	bool operator > (Vidiocards& ext);
//	bool operator < (Vidiocards& ext);
	bool operator == (Vidiocards& ext);

	friend ostream& operator << (ostream& out, Vidiocards& subscr);
	friend istream& operator >> (istream& in, Vidiocards& subscr);

	friend ofstream& operator << (ofstream& out, Vidiocards& subscr);
	friend ifstream& operator >> (ifstream& in, Vidiocards& subscr);

	~Vidiocards() {}
};

