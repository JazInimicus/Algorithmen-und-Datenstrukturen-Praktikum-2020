
/*************************************************
* ADS Praktikum 2.1
* Ring.h
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
// Ring .h
#pragma once
#include<string>
#include "catch.hpp"
#include"RingNode.h"

class Ring {

private:
	// Ihr Code hier:	
	int AnzahlNodes = 0;			//max. 6 Nodes, dann ältestes Element (OldAge5) überschreiben bzw. löschen und ersetzen.
	RingNode* anker;				//Nullpointer bzw. Zeiger auf Ankernode.

	//Hilfsfunktion
	void Oldageplus();				//Knoten altern
	//
	////////////////////////////////////
public:
	// Ihr Code hier:
	Ring();
	~Ring();
	void setAnzahlNodes(int key);
	int getAnzahlNodes(void);
	void addNode(std::string Beschreibung, std::string Data);
	bool search(std::string Data);
	void print();


	//
	////////////////////////////////////
	// friend Funktionen müssen unangetastet bleiben! 
	friend RingNode* get_anker(Ring& r);
	friend int get_AnzahlNodes(Ring& r);
};

