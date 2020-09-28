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
    DSVector(const DSVector<PlaceHolderType> & copy) {
        length = copy.length;
        capacity = copy.capacity;
        data = new PlaceHolderType[capacity];

        for (int i = 0; i < copy.length; i++){
            data[i] = copy.data[i];
        }
    }
    //copy assignment operator
    DSVector& operator=(const DSVector<PlaceHolderType>& copy){
        if (this != &copy) {
            delete[] data;
            length = copy.length;
            capacity = copy.capacity;
            data = new PlaceHolderType[capacity];

            for (int i = 0; i < capacity; i++){
                data[i] = copy.data[i];
            }
        }
        return *this;
    }
    //destructor
    ~DSVector(){
        delete[] data;
    }
    //push back a new element into vector
    void push_back(const PlaceHolderType& payload){
        //if array is full, increase capacity
        if(length==capacity){
            data=resize();
        }
        data[length]=payload;
        length++;
    }
    //remove an element with given index
    void remove(int index){
        //decrease array size
        length--;
        //temp array
        PlaceHolderType* tempData = new PlaceHolderType[capacity];
        //index counter for array
        int x=0;
        //transfer data
        for (int i = 0; i < length; i++){
            //transfer all elements except
            if(i!=index){
                tempData[i] = data[x];
            }
            //at index to be removed, skip transfer
            else{
                x++;
                tempData[i] = data[x];
            }
            x++;
        }
        //deallocate old array
        delete[] data;
        data = new PlaceHolderType[capacity];
        //transfer new array to vector array
        for (int i = 0; i < capacity; i++){
            data[i] = tempData[i];
        }
        //deallocate temp array
        delete[] tempData;
    }
    //recreate bigger vector when it is at full capacity
    PlaceHolderType* resize(){
        //increase capacity by 5
        capacity+=5;
        //temp array
        PlaceHolderType* tempData = new PlaceHolderType[capacity];
        //transfer data
        for (int i = 0; i < capacity; i++){
            tempData[i] = data[i];
        }
        //deallocate array
        delete []data;

        return tempData;
    }
    //return element at given index
    PlaceHolderType& operator[] (int index){
        return data[index];
    }
    //get size of vector
    int size(){
        return length;
    }
    //get size of vector
    int getCapacity(){
        return capacity;
    }
};

#endif //INC_20F_AUTO_IDX_DSVECTOR_H
