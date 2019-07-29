#pragma once
#include <string>
#include <iostream>
#include "heap_monitor.h"
using namespace std;

class Vozidlo
{
private:
	
	string spz_;
	bool typ_;
	string datum_ = " ";


public:
	Vozidlo(string pspz_, bool ptyp_, string pdat_);
	string getSpz();
	bool getTyp();
	string & getDat();

	~Vozidlo();
};

