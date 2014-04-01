/*
 *	analyze.cpp
 *  Ikani Samani
 *  Program 3
 *  CS 3370
 *  
 *  No codes were copied in the creation of this file except those allowed by the instructor and or provided
 *  in the instructions for program 4.
 *
 *  Parameter: a *.ini file passed through commandline that should include the following information:
 *  vt = int to check for a rise over three consecutive points that is greater than this parameter
 *  width = parameter to check the width of the pulses
 *  pulse_delta : The between pulses to look for piggybacks
 *  below_drop_ration: int, the number of values less than drop ratio to check against
 *  drop_ratio: double, a number less than 1.
 *
 *  This program is designed to gather all .dat file within the same directory and create a single file to
 *  reference the file names, then process the data to find pulses within the given data.
 *  The file names is return along with the found pulses, the width for those pulse are given
 *  in the linve proceeding it.
 *
 */

#include <iostream>
#include <fstream>
#include <cstdlib> // system, exit macros
#include <exception>
#include <string>
#include <vector>

#if defined(__GNUC__)
#define listcmd "ls *.dat > datafiles.txt 2>/dev/null"
#else
#error Unsupported Complier
#endif

using namespace std;

int fileNum = 1;

struct Ini{
	int vt = 0;
	int width = 0;
	int pulse_delta = 0;
	double drop_ratio = 0.0;
	int below_drop_ratio = 0;
	Ini(int _vt, int _width, int _pulse_delta, double _drop_ratio, int _below_drop_ratio){
		this->vt = _vt;
		this->width = _width;
		this->pulse_delta = _pulse_delta;
		this->drop_ratio = _drop_ratio;
		this->below_drop_ratio = _below_drop_ratio;
	}
};

std::vector<int> calcWidth(vector<int> pulses, vector<int> v);
void check_pulses(std::vector<int>smoothData, std::vector<int>& pulses, std::vector<int>& peakVector, Ini iniFile);

int main(int argc,const char * argv[])
{
    
	int check = system(listcmd);
	if(check != 0)
		throw runtime_error("missing *.dat files");
    
    
	// open newly created file
	ifstream input("datafiles.txt");
	if(input.fail())
		throw runtime_error("Error Files not found\n");
    
	// loop through putting file names into vector
	std::vector<string> file_names;
	string temp;
	while(input){
		getline(input, temp);
		if(temp != "")
			file_names.push_back(temp);
	}
    
	// close ifstream and flush to be ready for reuse
	input.close();
	input.clear();

    
	// READ INI file ***************************************
    // readin *.ini file from commandline
    if(argc < 2)
        throw runtime_error("No imput passed in.");

    string fileName = argv[1];
	input.open("gage2scope.ini", ifstream::in);
	if(!input)
        throw runtime_error("*.ini file not found or invalid.");
    
	temp.clear();
	int vt = 0;
	int width = 0;
	int pulse_delta = 0;
	double drop_ratio = 0.0;
	int below_drop_ratio = 0;
	while(input){
		// readline up to '='
		getline(input, temp, '=');
		string temp2;
		getline(input, temp2);
		if(temp == "vt")
			vt = stoi(temp2, 0);
		else if(temp == "width")
			width = stoi(temp2, 0);
		else if(temp == "pulse_delta")
			pulse_delta = stoi(temp2, 0);
		else if(temp == "drop_ratio")
			drop_ratio = stod(temp2, 0);
		else if(temp == "below_drop_ratio")
			below_drop_ratio = stoi(temp2, 0);
        
		temp.clear(); // clear out temp buffer;
	}
    input.close();
	Ini iniFile(vt, width,pulse_delta, drop_ratio, below_drop_ratio);
    
	// END OF READIN INI FILE ***************************************************************************
//    
//	vector<int> v;
//	int num;
//	while(input){
//		input >> num;
//		v.push_back(num = -num); // negate the number then insert into vector
//	}
    
     vector<int> v;
    	for(auto j = file_names.begin(); j != file_names.end(); ++j){
        ifstream input;
        input.open(*j, ifstream::in);
        
       
        int num;
        while(input){
            input >> num;
            v.push_back(num = -num); // negate the number then insert into vector
        }
        
        input.close();
        input.clear();
        
        // Smooth out graph ************************************
        
        vector<int> smoothData = v;
        for(auto iter = (smoothData.begin() + 3); iter != (smoothData.end() - 3); iter++){
            *iter = (iter[-3] + 2*iter[-2] + 3*iter[-1] + 3*iter[0] + 3*iter[1] + 2*iter[2] + iter[3]) / 15;
        }
            
        // CHECK FOR PULSE ************************************
        // find pulse in smooth data and push into pulses vector
        std::vector<int> pulses;
        std::vector<int> peakVector;
            
        check_pulses(smoothData,pulses,peakVector, iniFile);
            
        cout << *j << ' ';
            
        for(auto i: pulses)
            cout << i << ' ';
            
        // Calculate width ***************
        vector<int> widths = calcWidth(pulses, v);
            
        cout << "\n";
        for(auto i : widths)
            cout << i << ' ';
            
        cout << endl;
            
            v.clear();
        } // end of file_names loop
	
    
	return 0;
    
} // end of main

