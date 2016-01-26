#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include <vector>
#include <deque>
#include <string>
#include <map>
#include "Node.h"
#include "Edge.h"
#include "PreisAngebot.h"

class Graph
{

public:

	struct tDijkstraEntry
	{
		double dist;
		Node* prevNode;
		Edge* prevEdge;
	};

	typedef std::list<Node*> tNodeList;
	typedef std::map<Node*, tDijkstraEntry> tDijkstraMap;
    typedef std::deque<Edge*> tPath;


	~Graph();

	Node& addNode(Node* pNode);
	void addEdge(Edge* pEdge);

	void deleteNode(Node* pNode);
	void deleteEdge(Edge* pEdge);

	const list<Node*>& getNodes() { return m_nodes; };
	const list<Edge*>& getEdges() { return m_edges; };

	void saveAsDot(const std::string& rFilename);

	bool findShortestPathDijkstra(tPath& rPath, Node* pSrcNode, Node* pDstNode, int preisstufe);


protected:

	list<Node*> m_nodes;
	list<Edge*> m_edges;
};

#endif