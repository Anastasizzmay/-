#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>

/*Исходный класс*/

using namespace std;

const int CH_NOM_SIZE = 30;

class complete
{
protected:
	long long int vendor_code;
	char nomination [CH_NOM_SIZE];
	long long int quantity;
	long long int price;
public:
	complete();
	void setVendorCode(long long int);
	void setNomination(const char nomination [CH_NOM_SIZE]);
	void setQuantity(long long int);
	void setPrice(long long int);
	long long int getVendorCode();
	long long int getQuantity();
	long long int getPrice();
	char* getNomination();
	friend ostream& operator << (ostream& out, complete& subscr);
	friend istream& operator >> (istream& in, complete& subscr);

	friend ofstream& operator << (ofstream& out, complete& subscr);
	friend ifstream& operator >> (ifstream& in, complete& subscr);

	~complete() {}
};
