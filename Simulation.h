#ifndef SIMULATION_H
#define SIMULATION_H

#include "GenQueue.h"
#include "Student.h"
#include "Window.h"
#include <iostream>
#include <fstream>
using namespace std;

class Simulation {
    public:
        Simulation(); //Constructor
        ~Simulation(); //Destructor

        void runSimulation(string filePath); //runs the simulation of the registrar
        bool allWindowsIdle(Window **wind, int capacity); //returns if all windows are idle or not
        void updateLongestStudWaitTime(int t); //updates the longest student wait time
        void inputIntoWaitTimeArray(int arr[], int waitTime); //adds waitTimes of students in order to array of wait times in order to find median
        void sortArray(int arr[]); //sorts array of ints in ascending order
        int findMedian(int arr[]); //finds the median given an array of ints
        void updateClockTickAndInfo(GenQueue<Student*> *studentQueue, Window **wind, int waitTimes[], int idleTimes[], int capacity); //updates the clockTick and all the necessary information that needs to updated in a clock tick

    private:
        int clockTick;
        int m_meanStudWaitTime;
        int m_medianStudWaitTime;
        int m_longestStudWaitTime;
        int m_numStudWaitingOverTenMin;
        double m_meanWindowIdleTime;
        int m_longestWindowIdleTime;
        int m_numWindowsIdleOverFiveMin;
        int m_numTotalStudents;
        int m_numIdleWindows;
};

#endif