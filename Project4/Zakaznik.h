#pragma once
#include <string>
#include "list/array_list.h"
#include <iostream>
#include "heap_monitor.h"
using namespace std;
using namespace structures;

class Zakaznik
{


private: 
	string meno_;
	int region_;
	
public:



	Zakaznik(string pmeno_, int pregion_);
	string getMeno();
	int getRegion();
	
	
	
	
	~Zakaznik();
};

