/* 
Derek Norman
2364922
norman@chapman.edu
CPSC-350-03
Assignment 5
*/

/*
* myList class where all list interface methods are implemented
*/

#ifndef MYLIST_H
#define MYLIST_H

#include "ListInterface.h"

template <class T>
class myList : public ListInterface<T> {

    public:
        myList(){ //constructor 
            dll = new DoublyLinkedList<T>();
        }

        ~myList(){ //destructor
            delete dll;
        }

        /*
        * Method Append inserts data at end of list
        * Method has single parameter d representing the data to be inserted at end of list
        */
        void Append(T d){ 
            dll->insertBack(d);
        }

        /*
        * Method Prepend inserts data at start of list
        * Method has single paramer d representing the data to be inserted at start of list
        */
        void Prepend(T d){
            dll->insertFront(d);
        }

        /*
        * Method InsertAfter inserts data after a given node
        * Method has two parameters. afterNode representing the node the data will be inserted after, d the data to be inserted
        */
        void InsertAfter(T afterNode, T d){
            //not used in assignment because do not need to insert after in a Queue.
        }

        /*
        * Method Remove, Removes data from front of the list (only need to remove from front of list because list is being used for queue implementation)
        * Returns T representing the data that was removed
        */
        T Remove(){
            return dll->removeFront();
        }

        /*
        * Method Search, returns the data if it is found or null if not found
        * Takes single parameter d representing data we want to find
        */
        T Search(T d){
            //not implemented because no list is sorted,  I sort arrays instead to find median
        }

        /* 
        * Method getFront returns the data at the front of the list
        * Method is used as helper function but not usually a part of list operations
        * Returns T representing the data at the front of the list
        */
        T getFront(){
            return (dll->getFront()); 
        }

        /*
        * Method Sort, sorts the lists items in ascending order
        */
        void Sort(){
            //not used in assignment. I sort an array instead in simulation
        }

        /*
        * Method Print, Prints lists items in order
        */
        void Print(){
            dll->printList(false);
        }

        /*
        * Method PrintReverse, Prints lists items in reverse order
        */
        void PrintReverse(){
            dll->printListReverse(false);
        }

        /*
        * Method isEmpty, returns if the list is empty or not
        * returns bool representing if the list is empty or not
        */
        bool isEmpty(){
            return (dll->isEmpty());
        }

        /*
        * Method getLength, returns the number of items in list
        * returns unsigned int representing the number of items in list
        */ 
        unsigned int getLength(){
            return (dll->getSize());
        }

    private:
        DoublyLinkedList<T> *dll;
        


};


#endif