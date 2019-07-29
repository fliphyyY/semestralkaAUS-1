#include "Datum.h"
#include "heap_monitor.h"
#include <iostream>


Datum::Datum()
{
	time_t teraz = time(0);
	tm  *cas = localtime(&teraz);

	rok_ = 1900 + cas->tm_year;
	mesiac_ =   1 + cas->tm_mon;
	den_ =  cas->tm_mday;


	
}


string Datum::getDatum()
{
	string rok = to_string(rok_);
	string mesiac;
	string den;
	string datum;


	if (mesiac_ <= 9)
	{
		mesiac = "0" + to_string(mesiac_);
	}
	else
	{
		mesiac = to_string(mesiac_);
	}
	if (den_ <= 9) {
		den = "0" + to_string(den_);
	}
	else
	{
		den = to_string(den_);
	}

	datum = den + "." + mesiac + "." + rok;
	return datum;
	
}

void Datum::pridajDen()
{
	if (mesiac_ == 2 && den_ == 28)
	{
		mesiac_ = 3;
		den_ = 0;
	}

	if ((mesiac_ == 4 || mesiac_ == 6 || mesiac_ == 9 || mesiac_ == 11) && den_ == 30)
	{
		mesiac_++;
		den_ = 0;
	}

	if (den_ == 31 && mesiac_ == 12)
	{
		den_ = 0;
		mesiac_ = 1;
		rok_++;
	}

	if (den_ == 31 && mesiac_ != 12) {
		den_ = 0;
		mesiac_++;
	}

	den_++;
	
}


int Datum::zmenDatum(string &vstup)
{
	int mesiac;
	int den;
	int rok;
	if (sscanf(vstup.c_str(), "%d.%d.%d", &den, &mesiac, &rok) != 3) {
		return NULL;
	}
	else {

		return 10000 * rok + 100 * mesiac + den;
	}
}

string Datum::datum7()
{
	int rok7 = rok_;
	int mesiac7 = mesiac_;
	int den7 = den_;

	string rok = to_string(rok7);
	string mesiac;
	string den;
	string datum;


	

	for (int i = 0; i < 7; i++)
	{



		if (mesiac7 == 2 && den7 == 28)
		{
			mesiac7 = 3;
			den7 = 0;
		}

		if ((mesiac7 == 4 || mesiac7 == 6 || mesiac7 == 9 || mesiac7 == 11) && den7 == 30)
		{
			mesiac7++;
			den7 = 0;
		}

		if (den7 == 31 && mesiac7 == 12)
		{
			den7 = 0;
			mesiac7 = 1;
			rok7++;
		}

		if (den7 == 31 && mesiac7 != 12) {
			den7 = 0;
			mesiac7++;
		}

		den7++;
	}

	if (mesiac7 <= 9)
	{
		mesiac = "0" + to_string(mesiac7);
	}
	else
	{
		mesiac = to_string(mesiac7);
	}
	if (den7 <= 9) {
		den = "0" + to_string(den7);
	}
	else
	{
		den = to_string(den7);
	}

	datum = den + "." + mesiac + "." + rok;

	return datum;
}

string Datum::datum1()
{

	int rok1 = rok_;
	int mesiac1 = mesiac_;
	int den1 = den_;

	string rok = to_string(rok1);
	string mesiac;
	string den;
	string datum;


	if (mesiac1 == 2 && den1 == 28)
	{
		mesiac1 = 3;
		den1= 0;
	}

	if ((mesiac1 == 4 || mesiac1 == 6 || mesiac1 == 9 || mesiac1 == 11) && den1 == 30)
	{
		mesiac1++;
		den1 = 0;
	}

	if (den1 == 31 && mesiac1 == 12)
	{
		den1 = 0;
		mesiac1 = 1;
		rok1++;
	}

	if (den1 == 31 && mesiac1 != 12) {
		den1 = 0;
		mesiac1++;
	}

	den1++;

	if (mesiac1 <= 9)
	{
		mesiac = "0" + to_string(mesiac1);
	}
	else
	{
		mesiac = to_string(mesiac1);
	}
	if (den1 <= 9) {
		den = "0" + to_string(den1);
	}
	else
	{
		den = to_string(den1);
	}

	datum = den + "." + mesiac + "." + rok;

	return datum;
}

string Datum::datum30()
{
	int rok30 = rok_;
	int mesiac30 = mesiac_;
	int den30 = den_;

	string rok = to_string(rok30);
	string mesiac = " ";
	string den = " ";
	string datum = " ";




	for (int i = 0; i < 30; i++)
	{



		if (mesiac30 == 3 && den30 == 1)
		{
			mesiac30 = 2;
			den30 = 29;
		}

		if ((mesiac30 == 4 || mesiac30 == 6 || mesiac30 == 10 || mesiac30 == 12) && den30 == 1)
		{
			mesiac30--;
			den30 = 32;
		}

		if (den30 == 1 && mesiac30 == 1)
		{
			den30 = 32;
			mesiac30 = 12;
			rok30--;
		}

		if (den30 == 1 && mesiac30 != 12) {
			den30 = 31;
			mesiac30--;
		}

	
		den30 --;
	}

	if (mesiac30 <= 9)
	{
		mesiac = "0" + to_string(mesiac30);
	}
	else
	{
		mesiac = to_string(mesiac30);
	}
	if (den30 <= 9) {
		den = "0" + to_string(den30);
	}
	else
	{
		den = to_string(den30);
	}

	datum = den + "." + mesiac + "." + rok;

	return datum;


}


Datum::~Datum()
{
	rok_ = 0;
	mesiac_ = 0;
	den_ = 0;
		
	

}
	

