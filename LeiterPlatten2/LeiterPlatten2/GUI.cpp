#include "GUI.h"

GUI::GUI(PreisMap& pm) : m_rPreisMap(pm) {

	for (auto node : pm.getNodes()) {
		m_revInfos[node] = 0.0;
	}
}

int GUI::showMenu()
{
		//--------test area start-----------------

		//Node* choice = inputNode("Please select a Node:");

		//--------test area end-------------------

		cout << endl;
		cout << "------------------------------------------------------------------------" << endl;
		cout << "Bitte waehlen Sie:" << endl
		<< "1. Neuer Auftrag" << endl
		<< "2. Ausgabe aller Umsaetze" << endl
		<< "3. Beenden" << endl;

	cout << "Eingabe: ";
	int eingabe;
	cin >> eingabe;
	return eingabe;
}

bool GUI::angebotBerechnung(Node& rStart, Node& rEnde)
{
	int preisstufe = 0;
	
	//PreisMap *currentPreisMap;
	int anzahl = 0;
	string word;
	deque<Edge*> result;
	
	cout << endl;
	anzahl = inputNumber("Bitte geben Sie die Anzahl an: ");
	
	if (anzahl >= 1000) {

		preisstufe = 2;

	}else if (anzahl >= 100) {

		preisstufe = 1;

	}else {

		preisstufe = 0;
	}

	for (auto node : m_rPreisMap.getNodes()) {

		m_revInfos[node] = 0.0;
	}

	m_rPreisMap.findShortestPathDijkstra(result, &rStart, &rEnde, preisstufe);

	for (auto edge : result) {

		double totalPrice = dynamic_cast<PreisAngebot*>(edge)->getWeight(preisstufe)*anzahl;
		cout << edge->toString() << " Total Price: " << totalPrice << endl;

		m_revInfos[&(edge->getDstNode())] = m_revInfos[&(edge->getDstNode())] + totalPrice;

	}

	return false;
}

void GUI::showRevenues() {

	cout << endl << "Die Umsaetze: " << endl << endl;

	for (auto info : m_revInfos) {

		cout << info.first->getID() << " : " << info.second << endl;
	}
}

 
int GUI::inputNumber(string question)
{
	int n;
	bool fail = true;	

	while (fail)  
	{
		cout << question << endl;
		cout << "Eingabe: ";
		cin >> n;

		if (!cin){

			cin.clear(); 
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
			cout << "\nFehlerhafte Eingabe! Nur Zahlen sind zulaessing...\n" << endl;

		}else{
			fail = false;
		}
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return n;
}

string GUI::inputString(string question)
{
	string input;
	bool fail = true;

	while (fail)  
	{
		cout << question << endl;
		getline(cin, input);

		if (!cin) {

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Fehlerhafte Eingabe!" << endl;
		}
		else {
			fail = false;
		}
	}
	return input;
}

Node* GUI::inputNode(string question)
{
	Node* pNode = NULL;
	unsigned input, i;
	stringstream ss;

	bool finished = false;

	list<Node*> nodeList = m_rPreisMap.getNodes();	

	i = 0;
	ss << question << "\n\n";
	for (auto node : nodeList) {

		ss << ++i << ". " << node->getID() << endl;
	}

	while (!finished) {

		input = inputNumber(ss.str());

		if ((input > nodeList.size())||(input<1)) {

			cout << "\nAuswahl ungueltig, bitte versuchen Sie es erneut... \n" << endl;
		}
		else {

			finished = true;
			pNode = *(next(nodeList.begin(), input - 1));
			cout << "\nIhre Auswahl : " << pNode->getID() << endl << endl;
		}
	}

	return pNode;
}