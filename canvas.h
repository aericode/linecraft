#include <math.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>
#include <cmath> 

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

    //adaptado de https://tinyurl.com/y5huypgj
	void draw_line(Location starter, Location final){



	    //inicial
	    int x;
	    int y;

	    //final
	    int xf;
	    int yf;

	    //deltas
	    int dx;
	    int dy;

	    //módulo dos deltas
	    int dxAbs;
	    int dyAbs;


	    //intervalos de erro
	    int px;
	    int py;

	    //calculando delta
	    dx = final.getX() - starter.getX();
	    dy = final.getY() - starter.getY();

	    //módulos de delta
	    dxAbs = abs(dx);
	    dyAbs = abs(dy);

	    //intervalos de erro
	    px = 2 * dyAbs - dxAbs;
	    py = 2 * dxAbs - dyAbs;

	    // The line is X-axis dominant
	    if (dyAbs <= dxAbs) {

	        
	        if (dx >= 0) {
	        	//esquerda para direita
	        	x  = starter.getX();
	        	y  = starter.getY();

	        	xf = final.getX();
	        } else { 
	        	//trocar e direita para esquerda
	            x  = final.getX();
	        	y  = final.getY();

	        	xf = starter.getX();
	        }

	        plotBuffer->changePixel(Location(x,y));


	        for (int i = 0; x < xf; i++) {
	            x = x + 1;

	            // Octantes
	            if (px < 0) {
	                px = px + 2 * dyAbs;
	            } else {
	                if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0)) {
	                    y = y + 1;
	                } else {
	                    y = y - 1;
	                }
	                px = px + 2 * (dyAbs - dxAbs);
	            }

	            plotBuffer->changePixel(Location(x,y));
	        }

	    } else { 

	        
	        if (dy >= 0) {
	        	// baixo - cima
	            x  = starter.getX();
	        	y  = starter.getY();

	        	yf = final.getY();
	        } else { 
	        	// cima - baixo
	            x  = final.getX();
	        	y  = final.getY();

	        	yf = starter.getY();
	        }

	        plotBuffer->changePixel(Location(x,y));

	        for (i = 0; y < yf; i++) {
	            y = y + 1;

	            //Octantes
	            if (py <= 0) {
	                py = py + 2 * dxAbs;
	            } else {
	                if ((dx < 0 && dy<0) || (dx > 0 && dy > 0)) {
	                    x = x + 1;
	                } else {
	                    x = x - 1;
	                }
	                py = py + 2 * (dxAbs - dyAbs);
	            }

	            plotBuffer->changePixel(Location(x,y));
	        }
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
