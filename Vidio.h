#pragma once
#include "InternalComplete.h"

class Vidio : public InternalComplete
{
public:
	void header();
protected:
	bool HDMI; 
	bool VGA;
	bool DVI;
public:
	Vidio();
	void searchInstance();
	void setHDMI(bool);
	void setVGA(bool);
	void setDVI(bool);
	bool getHDMI();
	bool getVGA();
	bool getDVI();
	void edit();

//	bool operator > (Vidio& ext);
//	bool operator < (Vidio& ext);
	bool operator == (Vidio& ext);

	friend ostream& operator << (ostream& out, Vidio& subscr);
	friend istream& operator >> (istream& in, Vidio& subscr);

	friend ofstream& operator << (ofstream& out, Vidio& subscr);
	friend ifstream& operator >> (ifstream& in, Vidio& subscr);

	~Vidio() {}
};
