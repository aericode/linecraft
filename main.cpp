#include <iostream>

#include "plotter.h"
#include "location.h"
#include "color.h"
#include "pixel.h"
#include "canvas.h"


int main(){

	Location start(0,0);
	Location end(50,99);


	Canvas canvas(100,100,"ruim.ppm");


	canvas.lineBres(start,end);

	canvas.plotAll();


	return 0;
}