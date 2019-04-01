#include "json.hpp"
#include <iostream>
#include <cstddef>
#include <algorithm>
#include <fstream>
#include <string>

using json::JSON;
using namespace std;



string stringFromFile(string filename)
{
    //pega o arquivo e transforma em uma string pronta para ser convertida em objeto
    string aux;
    string userInput;
    ifstream infile;
    infile.open (filename);
        while(!infile.eof()){
            getline(infile,aux);
            userInput += aux;
        }
    infile.close();

    return userInput;
}




void jsonToLines(JSON obj){
    string index;
    string shape;

    int commandNumber = obj["commands"].ToInt();
    for(int i = 1;i <= commandNumber; i++){
        index = to_string(i);
        shape = obj[index]["shape"].ToString();

        if(shape == "line"){
            int x1 = obj[index]["x1"].ToInt();
            int y1 = obj[index]["y1"].ToInt();

            int x2 = obj[index]["x2"].ToInt();
            int y2 = obj[index]["y2"].ToInt();

            int thickness;
            if(obj[index]["thickness"].IsNull()){
                thickness = 1;
            }else{
                thickness = obj[index]["thickness"].ToInt();
            }

            cout << "okay, draw a line from [" << x1 << "," << y1 <<"] to [" << x2 << "," << y2 <<"]" << endl;
            cout << "thickness: " << thickness << endl;
        }
    }
}


int main()
{

    JSON obj;
    string userInput = stringFromFile("lines.json");   
    
    obj = JSON::Load(userInput);

    //cout << obj["commands"] << endl;
    jsonToLines(obj);

    //cout<<obj["thickness"]<<endl;

}
