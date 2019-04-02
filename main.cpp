#include <iostream>
#include <vector>

#include "json.hpp"

#include "jsonReader.h"

#include "plotter.h"
#include "location.h"
#include "color.h"
#include "canvas.h"


int main(){
	/*
	std::vector<Location> mouth;
	std::vector<Location> nose;

	mouth.push_back(Location(20,60));
	mouth.push_back(Location(30,70));
	mouth.push_back(Location(70,70));

	Canvas canvas(100,100,"default.ppm");

	canvas.circleMidPoint(Location(30,50), 10);
	canvas.circleMidPoint(Location(60,50), 10);

	canvas.lineBres(Location(40,50) , Location(50,50));
	canvas.lineBres(Location(43,45) , Location(50,60));

	canvas.lineBres(Location(0,50) , Location(20,50));

	canvas.polyLine(mouth);

	canvas.saveFile();
	*/

	//Canvas canvas(100,100,"default.ppm");

	//canvas.drawLine(Location(50,50),Location(10,90),2);

	/*
	for(int i = 0; i < 8 ; i++){
		canvas.lineBres(Location(50,50-i),Location(90,10-i));
	}
	*/

	//canvas.saveFile();


	JSON obj;
    string userInput = stringFromFile("lines.json");

    obj = JSON::Load(userInput);


    jsonToLines(obj);

	return 0;
}