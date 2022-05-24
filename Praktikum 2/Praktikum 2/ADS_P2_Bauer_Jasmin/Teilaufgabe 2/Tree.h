/*************************************************
* ADS Praktikum 2.2
* Tree.h
* Erweiterung um Hilfsattribute und -funktionen gestattet, wenn erforderlich.
*************************************************/
#pragma once
#include <string>
#include "TreeNode.h"
#include "catch.hpp"

using namespace std;

class Tree {

private:
	TreeNode* anker;				//Pointer auf ersten TreeNode. Nullptr, wenn keine Nodes vorhanden.
	int NodeIDCounter;				

	//Hilfsfunktion
	TreeNode* minorNode(TreeNode* node, TreeNode*& parent);					//Findet den kleinsten, direkt verbundenen Knoten

public:
	Tree();																	//Konstruktor
	void addNode(string Name, int Alter, double Einkommen, int PLZ);
	void deleteNode(int NodePosID);
	bool searchNode(string Name);
	void printAll();														//darf keine Argumente beinhalten








// friend-Funktionen sind für die Tests erforderlich und müssen unangetastet bleiben! 
	friend TreeNode* get_anker(Tree& TN);
};


