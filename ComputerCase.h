#pragma once
#include "ExternalComplete.h"


const int CH_CASE_SIZE = 15;
const int CH_COLOUR_SIZE = 20;

class ComputerCase : public ExternalComplete
{
public:
	void header();
protected:
	char dimensions[CH_CASE_SIZE];
	char colour[CH_COLOUR_SIZE]; 
	long long int cell;
public:
	ComputerCase();
	void searchInstance();
	void setDimensions(const char[CH_CASE_SIZE]);
	void setColour(const char[CH_CASE_SIZE]);
	void setCell(long long int);
	char* getDimensions();
	char* getColour();
	long long int getCell();
	void edit();

	bool operator > (ComputerCase& ext);
	bool operator < (ComputerCase& ext);
	bool operator == (ComputerCase& ext);

	friend ostream& operator << (ostream& out, ComputerCase& subscr);
	friend istream& operator >> (istream& in, ComputerCase& subscr);

	friend ofstream& operator << (ofstream& out, ComputerCase& subscr);
	friend ifstream& operator >> (ifstream& in, ComputerCase& subscr);

	~ComputerCase() {}
};
