#pragma once
#include "Datum.h"
#include "heap_monitor.h"
#include "Biofarmar.h"
#include "Zakaznik.h"
#include "ObjZakaznik.h"
#include "list/array_list.h"
#include <fstream>

using namespace structures;
using namespace std;
class Firma
{

private:

	Datum * datum_;
	ArrayList<Biofarmar*> *zoznamB;
	ArrayList<Zakaznik*> *zoznamZ;
	ArrayList<ObjZakaznik*> *zoznamOz;

	int  zemiaky_;
	int  olej_;
	int ochucovadla_;

	int dzem_;
	int dolej_;
	int doch_;
	string datN;
	string zakaz;
public:
	Firma(Datum *dat);
	void pridajZ(Zakaznik * zakaznik);
	void pridajBs(Biofarmar * farmar);
	void pridajBk(Biofarmar * farmar);
	void PridajOz(ObjZakaznik * oz);

	void nacitajZ();
	void nacitajB();
	void vypisZ();
	void vypisB();
	void vypis();
    void nakup();

	int getSizeOz();
	void nacitajOz();

	int zistiH();
	int zistiL();

	int& getZem();
	int& getOlej();
	int& getOchu();
	int& getDzem();
	int& getDolej();
	int& getDoch();
	int najmTrz();

	double vypocZem();
	double vypocOlej();
	double vypocOch();

	int getSizeZ();
	Zakaznik * getZ(int i);
	Biofarmar * getB(int i);
	ObjZakaznik * getOz(int i);
	int getSizeB();
	void spocZas();
	void nakup2();
	void aktualizuj();
	void objZaNas();

	int zistiReg();
	int overKapac(string datum, bool typ);
	void zruseneObj();
	int najmTrzby();
	int zistiH1();
	int zistiL1();

	double vypocZem1();
	double vypocOlej1();
	double vypocOch1();
	void priemCenaBio();

	void zapisBiofarmarov(const string filename);
	
	~Firma();
};

