/* 
Derek Norman
2364922
norman@chapman.edu
CPSC-350-03
Assignment 5
*/

/*
* Interface for the myList class, shows all methods that will be implemented
*/
#ifndef LISTINTERFACE_H
#define LISTINTERFACE_H

#include "doublylinkedlist.h"

template <class T>
class ListInterface {
    public: 
        virtual void Append(T d) = 0; //Append will insert data at the back of the list
        virtual void Prepend(T d) = 0; //Prepend inserts data at the front of the list
        virtual void InsertAfter(T afterNode, T d) = 0; //insertAfter not implmemented because not used but would insert data after a given node
        virtual T Remove() = 0; //removes the front of the list because we are using this for queue implementation
        virtual T Search(T d) = 0; //not implemented because not needed for assignment but would return if the data if found and null if not found
        virtual T getFront() = 0; //getFront used to get front of the list. Not usually included in list but I included as helper method
        virtual void Print() = 0; //Prints a visual representation of the list
        virtual void PrintReverse() = 0; //prints a visual representation of the list reversed
        virtual void Sort() = 0; //sorts the lists items in ascending order, not implemented because I do not sort a list
        virtual bool isEmpty() = 0; //returns whether or not the list is empty
        virtual unsigned int getLength() = 0; //returns the size/length of the list

};

#endif 