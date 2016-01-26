#ifndef TRAVEL_GUI
#define TRAVEL_GUI

#include <iostream>
#include <map>
#include <vector>
#include <string>

#include "PreisAngebot.h"
#include "PreisMap.h"

using namespace std;

class GUI
{

public:


	GUI(PreisMap& pm)  ;

    int showMenu();

    // Nutzerinteraktion zum Buchen eines Fluges
    // Rückgabewert: 'true', wenn die vom Nutzer gewählte Route gebucht werden soll, sonst 'false'
	bool angebotBerechnung(Node& rStart, Node& rEnde);

    // Gibt eine Liste aller gebuchten Reisen aus.
    // void showBookingList();

	void showRevenues() ;

	//~GUI();

private:

	//int readAnzahl(); // Helper Funktion, um eine Stadt einzulesen.
	PreisMap& m_rPreisMap;

	//vector<PreisMap*> m_rPreisMaps;

    //list<Booking> m_bookings;
	int inputNumber(string question);
	string inputString(string question);
	map<Node*, double> m_revInfos;

};


/*
 * Im Idealfall wirft die Anwendung im Fehlerfall eine Exception.
 */
//class TravelGuiException
//{
//
//public:
//
//    TravelGuiException(const std::string& msg) : m_msg(msg) {}
//
//    std::string getError() const { return m_msg; }
//
//
//private:
//
//    std::string m_msg;
//
//};

#endif