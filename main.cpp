#include <iostream>

#include "plotter.h"
#include "location.h"
#include "color.h"
#include "canvas.h"


int main(){




	Canvas canvas(100,100,"default.ppm");

	canvas.lineBres(Location(10,20) , Location(20,30));

	canvas.circleMidPoint(Location(50,50), 10);

	canvas.saveFile();



	return 0;
}