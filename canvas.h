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

	Plotter* plotBuffer;

	Canvas(){}

	Canvas(int xSize_, int ySize_, std::string filename_){	

		xSize = xSize_;
		ySize = ySize_;
		filename = filename_;

		plotBuffer = new Plotter (xSize,ySize,filename);

		plotBuffer->clear();
		plotBuffer->plotFile();
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
			plotBuffer->changePixel(nextLocation, defaultColor);

			x++;
		}

    }


	void saveFile(){
		plotBuffer->plotFile();
	}
};
