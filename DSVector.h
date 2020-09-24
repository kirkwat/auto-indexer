//
// Created by watso on 9/24/2020.
//

#ifndef INC_20F_AUTO_IDX_DSVECTOR_H
#define INC_20F_AUTO_IDX_DSVECTOR_H

#include <iostream>

using namespace std;

template <class PlaceHolderType>
class DSVector {
private:
    PlaceHolderType *data;
    int capacity;
    int length;

public:
    //default constructor
    DSVector(){
        length=0;
        capacity=5;
        data=new PlaceHolderType[capacity];
    }
    //copy constructor
    DSVector(const DSVector & copy) {
        //TODO
    }
    //copy assignment operator
    DSVector& operator=(const DSVector& copy){
        delete[] data;
        //TODO
    }
    //destructor
    ~DSVector(){
        delete[] data;
    }
    //push back a new node into vector
    void push_back(const PlaceHolderType& payload){
        data[length]=payload;
        length++;
    }
    //remove a node with given index
    void remove(int index){
        //TODO
    }
    //return element at given index
    PlaceHolderType& operator[] (int index){
        return data[index];
    }
    //recreate bigger vector when it is at full capacity
    void resize(){
        //TODO
    }
    //get size of vector
    int getSize(){
        return length;
    }
};

#endif //INC_20F_AUTO_IDX_DSVECTOR_H
