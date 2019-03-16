#ifndef PLOTTER
#define PLOTTER
#include <iostream>
#include <fstream>

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

    int filePixelCount;

public:
	Plotter(){}

	Plotter(int xSize_,int ySize_,std::string fileName_){

		fileName = fileName_;

		xSize = xSize_;
		ySize = ySize_;

		filePixelCount = (xSize*ySize) + 3;

		docLines = std::vector<std::string>(filePixelCount, "0 0 0");

		docLines[0] = "P3";
		docLines[1] = std::to_string(xSize) + " " +  std::to_string(ySize);
		docLines[2] = "255";

		std::cout<<docLines.size()<<std::endl;
	}

	int matrixToLine(Location location){
		int x = location.getX();
		int y = location.getY();

		return y*xSize + x;
	}

	std::string colorToString(Color color){

		std::string colorString;

		int r = color.getR();
		int g = color.getG();
		int b = color.getB();


		colorString =  std::to_string(r) + " " +  std::to_string(g) + " " +  std::to_string(b);

		return colorString;

	}


	void changePixel(Location location, Color color){
		int indexLine = 3 + matrixToLine(location);

		docLines[indexLine] = colorToString(color);
	}



	void clear(){
		for(int i = 3;i < docLines.size();i++){
			docLines[i]="255 255 255";
		}
	}


	void printBuffer(){
		for(int i = 0;i < docLines.size();i++){
			std::cout<<docLines[i]<<std::endl;
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