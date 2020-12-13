#pragma once
#include <iostream>
#include "sha256.h"
#include <windows.h>
#include <conio.h>
#include <fstream>

using namespace std;

const string PASS_WAY = "D://main.cpp/Interface.dat"; 

//default 98502e479612f04bc425da8a10f2a3fba5f338537011ce86613e14e44a54feea

void inputPass(string& s);
void hidePass(string& s);
bool checkUser(string);
void rewritePass(string);
void checkDefaultPass();
void core();
