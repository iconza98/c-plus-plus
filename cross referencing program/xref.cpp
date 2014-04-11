//
//  xref.cpp
//  program5
//
//  Created by Ikani Samani on 4/8/14.
//  Copyright (c) 2014 Ikani Samani. All rights reserved.

#include <iostream> // cout
#include <fstream> 	// ifstream
#include <map>
#include <stdexcept>
#include <cctype> 	//isalpha
#include <algorithm> //transform, copy
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>

using namespace std;

// Comparison class for map's third parameter
struct classcomp{
	bool operator()(const string& lhs, const string& rhs) const 
	{
	    string s1(lhs);
	    string s2(rhs);
	    transform(lhs.begin(), lhs.end(), s1.begin(), ::tolower);
	    transform(rhs.begin(), rhs.end(), s2.begin(), ::tolower);

	    // if equal ignoring case
	    if(s1.compare(s2) == 0){
	        int temp = lhs.compare(rhs);
	        return (temp < 0)? true : false;
	    }
	    else 
	    	return s1 < s2;
	}
};

char removeInvalidChar(char c){
	if(!isalpha(c) && c != '\'')
        c = ' ';
    return c;
}

int main(int argc, const char * argv[])
{
    string filename, readline;
    int maxWordLength = 0, lineNumber = 1;
   
    if(argc < 2){
        cout << "Please enter the file name with the extension.." << endl;
        cin >> filename;
    }
    else
        filename = argv[1];

    ifstream inputFile(filename);
    if(inputFile.fail())
        throw runtime_error("File invalid");

    map<string,map<int,int>, classcomp > wordMap ; // map to save the data
    
    while(inputFile)
    {
        // read in line and remove invalid characters
        getline(inputFile, readline);
        transform(readline.begin(), readline.end(), readline.begin(), removeInvalidChar);

        // split the line
        istringstream iss(readline);
        vector<string> words;
        copy(istream_iterator<string>(iss),istream_iterator<string>(), back_inserter<vector<string> >(words));
        for(auto i : words){
        	if(i.size() > maxWordLength)
        		maxWordLength = i.size();
            // for each word insert into map with line and count
            wordMap[i][lineNumber] = (wordMap[i][lineNumber] == 0)? 1: wordMap[i][lineNumber] + 1;
        }

        ++lineNumber;
    } // end of while(inputFile)

    //print out results
     for(auto it = wordMap.begin(); it != wordMap.end(); ++it){
          cout << it->first << std::setw((maxWordLength + 2) - it->first.size()) << ": ";
          int count = 0;
        for(auto i = it->second.begin(); i != it->second.end(); ++i){
            if(count == 9){
                cout << "\n" << std::setw((maxWordLength + 2)) << " : ";
                count = 0;
            }
            cout << i->first << ":";
            cout << i->second << ", ";
            ++count;
        }
        cout << endl;
    }
    return 0;   
}

