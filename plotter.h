#ifndef PLOTTER
#define PLOTTER
#include <iostream>

#include "location.h"
#include "color.h"

#include <vector>
#include <string>

class Plotter
{
private:

	int xSize;
	int ySize;
    std::vector<std::string> docLines;
    std::string fileName;

public:
	Plotter(){}

	Plotter(int xSize_,int ySize_,std::string fileName_){

		clear();

		xSize = xSize_;
		ySize = ySize_;

		docLines.reserve( (xSize*ySize) + 3 );
		docLines[0] = "P3";
		docLines[1] = xSize + " " +ySize;
		docLines[2] = "255";

	}

	int matrixToLine(Location location){
		int x = location.getX();
		int y = location.getY();

		return y*ySize + x;
	}

	std::string colorToString(Color color){

		std::string colorString;

		int r = color.getR();
		int g = color.getG();
		int b = color.getB();


		colorString =  std::to_string(r) + " " +  std::to_string(g) + " " +  std::to_string(b);

		return colorString;

	}


	void changeLine(Location location, Color color){
		int indexLine = 3 + matrixToLine(location);

		docLines[indexLine] = colorToString(color);
	}



	void clear(){
		for(int i = 3;i < docLines.size();i++){
			docLines[i]="0 0 0";
		}
	}
	
	void plotFile(){
		std::ofstream myfile;

		myfile.open(fileName.c_str());

		for(int i = 0;i < docLines.size();i++){
			myfile<<docLines[i]<<std::endl;
		}
	}
};

#endif