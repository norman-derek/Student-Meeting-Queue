/* 
Derek Norman
2364922
norman@chapman.edu
CPSC-350-03
Assignment 5
*/

/*
* Template class for a Queue using a list ADT
*/
#ifndef GENQUEUE_H
#define GENQUEUE_H

#include "mylist.h"

template <class T>
class GenQueue {
    public: 
        GenQueue(); //constructor
        ~GenQueue(); //destructor

        void Enqueue(T d); //Adds element to the back of the queue
        T Dequeue(); //Removes the element from the front of the queue
        T Peek(); //Returns the element at the front of the queue
        bool isEmpty(); //returns if the queue is empty
        unsigned int getLength(); //returns the length of the queue
        void Print(); //prints the queue 

    private: 
        myList<T> *list;
    
};


template <class T>
GenQueue<T>::GenQueue(){ //constructor
    list = new myList<T>();
}

template <class T>
GenQueue<T>::~GenQueue(){ //destructor
    delete list;
}

/*
* This method is called Enqueue, Enqueue inserts data of type T to the back of the queue
* This method takes a single parameter d representing the data to be inserted at the back of the queue
*/
template <class T>
void GenQueue<T>::Enqueue(T d){
    list->Append(d);
}

/*
* This method is called Dequeue, Dequeue removes the data at the front of the queue 
* This method returns a value of type T representing the data that was removed from the queue
*/
template <class T>
T GenQueue<T>::Dequeue(){
    return (list->Remove());
}

/*
* This method is called Peek, Peek returns the data at the front of the queue
* returns T representing the data at the front of the queue
*/
template <class T>
T GenQueue<T>::Peek(){
    return (list->getFront());
}

/*
* This method is called isEmpty, returns if the queue is empty or not
* This method returns a bool representing if the queue is open or not
*/
template <class T>
bool GenQueue<T>::isEmpty(){
    return (list->isEmpty());
}

/*
* This method is called getLength, returns the length of the queue
* returns unsigned int representing the size/length of the queue
*/
template <class T>
unsigned int GenQueue<T>::getLength(){
    return (list->getLength());
}

/*
* This method is called Print, method prints a visual representation of the queue
*/
template <class T>
void GenQueue<T>::Print(){
    list->Print();
}

#endif