#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "image.h"
#include "basic.h"
#include "exception.h"
#include "decorator.h"
#include "flip.h"
#include "rotate.h"
#include "sepia.h"

using namespace std;

int main(int argc, char *argv[]){
  if(argc < 3){ 
    cerr << "Provide the input and output file name" << endl;
    return 1;
  }        
  PPM ppm;
  Image *img = new BasicImage(argv[1]);
  string cmd;

  cerr << "Enter \"quit\" when done with editing" << endl;
  for (cin >> cmd) {
    if (cmd == "rotate") {
       img = new Rotate{img};
    } else if (cmd == "flip") {
       img = new Flip{img};
    } else if (cmd == "sepia") {
       img = new Sepia{img};
    } else if (cmd == "quit") {
      break;
    } else {
      cerr << "Invalid transformation (ignored)" << dec << endl;
    }
  }//end going through transformations

  try {
    //read image and apply any transformations
    img->render(ppm); 

    ofstream out{argv[2]};
    if(out.fail()){
      cerr << "Something bad happened with the output file." << endl;
      return 1;
    }    
    out << ppm; 

  } catch (PPMInputFormatException &e){
    cerr << e.getErrorMessage();    
  }
  delete img;
}
