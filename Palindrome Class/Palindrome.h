//
//  Palindrome.h
//  Palindrome
//
//  Created by Ikani Samani on 2/10/14.
//  Copyright (c) 2014 Ikani Samani. All rights reserved.
//  IDE: Xcode 5.0.2

/*
    Palindrome Class takes in string, splits the string and searches for the longest
    palindrome in that given string and returns it by value
 */

#ifndef __Palindrome__Palindrome__
#define __Palindrome__Palindrome__

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Palindrome{
    string line;
    vector<string>array;
    bool check_string(const string& substring);
    string subString();
    void findString();
    
public:
    // object mangaments
    Palindrome(){line = nullptr;};
    Palindrome(string s): line(s){}
    ~Palindrome(){}
    Palindrome(const Palindrome& p): line(p.line){}
    Palindrome& operator= (const Palindrome& p){
        line = p.line;
        return *this;
    };
    
    // class functions
    string longest();
    
    
};

#endif /* defined(__Palindrome__Palindrom__) */
