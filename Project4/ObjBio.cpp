#include "ObjBio.h"



ObjBio::ObjBio(string pmeno_ , int pmnozstvo_, char ptyp_, int pcena_, string pdatumObj_, int ppriemCena_)
{
	meno_ = pmeno_;
	mnozstvo_ = pmnozstvo_;
	typ_ = ptyp_;
	cena_ = pcena_;
	datumObj_ = pdatumObj_;
	priemCena_ = ppriemCena_;

}





int ObjBio::getMnoz()
{
	return mnozstvo_;
}

char ObjBio::getTyp()
{
	return typ_;
}

int ObjBio::getCena()
{
	return cena_;
}

string ObjBio::getDatumObj()
{
	return datumObj_;
}

string ObjBio::getMeno()
{
	return meno_;
}

int &ObjBio::getpriemCena()
{
	return  priemCena_;
}


ObjBio::~ObjBio()
{
}