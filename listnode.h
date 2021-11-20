/* 
Derek Norman
2364922
norman@chapman.edu
CPSC-350-03
Assignment 5
*/

/*
* list node class is a template class that is a simple representation of a node in a doubly linked list
* A list node has two pointers of prev and next and holds data of type T
*/

#ifndef LISTNODE_H
#define LISTNODE_H

#include <iostream>
#include <exception>
using namespace std;

template <class T>
class ListNode{
    public:
        ListNode(); //constructor
        ListNode(T data); //overloaded constructor
        virtual ~ListNode(); //destructor

        T data; // data 
        ListNode<T> *next; //next pointer that points to null or next node in doubly linked list
        ListNode<T> *prev; //prev pointer that points to null or previous node in the doubly linked list
};

template <class T>
ListNode<T>::ListNode(){ //constructor
    data = NULL;
    next = NULL;
    prev = NULL;
}

template <class T>
ListNode<T>::ListNode(T d){ //overloaded constructor
    data = d; //sets data in node to d
    next = NULL;
    prev = NULL;
}

template <class T>
ListNode<T>::~ListNode(){ //destructor
    next = NULL; 
    prev = NULL;
}


#endif