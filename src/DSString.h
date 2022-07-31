#ifndef INC_20F_AUTO_IDX_DSSTRING_H
#define INC_20F_AUTO_IDX_DSSTRING_H

#include <iostream>

using namespace std;
//This class implements a String container.
class DSString {
private:
    char* string;   //char array to hold string

public:

    /**
     * Constructors and destructor
     *
     **/
    DSString();
    DSString(const char*);
    DSString(const DSString&);
    ~DSString();

    /**
     * Standard relational operators.
     *
     * Note that for each operator, there are two overloaded versions:
     *    one that takes a DSString object
     *    one that takes a null-terminated c-string
     *
     **/
    DSString& operator= (const char*);
    DSString& operator= (const DSString&);
    DSString operator+ (const DSString&);
    bool operator== (const char*)const;
    bool operator== (const DSString&)const;
    bool operator> (const DSString&)const;
    bool operator< (const DSString&)const;
    char& operator[] (const int);

    /**
     * getLength() returns the number (count) of characters in the string.
     **/
    int getLength();

    /**
     * The substring method returns a string object that contains a
     * sequence of characters from this string object.
     *
     * param start - the index of where to start
     * param numChars - the number (count) of characters to copy into
     *    the substring
     **/
    DSString substring(int start, int numChars);

    /**
     * the c_str function returns a null-terminated c-string holding the
     * contents of this object.
     **/
    char* c_str();

    /**
     * Overloaded stream insertion operator to print the contents of this
     * string to the output stream in the first argument.
     **/
    friend std::ostream& operator<< (std::ostream&, const DSString&);

    friend std::istream& operator>> (std::istream&, const DSString&);

    int find(char[]);
    int find(DSString);
    int findchr(char chr);
    void tolower();
    char tolower(char);
};


#endif //INC_20F_AUTO_IDX_DSSTRING_H
