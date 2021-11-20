/* 
Derek Norman
2364922
norman@chapman.edu
CPSC-350-03
Assignment 5
*/

/*
* Window class, a simple representation of a window where a student can meet with advisor/teacher
*/

#ifndef WINDOW_H
#define WINDOW_H

#include "Student.h"

class Window {
    public:
        Window(); //Constructor
        Window(Student *s); //overloaded constructor
        ~Window(); //Destructor

        //getter and setter
        int getIdleTime(); //returns the idle time of the window
        void updateIdleTime(); //increments the idle time of the window

        bool isWindowIdle(); //returns true or false depending if the window is idle or not
        void setWindowBusy(); //sets the window to busy/occupied

        Student* getStudent(); //returns student at window or null if window is not occupied
        
    private:
        int idleTime;
        bool isOccupied;
        Student *student;
};

#endif