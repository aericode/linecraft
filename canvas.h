#include <math.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>

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
	Canvas(int xSize_, int ySize_, std::string filename_ = "default.ppm"){		
		xSize = xSize_;
		ySize = ySize_;
		filename = filename_;

		Plotter plotTest(xSize,ySize,"teste.ppm");

		plotTest.clear();
		plotTest.plotFile();
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

		if(starter.getX()>final.getY()){
			std::swap(starter,final);
		}

		int dx  = final.getX() - starter.getX();
        int dy  = final.getY() - starter.getY();


        int x   = starter.getX();
        int y   = starter.getY();



        int eps = 2*dy - dx;
    
    	while(x<final.getX()){
			if(eps  >= 0){
				y++;
				eps += (2*dy-2*dx);
			}
			else{
				eps += 2*dy;
			}

			Location nextLocation(x,y);
			Pixel nextPixel(nextLocation,defaultColor);

			plotPending.push_back(nextPixel);

			x++;
		}


		Pixel lastPixel(final,defaultColor);

		plotPending.push_back(lastPixel);

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

};
