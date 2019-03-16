#include <iostream>

#include "plotter.h"
#include "location.h"
#include "color.h"
#include "pixel.h"
#include "canvas.h"


int main(){

	Location start(0,0);
	Location end(10,30);


	Canvas canvas(100,100);


	canvas.lineBres(start,end);

	//canvas.plotAll();


	return 0;
}