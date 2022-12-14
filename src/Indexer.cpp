#include <iostream>
#include <fstream>
#include "Indexer.h"
#include <math.h>
#include <cstring>

using namespace std;

Indexer::Indexer(){}
//read file and place into indexed list
//arguments - input file path
void Indexer::parse(char* inputFile){
    ifstream file;
    cout<<"Reading "<<inputFile<<"..."<<endl;
    //open users table file
    file.open(inputFile);
    //check if it was opened properly
    if (!file.is_open()) {
        cout << "Could not open file "<<inputFile<<"." << endl;
        return;
    }
    int pageNumber = 0;
    DSString input;
    //iterate through input until the end of the file
    do {
        //read file
        file >> input;
        //convert to lowercase
        input.tolower();
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
                input2.tolower();
                input=input+" "+input2;
            }
            //check for master category for phrase
            if(input.findchr('(')!=-1){
                //get masterword from input
                int numChar=input.findchr(')')-input.findchr('(')-1;
                DSString masterWord=DSString(input.substring(input.findchr('(')+1,numChar));
                //get subword from string and remove brackets
                input=input.substring(1,input.findchr(']')-1);
                //remove any trailing punctuation from word
                input=removeTrailPunct(input);
                masterWord=removeTrailPunct(masterWord);
                //add masterword to list
                int masterIndex=addKeyIndex(masterWord, pageNumber);
                //add word to list
                addKeyword(input, pageNumber);
                //add subword pointer to masterwords list
                assignSubWord(masterIndex,input);
            }
            else{
                //remove brackets
                input=input.substring(1,input.findchr(']')-1);
                //remove any trailing punctuation from word
                input=removeTrailPunct(input);
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
                //remove any trailing punctuation from word
                input=removeTrailPunct(input);
                masterWord=removeTrailPunct(masterWord);
                //add masterword to list
                int masterIndex=addKeyIndex(masterWord, pageNumber);
                //add word to list
                addKeyword(input, pageNumber);
                //add subword pointer to masterwords list
                assignSubWord(masterIndex,input);
            }
            else{
                //remove any trailing punctuation from word
                input=removeTrailPunct(input);
                //add keyword to list
                addKeyword(input, pageNumber);
            }
        }
    }while(pageNumber!=-1);
    //close file
    file.close();
    cout<<"...Complete"<<endl;
}
//create index
//arguments - output file path
void Indexer::create(char* outputFile){
    cout<<endl<<"Creating index and saving it to "<<outputFile<<"..."<<endl;
    //open results file
    ofstream file(outputFile);
    //check if it was opened properly
    if (!file.is_open()) {
        cout << "Could not open file "<<outputFile<<"." << endl;
        return;
    }
    //sort index
    sortIndex();
    cout<<endl<<"Index: "<<endl;
    char letter,temp;
    //format and output index to file
    for(int z=0;z<index.getSize();z++){
        //get char for alphabetical categories
        temp=index.at(z).getWord()[0];
        //assign letter at beginning and when letter changes
        if(z==0||temp!=letter){
            letter=temp;
            cout<<"["<<char(toupper(letter))<<"]"<<endl;
            file<<"["<<char(toupper(letter))<<"]"<<endl;
        }
        //if keyword has subwords, print subwords
        if(index.at(z).printKeyword(file)){
            //loop through each subword
            for(int b=0;b<index.at(z).getSubSize();b++){
                //indent for subwords
                file<<"  ";
                cout<<"  ";
                //get subword
                DSString subword=index.at(z).getSubAt(b);
                //find subword in list
                for(int c=0;c<index.getSize();c++){
                    //print keyword when found
                    if(subword==index.at(c).getWord()){
                        bool placeholder=index.at(c).printKeyword(file);
                    }
                }
            }
        }
    }
    //close file
    file.close();
    cout<<endl<<"...Complete"<<endl;
}
//get page number from input
//arguments - unparsed page input
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
//arguments - keyword input, keyword page number
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
        //if not found, add keyword to list in alphabetical order
        if (f == 0) {
            word.addPage(pageNumber);
            index.push_back(word);
        }
    }
}
//add keyword and return its index in the list
//arguments - keyword input, keyword page number
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
        //find word to return its index
        for (int i = 0; i < index.getSize(); i++) {
            //when found return index
            if (word == index.at(i)) {
                index.at(i).addPage(pageNumber);
                return i;
            }
        }
    }
    return -1;
}
//assign subwords to its masterword
//arguments - index of word, subword string
void Indexer::assignSubWord(int masterIndex,DSString subWord){
    index.at(masterIndex).addSub(subWord);
}
//sort keywords in alphabetical order
void Indexer::sortIndex(){
    sortIndex(0,index.getSize()-1);
}
//arguments - left side of list, right side of list
void Indexer::sortIndex(int left, int right){
    //end sort if list size is less than or equal to 1
    if (left >= right){
        return;
    }
    //quicksort index
    DSString pivot = index.at(right).getWord();
    int num = left;
    for (int i = left; i <= right; i++){
        //if true swap elements
        if (index.at(i).getWord() < pivot||index.at(i).getWord() == pivot){
            Keyword temp=index.at(num);
            index.at(num)=index.at(i);
            index.at(i)=temp;
            num++;
        }
    }
    //sort left side
    sortIndex(left, num-2);
    //sort right side
    sortIndex(num, right);
}
//remove trailing punctuation from strings
//arguments - word string
DSString Indexer::removeTrailPunct(DSString word){
    //loop through end of string until reaching the end of punctuation
    if(ispunct(word[word.getLength()-1])){
        for(int x=word.getLength()-1;x>=0;x--){
            if(!ispunct(word[x])){
                //remove punctuation
                DSString temp=word.substring(0,x+1);
                return temp;
            }
        }
    }
    else{
        return word;
    }
    return word;
}