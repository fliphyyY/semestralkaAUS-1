#include "Firma.h"
#include "heap_monitor.h"


using namespace std;
using namespace structures;




Firma::Firma(Datum *dat)
{

	zoznamB = new ArrayList<Biofarmar*>();
	zoznamZ = new ArrayList<Zakaznik*>();
	zoznamOz = new ArrayList<ObjZakaznik*>();
	datum_ = dat;
	this -> zemiaky_ = 0;
	this->olej_ = 0;
	this->ochucovadla_ = 0;


	this->doch_ = 0;
	this->dolej_ = 0;
	this->dzem_ = 0;
	string zakaz = " ";
}





void Firma::pridajZ(Zakaznik * zakaznik)
{

	zoznamZ->add(zakaznik);

}


void Firma::pridajBs(Biofarmar *farmar) 
{
	zoznamB->add(farmar);
}

void Firma::pridajBk(Biofarmar *farmar)
{

	if (this->zoznamB->size() == 0)
	{
		zoznamB->add(farmar);
	}
	else {


		for (int i = 0; i < (int)zoznamB->size(); i++)
		{



			if (farmar->getNazov() <= this->getB(0)->getNazov())
			{
				this->zoznamB->insert(farmar, 0);
				break;
			}

			if (farmar->getNazov() >= this->getB((int)zoznamB->size() - 1)->getNazov())
			{
				this->zoznamB->insert(farmar, (int)zoznamB->size() - 1);
				swap((*zoznamB)[(int)zoznamB->size() - 2], (*zoznamB)[(int)zoznamB->size() - 1]);
				break;
			}
			if (this->getB(i)->getNazov() <= farmar->getNazov() && this->getB(i + 1)->getNazov() >= farmar->getNazov())
			{
				this->zoznamB->insert(farmar, i + 1);
				break;
			}
		}
	}

}




void Firma::PridajOz(ObjZakaznik * oz)
{

	zoznamOz->add(oz);

}


void Firma::nacitajZ()
{

	ifstream inputfile("zakaznici.txt");
	if (inputfile.is_open())
	{
		string m = "";
		int r = 0;

		while (!inputfile.eof()) {
			inputfile >> m;
			inputfile >> r;
			this->pridajZ(new Zakaznik(m, r));

		}
		inputfile.close();
	}
}

void Firma::nacitajB()
{

	ifstream inputfile("farmari.txt");
	if (inputfile.is_open())
	{
		string meno = "";
		bool z = false;
		bool o = false;
		bool oc = false;
		double priem = 0.0;

		while (!inputfile.eof()) {
			inputfile >> meno;
			inputfile >> z;
			inputfile >> o;
			inputfile >> oc;
			this->pridajBs(new Biofarmar(datum_, meno, z, o, oc, priem));

		}
		inputfile.close();

	}


}


void Firma::vypisZ()
{

	for (Zakaznik *z : *zoznamZ) {
		cout << z->getMeno() << " " << z->getRegion() << endl;
	}
}

void Firma::vypisB()
{

	if (zoznamB->size() == 0)
	{
		cout << "Zoznam je prazdny" << endl;
		
	}
	else
	{
		for (Biofarmar *b : *zoznamB)
		{
			cout << "Obchodne meno " << b->getNazov() << " a farmar predava ";
			if (b->getZem() == 1) {
				cout << "zemiaky ";
			}

			if (b->getOlej() == 1) {

				cout << "olej ";
			}
			if (b->getOchu() == 1) {

				cout << "ochucovadla ";
			}
			cout << "a jeho priemerna cena za produkty je: " << b->getPriem();
			cout << endl;

		}
	}


}



void Firma::vypis()
{



	for (ObjZakaznik *o : *zoznamOz)
	{

		cout << o->getDatumZ() << " " << o->getZakaznik() << " ";
		if (o->getTyp() == 1) {
			cout << " Hranolky; ";
		 }

		else
		{
			cout << "Lupineky; ";
		}
		cout  << "Mnozstvo "  << o->getMnozsto() << "; " <<"Cena " <<  o->getCena() <<
			"; " <<"Datum dorucenia: " <<  o->getDatumD() << " " << o->getKontrola()   << endl;

	}
}

