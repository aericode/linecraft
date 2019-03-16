#include <iostream>
#include "location.h"
#include "color.h"
#include "pixel.h"
#include "canvas.h"


int main(){

	Location start(99,50);
	Location end(0,0);


	Canvas canvas(100,100);


	canvas.lineBres(start,end);
	canvas.plotAll();

	return 0;
}