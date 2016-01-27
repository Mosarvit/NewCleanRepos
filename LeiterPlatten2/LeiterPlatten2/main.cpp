#include <iostream>
#include <vector>

#include "PreisAngebot.h"
#include "PreisMap.h"
#include "GUI.h"

using namespace std;

int main()
{
	

	PreisMap preisMap1, preisMap100, preisMap1000;

	Node& rSysEng = preisMap1.addNode(new Node("SysEng"));
	Node& rEndos = preisMap1.addNode(new Node("Endos"));
	Node& rLightOff = preisMap1.addNode(new Node("LightOff"));
	Node& rLPBes = preisMap1.addNode(new Node("LPBes"));
	Node& rBP = preisMap1.addNode(new Node("BP"));
	Node& rHWTesting = preisMap1.addNode(new Node("HWTesting"));

	

	//preisMap100.addNode(&rSysEng);
	//preisMap100.addNode(&rEndos);
	//preisMap100.addNode(&rLightOff);
	//preisMap100.addNode(&rLPBes);
	//preisMap100.addNode(&rBP);
	//preisMap100.addNode(&rHWTesting);

	//preisMap1000.addNode(&rSysEng);
	//preisMap1000.addNode(&rEndos);
	//preisMap1000.addNode(&rLightOff);
	//preisMap1000.addNode(&rLPBes);
	//preisMap1000.addNode(&rBP);
	//preisMap1000.addNode(&rHWTesting);

	//PreisMap preisMap100 = new PreisMap(preisMap1);
	//PreisMap preisMap1000(preisMap1);

	preisMap1.addPreisAngebot(rSysEng, rEndos, 200.0, 80.0, 20.0);
//	preisMap100.addPreisAngebot(rSysEng, rEndos, 80.0);
	//preisMap1000.addPreisAngebot(rSysEng, rEndos, 20.0);

	//preisMap1.addPreisAngebot(rSysEng, rLightOff, 160.0, 120.0, 70.0);
	//preisMap100.addPreisAngebot(rSysEng, rLightOff, 120.0);
	//preisMap1000.addPreisAngebot(rSysEng, rLightOff, 70.0);

	preisMap1.addPreisAngebot(rEndos, rLPBes, 180.0, 100.0, 30.0);
	//preisMap100.addPreisAngebot(rEndos, rLPBes, 100.0);
	//preisMap1000.addPreisAngebot(rEndos, rLPBes, 30.0);

	preisMap1.addPreisAngebot(rLightOff, rLPBes, 160.0, 80.0, 20.0);
	//preisMap100.addPreisAngebot(rLightOff, rLPBes, 80.0);
	//preisMap1000.addPreisAngebot(rLightOff, rLPBes, 20.0);

	preisMap1.addPreisAngebot(rLightOff, rBP, 170.0, 120.0, 20.0);
	//preisMap100.addPreisAngebot(rLightOff, rBP, 120.0);
	//preisMap1000.addPreisAngebot(rLightOff, rBP, 20.0);

	preisMap1.addPreisAngebot(rLPBes, rHWTesting, 300.0, 260.0, 210.0);
	//preisMap100.addPreisAngebot(rLPBes, rHWTesting, 260.0);
	//preisMap1000.addPreisAngebot(rLPBes, rHWTesting, 210.0);

	preisMap1.addPreisAngebot(rBP, rHWTesting, 290.0, 280.0, 200.0);
	//preisMap100.addPreisAngebot(rBP, rHWTesting, 280.0);
	//preisMap1000.addPreisAngebot(rBP, rHWTesting, 200.0);
	
	//for (auto preisAngebot : preisMap1.getEdges()) {

	//	cout << preisAngebot->toString() << " " << dynamic_cast<PreisAngebot*>(preisAngebot)->getWeight(2) << endl;
	//}

	//routes.addFlightRoute(rBerlin, rWien, 530);
 //   routes.addFlightRoute(rWien, rMadrid, 1800);
 //   routes.addFlightRoute(rMadrid, rBarcelona, 505);
 //   routes.addFlightRoute(rBerlin, rLondon, 930);
 //   routes.addFlightRoute(rLondon, rNewYork, 5600);

 //   routes.addBusRoute(rBerlin, rMadrid, 2300);
 //   routes.addBusRoute(rBerlin, rWien, 680);
 //   routes.addBusRoute(rWien, rMadrid, 2450);
 //   routes.addBusRoute(rMadrid, rBarcelona, 619);
    
//	vector<PreisMap*> preisMaps;

	//preisMaps.push_back(&preisMap1);
	//preisMaps.push_back(&preisMap100);
	//preisMaps.push_back(&preisMap1000);

	GUI gui(preisMap1);

    bool bRunning = true;

    // Endlosschleife, bis bRunning auf 'false' gesetzt wird vv
    while (bRunning)
    {
        int menuEntry = gui.showMenu();

        // Hinweis: Die Fallunterscheidung geht auch mit Switch-Case (siehe C-Programmierung)

        // Flug buchen
        if (menuEntry == 1) 
        {
            //try {
				gui.angebotBerechnung(rSysEng, rHWTesting);
            //}
            //catch (const TravelGuiException& e) {
            //    std::cout << "Route konnte nicht gebucht werden!" << std::endl;
            //    std::cout << "Ursache: " << e.getError() << std::endl;
            //}
        }
        // Liste aller Buchungen anzeigen
        else if (menuEntry == 2) 
        {
			gui.showRevenues();
			// gui.showBookingList();
        }
        // Schleife verlassen und Programm beenden
        else if (menuEntry == 3)
        {
			bRunning = false; 
        }
        // falsche Eingabe
        else 
        {
            std::cout << "Fehlerhafte Eingabe! " << std::endl;
        }
    }
    
	return 0;
}