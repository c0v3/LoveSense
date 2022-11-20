#include "lovense_config.hpp"


void lovenseconfig::innit_lovense() {


	


}
void waitForSeconds(int seconds) {
	for (int i = 1; i <= seconds; i++) {
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		LOG(INFO) << "Wait: " << i << " seconds" << std::endl;
	}
}
//uhhh im doing this late as fuck this is 100% a goofy way to do it
lovensethread::lovensethread()
{
	toy_connected_result = false;

	bool systemReady = control.setupSystem();

	if (systemReady) {

		toy_connected_result = true;

		LOG(INFO) << "lovense begin, toy found and connected";

		LOG(INFO) << " DEBUG ONLY: toy should vibrate on number 3 intensity every 2 or so seconds :) (i hate this so fucking much cunt)";

		LOG(INFO) << "SEnding test vibrations";
		control.vibrateToy(3);
		waitForSeconds(2);
		LOG(INFO) << "UNO";

		control.vibrateToy(3);
		waitForSeconds(2);
		LOG(INFO) << "DUO";

		control.vibrateToy(3);
		waitForSeconds(2);
		LOG(INFO) << "tre";


		



	}
	else {
		LOG(INFO) << "Lovense innit failed, toy likely not found";

	}

	

}

lovensethread::~lovensethread()
{

	if (!big::g_running) {
		control.closeSystem();
		LOG(INFO) << "LOVENSE CLOSED";
	}
}



void lovensethread::lovensemain() {


	


	/*

		if (TOGGLES.cookedasf) {//this is the stupid skill issue toggle, seen in many skids and/or terrible programmers code #swagginandbaggin


			if (toy_connected_result) {

				g_lovense->sendvibration(control);

				LOG(INFO) << "vibration sent";



			}
			else if (!toy_connected_result) {

				LOG(INFO) << "toy not connected?" << "the fact this dogshit implementation got this far maybe is an ok thing tho? :)";
			}


			TOGGLES.cookedasf = false;
		}*/










	


	/*
	if (TOGGLES.cookedasf) {//this is the stupid skill issue toggle, seen in many skids and/or terrible programmers code #swagginandbaggin


		if (toy_connected_result) {

			g_lovense->sendvibration();

			LOG(INFO) << "vibration sent";



		}
		else if (!toy_connected_result) {

			LOG(INFO) << "toy not connected?" << "the fact this dogshit implementation got this far maybe is an ok thing tho? :)";
		}


		TOGGLES.cookedasf = false;
	}

	

	*/




	

}


void lovensethread::lovensemaindisable() {

	

}


void lovensethread::sendvibration(LovenseControl test ,int intensity =3, int waitduration =2) {


	test.vibrateToy(intensity);
	//waitForSeconds(waitduration);

}