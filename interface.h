#pragma once
#include <iostream>
#include <Windows.h>
#include "list.cpp"
#include "userValidation.h"

#include "Adapter.h"
#include "SSD.h"
#include "Vidio.h"
#include "Hard.h"
#include "Monitor.h"
#include "Freezer.h"
#include"ComputerCase.h"
#include"Mother.h"
#include"Oper.h"
#include"Optic.h"
#include"Power.h"
#include"Processors.h"
#include"Sound.h"
#include"Vidiocards.h"

using namespace std;


template <class T>
class Interface
{
private:
	T subscrType;
public:
	string FileWay;
	Interface() {}

	void objectSelectionMenu();
	void mainLogic();

	~Interface() {}
};
