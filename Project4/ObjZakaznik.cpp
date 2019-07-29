#include "ObjZakaznik.h"
#include "heap_monitor.h"



ObjZakaznik::ObjZakaznik(Datum *dat, string pdatumZ_, string pzakaznik_, bool ptyp_, int pmnozstvo_, unsigned int pcena_ , string pdatumD_, string pkontrola_)
{

	 datumZ_ = pdatumZ_;
	 zakaznik_ = pzakaznik_;
	 typ_ = ptyp_;
	 mnozstvo_ = pmnozstvo_;
	 cena_ = pcena_;
	 datumD_ = pdatumD_;
	 datum = dat;
	 kontrola = pkontrola_;
}

string & ObjZakaznik::getDatumZ()
{
	return datumZ_;
}

string ObjZakaznik::getZakaznik()
{
	return zakaznik_;
}

bool ObjZakaznik::getTyp()
{
	return typ_;
}

int ObjZakaznik::getMnozsto()
{
	return mnozstvo_;
}

unsigned int ObjZakaznik::getCena()
{
	return cena_;
}

string ObjZakaznik::getDatumD()
{
	return datumD_;
}

string& ObjZakaznik::getKontrola()
{
	return kontrola;
}


ObjZakaznik::~ObjZakaznik()
{
}
