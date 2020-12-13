#pragma once
#include "ExternalComplete.h"


const int CH_MATRIX_SIZE = 15;


class Monitor : public ExternalComplete
{
public:
	void header();
protected:
	char matrix[CH_MATRIX_SIZE];
	long long int dimensions_screen;
	long long int light;
public:
	Monitor();
	void searchInstance();
	void setMatrix(const char[CH_MATRIX_SIZE]);
	void setDimensionsScreen(long long int);
	void setLight(long long int);
	char* getMatrix();
	long long int getDimensionsScreen();
	long long int getLight();
	void edit();

	bool operator > (Monitor& ext);
	bool operator < (Monitor& ext);
	bool operator == (Monitor& ext);

	friend ostream& operator << (ostream& out, Monitor& subscr);
	friend istream& operator >> (istream& in, Monitor& subscr);

	friend ofstream& operator << (ofstream& out, Monitor& subscr);
	friend ifstream& operator >> (ifstream& in, Monitor& subscr);

	~Monitor() {}
};
