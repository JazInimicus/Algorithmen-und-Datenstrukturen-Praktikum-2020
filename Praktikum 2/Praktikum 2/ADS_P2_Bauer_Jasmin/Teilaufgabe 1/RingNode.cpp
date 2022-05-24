/*************************************************
* ADS Praktikum 2.1
* RingNode.cpp
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
#include "RingNode.h"


// Ihr Code hier:

RingNode::RingNode(int age, std::string description, std::string data) {
	OldAge = age;
	Description = description;
	SymbolicData = data;
	next = nullptr;
}

int RingNode::getAge()
{
	return OldAge;
};

void RingNode::setAge(int key)
{
	OldAge = key;
};

std::string RingNode::getDescription()
{
	return Description;
};

void RingNode::setDescription(std::string key)
{
	Description = key;
};

std::string RingNode::getData()
{
	return SymbolicData;
};

void RingNode::setData(std::string key)
{
	SymbolicData = key;
};

RingNode* RingNode::getNext()
{
	return next;
};

void RingNode::setNext(RingNode* key)
{
	next = key;
};

void RingNode::OldAgePlus()
{
	OldAge++;
};


// 
////////////////////////////////////