void Firma::nakup()
{
	if ((this->getB(0)->zoznamSize() == 0 )|| (this->getB(0)->zoznamSize() != 0 && this->getB(0)->suZ() == false) || (this->getB(0)->zoznamSize() != 0 && this->getB(0)->suO() == false)
        || (this->getB(0)->zoznamSize() != 0 && this->getB(0)->suC() == false))
	{
		
		int zem = this->getZem();
		int olej = this->getOlej();
		int ochu = this->getOchu();
		if ((this->getB(0)->zoznamSize() == 0) || (this->getB(0)->zoznamSize() != 0 && this->getB(0)->suZ() == false))
		{



			for (int i = 0; i < (int)zoznamB->size(); i++)
			{

				if (zem >= this->vypocZem())
				{
					if (this->getB(i)->getZem() == true)
					{

						string meno = this->getB(i)->getNazov();
						int mnoz = 0;
						this->getDzem() += mnoz;
						zem = this->getDzem() + this->getZem();
						int cena = 0;
						string datum = datum_->getDatum();
						int priemCena = 0;

						this->getB(0)->pridajOb(new ObjBio(meno, mnoz, 'z', cena, datum, priemCena));

					}
					
				}


				if (zem <= this->vypocZem() && this->vypocOlej() != 0)
				{

					if (this->getB(i)->getZem() == true)
					{


						string meno = this->getB(i)->getNazov();
						int mnoz = this->getB(i)->dodajZem();
						this->getDzem() += mnoz;
						zem = this->getDzem() + this->getZem();
						int cena = this->getB(i)->dajCzem();
						string datum = datum_->getDatum();
						int priemCena = 0;

						this->getB(0)->pridajOb(new ObjBio(meno, mnoz, 'z', cena, datum, priemCena));

					}
				}

			}

		}


		if ((this->getB(0)->zoznamSize() == 0) || (this->getB(0)->zoznamSize() != 0 && this->getB(0)->suO() == false))
		{

			for (int i = 0; i < (int)zoznamB->size(); i++)
			{

				if (olej >= this->vypocOlej())
				{

					if (this->getB(i)->getOlej() == true)
					{

						string meno = this->getB(i)->getNazov();
						int mnoz = 0;
						this->getDolej() += mnoz;
						olej = this->getDolej() + this->getZem();
						int cena = 0;
						string datum = datum_->getDatum();
						int priemCena = 0;

						this->getB(0)->pridajOb(new ObjBio(meno, mnoz, 'o', cena, datum, priemCena));

					}
				}

				if (olej <= this->vypocOlej())
				{

					if (this->getB(i)->getOlej() == true && this->vypocOlej() != 0)
					{


						string meno = this->getB(i)->getNazov();
						int mnoz = this->getB(i)->dodajOlej();
						this->getDolej() += mnoz;
						olej = this->getDolej() + this->getZem();
						int cena = this->getB(i)->dajColej();
						string datum = datum_->getDatum();
						int priemCena = 0;

						this->getB(0)->pridajOb(new ObjBio(meno, mnoz, 'o', cena, datum, priemCena));

					}

				}
			}

		}

		if ((this->getB(0)->zoznamSize() == 0) || (this->getB(0)->zoznamSize() != 0 && this->getB(0)->suC() == false))
		{

			for (int i = 0; i < (int)zoznamB->size(); i++)
			{

				if (ochu >= this->vypocOch())
				{

					if (this->getB(i)->getOchu() == true)
					{

						string meno = this->getB(i)->getNazov();
						int mnoz = 0;
						this->getDoch() += mnoz;
						ochu = this->getDoch() + this->getOchu();
						int cena = 0;
						string datum = datum_->getDatum();
						int priemCena = 0;

						this->getB(0)->pridajOb(new ObjBio(meno, mnoz, 'c', cena, datum, priemCena));

					}
				}

				if (ochu <= this->vypocOch() && this->vypocOch() != 0)
				{

					if (this->getB(i)->getOchu() == true)
					{


						string meno = this->getB(i)->getNazov();
						int mnoz = this->getB(i)->dodajOchu();
						this->getDoch() += mnoz;
						ochu = this->getDoch() + this->getOchu();
						int cena = this->getB(i)->dajCochu();
						string datum = datum_->getDatum();
						int priemCena = 0;

						this->getB(0)->pridajOb(new ObjBio(meno, mnoz, 'c', cena, datum, priemCena));

					}

				}
			}

		}

	}

}
			
		
	


int Firma::getSizeOz()
{
	return zoznamOz->size();
}

void Firma::nacitajOz()
{

	ifstream inputfile("objednavky.txt");
	if (inputfile.is_open())
	{
		string datZ = datum_->getDatum();
		string meno = " ";
		bool typ = 0;
		int mn = 0;
		int c = 0;
		string daD = " ";
		string kontrola = " ";

		while (!inputfile.eof()) {
			inputfile >> meno;
			inputfile >> typ;
			inputfile >> mn;
			inputfile >> c;
			inputfile >> daD;

			this->PridajOz(new ObjZakaznik(datum_, datZ, meno, typ, mn, c, daD, kontrola));

		}
		inputfile.close();

	}
}

