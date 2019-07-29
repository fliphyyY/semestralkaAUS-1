#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>
#include <ctime>
#include <string>
#include "heap_monitor.h"
using namespace std;
class Datum
{
private:
	int rok_;
	int mesiac_;
	int den_;


public:
	Datum();

	string getDatum();
	void pridajDen();
	int zmenDatum(string &input);
    string datum7 ();
	string datum1();
	string datum30();

	~Datum();
};

