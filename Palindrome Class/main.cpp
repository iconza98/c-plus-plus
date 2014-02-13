//
//  main.cpp
//  Palindrome
//
//  Created by Ikani Samani on 2/10/14.
//  Copyright (c) 2014 Ikani Samani. All rights reserved.
// IDE: Xcode 5.0.2

#include <iostream>
#include <fstream>
#include <string>
#include "Palindrome.h"

using namespace std;

int main()
{
    string input;
    ifstream ifs;
    ifs.open("testfile.txt");
    
    if(ifs.good()){
        getline(ifs, input, ' ');
        Palindrome p = Palindrome(input);
        cout << "Palindrom Class" << endl;
        cout << "Longest: " << p.longest() << endl;
    }
    else
        cout << "File Failed" << endl;
    std::cin.get();
    return 0;
}

