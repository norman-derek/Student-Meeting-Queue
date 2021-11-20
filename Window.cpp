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

#include "Window.h"

Window::Window(){ //constructor
    idleTime = 0;
    isOccupied = false;
    student = nullptr;
}

Window::Window(Student *s){ //overloaded constructor
    idleTime = 0;
    isOccupied = true;
    student = s;
}

Window::~Window(){ //destructor
    delete student;
}

/*
* Method getIdleTime, returns the idle time of the window
* Returns an int representing the idle time of the window
*/
int Window::getIdleTime(){ //returns the time the window has been idle
    return idleTime;
}

/*
* Method updateIdleTime, increments the idle time of the window
*/
void Window::updateIdleTime(){
    idleTime++; //increments amount of time window has been idle 
}

/*
* Method isWindowIdle, returns if the window is idle or not
* returns a bool representing if window is idle or not
*/
bool Window::isWindowIdle(){ //returns if the window is busy or not. if the window is not busy then returns true that window is idle, if window is busy then returns false that window is idle
    return (isOccupied == false);
}

/*
* Method setWindowBusy, sets the window to busy meaning it is occupied
*/
void Window::setWindowBusy(){
    isOccupied = true;
}

/*
* Method getStudent, returns the student at the window
* Returns the student at the window
*/
Student* Window::getStudent(){
    return student;
}


