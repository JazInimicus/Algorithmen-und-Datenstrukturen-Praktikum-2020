/*************************************************
* ADS Praktikum 2.1
* RingNode.h
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
#pragma once
#include <string>

class RingNode {

private:
	// Ihr Code hier:
	int OldAge;						//Alter des Knotens, start bei 0, erhöht bei hinzufügen
	std::string Description;		//Beschreibung Knoten
	std::string SymbolicData;		//Data
	RingNode* next;					//Pointer auf Folgeknoten
	//	
public:
	// Ihr Code hier:
	RingNode(int age, std::string description, std::string data);					//Konstruktor
	RingNode() = default;															//Standardkonstruktor
	int getAge();																	//Get Alter des Knotens
	void setAge(int);
	std::string getDescription();													//Get Beschreibung
	void setDescription(std::string Description);
	std::string getData();															//Get Data
	void setData(std::string SymbolicData);
	RingNode* getNext();															//Get Pointer auf Folgeknoten
	void setNext(RingNode * key);													//key, damit auf alles gezeigt wird, was in einem Knoten drin ist.
	void OldAgePlus();																//Knoten werden alt
	//
};

