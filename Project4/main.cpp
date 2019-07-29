#include "ZoznamVozidiel.h"
#include "heap_monitor.h"
#include "Zakaznik.h"
#include "Datum.h"
#include "Firma.h"
#include <fstream>
#include <random>
int main() {
	initHeapMonitor();
	
	Datum *datum = new Datum();
	Firma *firma = new Firma(datum);
	ZoznamVozidiel *parkovisko = new ZoznamVozidiel(datum);


	
	firma->nacitajB();
	parkovisko->nacitaj();
	firma->nacitajZ();
	firma->nacitajOz();


	char klavesnica = '7';
	while (klavesnica != '0') {

		if (klavesnica == '7')
		{
	
			cout << "1-------------------Vlozte noveho biofarmara do systemu----------------1" << endl;
			cout << "2-------------------Vypiste zoznam biofarmarov-------------------------2" << endl;
			cout << "3-------------------Vlozte nove vozidlo do systemu---------------------3" << endl;
			cout << "4-------------------Vypiste zoznam vozidiel----------------------------4" << endl;
			cout << "5------------------ Zaregistrujte noveho zakaznika---------------------5" << endl;
			cout << "6------------------ Evidencia novej objednavky-------------------------6" << endl;
			cout << "8-------------------Vypisanie objdnavok--------------------------------8" << endl;

			cout << "9-------------------Prechod na dalsi den-------------------------------9" << endl;
			
		} 

		if (klavesnica == '1')
		{
			string meno = "";
			bool z, ol, oc;
			double priem = 0.0;
			cout << "Zadaj meno: ";
			cin >> meno;
			for (int i = 0; i < (int)firma->getSizeB(); i++)
			{

				if (meno == firma->getB(i)->getNazov())
				{
					cout << "Biofarmara nie je mozne zaevidovat lebo uz je v zozname" << endl;
					break;
					

				}
				else {

					cout << "Zemiaky: ";
					cin >> z;
					cout << "Olej: ";
					cin >> ol;
					cout << "Ochucovadla: ";
					cin >> oc;
					firma->pridajBk(new Biofarmar(datum, meno, z, ol, oc, priem));
					break;
				}
			}
			


		}

			if (klavesnica == '2')
			{
				firma->priemCenaBio();
				firma->vypisB();

			}
		

		if (klavesnica == '3')
		{
			
			string spz = "";
			bool h = false;
			string dat = " ";
			cout << "Zadaj Spz: ";
			cin >> spz;

			for (int i = 0; i < (int)parkovisko->getSizeP(); i++)
			{
				if (spz == parkovisko->getV(i)->getSpz())
				{
					cout << "Vozidlo nieje mozne zaevidovat lebo uz je v zozname" << endl;
					break;
				}
				else
				{
					cout << "Ak ma auto rozvazat hranolky tak zadajte 1 ak lupienky tak zadajte 0: ";
					cin >> h;

					parkovisko->pridajV(new Vozidlo(spz, h, dat));
					break;
				}
			}
		   	
		
		}

		if (klavesnica == '5')
		{

			string m = "";
			int h = 0;
			cout << "Zadaj meno zakaznika: ";
			cin >> m;
			cout << "Zadaj region z ktoreho zakaznik pochadza: ";
			cin >> h;

			for (int i = 0; i <(int)firma->getSizeZ(); i++)
			{
				if (m == firma->getZ(i)->getMeno() && h == firma->getZ(i)->getRegion())
				{
					cout << "Zakaznika nie je mozne pridat lebo sa uz nachadza v zozname" << endl;
					break;
				}
				else
				{
					firma->pridajZ(new Zakaznik(m, h));
					firma->vypisZ();
					break;
				}
			}

	
		}

		if (klavesnica == '6')
		{
			int pom = 0;
			string dz = datum->getDatum();
			string meno = "";
			bool typ = NULL;
			int mnozstvo = 0;
			int cena = 0;
			string dd = " ";
			string kontrola = " ";

			cout << "Zadaj meno: ";
			cin >> meno;
			for (int i = 0; i < (int)firma->getSizeZ(); i++)
			{

				if (meno == firma->getZ(i)->getMeno())
				{
					cout << "Zadaj typ tovaru (1--hranolky)  " << endl;
					cout << "                 (0--lupienky): ";
					cin >> typ;
					cout << "Zadaj mnozstvo tovaru v kg: ";
					cin >> mnozstvo;
					cout << "Zadaj predajnu cenu (eur/kg): ";
					cin >> cena;
					cout << "Zadaj datum dorucenia:";
					cin >> dd;

					if (datum->zmenDatum(dd) > datum->zmenDatum(datum->datum7()))
					{
						if ((pom = firma->overKapac(dd, typ) + mnozstvo) > parkovisko->spocitaj(typ))
						{

							kontrola = "zamietnuta";
						}




						firma->PridajOz(new ObjZakaznik(datum, dz, meno, typ, mnozstvo, cena, dd, kontrola));

						firma->vypis();
						break;

					}

					else
					{
						cout << "Objednavku nie je mozne vlozit pretoze datum dorucenia musi byt aspon tyzden po zaevidovani" << endl;
						break;

					}
				}

				else if (meno != firma->getZ(i)->getMeno() && i == firma->getSizeZ() - 1)
				{

					cout << "Zadali ste zakaznika ktory nieje v zozname " << endl;
				
				}
			}
	

		
		}


		if (klavesnica == '8')
		{   
			firma->objZaNas();
		}

		if (klavesnica == '9')
		{	

			// kontrolne vypisy ktore nie su potrebne ale su vypisane kvoli kontrole fungovania 7 funkcionality 
			firma->aktualizuj();
			datum->pridajDen();
			firma->getB(0)->skontrolujObj();
			firma->nakup();
			cout << datum->getDatum() << endl;
			firma->spocZas();
			firma->nakup2();
			cout << "objednavky na 7 dni hranolky " <<  firma->zistiH() << endl;
			cout << "objednavky na 7 dni lupienky " << firma->zistiL() << endl;
			cout << "Zasoby zemiakov " << firma->getZem() << endl;
			cout << " zasoby oleja " <<  firma->getOlej() << endl;
			cout << "zasoby ochucovadiel  " << firma->getOchu() << endl;
			cout <<" kolko treba zemiakov na obj " <<  firma->vypocZem() <<  " kolko treba oleja  " << firma->vypocOlej() << " kolko treba ochu  " << firma->vypocOch() << endl;
			firma->getB(0)->vypisObBio();
			cout << datum->datum30() << endl;
			cout << firma->zistiH() << "  " << firma->zistiL() << endl;
			cout << "  " << endl;
			firma->vypis();

		}
	
		if (klavesnica == '4')
		{
			parkovisko->vypis();

		}

		cin >> klavesnica;
	} 
	
	firma->zapisBiofarmarov("vystup.txt");
	delete datum;
	delete parkovisko;
	delete firma;

	


	
}