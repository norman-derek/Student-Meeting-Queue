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

#include "Student.h"

Student::Student(){ //constructor 
    waitTime = 0;
    timeNeeded = 0;
    timeArrived = 0;
}

Student::Student(int ta, int tn){ //overloaded constructor
    waitTime = 0;
    timeNeeded = tn;
    timeArrived = ta;
}

Student::~Student(){ //destructor

}

/*
* Method getWaitTime, returns the wait time of the student
* Method returns an int representing the wait time of the student
*/
int Student::getWaitTime(){ 
    return waitTime;
}

/*
* Method updateWaitTime, increments the waitTime for the student
*/
void Student::updateWaitTime(){
    waitTime++;
}

/*
* Method setWaitTime, sets the waitTime for the student
* Method has single paramter t representating the wait time of the student
*/
void Student::setWaitTime(int t){
    waitTime = t;
}   

/*
* Method getTimeNeeded, returns the amount of time the student needs for the meeting
* Returns an int representing the time the student needs for the meeting
*/
int Student::getTimeNeeded(){
    return timeNeeded;
}

/*
* Method setTimeNeeded, sets the time the student needs for the meeting
* Method takes a single parameter t representing the time the student needs for the meeting
*/
void Student::setTimeNeeded(int t){
    timeNeeded = t;
}

/*
* Method updateTimeNeeded, deincrements the time the student needs for the meeting
*/
void Student::updateTimeNeeded(){
    timeNeeded--;
}

/*
* Method getTimeArrived, returns the time the student arrived
* Returns an int representing the time the student arrived
*/
int Student::getTimeArrived(){
    return timeArrived;
}