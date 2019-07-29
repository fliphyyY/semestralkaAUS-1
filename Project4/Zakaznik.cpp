#include "Zakaznik.h"
#include "heap_monitor.h"
#include <fstream>

Zakaznik::Zakaznik(string pmeno_, int pregion_)
{
	meno_ = pmeno_;
	region_ = pregion_;
	
}

string Zakaznik::getMeno()
{
	return meno_;
}

int Zakaznik::getRegion()
{
	return region_;
}


Zakaznik::~Zakaznik()
{
}
