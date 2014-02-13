//
//  Palindrom.cpp
//  Palindrome
//
//  Created by Ikani Samani on 2/10/14.
//  Copyright (c) 2014 Ikani Samani. All rights reserved.
//  IDE: Xcode 5.0.2

#include "Palindrome.h"
using namespace std;
// check_string fucntion
// purpose: indicator whether a string is a palindrome
// paramenter: a single string
// postcondition: returns true if the string is a palindrome
bool Palindrome::check_string(const string& substring){
    auto k = --substring.end();
    for (auto i = substring.begin() ; i != substring.end(); ++i) {
        if (*i == *k)
            --k;
        else
            return false;
    }
    
    return true;
}
// find string function
// purpose: split the string in the 'line' data member
// postcondition: the 'array' datamember will be populated with strings
//                that might be palindromes
void Palindrome::findString(){
    string temp;
    vector<string> tempArray;
    char letter;
    
    for(int i = 0; i < (int)line.length(); ++i){
        letter = line[i];
        int j = 1;
        for(; j < line.length(); ++j) {
            if(letter == line[j]){
                temp = line.substr(i,(j-i + 1));
                tempArray.push_back(temp);
            }
            
            
        }
    }
    for (auto i = tempArray.begin(); i < tempArray.end(); ++i) {
        if(check_string(*i))
            array.push_back(*i);
    }
}
// lonest function
// purpose: returns the longest palindrome within a given string
// Precondtion: 'line' data memeber must not be empty
// postcondition: a string is returned that is the longest palidrome
//                or a messages that says its empty
string Palindrome::longest(){
    string longest;
    string temp;
    
    
    if (line.empty()) {
        temp = "Nothing insserted";
        return temp;
    }
    
    findString();
    
    if(array.empty()){
        temp = "No Palidromes";
        return temp;
    }
    
    for (auto i = array.begin(); i < array.end(); ++i){
        temp = *i;
        if (longest.length() < temp.length() ) {
            longest = temp;
        }
    }
    temp = "No Palidromes";
    return (!(longest.length() <= 1))? longest: temp;
}
