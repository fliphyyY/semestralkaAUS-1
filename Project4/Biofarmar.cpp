#include "Biofarmar.h"
#include "heap_monitor.h"

#define MIN_MN_ZEM 0
#define MAX_MN_ZEM 5000

#define MIN_MN_OLEJ 0
#define MAX_MN_OLEJ 1000

#define MIN_MN_OCHU 0
#define MAX_MN_OCHU 50000


#define MIN_CENA_ZEM 1
#define MAX_CENA_ZEM 3

#define MIN_CENA_OLEJ 1
#define MAX_CENA_OLEJ 4

#define MIN_CENA_OCHU 1
#define MAX_CENA_OCHU 2


Biofarmar::Biofarmar(Datum *pdat_, string pnazov_, bool pzemiaky_, bool polej_, bool pochu_, double ppriem_)

{
	
	zoznam_ = new ArrayList<ObjBio*>();
	podlaCeny_ = new Heap<ObjBio*>();
	nazov_ = pnazov_;
	zemiaky_ = pzemiaky_;
	olej_ = polej_;
	ochu_ = pochu_;
	dat = pdat_;
	priem_ = ppriem_;

}

string Biofarmar::getNazov()
{
	return nazov_;
}

bool Biofarmar::getZem()
{
	return zemiaky_;
}

bool Biofarmar::getOlej()
{
	return olej_;
}

bool Biofarmar::getOchu()
{
	return ochu_;
}

void Biofarmar::pridajOb(ObjBio *obj)
{
	zoznam_->add(obj);
	this->vpriemCenu();
}


void Biofarmar::dajPodlaCeny()
{

	ArrayList <ObjBio*> *pom = new ArrayList<ObjBio*>();
	*pom = *zoznam_;




	int p = zoznam_->size();
	for (int i = 0; i < p; i++)
	{
		
		for (int j = i+1; j < p; j++)
		{
			if ((this->getObjBio(i)->getMeno() == this->getObjBio(j)->getMeno()) && (this->getObjBio(i)->getTyp() == this->getObjBio(j)->getTyp()) )
			{
				this->zoznam_->removeAt(j);
				p--;
			}
		}
	}



	podlaCeny_->clear();
	for (ObjBio *a : *zoznam_)
	{
		podlaCeny_->push(a->getpriemCena(), a);

	}

	*zoznam_ = *pom;
	delete pom;
	
}

ObjBio * Biofarmar::getObjBio(int i)
{
	return (*zoznam_)[i];
}

void Biofarmar::vpriemCenu()
{
	int pocet = 0;
    int cena = 0;
	if (zoznam_-> size() == 1)
	{
		this->getObjBio(0)->getpriemCena() = this->getObjBio(0)->getCena();
	}
	char z = this->getObjBio(zoznam_->size() - 1)->getTyp();
	string pom = this->getObjBio(zoznam_->size()-1) ->getMeno();
	for (int i = 0; i < (int)zoznam_->size(); i++)
	{
		if ((pom == this->getObjBio(i)->getMeno() &&  this->getObjBio(i)->getTyp() == z ) && (dat->zmenDatum(this->getObjBio(i)->getDatumObj()) > dat->zmenDatum(dat->datum30())) &&  (this->getObjBio(i)->getCena() != 0) )
		{
			pocet++;
			cena += this->getObjBio(i)->getCena();
			
		}

	}
	for (int i = 0; i < (int)zoznam_->size(); i++) {
		if ((pom == this->getObjBio(i)->getMeno() && this->getObjBio(i)->getTyp() == z)  &&  (dat->zmenDatum(this->getObjBio(i)->getDatumObj()) > dat->zmenDatum(dat->datum30()))) {


			if (pocet == 0)
			{
				this->getObjBio(i)->getpriemCena() = 0;
				break;
			}
		this->getObjBio(i)->getpriemCena() = (cena / pocet);

		}
	}

}

void Biofarmar::vypisObBio()
{

	for (ObjBio *a : *zoznam_) 

	
	{

		cout << a->getMeno() << " " << a->getMnoz()<<  " " << a->getTyp()
			<< " " << a->getCena() << " " << a->getDatumObj() << "  " << a->getpriemCena() << endl;
		
	}
	

}

void Biofarmar::vypisHeap()
{
	
	
}

