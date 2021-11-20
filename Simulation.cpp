/* 
Derek Norman
2364922
norman@chapman.edu
CPSC-350-03
Assignment 5
*/

/*
* Simulation class, represents a simulation where students are put into a queue and go to windows to meet with advisor/teachers 
* based on the time arrived and how much time they need
*/

#include "Simulation.h"


Simulation::Simulation(){ //constructor
    clockTick = 0;
    m_meanStudWaitTime = 0;
    m_medianStudWaitTime = 0;
    m_longestStudWaitTime = 0;
    m_numStudWaitingOverTenMin = 0;
    m_meanWindowIdleTime = 0.0;
    m_longestWindowIdleTime = 0;
    m_numWindowsIdleOverFiveMin = 0;
    m_numTotalStudents = 0;
    m_numIdleWindows = 0;
}

Simulation::~Simulation(){ //destructor

}

/*
* Method runSimulation, runs a simulation where students are put into a queue and go to windows to meet with advisor/teachers 
* based on the time arrived and how much time they need
*/
void Simulation::runSimulation(string filePath){


    if(filePath.length() < 4) { //checks if file name length is 3 or less which is not possible with .txt extension
        throw runtime_error("please use a valid file name with .txt");
    }
    else if(filePath.substr(filePath.length() - 4) != ".txt"){ //check if file has .txt extension
        cout << "please input a .txt file for the input" << endl;
        throw runtime_error("please use a valid file name with .txt");

    }

    int capacity;
    GenQueue<Student*> *studentQueue = new GenQueue<Student*>();
    int *waitTimes = new int[m_numTotalStudents]; //hold waitTimes from students 
    int *idleTimes = new int[capacity]; //holds the total idle time for each window

    ifstream inputFile; //inputFile to read from
    inputFile.open(filePath, ios::out); //open the inputFile for reading
    if (inputFile.is_open()){ //while the input file is open for reading
        string line; //line that will hold line read from txt file
        getline(inputFile, line); //gets the first line of the text file
        capacity = stoi(line); //assigns the first line of the text file to capacity because the first line is how many windows there will be 

        while (getline(inputFile, line)){ //while we can get a line (also does grab a line)
            int timeArrived; //second line it grabbed from above while loop condition is time arrived
            timeArrived = stoi(line); //set the time arrived to the variable
            int numStudentsArrived; 
            getline(inputFile, line); //3rd line is how many students arrived
            numStudentsArrived = stoi(line); //assings the number of students arrived to variable

            for (int i = 0; i < numStudentsArrived; ++i){ //for the num students arrived
                int timeNeeded;
                getline(inputFile, line); //we get their TimeNeede
                timeNeeded = stoi(line); //assign timeNeeded to a variable
                studentQueue->Enqueue(new Student(timeArrived, timeNeeded)); //We queue the students in order read from txt file and assign the time they arrived and the time they each need.
            }

        }

    }
    inputFile.close(); //close file for reading now that all students are in the queue

    m_numTotalStudents = studentQueue->getLength(); //total students is the length of the queue at this point


    Window **wind = new Window*[capacity]; //initalize windows using the capacity from the txt files

    for(int i = 0; i < capacity; ++i){ 
        wind[i] = new Window(); //initialize windows as empty and idle 
    } 


    while(!allWindowsIdle(wind, capacity) || !studentQueue->isEmpty()){ //while there are students in the queue or the windows are not idle
        updateClockTickAndInfo(studentQueue, wind, waitTimes, idleTimes, capacity); //continue updating infor students and increment clockTick
    }


    //runs at the end of the loop one more time because after the while loop terminates does not collect data for final window idle times 
    for(int i = 0; i < capacity; ++i){ 
        m_meanWindowIdleTime += wind[i]->getIdleTime(); //retrieves idle time from windows if they were idle at the end loop and the loop did not run again
        idleTimes[i] += wind[i]->getIdleTime(); //updates total idleTime for the window 
    }

    for (int i = 0; i < capacity; ++i){
        //finds the longest Window idle time
        if(m_longestWindowIdleTime < idleTimes[i]){ //if the window idle time is greater than current longest window idle time
            m_longestWindowIdleTime = idleTimes[i]; //update longest window idle time
        }
        if(idleTimes[i] > 5){ //if the current window idleTime is greater than 5
            m_numWindowsIdleOverFiveMin++; //increment amount of windows idle over 5 minutes
        }
    }



    m_meanStudWaitTime = m_meanStudWaitTime / m_numTotalStudents; // the mean student wait time is the total of all the student wait times as of now so we divide by total amount of student
    sortArray(waitTimes); //sorts the waitTime array so we can find the median
    m_medianStudWaitTime = findMedian(waitTimes); //finds the median and sets it to median student wait time
    m_meanWindowIdleTime = m_meanWindowIdleTime / capacity; //the mean window idle time is the sum of all the windows at this point so we divide by the total number of windows



    cout << endl;
    cout << "1. Mean Student Wait Time: " << m_meanStudWaitTime << endl;
    cout << "2. Median Student Wait Time: " << m_medianStudWaitTime << endl;
    cout << "3. Longest Student Wait Time: " << m_longestStudWaitTime << endl;
    cout << "4. The Number of Students Waiting Over 10 Minutes: " << m_numStudWaitingOverTenMin << endl;
    cout << "5. Mean Window Idle Time: " << m_meanWindowIdleTime << endl;
    cout << "6. Longest Window Idle Time: " << m_longestWindowIdleTime << endl;
    cout << "7. Number of Windows Idle Over 5 Minutes: " << m_numWindowsIdleOverFiveMin << endl;

    cout << endl;
    delete studentQueue;
    delete []waitTimes;
    delete []idleTimes;


}

