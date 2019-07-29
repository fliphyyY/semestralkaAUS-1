#pragma once
#include "Datum.h"
#include "heap_monitor.h"
using namespace std;
class ObjZakaznik
{

private:
	Datum *datum;
	string datumZ_;
	string  zakaznik_;
	bool typ_;
	int mnozstvo_;
	unsigned int cena_;
	string datumD_;
	string kontrola;
public:
	ObjZakaznik(Datum *dat, string pdatumZ_, string pzakaznik_, bool ptyp_, int pmnozstvo_, unsigned int pcena_, string pdatumD_, string pkontrola_);


	string & getDatumZ();
	string getZakaznik();
	bool getTyp();
	int getMnozsto();
	unsigned int getCena();
	string getDatumD();
	string & getKontrola();

	~ObjZakaznik();
};

