#include <iostream>
#include <vector>

#include "json.hpp"

#include "jsonReader.h"
#include "vec3.h"
#include "plotter.h"
#include "location.h"
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


	Canvas canvas(200,100,"fromJson.ppm");

	JSON obj;
    string userInput = stringFromFile("lines.json");
    obj = JSON::Load(userInput);
    jsonToLines(obj,canvas);


    canvas.saveFile();



	/*
	Canvas canvas(200,100,"default.ppm");

    Color cor00( 10.0, 50.0,  0.0);
	Color cor10( 30.0,250.0,100.0);
	Color cor01(100.0,100.0, 30.0);
	Color cor11(200.0,  0.0,150.0);

	canvas.interpolate(cor00,cor10,cor01,cor11);


	canvas.circleMidPoint(Location(100,50),20);

	canvas.saveFile();
	*/

	return 0;
}