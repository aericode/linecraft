#ifndef PLOTTER
#define PLOTTER
#include <iostream>
#include <string>
#include <vector>

class Plotter
{
private:
    std::vector<std::string> docLines;
public:
	Plotter(){}
	Plotter(int xSize,int ySize){
		docLines.reserve( (xSize*ySize) + 3 );
		docLines[0] = "P3";
		docLines[1] = xSize + " " +ySize;
		docLines[2] = "255";
	}

	void clear(){
		for(int i = 3;i < docLines.size();i++){
			docLines[i]="0 0 0";
		}
	}
	
	void plotFile(std::string fileName){
		std::ofstream myfile;
		myfile.open(fileName.c_str());

		for(int i = 0;i < docLines.size();i++){
			myfile<<docLines[i]<<std::endl;
		}
	}
};

#endif