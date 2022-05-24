/*************************************************
* ADS Praktikum 2.1
* Ring.cpp
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
// Ring .cpp
#include "Ring.h"
#include "RingNode.h"
#include <iostream>

// Ihr Code hier:
void Ring::Oldageplus()
{
	if (anker == nullptr) return;

	RingNode* iterator = anker;
	do {
		iterator->OldAgePlus();
		iterator = iterator->getNext();
	} while (iterator != anker);

};

Ring::Ring()
{
	anker = nullptr;
	AnzahlNodes = 0;
};

Ring::~Ring()
{		//Destruktor - alle Knoten werden nacheinander gelöscht

	if (anker == nullptr) return;

	while (anker->getNext() != anker) {
		RingNode* next = anker->getNext()->getNext();
		delete anker->getNext();
		anker->setNext(next);
	}

	delete anker;



};

int Ring::getAnzahlNodes(void)
{
	return AnzahlNodes;
};


void Ring::setAnzahlNodes(int key)									
{
	AnzahlNodes = key;
};

void Ring::addNode(std::string Description, std::string Data)
{
	//legt einen neuen Knoten mit Wert im Ring an und kümmert sich ggf um das Überschreiben und aktualisieren der OldAge Info

	RingNode* node = new RingNode(0, Description, Data);
	node->setNext(node);

	// < Maximum => Neuer Knoten muss eingefügt werden
	if (AnzahlNodes < 6) {												
		if (anker == nullptr) anker = node;

		node->setNext(anker->getNext());
		AnzahlNodes++;

		// >= Maximum => Neuer Knoten muss ersetzt werden (Funktioniert nur wenn MAX_NODES > 1)
	}
	else {
		node->setNext(anker->getNext()->getNext());
		delete anker->getNext();

	}

	anker->setNext(node);
	anker = node;

	// Alle OldAge Attribute +1
	Oldageplus();

};

bool Ring::search(std::string key)
{
	//sucht nach Übereinstimmung mit dem Parameterwert im Ring					

	RingNode* tmpAnker;
	tmpAnker = anker->getNext();

	while (tmpAnker != anker)
	{
		if (tmpAnker->getData() == key) { break; }
		tmpAnker = tmpAnker->getNext();
	}

	if (tmpAnker->getData() == key) {
		std::cout << "+ Gefunden in Backup " << tmpAnker->getAge() << ", Beschreibung: " << tmpAnker->getDescription() << ", Daten: " << tmpAnker->getData() << std::endl;
		return true;
	}
	else
	{
		std::cout << "+ Datensatz konnte nicht gefunden werden" << std::endl;
		return false;
	}
	return false;

};

void Ring::print()
{
	//Ausgabe des bestehenden Rings, OldAge wird aufsteigend angezeigt

	RingNode* tmp = anker;
	std::string  description, data;
	int age;

	while (tmp->getNext() != anker) {

		age = tmp->getAge();
		description = tmp->getDescription();
		data = tmp->getData();
		std::cout << "OldAge: " << age << ", Descr: " << description << ", Data: " << data << std::endl;
		std::cout << std::string(26, '-') << std::endl;




		tmp = tmp->getNext();
	}

	age = tmp->getAge();
	description = tmp->getDescription();
	data = tmp->getData();
	std::cout << "OldAge: " << age << ", Descr: " << description << ", Data: " << data << std::endl;
	std::cout << std::string(26, '-') << std::endl;


};


//
////////////////////////////////////
