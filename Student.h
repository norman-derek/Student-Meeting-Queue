/* 
Derek Norman
2364922
norman@chapman.edu
CPSC-350-03
Assignment 5
*/

/*
* Student class, a simple representation of student waiting to meet with a teacher/advisor
*/

#ifndef STUDENT_H
#define STUDENT_H

class Student {
    public:
        Student(); //Constructor
        Student(int ta, int tn); //Overloaded Constructor 
        ~Student(); //Destructor

        //getters & setters
        int getWaitTime(); //returns the wait time of the student
        void updateWaitTime(); //increments the wait time by one clock tick
        void setWaitTime(int t); //sets the wait time of the student

        int getTimeNeeded(); //returns the time needed by the student
        void setTimeNeeded(int t); //sets the time the student needs
        void updateTimeNeeded(); //deincrements the time needed 

        int getTimeArrived(); //returns the time the student arrived

    private:
        int timeNeeded;
        int waitTime;
        int timeArrived;
};

#endif