#ifndef BUS_ROUTE
#define BUS_ROUTE

#include <vector>

#include "Edge.h"

using namespace std;

class PreisAngebot : public Edge
{

public:

	PreisAngebot(Node& rSrc, Node& rDst, double angebot1, double angebot100, double angebot1000) ;

    // Kantengewicht = Preis (18ct / km)

	 virtual double getWeight(int preisStufe) { return *(next(m_angebote.begin(), preisStufe)); }

	//const double& getAngebot() { return *(next(m_angebote.begin(), preisStufe)) ; }

    /*
    *   Zeit in Stunden = (700km/h) / strecke ==> mal 60 = Minuten
    *   nach 'int' casten, um Nachkommastellen zu eliminieren
    */
    // int getMinutes() { return static_cast<int>((m_distance / 75) * 60); }

    // double getPrice()  { return getWeight(); }

private:

	vector<double>  m_angebote;
};


#endif