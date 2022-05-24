/*************************************************
* ADS Praktikum 2.2
* main.cpp
*
*************************************************/
#define CATCH_CONFIG_RUNNER
#include <iostream>
#include "Tree.h"
#include "catch.hpp"

using namespace std;

///////////////////////////////////////
// Hilfsmethoden fürs Menü hier:



//
///////////////////////////////////////
int main() {

	int result = Catch::Session().run();

	///////////////////////////////////////
	// Ihr Code hier:

	Tree* myTree = new Tree();
	int input123456;
	std::string inputName;
	int inputAlter;
	double inputEinkommen;
	int inputPLZ;

	while (true) {
		cout << std::string(34, '=') << endl;
		cout << "1) Datensatz einfuegen, maneull" << endl;
		cout << "2) Datensatz einfuegen, CSV Datei" << endl;
		cout << "3) Datensatz loeschen" << endl;
		cout << "4) Suchen" << endl;
		cout << "5) Datenstruktur anzeigen" << endl;
		cout << std::string(34, '=') << endl;


		cin >> input123456;
		while (cin.fail()) {
			cout << "Fehler! Bitte geben Sie eine Zahl zwischen 1 und 5 ein. " << endl;
			cin.clear();
			cin.ignore(256, '\n');
			cin >> input123456;
		}


		if (input123456 == 1) {


			cout << "+ Bitte geben Sie den Datensatz ein" << endl;
			cout << "Name ?>";
			cin >> inputName;
			while (cin.fail()) {
				cout << "Fehler! Bitte geben Sie einen Namen ein. " << endl;
				cin.clear();
				cin.ignore(256, '\n');

				cin >> inputName;
			}
			cout << "Alter ?> ";
			cin >> inputAlter;
			while (cin.fail()) {
				cout << "Fehler! Bitte geben Sie eine ganze Zahl ein" << endl;
				cin.clear();
				cin.ignore(256, '\n');
				cin >> inputAlter;
			}
			cout << "Einkommen ?> ";
			cin >> inputEinkommen;
			while (cin.fail()) {
				cout << "Fehler! Bitte geben Sie eine double Zahl ein " << endl;
				cin.clear();
				cin.ignore(256, '\n');
				cin >> inputEinkommen;
			}
			cout << "PLZ ?> ";
			cin >> inputPLZ;
			while (cin.fail()) {
				cout << "Fehler! Bitte geben Sie eine ganze Zahl ein. " << endl;
				cin.clear();
				cin.ignore(256, '\n');
				cin >> inputPLZ;
			}


			myTree->addNode(inputName, inputAlter, inputEinkommen, inputPLZ);



		}
		else if (input123456 == 2) {

			ifstream csvread;
			csvread.open("ExportZielanalyse.csv", ios::in);
			if (csvread)
			{
				string name, alter, einkommen, plz;
				while (!csvread.eof())
				{

					getline(csvread, name, ';');
					getline(csvread, alter, ';');
					getline(csvread, einkommen, ';');
					getline(csvread, plz, '\n');




					inputName = name;
					inputAlter = stoi(alter);
					inputEinkommen = stod(einkommen);
					inputPLZ = stoi(plz);
					myTree->addNode(inputName, inputAlter, inputEinkommen, inputPLZ);

				}
				csvread.close();
			}
			else
			{
				cout << "Fehler beim Lesen!" << endl;

			}

		}
		else if (input123456 == 3) {
			cout << "Bitte geben Sie den zu loeschenden Datensatz an" << endl;
			cout << "PosID ?> ";
			cin >> inputAlter;
			while (cin.fail()) {
				cout << "Fehler! Bitte geben Sie eine ganze Zahl ein " << endl;
				cin.clear();
				cin.ignore(256, '\n');
				cin >> inputAlter;
			}

			myTree->deleteNode(inputAlter);
		}
		else if (input123456 == 4) {

			cout << "+ Bitte geben Sie den zu suchenden Datensatz an" << endl;
			cout << "Name ?> ";
			cin >> inputName;
			while (cin.fail()) {
				cout << "Fehler! Bitte geben Sie einen Namen ein " << endl;
				cin.clear();
				cin.ignore(256, '\n');
				cin >> inputName;
			}
			cout << "+ Fundstellen :" << endl;
			myTree->searchNode(inputName);

		}
		else if (input123456 == 5) {
			myTree->printAll();

		}
		else if (input123456 == 6) {
			break;
		}

		cin.clear();
	}

	system("PAUSE");

	return 0;
}
