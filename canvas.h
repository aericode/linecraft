#ifndef CANVAS_H
#define CANVAS_H


#include <math.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>
#include <cmath> 


#include "vec3.h"
#include "plotter.h"
#include "location.h"

typedef vec3 Color;

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



    void drawLine(Location starter, Location final, int thickness = 1){

		//lineBres(starter,final);

		int dx = final.getX() - starter.getX();
		int dy = final.getY() - starter.getY();

		bool isVertical = false;

		if(dx == 0){
			dx = 1;//não dividir por zero
			isVertical = true;
		}

		if(dy/dx < 1 && !isVertical){
	        for(int i = 0 ; i < thickness;i++){

	        	Location   upStarter(starter.getX()  , starter.getY() + i);
	        	Location     upFinal(final.getX()    , final.getY()   + i);

				Location   downStarter(starter.getX(), starter.getY() - i);
				Location     downFinal(final.getX()  , final.getY()   - i);


	            lineBres(upStarter,upFinal);
				lineBres(downStarter,downFinal);

	        }
	    }else{
	        for(int i = 0; i < thickness; i++){

	        	Location   rightStarter(starter.getX() + i, starter.getY());
	        	Location     rightFinal(final.getX()   + i,   final.getY());

				Location   leftStarter(starter.getX() - i,  starter.getY());
				Location     leftFinal(final.getX()   - i,    final.getY());


	            lineBres(rightStarter,rightFinal);
				lineBres(leftStarter,leftFinal);
	        }
	    }
	}




    //adaptado de https://tinyurl.com/y5huypgj
	void lineBres(Location starter, Location final){

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

	        for (int i = 0; y < yf; i++) {
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

	/*
		tx = x/Xtotal
		ty = Y/Ytotal 
		lowerbottom = 00
		upperleft   = 10
		lowerright  = 01
		upperright  = 11
		baseado no algoritmo de interpolação de https://bit.ly/2HTu8eL
	*/
	Color interpolatePixel(float tx, float ty, Color cor00, Color cor10, Color cor01, Color cor11){
		Color left  = cor00 * (1 - tx) + cor10 * tx;
		Color right = cor01 * (1 - tx) + cor11 * tx;

		Color interpolated = left * (1 - ty) + right * ty;
		interpolated[0] = (int)interpolated[0];
		interpolated[1] = (int)interpolated[1];
		interpolated[2] = (int)interpolated[2];

		return interpolated;
	}

	void interpolate(Color cor00, Color cor10, Color cor01, Color cor11){

		Color currentColor;

		for (int j = ySize-1; j >=  0; j--){
			for(int i = 0; i <  xSize; i++){

				float tx = float(i) / float (xSize);//percentual horizontal
				float ty = float(j) / float (ySize);//percentual vertical

				currentColor = interpolatePixel(tx,ty,cor00,cor10,cor01,cor11);

				plotBuffer->changePixel(Location ( i, j), currentColor);
			}
		}
	}
};

#endif