/*************************************************
* ADS Praktikum 2.2
* TreeNode.cpp
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
#include "TreeNode.h"
#include <iostream>
#include <string>




TreeNode::TreeNode(int nodeID, std::string name, int age, double income, int postcode)
{
	NodePosID = age + postcode + income;
	NodeID = nodeID;
	Name = name;
	Alter = age;
	Einkommen = income;
	PLZ = postcode;

	left = nullptr;
	right = nullptr;
};

int TreeNode::getNodePosID()
{
	return NodePosID;
};

int TreeNode::getNodeID()
{
	return NodeID;
};

std::string TreeNode::getName()
{
	return Name;
};

void TreeNode::setName(std::string key)
{
	Name = key;
};

int TreeNode::getAlter()
{
	return Alter;
};

void TreeNode::setAlter(int key)
{
	Alter = key;
};

double TreeNode::getEinkommen()
{
	return Einkommen;
};

void TreeNode::setEinkommen(double key)
{
	Einkommen = key;
};

int TreeNode::getPLZ()
{
	return PLZ;
};

void TreeNode::setPLZ(int key)
{
	PLZ = key;
};


TreeNode* TreeNode::getLeft()
{
	return left;
};

TreeNode* TreeNode::getRight()
{
	return right;
};

void TreeNode::setLeft(TreeNode* key)
{
	left = key;
};

void TreeNode::setRight(TreeNode* key)
{
	right = key;
};

void TreeNode::print()
{
	std::cout << "NodeID: " << NodeID <<
		", Name: " << Name <<
		", Alter: " << Alter <<
		", Einkommen: " << Einkommen <<
		", PLZ: " << PLZ <<
		", PosID: " << NodePosID <<
		std::endl;

};

void TreeNode::printTreeInfo(void)
{
	cout << NodeID << "   |      " << Name << "|    " << Alter << " |          " << Einkommen << "|  " << PLZ << " |" << NodePosID << endl;
};


//
////////////////////////////////////
