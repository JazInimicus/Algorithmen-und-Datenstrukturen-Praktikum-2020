/*************************************************
* ADS Praktikum 2.1
* main.cpp
*
*************************************************/
#define CATCH_CONFIG_RUNNER

#include <iostream>
#include <string>
#include "Ring.h"
#include "catch.hpp"

using namespace std;


int main()
{
	int result = Catch::Session().run();
	// Ihr Code hier:
	Ring* myRingbuffer = new Ring;
	std::string input123, inputDescr, inputSymData, inputSearchData;

	while (true)
	{
		cout << std::string(26, '=') << endl;
		cout << "1) Backup einfuegen" << endl;
		cout << "2) Backup suchen" << endl;
		cout << "3) Alle Backups ausgeben" << endl;
		cout << std::string(26, '=') << endl;
		getline(cin, input123);
		if (input123 == "1")
		{
			cout << "+Neuen Datensatz einfuegen" << endl;
			cout << "Beschreibung ?>";
			getline(cin, inputDescr);
			cout << "Daten ?>";
			getline(cin, inputSymData);
			cout << endl;
			myRingbuffer->addNode(inputDescr, inputSymData);


		}
		else if (input123 == "2")
		{
			cout << "+ Nach welchen Daten soll gesucht werden?" << endl;
			cout << "?> ";
			getline(cin, inputSearchData);
			myRingbuffer->search(inputSearchData);
		}
		else if (input123 == "3")
		{
			myRingbuffer->print();
		}
		else if (input123 == "quit") { break; }

	}


	//
	///////////////////////////////////////
	system("Pause");
	return 0;
}
