#include "ZoznamVozidiel.h"
#include "heap_monitor.h"

ZoznamVozidiel::ZoznamVozidiel(Datum *dat)
{

	park = new ArrayList<Vozidlo*>();
	datum = dat;



}

void ZoznamVozidiel::pridajV(Vozidlo  *vozidlo)
{


	if (park->size() == 0)
	{

		park->add(vozidlo);
		this->getV(0)->getDat() = datum->getDatum();
	}

	for (int i = 0; i < (int)park->size(); i++)
	{

		if (this->getV(i)->getSpz() == vozidlo->getSpz())
		{
			break;
		}

		if (this->getV(i)->getSpz() != vozidlo->getSpz() && i + 1 == park->size()) {
			park->add(vozidlo);
			this->getV(i + 1)->getDat() = datum->getDatum();

		}
	}
	
	
}

Vozidlo * ZoznamVozidiel::getV(int i)
{
	return (*park)[i];
}

void ZoznamVozidiel::nacitaj()
{

	ifstream inputfile("vozidla.txt");
	if (inputfile.is_open())
	{
		string meno = " ";
		bool h = false;
		string dat = " ";

		while (!inputfile.eof()) {
			inputfile >> meno;
			inputfile >> h;
			inputfile >> dat;
			this->pridajV(new Vozidlo(meno, h, dat));

		}
		inputfile.close();
		
	}
	
	
}


void ZoznamVozidiel::vypis()
{
	for (Vozidlo *v : *park)
	{
		cout << v->getSpz();

		if (v-> getTyp() == 1)
		{
		cout << " Hranolky " << v->getDat() << endl;
		}

		else
		{
		cout << " Lupienky " << v->getDat() << endl;
		}
	}
}

int ZoznamVozidiel::getSizeP()
{
	return park->size();
}



int ZoznamVozidiel::spocitaj(bool typ)
{
	int pocitadloH = 0;
	int pocitadloL = 0;

	if (typ == 1)
	{	
		for (Vozidlo *z : *park)
		{
			if (z->getTyp() == 1)
			{
				pocitadloH++;
			}
		}
	}

	if (typ == 0)
	{
		for (Vozidlo *z : *park)
		{
			if (z->getTyp() == 0)
			{
				pocitadloL++;
			}
		}		
	}

	if (typ == 1)
	return (pocitadloH * this->getkapacHra());

	else

		return (pocitadloL *  this->getkapacLup());
}

const int ZoznamVozidiel::getkapacHra()
{
	return kapacHra;
}

const int ZoznamVozidiel::getkapacLup()
{
	return kapacLup;
}

ZoznamVozidiel::~ZoznamVozidiel()
{
	for (Vozidlo *v : *park) 
	{
		if (v != nullptr) {
		
			delete v;
		}
	}
	delete park;
	datum = 0;
}





