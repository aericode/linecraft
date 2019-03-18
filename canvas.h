#include <math.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>

#include "plotter.h"
#include "location.h"
#include "color.h"

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
	}




	void lineBres(Location starter, Location final){

		if(starter.getX()>final.getY()){
			std::swap(starter,final);
		}

		int dx  = final.getX() - starter.getX();
        int dy  = final.getY() - starter.getY();


        int x   = starter.getX();
        int y   = starter.getY();



        int eps = 2*dy - dx;
    
    	while(x < final.getX()){
			if(eps  >= 0){
				y++;
				eps += (2*dy-2*dx);
			}
			else{
				eps += 2*dy;
			}

			plotBuffer->changePixel(Location(x,y));

			x++;
		}

    }

    //adaptando o modelo desse site
    //https://www.geeksforgeeks.org/mid-point-circle-drawing-algorithm/
    //para o canvas do projeto
    void circleMidPoint(Location centre, int r) {

    	int x_centre = centre.getX();
    	int y_centre = centre.getY();

	    int x = r, y = 0;

	    
	    plotBuffer->changePixel(Location ( x + x_centre, y + y_centre));
	      

	    if (r > 0) 
	    { 
	    	plotBuffer->changePixel(Location ( x + x_centre,-y + y_centre));
	    	plotBuffer->changePixel(Location ( y + x_centre, x + y_centre));
	    	plotBuffer->changePixel(Location (-y + x_centre, x + y_centre));
	    }


	    int P = 1 - r; 
	    while (x > y) 
	    {  
	        y++; 
	          
 
	        if (P <= 0){ 
	            P = P + 2*y + 1; 
	        }else{ 
	            x--; 
	            P = P + 2*y - 2*x + 1; 
	        } 
	          
	        if (x < y){break;}
	          


	        plotBuffer->changePixel(Location ( x + x_centre, y + y_centre));
	        plotBuffer->changePixel(Location (-x + x_centre, y + y_centre));
	        plotBuffer->changePixel(Location ( x + x_centre,-y + y_centre));
	        plotBuffer->changePixel(Location (-x + x_centre,-y + y_centre));
	          

	        if (x != y) 
	        { 
	        	plotBuffer->changePixel(Location ( y + x_centre, x + y_centre));
	        	plotBuffer->changePixel(Location (-y + x_centre, x + y_centre));
	        	plotBuffer->changePixel(Location ( y + x_centre,-x + y_centre));
	        	plotBuffer->changePixel(Location (-y + x_centre,-x + y_centre));
	        } 
	    } 
	}


	void polyLine(std::vector<Location> points){
		for(int i = 0; i < points.size() - 1; i++){
			lineBres(points[i],points[i+1]);
		}
	}


	void saveFile(){
		plotBuffer->plotFile();
	}
};
