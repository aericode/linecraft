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
    std::string* docLines;
    std::string  fileName;

    int fileLineCount;

public:
	Plotter(){}

	Plotter(int xSize_,int ySize_,std::string fileName_){

		fileName = fileName_;

		xSize = xSize_;
		ySize = ySize_;

		fileLineCount = (xSize*ySize) + 3;

		docLines = new std::string[fileLineCount];

		clear();

		docLines[0] = "P3";
		docLines[1] = std::to_string(xSize) + " " +  std::to_string(ySize);
		docLines[2] = "255";

		plotFile();
	}

	~Plotter(){
		delete[] docLines;
	}

	int matrixToLine(Location location){
		int x = location.getX();
		int y = location.getY();

		return x + y*xSize;
	}

	std::string colorToString(Color color){

		std::string colorString;

		int r = color.getR();
		int g = color.getG();
		int b = color.getB();


		colorString =  std::to_string(r) + " " +  std::to_string(g) + " " +  std::to_string(b);

		return colorString;

	}


	bool isValidLocation(Location location){
		bool validX = (location.getX() < xSize) && (location.getX()>= 0);
		bool validY = (location.getY() < ySize) && (location.getY()>= 0);

		return validX && validY;
	}


	void changePixel(Location location, Color color){
		//se estiver fora do limite simplesmente ignora
		if(!isValidLocation(location)){return;}


		int indexLine = 3 + matrixToLine(location);

		docLines[indexLine] = colorToString(color);
	}



	void clear(){
		for(int i = 3;i < fileLineCount;i++){
			docLines[i]="255 255 255";
		}
	}


	void printBuffer(){
		for(int i = 0;i < fileLineCount;i++){
			std::cout << docLines[i] << std::endl;
		}
	}

	
	void plotFile(){
		std::ofstream myfile;

		myfile.open(fileName.c_str());

		for(int i = 0;i < fileLineCount;i++){
			myfile<<docLines[i]<<std::endl;
		}
	}
};

#endif