int Biofarmar::heapSize()
{
	return podlaCeny_->size();
}

ObjBio* Biofarmar::pop()
{
	return podlaCeny_->pop();
}

ObjBio * Biofarmar::peek()
{
	return podlaCeny_->peek();
}

void Biofarmar::nacitajObj()
{


	ifstream inputfile("objBio.txt");
	if (inputfile.is_open())
	{
		
		string m = " ";
		int mn = 0;
		char typ = ' ';
		int cena = 0;
		string datum = " ";
		int priem = 0;
		


		while (!inputfile.eof()) {
			inputfile >> m;
			inputfile >> mn;
			inputfile >> typ;
			inputfile >> cena;
			inputfile >> datum;
			inputfile >> priem;
			this->pridajOb(new ObjBio(m, mn, typ , cena, datum, priem));

		}
		inputfile.close();

	}

	this->dajPodlaCeny();
}

int Biofarmar::zoznamSize()
{
	return zoznam_->size();
}

bool Biofarmar::suZ()
{

	 bool pom = false;
	for (ObjBio *a: *zoznam_)
	{
		if (a->getTyp() == 'z')
		{

			pom = true;
			break;

		}
	}

	return pom;
}

bool Biofarmar::suO()
{

	bool pom = false;
	for (ObjBio *a : *zoznam_)
	{
		if (a->getTyp() == 'o')
		{

			pom = true;
			break;

		}
	}

	return pom;
}

bool Biofarmar::suC()
{

	bool pom = false;
	for (ObjBio *a : *zoznam_)
	{
		if (a->getTyp() == 'c')
		{

			pom = true;
			break;

		}
	}

	return pom;
}

void Biofarmar::skontrolujObj()
{

	if (zoznam_->size() != 0) {
		if ((dat->zmenDatum(this->getObjBio(0)->getDatumObj()) < dat->zmenDatum(dat->datum30())))
		{
			while ((dat->zmenDatum(this->getObjBio(0)->getDatumObj()) < dat->zmenDatum(dat->datum30())))
			{

				if ((dat->zmenDatum(this->getObjBio(0)->getDatumObj()) < dat->zmenDatum(dat->datum30())))
				{
					this->zoznam_->removeAt(0);
					if (zoznam_->size() == 0)
					{
						break;
					}

				}

			}

			


		}

	}

}

double& Biofarmar::getPriem()
{
	return priem_;
}

ArrayList<ObjBio*>* Biofarmar::dajZoznam()
{
	return zoznam_;
}

int Biofarmar::dodajZem()
{
	mt19937 rng(random_device{}());
	uniform_int_distribution<> dist(MIN_MN_ZEM, MAX_MN_ZEM);

	auto random_number = dist(rng);
	return random_number;

}

int Biofarmar::dodajOlej()
{
	mt19937 rng(random_device{}());
	uniform_int_distribution<> dist(MIN_MN_OLEJ, MAX_MN_OLEJ);

	auto random_number = dist(rng);
	return random_number;
}

int Biofarmar::dodajOchu()
{
	mt19937 rng(random_device{}());
	uniform_int_distribution<> dist(MIN_MN_OCHU, MAX_MN_OCHU);

	auto random_number = dist(rng);
	return random_number;
}

int Biofarmar::dajCzem()
{

	mt19937 rng(random_device{}());
	uniform_int_distribution<> dist(MIN_CENA_ZEM, MAX_CENA_ZEM);

	auto random_number = dist(rng);
	return random_number;

}

int Biofarmar::dajColej()
{
	mt19937 rng(random_device{}());
	uniform_int_distribution<> dist(MIN_CENA_OLEJ, MAX_CENA_OLEJ);

	auto random_number = dist(rng);
	return random_number;
}

int Biofarmar::dajCochu()
{
	mt19937 rng(random_device{}());
	uniform_int_distribution<> dist(MIN_CENA_OCHU, MAX_CENA_OCHU);

	auto random_number = dist(rng);
	return random_number;
}


Biofarmar::~Biofarmar()
{
	while (!podlaCeny_->isEmpty()) {
	       podlaCeny_->pop();
	}
	delete podlaCeny_;

	for (ObjBio *o : *zoznam_)
	{
		if (o != nullptr) {

			delete o;
		}
	}
	delete zoznam_;

}

