//
// Created by watso on 10/1/2020.
//

#include "Keyword.h"

using namespace std;

Keyword::Keyword(){}

Keyword::Keyword(char input[]){
    word=DSString(input);
}

Keyword::Keyword(DSString input){
    word=input;
}

bool Keyword::operator== (const Keyword& copy)const{
    if(word==copy.word){
        return true;
    }
    else{
        return false;
    }
}

void Keyword::addPage(int page){
    //add page to vector if vector is empty
    if(pageNumbers.size()==0){
        pageNumbers.push_back(page);
    }
    else{
        //check if page is in vector
        for(int x=0;x<pageNumbers.size();x++){
            //if found do not readd to list
            if(pageNumbers[x]==page){
                return;
            }
        }
        //if not found, add sub to list
        pageNumbers.push_back(page);
    }
}

void Keyword::addSub(int index){
    //add index to vector if vector is empty
    if(subwords.size()==0){
        subwords.push_back(index);
    }
    else{
        //check if index is in vector
        for(int x=0;x<subwords.size();x++){
            //if found do not readd to list
            if(subwords[x]==index){
                return;
            }
        }
        //if not found, add sub to list
        subwords.push_back(index);
    }
}
//print
bool Keyword::printPages(){
    cout<<word<<": ";
    if(pageNumbers.size()==1){
        cout<<pageNumbers[0]<<endl;
    }
    else{
        for(int x=0;x<pageNumbers.size();x++){
            if(x==pageNumbers.size()-1){
                cout<<pageNumbers[x]<<endl;
            }
            else{
                cout<<pageNumbers[x]<<", ";
            }
        }
    }
    //returns true if keyword has subwords
    if(subwords.size()>0){
        return true;
    }
    return false;
}
//return string of keyword
DSString Keyword::getWord(){
    return word;
}
//return size of sub index vector
int Keyword::getSubSize(){
    return subwords.size();
}
//return sub index from vector for given index
int Keyword::getSubAt(int index){
    return subwords[index];
}
