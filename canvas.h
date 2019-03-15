#include <math.h>
#include <iostream>
#include <fstream>
#include <vector>

#include "plotter.h"
#include "location.h"
#include "color.h"
#include "pixel.h"

class Canvas{
public:
	int xSize;
	int ySize;
	std::ofstream myfile;
	std::string filename;

	std::vector<Pixel> plotPending;

	Plotter plotBuffer;

	Canvas(){}
	Canvas(int _xSize, int _ySize, std::string _filename = "default.ppm"){		
		xSize = _xSize;
		ySize = _ySize;
		filename = _filename;
	}

	void clear(){
		myfile.open(filename.c_str());

		myfile<< "P3"  << std::endl
			  << xSize << " " << ySize << std::endl 
			  << "255" << std::endl;

		for (int j = 0; j <  ySize; j++){
			for(int i = 0; i < xSize; i++){

				int r  = 255;
				int g  = 255;
				int b  = 255;

				myfile<< r << " " << g << " " << b << std::endl;
			}
		}
	}


	void lineBres(Location starter, Location final){
		Color defaultColor(0,0,0);


		int x = starter.getX();
		int y = starter.getY();

		int dx = final.getX() - starter.getX();
		int dy = final.getY() - starter.getY();

		int x2 = final.getX();

		int incx = 1;
		int incy = 1;


		Pixel startingPixel(starter, defaultColor);

		plotPending.push_back(startingPixel);

		int d    = 2*dy - dx;
		int incI = 2*dy;
		int incS = 2*(dy-dx);

		while(x != x2){
			if(d<=0){
				d = d + incI;
				x = x + incx;
			}else{
				d = d + incS;
				x = x + incx;
				y = y + incy;
			}

			Location nextLocation(x,y);
			Pixel nextPixel(nextLocation,defaultColor);

			plotPending.push_back(nextPixel);
		}

	}

	bool isIncluded(Location tested){
		for(int i = 0; i < plotPending.size();i++){
			if(tested.equals( plotPending[i].getLocation()) ){
				return true;
			}
		}
		return false;
	}


	void plotAll(){

		int r;
		int g;
		int b;


		myfile.open(filename.c_str());

		myfile<< "P3"  << std::endl
			  << xSize << " " << ySize << std::endl 
			  << "255" << std::endl;

		for (int j = 0; j <  ySize; j++){
			for(int i = 0; i < xSize; i++){

				Location nextLocation(i,j);

				if( isIncluded(nextLocation) ){
					r = 0;
					g = 0;
					b = 0;
				}else{
					r = 255;
					g = 255;
					b = 255;
				}
				

				myfile<< r << " " << g << " " << b << std::endl;
			}
		}
	}

	void pendingNumber(){
		std::cout<< plotPending.size()<<std::endl;
	}

	void sayPending(){
		for(int i = 0; i < plotPending.size();i++){
			std::cout<< plotPending[i].getLocation().getX()<< " "<< plotPending[i].getLocation().getY() <<std::endl;
		}
	}

};
