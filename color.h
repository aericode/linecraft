#ifndef COLOR
#define COLOR
#include <iostream>
#include <string>

class Color
{
private:
    int r;
    int g;
    int b;

    friend std::ostream& operator<<(std::ostream&, const Color&);

public:
	Color(){}
	Color(int _r, int _g, int _b){
		r = _r;
		g = _g;
		b = _b;
	}

	int getR(){return r;}
	int getG(){return g;}
	int getB(){return b;}

	void setR(int _r){r = _r;}
	void setG(int _g){g = _g;}
	void setB(int _b){b = _b;}

};

std::ostream& operator<<(std::ostream &strm, const Color& col) {
	return strm << col.r << " " << col.g << " " << col.b;
}

#endif