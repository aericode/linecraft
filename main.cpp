#include <iostream>
#include <vector>

#include "json.hpp"

#include "jsonReader.h"
#include "vec3.h"
#include "plotter.h"
#include "location.h"
#include "canvas.h"


int main(){
	

	Canvas canvas(200,100,"fromJson.ppm");

	JSON obj;
    string userInput = stringFromFile("lines.json");
    obj = JSON::Load(userInput);
    jsonToLines(obj,canvas);


    canvas.saveFile();



	/*
	//Uso do interpolate sem o json

    Color cor00( 10.0, 50.0,  0.0);
	Color cor10( 30.0,250.0,100.0);
	Color cor01(100.0,100.0, 30.0);
	Color cor11(200.0,  0.0,150.0);

	canvas.interpolate(cor00,cor10,cor01,cor11);
	canvas.saveFile();
	*/

	return 0;
}