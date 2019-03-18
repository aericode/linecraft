#include <iostream>

#include "plotter.h"
#include "location.h"
#include "color.h"
#include "canvas.h"


int main(){

	Location start(10,10);
	Location end(30,30);


	Canvas canvas(100,100,"default.ppm");

	canvas.lineBres(start,end);

	canvas.saveFile();



	return 0;
}