#ifndef PIXEL
#define PIXEL
#include "location.h"
#include "color.h"

class Pixel
{
private:
	Location location;
    Color color;

public:
	Pixel(){}
	Pixel(Location _location, Color _color){
		location = _location;
		color    = _color;
	}

	Location getLocation(){return location;}
	Color getColor(){return color;}

	Location setLocation(Location _location){location = _location;}
	Color setColor(Color _color){color = _color;}

};

#endif