int Firma::zistiH()
{

	int pom = 0;
	for (ObjZakaznik *j : *zoznamOz)
	{
		if (j->getTyp() == 1 &&  (j->getKontrola() == " ") && (datum_->zmenDatum(j->getDatumD()) >= datum_->zmenDatum(datum_->datum1())) && (datum_->zmenDatum(j->getDatumD()) <= datum_->zmenDatum(datum_->datum7())))
		{
			pom += j->getMnozsto();
		}
	}

	return pom;
	
}

int Firma::zistiL()
{
	int pom = 0;
	for (ObjZakaznik *j : *zoznamOz)
	{
		if (j->getTyp() == 0 &&  (j->getKontrola() == " ") && (datum_->zmenDatum(j->getDatumD()) >= datum_->zmenDatum(datum_->datum1())) && (datum_->zmenDatum(j->getDatumD()) <= datum_->zmenDatum(datum_->datum7())))
		{
			pom += j->getMnozsto();
		}
	}

	return pom;
}

int& Firma::getZem()
{
	return zemiaky_;
}

int& Firma::getOlej()
{
	return olej_;
}

int& Firma::getOchu()
{
	return ochucovadla_;
}

int & Firma::getDzem()
{

	return dzem_;
}

int & Firma::getDolej()
{
	return dolej_;
}

int & Firma::getDoch()
{
	return doch_;
}

int Firma::najmTrz()
{

	int pom = 10000000;
	for (ObjZakaznik *a: *zoznamOz)
	{

		int pom2 = (a->getCena() * a->getMnozsto());
		if (pom2 <= pom)
		{
			pom = pom2;
		}
	}

	return pom;
}

double Firma::vypocZem()
{
	double pom1 = (this->zistiH()) * 1.5;
	double pom2 = (this->zistiL()) * 2;

	return pom1 + pom2;
}

double Firma::vypocOlej()
{
	double pom1 = (this->zistiH()) * 0.2;
	double pom2 = (this->zistiL()) * 0.4;

	return pom1 + pom2;
}

double Firma::vypocOch()
{
	double pom1 = (this->zistiL()) * 20;

	return pom1;
}

int Firma::getSizeZ()
{
	return zoznamZ->size();
}



Zakaznik * Firma::getZ(int i)
{
	return (*zoznamZ)[i];
}

Biofarmar * Firma::getB(int i)
{
	return (*zoznamB)[i];
}

ObjZakaznik * Firma::getOz(int i)
{
	return (*zoznamOz)[i];
}



int Firma::getSizeB()
{
	return zoznamB->size();
}

void Firma::spocZas()
{

this->zruseneObj();
	int mnozstvo = 0;
	for (ObjZakaznik *a: *zoznamOz )
	{
		if ((a->getDatumD() == datum_->getDatum()) && a->getTyp() == 1 &&  (a->getKontrola() == " "))
		{
			 mnozstvo += a->getMnozsto();
		}

	}

	int zem = int (mnozstvo * 1.5);
	int olej = int (mnozstvo * 0.2);

	this->getZem() -= zem;
	this->getOlej() -= olej;

	int mnozstvo1 = 0;
	for (ObjZakaznik *a : *zoznamOz)
	{
		if ((a->getDatumD() == datum_->getDatum()) && (a->getTyp() == 0 ) &&  (a->getKontrola() == " "))
		{
			mnozstvo1 += a->getMnozsto();
		}

	}

	int zem1 = int(mnozstvo1 * 2);
	int olej1 = int(mnozstvo1 * 0.4);
	int ochu1 = int(mnozstvo1 * 20);

	this->getZem() -= zem1;
	this->getOlej() -= olej1;
	this->getOchu() -= ochu1;
 


}

