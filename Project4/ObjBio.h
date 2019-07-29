#pragma once
#include <string>
#include "Datum.h"
using namespace std;
class ObjBio
{

private:

	Datum * dat;
	string meno_;
	int mnozstvo_;
	char typ_;
	int cena_;
	string datumObj_;
	int priemCena_;


public:
	ObjBio(string pmeno_ , int pmnozstvo_, char ptyp_ , int pcena_, string pdatumObj_, int ppriemCena);
	~ObjBio();
	int getMnoz();
	char getTyp();
	int getCena();
	string getDatumObj();
	string getMeno();
	int& getpriemCena();
	
};

