
/*************************************************
* ADS Praktikum 2.2
* TreeNode.h
* Erweiterung um Hilfsattribute und -funktionen gestattet, wenn erforderlich.
*************************************************/
#pragma once
#include <string>

using namespace std;

class TreeNode {

private:

	int NodePosID;					//Alter(int) + PLZ(int) + Einkommen(double) = NodePosID(int)
	int NodeID;						//Seriennummer für nodes: 0 und dann aufwärts
	string Name;
	int Alter;
	double Einkommen;
	int PLZ;
	TreeNode* left;					//Pointer auf linken Knoten
	TreeNode* right;				//Pointer auf rechten Knoten

public:

	TreeNode(int nodeID, std::string name, int age, double income, int postcode);			//Konstruktor TreeNode-Klasse
	int getNodePosID();
	int getNodeID();
	string getName();
	void setName(string key);
	int getAlter();
	void setAlter(int key);
	double getEinkommen();
	void setEinkommen(double key);
	int getPLZ();
	void setPLZ(int key);

	TreeNode* getLeft();
	TreeNode* getRight();
	void setLeft(TreeNode*);
	void setRight(TreeNode*);
	void print();											//Ausgabe der Knoten nach Vorgabe

	//Hilfsfunktion
	void printTreeInfo(void);


};
#pragma once