void Firma::nakup2()
{
	if (this->getDzem() == 0)
	{

		int zem = this->getZem();
		int olej = this->getOlej();
		int ochu = this->getOchu();
		this->getB(0)->dajPodlaCeny();
		while ((zem  < this->vypocZem()))
		{
			if (this->getB(0)->suZ() == false)
			{
				nakup();
				break;
			}

			if (this->getB(0)->heapSize() == 0)
			{
				break;
			}
			if (this->getB(0)->peek()->getTyp() != 'z')
			{
				this->getB(0)->pop();
			}
			else
			{
				string meno = this->getB(0)->pop()->getMeno();
				
				for (int i = 0; i < (int)zoznamB->size(); i++)
				{
				
					if ((this->getB(i)->getZem() == true) && (this->getB(i)->getNazov() == meno))
					{
						string meno = this->getB(i)->getNazov();
						int mnoz = this->getB(i)->dodajZem();
						this->getDzem() += mnoz;
						zem = this->getDzem() + this->getZem();
						int cena = this->getB(i)->dajCzem();
						string datum = datum_->getDatum();
						int priemCena = 0;

						this->getB(0)->pridajOb(new ObjBio(meno, mnoz, 'z', cena, datum, priemCena));
						break;
					}
				}
			}
		}

		this->getB(0)->dajPodlaCeny();
		while (olej < this->vypocOlej())
		{

			if (this->getB(0)->suO() == false)
			{
				nakup();
				break;
			}
			if (this->getB(0)->heapSize() == 0)
			{
				break;
			}
			if (this->getB(0)->peek()->getTyp() != 'o')
			{
				this->getB(0)->pop();
			}
			else
			{
				string meno = this->getB(0)->pop()->getMeno();
				for (int i = 0; i < (int)zoznamB->size(); i++)
				{
					
					if ((this->getB(i)->getOlej() == true) && (this->getB(i)->getNazov() == meno))
					{
						string meno = this->getB(i)->getNazov();
						int mnoz = this->getB(i)->dodajOlej();
						this->getDolej() += mnoz;
						olej = this->getDolej() + this->getOlej();
						int cena = this->getB(i)->dajColej();
						string datum = datum_->getDatum();
						int priemCena = 0;

						this->getB(0)->pridajOb(new ObjBio(meno, mnoz, 'o', cena, datum, priemCena));
						break;
					}
				}
			}
		}

		this->getB(0)->dajPodlaCeny();
		while (ochu < this->vypocOch())
		{

			if (this->getB(0)->suC() == false)
			{
				nakup();
				break;
			}
			if (this->getB(0)->heapSize() == 0)
			{
				break;
			}
			if (this->getB(0)->peek()->getTyp() != 'c')
			{
				this->getB(0)->pop();
			}
			else
			{
				string meno = this->getB(0)->pop()->getMeno();
				for (int i = 0; i < (int)zoznamB->size(); i++)
				{
				
					if ((this->getB(i)->getOchu() == true) && (this->getB(i)->getNazov() == meno))
					{
						string meno = this->getB(i)->getNazov();
						int mnoz = this->getB(i)->dodajOchu();
						this->getDoch() += mnoz;
						ochu = this->getDoch() + this->getOchu();
						int cena = this->getB(i)->dajCochu();
						string datum = datum_->getDatum();
						int priemCena = 0;

						this->getB(0)->pridajOb(new ObjBio(meno, mnoz, 'c', cena, datum, priemCena));
						break;
					}
				}
			}
		}
	}
}

void Firma::aktualizuj()
{

	this->getZem() += this->getDzem();
	this->getOlej() += this->getDolej();
	this->getOchu() += this->getDoch();


	this->doch_ = 0;
	this->dolej_ = 0;
	this->dzem_ = 0;

}

void Firma::objZaNas()
{

	bool pom = false;
	for (ObjZakaznik *z: *zoznamOz)
	{

		if (datum_->zmenDatum(z->getDatumD()) == datum_->zmenDatum(datum_->datum1())  )
		{
			zakaz = z->getZakaznik();
			cout << z->getZakaznik() << "  " << this->zistiReg() << "  " <<  z->getDatumZ() << " " << z->getTyp() << " " << z->getMnozsto() <<" " << z->getCena()
				<< " " << (z->getCena() * z->getMnozsto()) << " " << z->getKontrola() << endl;
			pom = true;
		}
		
	}

	if (pom == false )
	{


		cout << "Zajtra nie je ziadna objednavka" << endl;
	}
}

int Firma::zistiReg()
{

	int reg = 0;
	for (Zakaznik *z: *zoznamZ)
	{
		if (z->getMeno() == zakaz)
		{
			reg = z->getRegion();
		}

	}

	return reg;
}




int Firma::overKapac(string datum, bool typ)
{
	int mnozstvoH = 0;
	int mnozstvoL = 0;
	if (typ == 1)
	{
		
		for (ObjZakaznik *o : *zoznamOz)
		{
			int pom = 0;
			if ((o->getDatumD() == datum && o->getTyp() == 1) && (o->getKontrola() == " "))
			{
				pom =  o->getMnozsto();
				mnozstvoH += pom;
			}
		}

	}


	if (typ == 0)
	{
		int pom = 0;
		
		for (ObjZakaznik *o : *zoznamOz)
		{
			if ((o->getDatumD() == datum && o->getTyp() == 0) && (o->getKontrola() == " "))
			{

				pom = o->getMnozsto();
				mnozstvoL += pom;
			}
		}

	}

	if (typ == 1)

		return mnozstvoH;

	else
		return mnozstvoL;
	
}

