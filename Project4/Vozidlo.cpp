#include "Vozidlo.h"
#include "heap_monitor.h"



Vozidlo::Vozidlo(string pspz_, bool ptyp_, string pdat_)
{

	int nosnot_ = 0;
	int naklady_ = 0;
	spz_ = pspz_;
	typ_ = ptyp_;
	datum_ = pdat_;
}

string Vozidlo::getSpz()
{
	return spz_;
}

bool Vozidlo::getTyp()
{
	return typ_;
}

string & Vozidlo::getDat()
{
	return datum_;
}


Vozidlo::~Vozidlo()
{
}
