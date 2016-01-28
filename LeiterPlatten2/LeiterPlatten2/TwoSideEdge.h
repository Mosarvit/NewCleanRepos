#ifndef TWOSIDEEDGE
#define TWOSIDEEDGE

#include "Edge.h"

using namespace std;

class TwoSideEdge : public Edge
{
	TwoSideEdge(Node& rSrc, Node& rDst, double distance) : Edge(rSrc, rDst), m_distance(distance) { }

	virtual double getWeight() { return 80.0 + 0.10 * m_distance; }

	int getMinutes() { return static_cast<int>((m_distance / 700.0) * 60); }

	double getPrice() { return getWeight(); }

private:

	double m_distance;

};

#endif