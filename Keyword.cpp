//
// Created by watso on 10/1/2020.
//

#include "Keyword.h"
#include <fstream>

using namespace std;
//default constructor
Keyword::Keyword(){
    isSorted=0;
}
//overloaded constructor with cstring
Keyword::Keyword(char input[]){
    word=DSString(input);
    isSorted=0;
}
//overloaded constructor with string
Keyword::Keyword(DSString input){
    word=input;
    isSorted=0;
}

bool Keyword::operator== (const Keyword& copy)const{
    if(word==copy.word){
        return true;
    }
    else{
        return false;
    }
}
//greater than operator with string
bool Keyword::operator> (const Keyword& copy)const{
    if(word>copy.getWord()){
        return true;
    }
    else{
        return false;
    }
}
//less than operator with string
bool Keyword::operator< (const Keyword& copy)const{
    if(word<copy.getWord()){
        return true;
    }
    else{
        return false;
    }
}
//add pages to page vector
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
        //if not found, add page to list
        pageNumbers.push_back(page);
    }
}
//add subword to subword vector
void Keyword::addSub(DSString index){
    //add string to vector if vector is empty
    if(subwords.size()==0){
        subwords.push_back(index);
    }
    else{
        //check if string is in vector
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
//print keyword and its page numbers to file
bool Keyword::printKeyword(ofstream &fout){
    //sort page numbers if they havent been already
    if(isSorted==0){
        sort();
    }
    fout<<word+": ";
    //print page numbers
    if(pageNumbers.size()==1){
        fout<<pageNumbers[0]<<endl;
    }
    else{
        //print each page number
        for(int x=0;x<pageNumbers.size();x++){
            //end line for last number
            if(x==pageNumbers.size()-1){
                fout<<pageNumbers[x]<<endl;
            }
            else{
                fout<<pageNumbers[x]<<", ";
            }
        }
    }
    //returns true if keyword has subwords
    if(subwords.size()>0){
        return true;
    }
    else{
        return false;
    }
}
//sort page numbers and subwords
void Keyword::sort(){
    sortPages(0,pageNumbers.size()-1);
    sortSub(0,subwords.size()-1);
    isSorted=1;
}
//recursion sort for page numbers
void Keyword::sortPages(int left, int right){
    //end sort if vector size is less than or equal to 1
    if (left >= right){
        return;
    }
    //quicksort page vector
    int pivot = pageNumbers[right];
    int num = left;
    for (int i = left; i <= right; i++){
        //if true swap elements
        if (pageNumbers[i] <= pivot){
            int temp=pageNumbers[num];
            pageNumbers[num]=pageNumbers[i];
            pageNumbers[i]=temp;
            num++;
        }
    }
    //sort left side
    sortPages(left, num-2);
    //sort right side
    sortPages(num, right);
}
//recursion sort for subwords
void Keyword::sortSub(int left, int right){
    //end sort if vector size is less than or equal to 1
    if (left >= right){
        return;
    }
    //quicksort subwords vector
    DSString pivot = subwords[right];
    int num = left;
    for (int i = left; i <= right; i++){
        //if true swap elements
        if (subwords[i] < pivot||subwords[i] == pivot){
            DSString temp=subwords[num];
            subwords[num]=subwords[i];
            subwords[i]=temp;
            num++;
        }
    }
    //sort left side
    sortSub(left, num-2);
    //sort right side
    sortSub(num, right);
}
//return string of keyword
DSString Keyword::getWord()const{
    return word;
}
//return size of sub index vector
int Keyword::getSubSize(){
    return subwords.size();
}
//return sub index from vector for given index
DSString Keyword::getSubAt(int index){
    return subwords[index];
}
