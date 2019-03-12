#ifndef COLOR
#define COLOR

class Color
{
private:
    int r;
    int g;
    int b;
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

#endif