void Firma::zruseneObj()
{

	while ((this->vypocOch1() > this->getOchu()) || (this->vypocZem1() > this->getZem()) || (this->vypocOlej1() > this->getOlej()) )
	{
		this->getOz(this->najmTrzby())->getKontrola() = "zrusena";
	}

}

int Firma::najmTrzby()
{
	int pom = INT_MAX;
	int index = 0;

	for (int i = 0; i < (int)zoznamOz->size() ;i++)
	{
		if (datum_->zmenDatum(this->getOz(i)->getDatumD()) == datum_->zmenDatum(datum_->datum1()) &&  (this->getOz(i)->getKontrola()== " "))
		{
			int cena = this->getOz(i)->getCena() * this->getOz(i)->getMnozsto();
			if (cena <= pom)
			{
				pom = cena;
				index = i;
			}
		}
		
	}

	return index;
}

int Firma::zistiH1()
{
	int pom = 0;
	for (ObjZakaznik *j : *zoznamOz)
	{
		if ((datum_->zmenDatum(j->getDatumD()) == datum_->zmenDatum(datum_->datum1())) && (j->getTyp() == 1) &&  (j->getKontrola() == " "))
		{
			pom += j->getMnozsto();
		}
	}
	return pom;
}

int Firma::zistiL1()
{
	int pom = 0;
	for (ObjZakaznik *j : *zoznamOz)
	{
		if ((datum_->zmenDatum(j->getDatumD()) == datum_->zmenDatum(datum_->datum1())) && (j->getTyp() == 0)  && (j->getKontrola() == " "))
		{
			pom += j->getMnozsto();
		}
	}
	return pom;
}

double Firma::vypocZem1()
{
	double pom1 = (this->zistiH1()) * 1.5;
	double pom2 = (this->zistiL1()) * 2;

	return pom1 + pom2;
}

double Firma::vypocOlej1()
{
	double pom1 = (this->zistiH1()) * 0.2;
	double pom2 = (this->zistiL1()) * 0.4;

	return pom1 + pom2;
}

double Firma::vypocOch1()
{
	double pom1 = (this->zistiL1()) * 20;

	return pom1;
}

void Firma::priemCenaBio()
{


	
	if ((zoznamB->size() != 0) )
	{
		

		for (int i = 0; i < (int)zoznamB->size(); i++)
		{
			int pocet = 0;
			int suma = 0;


			for (int j = 0; j < this->getB(0)->zoznamSize(); j++)
			{
				if ((this->getB(i)->getNazov() == this->getB(0)->getObjBio(j)->getMeno() && (this->getB(0)->getObjBio(j)->getCena() != 0)))
				{
					pocet++;
					suma += this->getB(0)->getObjBio(j)->getCena();
				}

			}

			if (pocet == 0 || suma == 0)
			{
				this->getB(i)->getPriem() = 0;
				break;
			}
			this->getB(i)->getPriem() = (suma / (double)pocet);

		
		}

	}
	
}

void Firma::zapisBiofarmarov(const string filename)
{

	ofstream subor;
	subor.open(filename);
	if (subor.is_open())
	{


		for (Biofarmar *b:  *zoznamB)
		{

			subor << b->getNazov() << " "<< b->getZem() << " "<< b->getOlej()<< " "<< b->getOchu() << " "<< b->getPriem() << endl;

		}


		subor << endl;
		for (Zakaznik *z : *zoznamZ)
		{

			subor << z->getMeno() << " " << z->getRegion() << endl;

		}

		subor << endl;
		for (ObjZakaznik *o : *zoznamOz)
		{

			subor << o->getDatumZ() << " " << o->getZakaznik() << " " << o->getTyp() << " " << o->getMnozsto() << " " << o->getCena() << " " << o->getDatumD() << " " << o->getKontrola() << endl;

		}


	}
}





Firma::~Firma()
{

	for (Zakaznik *z : *zoznamZ)
	{
		if (z != nullptr) {

			delete z;
		}
	}
	delete zoznamZ;

	for (Biofarmar *a : *zoznamB)
	{
		if (a != nullptr) {

			delete a;
		}
	}
	delete zoznamB;


	for (ObjZakaznik *j : *zoznamOz)
	{

		if (j != nullptr)
		{
			delete j;
		}
	}

	delete zoznamOz;
}



