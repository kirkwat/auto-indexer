//
// Created by watso on 10/1/2020.
//

#include <iostream>
#include <fstream>
#include "Indexer.h"
#include "DSList.h"
#include <math.h>
#include <cstring>

using namespace std;

Indexer::Indexer(){}
//read file and place into indexed list
void Indexer::parse(char* inputFile){
    ifstream file;
    cout<<"Reading input01.txt..."<<endl;
    //open users table file
    file.open(inputFile);
    //check if it was opened properly
    if (!file.is_open()) {
        cout << "Could not open file prisonDoorScarletLetter.txt." << endl;
        return;
    }
    int pageNumber = 0;
    DSString input;
    //iterate through input until the end of the file
    do {
        //read file
        file >> input;
        //check for page number
        if (input[0] == '<') {
            pageNumber = getPage(input);
            //end program at end of file or if there is an error
            if (pageNumber == -1 || pageNumber == -2) {
                break;
            }
            continue;
        }
        //if input is a phrase marked by brackets
        if (input[0] == '[') {
            DSString input2;
            //find end of phrase
            while(input2.findchr(']')==-1){
                file>>input2;
                input=input+" "+input2;
            }
            //check for master category for phrase
            if(input.findchr('(')!=-1){
                //get masterword from input
                int numChar=input.findchr(')')-input.findchr('(')-1;
                DSString masterWord=DSString(input.substring(input.findchr('(')+1,numChar));
                //get subword from string and remove brackets
                input=input.substring(1,input.findchr(']')-1);
                //add masterword to list
                int masterIndex=addKeyIndex(masterWord, pageNumber);
                //add word to list
                int subIndex=addKeyIndex(input, pageNumber);
                //add subword pointer to masterwords list
                assignSubWord(masterIndex,subIndex);
            }
            else{
                //remove brackets
                input=input.substring(1,input.findchr(']')-1);
                //add keyword to list
                addKeyword(input, pageNumber);
            }
        }
            //if input is just a word
        else{
            //check for master category for word
            if(input.findchr('(')!=-1){
                //get masterword from input
                int numChar=input.findchr(')')-input.findchr('(')-1;
                DSString masterWord=DSString(input.substring(input.findchr('(')+1,numChar));
                //get subword from string
                numChar=input.findchr('(');
                input=input.substring(0,numChar);
                //add masterword to list
                int masterIndex=addKeyIndex(masterWord, pageNumber);
                //add word to list
                int subIndex=addKeyIndex(input, pageNumber);
                //add subword pointer to masterwords list
                assignSubWord(masterIndex,subIndex);
            }
            else{
                //add keyword to list
                addKeyword(input, pageNumber);
            }
        }
    }while(pageNumber!=-1);
    //TODO DELETE
    printList();
    //close file
    file.close();
    cout<<"...Complete"<<endl;
}
//create index
void Indexer::create(char* outputFile){
    cout<<endl<<"Creating index and saving it to output.txt..."<<endl;
    //open results file
    ofstream file(outputFile);
    //check if it was opened properly
    if (!file.is_open()) {
        cout << "Could not open file output.txt." << endl;
        return;
    }

    //TODO
    //TODO
    //TODO
    //TODO
    //TODO
    //TODO

    //close file
    file.close();
    cout<<"...Complete"<<endl;
}
//get page number from input
int Indexer::getPage(DSString pageInput){
    //end of file if input is <-1>
    if(pageInput[1]=='-'&&pageInput[2]=='1'){
        return -1;
    }
    int pgNumber [5];//assuming the book is not bigger than 99999 pages
    int page,numberSize=0;
    int ascii=48;//value for 0
    //extract number from input into array
    while(pageInput[numberSize+1]!='>'){
        page=pageInput[numberSize+1];
        if(page==ascii){
            pgNumber[numberSize]=0;
        }
        else if(page==ascii+1){
            pgNumber[numberSize]=1;
        }
        else if(page==ascii+2){
            pgNumber[numberSize]=2;
        }
        else if(page==ascii+3){
            pgNumber[numberSize]=3;
        }
        else if(page==ascii+4){
            pgNumber[numberSize]=4;
        }
        else if(page==ascii+5){
            pgNumber[numberSize]=5;
        }
        else if(page==ascii+6){
            pgNumber[numberSize]=6;
        }
        else if(page==ascii+7){
            pgNumber[numberSize]=7;
        }
        else if(page==ascii+8){
            pgNumber[numberSize]=8;
        }
        else if(page==ascii+9){
            pgNumber[numberSize]=9;
        }
        else{
            //error reading file
            return -2;
        }
        numberSize++;
    }
    //convert number array into int
    int pageNumber=0,z=0;
    for(int i=0;i<numberSize;i++){
        z=pow(10,numberSize-i-1);
        pageNumber+=z*pgNumber[i];
    }
    //return page number
    return pageNumber;
}
//add keyword to list
void Indexer::addKeyword(DSString input, int pageNumber){
    //create word
    Keyword word=Keyword(input);
    //add keyword to list if it is empty
    if (index.getSize() == 0) {
        word.addPage(pageNumber);
        index.push_back(word);
    }
    else {
        int f = 0;
        //check if keyword is in list
        for (int i = 0; i < index.getSize(); i++) {
            //if found, add page number
            if (word == index.at(i)) {
                index.at(i).addPage(pageNumber);
                f = 1;
                break;
            }
        }
        //if not found, add keyword to list
        if (f == 0) {
            word.addPage(pageNumber);
            index.push_back(word);
        }
    }
}
//add keyword and return its index in the list
int Indexer::addKeyIndex(DSString input, int pageNumber){
    //create word
    Keyword word=Keyword(input);
    //add keyword to list if it is empty
    if (index.getSize() == 0) {
        word.addPage(pageNumber);
        index.push_back(word);
    }
    else {
        //check if keyword is in list
        for (int i = 0; i < index.getSize(); i++) {
            //if found, add page number
            if (word == index.at(i)) {
                index.at(i).addPage(pageNumber);
                return i;
            }
        }
        //if not found, add keyword to list
        word.addPage(pageNumber);
        index.push_back(word);
        return index.getSize()-1;
    }
}
//assign subwords to its masterword
void Indexer::assignSubWord(int masterIndex,int subIndex){
    index.at(masterIndex).addSub(subIndex);
}
//TODO DELETE
//print list
void Indexer::printList(){
    //print keywords and their pages
    for(int z=0;z<index.getSize();z++){
        //if keyword has subwords, print subwords
        if(index.at(z).printPages()){
            //loop through each subword
            for(int b=0;b<index.at(z).getSubSize();b++){
                //indent for subwords
                cout<<"  ";
                index.at(index.at(z).getSubAt(b)).printPages();
            }
        }
    }
}