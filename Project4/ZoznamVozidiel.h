#pragma once
#include "list/array_list.h"
#include "Vozidlo.h"
#include "Datum.h"
#include <fstream>
#include "heap_monitor.h"

using namespace structures;

class ZoznamVozidiel
{

private:
	Datum *datum;
	ArrayList <Vozidlo*> *park;
	string date;
	const int kapacHra = 5000;
	const int kapacLup = 2000;
	
public:
	ZoznamVozidiel(Datum *dat);
    void pridajV(Vozidlo *vozidlo);
	Vozidlo * getV(int i);
	void nacitaj();
	void vypis();
	int getSizeP();
	int spocitaj(bool typ);
	const int getkapacHra();
	const int getkapacLup();
	~ZoznamVozidiel();
	
};