/*
* Method allWindowsIdle, returns if all windows are idle or not
* Takes 2 paramters, wind representing an array of Window pointers, and capacity representing the number of windows there are total
* returns a bool representing if the windows are all idle or not
*/
bool Simulation::allWindowsIdle(Window **wind, int capacity){
    bool allWindowsOpen = true;
    for(int i = 0; i < capacity; ++i){
        if(!wind[i]->isWindowIdle()){
            allWindowsOpen = false;
        }
    }

    return allWindowsOpen;
}

/*
* Method updateLongestStudWaitTime, updates the longest student wait time 
* Takes single parameter t representing the time to check if it is the longest student wait time
*/
void Simulation::updateLongestStudWaitTime(int t){
    if(t > m_longestStudWaitTime){ //if t is greater than the current longest student wait time then t is now the longest student wait time.
        m_longestStudWaitTime = t; //update longest student wait time
    } else {
        m_longestStudWaitTime = m_longestStudWaitTime; //longest student wait time stays the same
    }
}

/*
* Method inputIntoWaitTimeArray, inputs the waitTime of a student into an array the size of number of total students
* Takes 2 parameters, arr[] representing an array of integers, and waitTime an int representing the wait time of the student
*/
void Simulation::inputIntoWaitTimeArray(int arr[], int waitTime){
    for(int i = 0; i < m_numTotalStudents; ++i){
        if(arr[i] == 0){
            arr[i] = waitTime;
            break;
        }
    }
}

