#include <string>
#include "list/array_list.h"
#include "list/linked_list.h"
#include <iostream>
#include "heap_monitor.h"
#include "priority_queue\heap.h"
#include "ObjBio.h"
#include <random>
#include <fstream>
#include <string>
#include "Datum.h"



using namespace std;
using namespace structures;

class Biofarmar
{

private:
	 ArrayList<ObjBio*> *zoznam_;
	Heap<ObjBio*> *podlaCeny_;


	Datum *dat;

	string nazov_;
	bool zemiaky_;
	bool olej_;
	bool ochu_;
	double priem_;


public:
	Biofarmar(Datum *pdat_, string pnazov_, bool pzemiaky_, bool polej_, bool pochu_, double ppriem_);

	string getNazov();
	bool getZem();
	bool getOlej();
	bool getOchu();
	void pridajOb(ObjBio * obj);
	int dodajZem();
	int dodajOlej();
	int dodajOchu();
	int dajCzem();
	int dajColej();
	int dajCochu();
	void dajPodlaCeny();
	ObjBio * getObjBio(int i);
	void vpriemCenu();
	void vypisObBio();
	void vypisHeap();
	int heapSize();
	ObjBio * pop();
	ObjBio *peek();
	void nacitajObj();
	int zoznamSize();
	bool suZ();
	bool suO();
	bool suC();
	void skontrolujObj();
	double& getPriem();

	ArrayList<ObjBio*> *dajZoznam();

	~Biofarmar();
};
