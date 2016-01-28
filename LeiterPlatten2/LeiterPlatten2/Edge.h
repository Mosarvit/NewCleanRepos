#ifndef EDGE_H
#define EDGE_H

#include "Node.h"
#include "Utilities.h"

using namespace std;

class Edge
{
public:

	Edge(Node& rSrc, Node& rDst)
		: m_rSrc(rSrc), m_rDst(rDst)
	{ }


	Node& getSrcNode() { return m_rSrc; }
	Node& getDstNode() { return m_rDst; }

	string toString() const;

	virtual double getWeight() { return 1; }


private:

	Node& m_rSrc;
	Node& m_rDst;

};

#endif