#include <iostream>
#include <vector>

#include "PreisAngebot.h"
#include "PreisMap.h"
#include "GUI.h"

using namespace std;

int main()
{
	PreisMap preisMap1;

	Node& rSysEng = preisMap1.addNode(new Node("SysEng"));
	Node& rEndos = preisMap1.addNode(new Node("Endos"));
	Node& rLightOff = preisMap1.addNode(new Node("LightOff"));
	Node& rLPBes = preisMap1.addNode(new Node("LPBes"));
	Node& rBP = preisMap1.addNode(new Node("BP"));
	Node& rHWTesting = preisMap1.addNode(new Node("HWTesting"));
		
	preisMap1.addPreisAngebot(rSysEng, rEndos, 200.0, 80.0, 20.0);
	preisMap1.addPreisAngebot(rEndos, rLPBes, 180.0, 100.0, 30.0);
	preisMap1.addPreisAngebot(rLightOff, rLPBes, 160.0, 80.0, 20.0);
	preisMap1.addPreisAngebot(rLightOff, rBP, 170.0, 120.0, 20.0);
	preisMap1.addPreisAngebot(rLPBes, rHWTesting, 300.0, 260.0, 210.0);
	preisMap1.addPreisAngebot(rBP, rHWTesting, 290.0, 280.0, 200.0);

	GUI gui(preisMap1);

    bool finished = false;

    // Endlosschleife, bis finished auf 'true' gesetzt wird 

    while (!finished)
    {
        int menuEntry = gui.startMenu();

		switch (menuEntry)
		{
		case 1:

			gui.angebotBerechnung(rSysEng, rHWTesting);
			break;

		case 2:

			gui.showRevenues();
			break;

		case 3:

			finished = true;
			break;

		default:
			break;
		}
    }
    
	return 0;
}