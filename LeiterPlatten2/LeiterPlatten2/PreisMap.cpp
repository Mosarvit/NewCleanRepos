#include "PreisMap.h"
#include "PreisAngebot.h"

void PreisMap::addPreisAngebot(Node & rSchritt1, Node & rSchritt2, double angebot1, double angebot100, double angebot1000)
{
	addEdge(new PreisAngebot(rSchritt1, rSchritt2, angebot1, angebot100, angebot1000));
}

void PreisMap::addPreisAngebot(Node & rSchritt1, Node & rSchritt2, double angebot1)
{
	addEdge(new PreisAngebot(rSchritt1, rSchritt2, angebot1));
}

Node* PreisMap::getNodeById(const string& rNodeId)
{
	for (list<Node*>::iterator it = m_nodes.begin(); it != m_nodes.end(); it++) {
		if ((*it)->getID() == rNodeId)
			return *it;
	}
	return NULL;
}