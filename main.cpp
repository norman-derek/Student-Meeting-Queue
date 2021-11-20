/* 
Derek Norman
2364922
norman@chapman.edu
CPSC-350-03
Assignment 5
*/

/*
* Main method 
*/

#include "Simulation.h"

int main(int argc, char** argv)
{

    int arguments = argc;
    if(arguments == 2){
        string file = argv[1];
        Simulation *sim = new Simulation();
        sim->runSimulation(file);
    } else {
        throw runtime_error("oops you didnt provide a text file in the command line! Please run again. When running include the name of the txt file on the command line");
    }


    return 0;
}
