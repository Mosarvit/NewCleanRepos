#include <string>
#include <sstream>
#include <iomanip>
#include <cctype>

#include "PreisAngebot.h"

using namespace std;


PreisAngebot::PreisAngebot(Node& rSrc, Node& rDst, double angebot1, double angebot100, double angebot1000) : Edge(rSrc, rDst) {

	m_angebote.push_back(angebot1);
	m_angebote.push_back(angebot100);
	m_angebote.push_back(angebot1000);
};

PreisAngebot::PreisAngebot(Node& rSrc, Node& rDst, double angebot1) : Edge(rSrc, rDst) {

	m_angebote.push_back(angebot1);
};