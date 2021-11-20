/* 
Derek Norman
2364922
norman@chapman.edu
CPSC-350-03
Assignment 5
*/

/*
* Template class for a doubly linked list
*/
#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "listnode.h"

template <class T>
class DoublyLinkedList{
    private:
        ListNode<T> *front;
        ListNode<T> *back;
        unsigned int size;

    public:
        DoublyLinkedList(); //constructor
        ~DoublyLinkedList(); //destructor

        void insertFront(T d); //inserts node at front of the list
        void insertBack(T d); //inserts node at the back of the list
        T getFront(); //returns the front of the list
        T removeFront(); //removes the node at the front of the list
        T removeBack(); //removes the node at the back of the list
        T removeNode(T value); //removes a node with the given the value/data
        T find(T value); //find a node given the value/data
        bool isEmpty(); //boolean returns if the list is empty or not
        unsigned int getSize(); //returns the size of the list
        void printList(bool isPrintLink); //prints a visual representation of the doubly linked list
        void printListReverse(bool printLink); //prints a visual representation of the doubly linked list in reverse
};

template <class T>
DoublyLinkedList<T>::DoublyLinkedList(){ //constructor
    //empty list
    size = 0;
    front = NULL;
    back = NULL;

}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList(){ //destructor
    //research 
    //hint: theres a loop
    ListNode<T> *curr = front;
    while( curr != 0 ) {
    ListNode<T> *next = curr->next;
    delete curr;
    curr = next;
    }
    front = 0;
}

/*
* This method is insertFront and inserts a node at the front of the list and increments the size
* This method takes a single parameter d representing the data to be inserted into the list
*/
template <class T>
void DoublyLinkedList<T>::insertFront(T d){ 
    ListNode<T> *node = new ListNode<T>(d);

    if(isEmpty()){
        back = node;
    } else {
        node->next = front;
        front->prev = node;
    }
    front = node;
    ++size;
}

/*
* This is the insertBack method, insertBack inserts a node in the back of the list
* This method has a single parameter d representing the data to be inserted into the list
*/
template <class T>
void DoublyLinkedList<T>::insertBack(T d){
    ListNode<T> *node = new ListNode<T>(d);

    if(isEmpty()){
        front = node;
    } else {
        node->prev = back;
        back->next = node;
    }
    back = node;
    ++size;
}

/*
* This is the getFront method, returns the data of the node at front of the list
* returns the data of the node at the front of the list
*/
template <class T>
T DoublyLinkedList<T>::getFront(){
    return front->data;
}

/*
* This method is calle removeFront, this method removes the node at the front of the list
* This method returns data representing the data of the node removed from the front of the list
*/
template <class T>
T DoublyLinkedList<T>::removeFront(){
    if(isEmpty()){
        throw runtime_error("List is empty!");
    }
    ListNode<T> *temp = front;

    if(front->next == NULL){
        back = NULL;

    } else {
        front->next->prev = NULL;
        
    }

    front = front->next;
    temp->next = NULL;
    T data = temp->data;
    --size;
    delete temp;
    return data;

    
}

/*
* This method is removeBack, this method removes the node at the back of the list
* This method returns data representing the data of the node removed from the back of the list
*/
template <class T>
T DoublyLinkedList<T>::removeBack(){
    if(isEmpty()){
        throw runtime_error("List is empty!");
    }
    ListNode<T> *temp = back;

    if(back->prev == NULL){
        //only node in the list
        front = NULL;
    } else {
        //more than one node in the list
        back->prev->next = NULL;
    }

    back = back->prev;
    temp->prev = NULL;
    T data = temp->data;
    --size;
    delete temp;
    return data;
}

/*
* This method is called find, this method finds a node in the doubly linked list given the data/value of the node
* This method returns temp representing the data/value from the node found in the doubly linked list
*/
template <class T>
T DoublyLinkedList<T>::find(T value){
    int pos = -1;

    ListNode<T> *curr = front;
    while (curr != NULL){
        ++pos;
        if(curr->data == value){
            //return pos;
            break;
        }
        curr = curr->next;
    }
    //check if curr is NULL which signifies value not in doubly linked list
    if(curr == NULL){
        pos = -1; // or -1
    }

    T temp = curr->data;
    delete curr;
    return temp;
}

/*
* This method is called isEmpty, this method indicated if the doubly linked list is empty or not
* returns a boolean representing if the list is empty or not
*/
template <class T>
bool DoublyLinkedList<T>::isEmpty(){
    return (size == 0);
}

/*
* This method is getSize, which returns the size of the list
* returns size representing the size of the list
*/
template <class T>
unsigned int DoublyLinkedList<T>::getSize(){
    return size;
}

/*
* This method is called removeNode, that removes a node from the list given the value/data of the node
* Takes a single parameter value representing the value/data of the node to be removed from the list 
*/
template <class T>
T DoublyLinkedList<T>::removeNode(T value){ //removes a specified node in the list or 
    if(isEmpty()){
        throw runtime_error("This is empty!");
    }
    //could leverage the find method
    //ListNode<T> *node = find(value); //find the node and verify it exists

    ListNode<T> *curr = front;

    while(curr->data != value){
        curr = curr->next;

        if(curr == NULL){
            return -1;
        }
    }
    //if we make it here then we found the value
    //we found it so lets remove it

    if(curr != front && curr != back){
        //its in between two nodes
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        
    }

    if(curr == front){ //its at front of the list
        front = curr->next;
        front->prev = NULL;
    }

    if(curr == back){ //its at back of the list
        back = curr->prev;
        back->next = NULL;
    }

    curr->next = NULL;
    curr->prev = NULL;
    T data = curr->data;
    --size;
    delete curr;
    return data;

}

/*
* This method is printList, this method prints a visual representation of the list
* Takes a parameter called printLink representing whether or not to print the next and prev pointers for list
*/
template <class T>
void DoublyLinkedList<T>::printList(bool printLink)
{
    ListNode<T> *curr = front;
    while(curr != 0){
    if(curr == front){
        cout << "{FRONT}: ";
    }
    else if(curr == back){
        cout << "{REAR}: ";
    }
    if(printLink)
        cout << "[ PREV: "<< curr->prev << " || " << curr->data << " || NEXT: "<< curr->next << " ] ";
    else
        cout << "[ " << curr->data << " ] ";
    curr = curr->next;
    if(curr != 0){
        cout << " ==> ";
    }
    }
    cout << endl;
}

/*
* This method is printListReverse, this method prints a visual representation of the list in reverse
* Takes a parameter called printLink representing whether or not to print the next and prev pointers for list
*/
template <class T>
void DoublyLinkedList<T>::printListReverse(bool printLink)
{
    ListNode<T> *curr = back;
    while(curr != 0){
    if(curr == front){
        cout << "{FRONT}: ";
    }
    else if(curr == back){
        cout << "{REAR}: ";
    }
    if(printLink)
        cout << "[ NEXT: "<< curr->next << " || " << curr->data << " || PREV: "<< curr->prev << " ] ";
    else
        cout << "[ " << curr->data << " ] ";
    curr = curr->prev;
    if(curr != 0){
        cout << " <== ";
    }
    }
    cout << endl;
}



#endif