/*
* Method sortArray, sorts an array of integers in ascending order
* Takes a single parameter arr[] representing an array of integers
*/
void Simulation::sortArray(int arr[]){
    for(int i = 0; i < m_numTotalStudents; ++i){
        for(int j = i + 1; j < m_numTotalStudents; ++j){
            if(arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

/*
* Method findMedian, finds the median given a sorted array of integers
* Returns an in representing the median of the array
*/
int Simulation::findMedian(int arr[]){
    int median;
    int pos = m_numTotalStudents / 2;
    if(m_numTotalStudents % 2 == 0){
        median = (arr[pos] + arr[pos + 1] / 2);
    } 
    else {
        median = arr[pos];
    }

    return median;
}

/*
* Method updateClockTickAndInfo, updates all information needed in a clockTick then increments the clockTick
* Takes 5 parameters:
* studentQueue which is a Queue of students,
* wind which is an array of window pointers representing the windows,
* waitTimes which is an array of wait times from students,
* idleTimes which is an array of idle times from windows,
* capacity which is the total number of windows
*/
void Simulation::updateClockTickAndInfo(GenQueue<Student*> *studentQueue, Window **wind, int waitTimes[], int idleTimes[], int capacity){
    if(!studentQueue->isEmpty()){
        for(int i = 0; i < capacity; ++i){
            if((wind[i]->isWindowIdle()) && (!studentQueue->isEmpty()) && (studentQueue->Peek()->getTimeArrived() <= clockTick) ){ //if there is an open window and the studentQueue is not empty and the student at the front of the queue time arrived is not equal to or smaller than the current time
                Student *s = studentQueue->Dequeue();
                int waitTime = clockTick - s->getTimeArrived();
                updateLongestStudWaitTime(waitTime);
                if(waitTime > 0){
                    if(waitTime > 10){
                        m_numStudWaitingOverTenMin++; //if the wait time of the student is over 10 minutes then increment number of students waiting over 10 min
                    }
                    s->setWaitTime(waitTime);
                    inputIntoWaitTimeArray(waitTimes, waitTime); //inputs wait time into array of wait times in order
                    m_meanStudWaitTime += waitTime; //add wait time to mean student wait time. Will divide later
                } else {
                    s->setWaitTime(0);
                    inputIntoWaitTimeArray(waitTimes, 0); //inputs wait time into array of wait times in order
                }
                m_meanWindowIdleTime += wind[i]->getIdleTime(); 
                idleTimes[i] += wind[i]->getIdleTime(); //updates total idleTime for the window 
                wind[i] = new Window(s); //puts student at front of queue at open window
            } 
            else {
                if(!wind[i]->isWindowIdle()){
                    wind[i]->getStudent()->updateTimeNeeded();
                    if(wind[i]->getStudent()->getTimeNeeded() <= 0){ //if window time needed is now 0...
                        m_meanWindowIdleTime = m_meanWindowIdleTime + wind[i]->getIdleTime(); //adds idle time of window to mean window idle time variable before resetting window
                        idleTimes[i] += wind[i]->getIdleTime(); //updates total idleTime for the window 
                        wind[i] = new Window(); //...reset the window 
                        if(!studentQueue->isEmpty() && (studentQueue->Peek()->getTimeArrived() <= clockTick)){ //if student queue is not empty and timeArrived of first student in queue is less than or equal to the time
                            Student *s = studentQueue->Dequeue(); //student is moved out of queue
                            int waitTime = clockTick - s->getTimeArrived(); //calculate wait time
                            updateLongestStudWaitTime(waitTime); //update longest student wait time
                            if(waitTime > 0){ //if wait time is greater than 0
                                if(waitTime > 10){
                                    m_numStudWaitingOverTenMin++; //if the wait time of the student is over 10 minutes then increment number of students waiting over 10 min
                                }
                                s->setWaitTime(waitTime); //sets wait time
                                m_meanStudWaitTime += waitTime; //add wait time to mean student wait time. Will divide later
                                inputIntoWaitTimeArray(waitTimes, waitTime); //inputs wait time into array of wait times in order
                            } else {
                                s->setWaitTime(0); //sets wait time
                                inputIntoWaitTimeArray(waitTimes, 0); //inputs wait time into array of wait times in order
                            }
                            m_meanWindowIdleTime += wind[i]->getIdleTime(); //gets the idle time of window before student is assigned to window
                            idleTimes[i] += wind[i]->getIdleTime(); //updates total idleTime for the window 
                            wind[i] = new Window(s); //puts student at front of queue at open window
                        }
                    }
                } 
                else {
                    wind[i]->updateIdleTime(); //increment idle time if window is open and there is no students from queue to add at the time
                }
            }
        }
    } 
    else {
        for(int i = 0; i < capacity; ++i){
            if(wind[i]->isWindowIdle()){ //if window is not idle
                wind[i]->updateIdleTime();
            }
            else { //if window is not idle 
                wind[i]->getStudent()->updateTimeNeeded();
                if(wind[i]->getStudent()->getTimeNeeded() <= 0){ //if window time needed is now 0...
                    m_meanWindowIdleTime = m_meanWindowIdleTime + wind[i]->getIdleTime(); //adds idle time of window to mean window idle time variable before resetting window
                    idleTimes[i] += wind[i]->getIdleTime(); //updates total idleTime for the window 
                    wind[i] = new Window(); //...reset the window 
                }
            } 
        }
    }
    clockTick++;
}