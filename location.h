#ifndef LOCATION
#define LOCATION

class Location
{
private:
    int x;
    int y;
public:
	Location(){}
	Location(int _x, int _y){
		x = _x;
		y = _y;
	}

	int getX(){return x;}
	int getY(){return y;}

	void setX(int _x){x = _x;}
	void setY(int _y){y = _y;}

	bool equals(Location other){
		return (x == other.getX() && y == other.getY());
	}
};

#endif