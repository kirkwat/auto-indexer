//
// Created by watso on 10/1/2020.
//

#include <cstring>
#include <iostream>
#include "DSString.h"

using namespace std;
//default constructor
DSString::DSString() {
    string=new char[1];
    string[0]='\0';
}
//overloaded constructor with cstring
DSString::DSString(const char* cstring){
    if(cstring==nullptr){
        string=new char[1];
        string[0]='\0';
    }
    else{
        string = new char[strlen(cstring)+1];
        strcpy(string, cstring);
    }
}
//copy constructor
DSString::DSString(const DSString& copy){
    string = new char[strlen(copy.string) + 1];
    strcpy(string, copy.string);
}
//destructor
DSString::~DSString(){
    delete[] string;
}
//copy assignment operator with cstring
DSString& DSString::operator= (const char* copy){
    delete[] string;
    string = new char[strlen(copy) + 1];
    strcpy(string, copy);

    return *this;
}
//copy assignment operator with string
DSString& DSString::operator= (const DSString& copy){
    if (this != &copy) {
        delete [] string;
        string = new char[strlen(copy.string) + 1];
        strcpy(string, copy.string);
    }
    return *this;
}
//+ operator with string
DSString DSString::operator+ (const DSString& copy){
    char* string2 = new char[strlen(string)+strlen(copy.string) + 1];

    strcpy(string2, string);
    strcat(string2, copy.string);

    return DSString(string2);
}
//equal to operator with cstring
bool DSString::operator== (const char* string2)const{
    if(strcmp(string,string2)==0){
        return true;
    }
    else{
        return false;
    }
}
//equal to operator with string
bool DSString::operator== (const DSString& copy)const{
    if(strcmp(string,copy.string)==0){
        return true;
    }
    else{
        return false;
    }
}
//greater than operator with string
bool DSString::operator> (const DSString& copy)const{
    if(strcmp(string,copy.string)>0){
        return true;
    }
    else{
        return false;
    }
}
//less than operator with string
bool DSString::operator< (const DSString& copy)const{
    if(strcmp(string,copy.string)<0){
        return true;
    }
    else{
        return false;
    }
}
//access operator, returns element at given index
char& DSString::operator[] (const int index){
    //return first element of string, if index is bigger than string
    if(index>strlen(string)) {
        return string[0];
    }
    return string[index];
}
//returns the number of characters in a string
int DSString::getLength(){
    return strlen(string);
}
//returns a substring within the string using the index and length
DSString DSString::substring(int start, int numChars){
    DSString substring;
    //if parameters arent positive, an empty string will be returned
    if(start<0&&numChars<1){
        return substring;
    }
    //if start position is bigger than string length, an empty string will be returned
    if(start>strlen(string)+1){
        return substring;
    }

    char sub[numChars+1];

    int x=0;
    for(x;x<numChars;x++){
        sub[x]=string[start+x];
    }
    sub[x]='\0';

    substring=DSString(sub);
    return substring;
}
//returns the string as a cstring
char* DSString::c_str(){
    return string;
}
//Overloaded stream insertion operator, print string to output stream
std::ostream& operator<< (std::ostream& out, const DSString& str) {
    out<<str.string;
    return out;
}
//Overloaded stream insertion operator, print string to output stream
std::istream& operator>> (std::istream& in, const DSString& str) {
    in>>str.string;
    return in;
}
//find substring in string
int DSString::find(char sub[]){
    //make sure substring is not bigger than string
    if(strlen(string)<strlen(sub))
        return -1;
    //iterate through each letter in string for search
    int y;
    for(int x=0;x<strlen(string);x++){
        //iterate through substring
        for(y=0;y<strlen(sub);y++){
            //check for matching substring
            if(string[x+y]!=sub[y])
                break;
        }
        //if y iterator is equal to substring length
        //that means it was found at index x
        if (y==strlen(sub))
            return x;
    }
    //if the substring can't be found
    return -1;
}
//find substring in string
int DSString::find(DSString sub){
    //make sure substring is not bigger than string
    if(strlen(string)<strlen(sub.string))
        return -1;
    //iterate through each letter in string for search
    int y;
    for(int x=0;x<strlen(string);x++){
        //iterate through substring
        for(y=0;y<strlen(sub.string);y++){
            //check for matching substring
            if(string[x+y]!=sub[y])
                break;
        }
        //if y iterator is equal to substring length
        //that means it was found at index x
        if (y==strlen(sub.string))
            return x;
    }
    //if the substring can't be found
    return -1;
}

int DSString::findchr(char chr){
    char* pointer;
    pointer=strchr(string,chr);
    while (pointer!=nullptr)
    {
        return pointer-string;
    }
    return -1;
}
//convert string to all lowercase
void DSString::tolower(){
    for(int x=0;x<strlen(string);x++){
        string[x]=tolower(string[x]);
    }
}
//convert char to lowercase
char DSString::tolower(char ch) {
    if (ch >= 'A' && ch <= 'Z'){
        ch = 'a' + (ch - 'A');
    }
    return ch;
}