std::vector<int>  calcWidth(vector<int> pulses, vector<int> v)
{
    const int HUND = 100;
    
	std::vector<int> temp;
    int end;
    for(int i = 0; i < pulses.size(); ++i){
        int sum = 0;
        int pos = pulses[i];
        
        if(pos == pulses[pulses.size()-1])
            end = ((v.size() - pos) > HUND)? pos + HUND : (int)pulses.size()-1;
        else
            end = pulses[i+1];
        
        while(pos < end)
            sum += v.at(pos++);
        temp.push_back(sum);
    }	return temp;
}

void check_pulses(std::vector<int>smoothData, std::vector<int>& pulses, std::vector<int>& peakVector, Ini iniFile){
    
	pulses.clear();
	peakVector.clear();
    for(auto iter = smoothData.begin(); iter != (smoothData.end()-2); ++iter)
    {
    	int riseCheck = *(iter + 2) - *iter;
        
    	if(riseCheck > iniFile.vt){
    		pulses.push_back((int)distance(smoothData.begin(), iter));
    		
    		while(*iter < *(iter +1)) //find peak
    			++iter;
            
    		peakVector.push_back((int)distance(smoothData.begin(), iter));
    		
    		if(pulses.back() == peakVector.back()){
    			pulses.pop_back();
    			peakVector.pop_back();
    		}
    		
    	}
    }
    
    //check for adjacent pulses
    // check adjecant pulses
    auto pIter = peakVector.begin();
    for(auto iter = pulses.begin(); iter != (pulses.end()); ++iter)
    {
    	// check for adjecent pulses
    	if(*(iter+1) - *iter <= iniFile.pulse_delta){
    		//calculate distance of peak
    		int tempPos = peakVector.at(distance(pulses.begin(), iter)); // get the peakpos from 1st
    		int endPos = *(iter+1); // endPos the next pulse position
    		int falseCount = 0;
    		//cout << "endPos: " << endPos << endl;
    		int check = iniFile.drop_ratio * smoothData.at(tempPos); // drop_ratio * peak
    		//cout << "check: " << check << "  peakpos: " << tempPos << "  value: " << smoothData.at(tempPos) <<endl;
    		while(tempPos < endPos){
    			if(smoothData.at(tempPos) < check)
    				++falseCount;
    			++tempPos;
    		}
            //cout << "falseCount: " << falseCount << endl;
    		if(falseCount > iniFile.below_drop_ratio){
    			//cout << "throwing out position: " << pulses.at(distance(pulses.begin(), iter)) << endl;
    			pulses.erase(iter);
    			peakVector.erase(pIter);
    		}
            
    	}
    	++pIter;
    }

}
// Newline required for sublime compiler
