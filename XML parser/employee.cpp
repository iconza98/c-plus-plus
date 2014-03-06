//
//  employee.cpp
//  program 3
//
//  Created by Ikani Samani on 2/24/14.
//  Copyright (c) 2014 Ikani Samani. All rights reserved.
//
//
#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <memory>
#include "employee.h"

using namespace std;

const string EMPTAG = "<Employee>";
const string NAMETAG = "<name>";
const string IDTAG = "<id>";
const string ADDYTAG = "<address>";
const string CITYTAG = "<city>";
const string COUNTRYTAG ="<country>";
const string STATETAG = "<state>";
const string SALTAG = "<salary>";
const string PHONETAG = "<phone>";

const string EMPTAG_END = "</Employee>";
const string NAMETAG_END = "</name>";
const string IDTAG_END = "</id>";
const string ADDYTAG_END = "</address>";
const string CITYTAG_END = "</city>";
const string COUNTRYTAG_END ="</country>";
const string STATETAG_END = "</state>";
const string SALTAG_END = "</salary>";
const string PHONETAG_END = "</phone>";

const string INVALID = "Invalid Tag: ";
const string MISSING_TAG = "MissingTag: ";
const string MULTIPLE_TAGS = "Multiple Tags of: ";

void Employee::store(std::iostream& is) const{
    is.clear();
    is.seekg(0, ios::beg); 
    auto pos = is.tellg();
    unique_ptr<Employee> emp(Employee::read(is));
    while(emp->id != id && is.good())
    {
        pos = is.tellg();
        emp = move(Employee::read(is));   
    }
    if(emp->id == id){
        is.seekg(pos);
        Employee::write(is);
    }
    else{
        is.clear();
        Employee::write(is);
    }
    
};
unique_ptr<Employee> Employee::retrieve(std::istream& is, int num){
    unique_ptr<Employee> emp(Employee::read(is));
    while(emp->id != num && is.good())
    {
        emp = Employee::read(is);
    }
    if(emp->id == num)
        return emp;
    else
        return nullptr;
}


void Employee::toXML(std::ostream& os) const{
    os << EMPTAG << "\n"
    << '\t' << NAMETAG << name << NAMETAG_END << "\n"
    << '\t' << IDTAG << id << IDTAG_END << "\n";
    if(!city.empty())
        os<< '\t' << CITYTAG << city << CITYTAG_END << "\n";
    if(!state.empty())
        os<< '\t' << STATETAG << state << STATETAG_END << "\n";
    if(!country.empty())
        os<< '\t' << COUNTRYTAG << country << COUNTRYTAG_END << "\n";
    if(!phone.empty())
        os<< '\t' << PHONETAG << phone << PHONETAG_END << "\n";
    if(!address.empty())
        os<< '\t' << ADDYTAG << address << ADDYTAG_END <<"\n";
    if (salary != 0.0)
        os<< '\t' << SALTAG << salary << SALTAG_END << "\n";
    os<< EMPTAG_END << '\n';
    
}
unique_ptr<Employee> Employee::read(std::istream& is){
    emprec inbuf;
    if(is.bad())
        return nullptr;
    is.read(reinterpret_cast<char*>(&inbuf), sizeof(inbuf));
    std::unique_ptr<Employee>emp(new Employee());
    if(is){
        emp->id = inbuf.id;
        emp->name = inbuf.name;
        emp->salary = inbuf.salary;
        emp->address = inbuf.address;
        emp->city = inbuf.city;
        emp->state = inbuf.state;
        emp->country = inbuf.country;
        emp->phone = inbuf.phone;
    }

    return emp;
}
void Employee::write(std::ostream& os) const{
    emprec outbuf;
    outbuf.id = id;
    strncpy(outbuf.name, name.c_str(), 31)[31] = '\0';
    strncpy(outbuf.address, address.c_str(), 26)[26] = '\0';
    strncpy(outbuf.city, city.c_str(), 21)[21] = '\0';
    strncpy(outbuf.state, state.c_str(), 21)[21] = '\0';
    strncpy(outbuf.country, country.c_str(), 21)[21] = '\0';
    strncpy(outbuf.phone, phone.c_str(), 21)[21] = '\0';
    outbuf.salary = salary;
    os.write(reinterpret_cast<const char*>(&outbuf), sizeof(outbuf));
};

// Read the XML record from a stream
// Return nullptr if they fail
unique_ptr<Employee> Employee::fromXML(std::istream& is ){
    
    bool check;
    string keeperstring =  string_emp_read(is, check);
    if(!check || keeperstring.empty())
        return nullptr;
    
    
  	// temp values to populate
	string _name = "";
 	int _id = -1;
 	string _address = "";
 	string _city = "";
 	string _state = "";
 	string _country = "";
 	string _phone = "";
 	double _salary = 0.0;
    
    string temp;
    string value;
    size_t pos, endpos;
    
    //check for employee tag;
    
    temp = find_tag(keeperstring, pos, endpos);
    if( str_cmpr(temp, EMPTAG) == 0){
        earse_tag(keeperstring);
  	}
    // Employee tag found will now start populating a struct
    
    while(!keeperstring.empty()){
        temp = find_tag(keeperstring, pos, endpos);
        
        if(str_cmpr(temp, SALTAG) == 0) {
            fill_value(keeperstring, endpos, _salary);
            find_closing(keeperstring, SALTAG_END);
        }
        else if(str_cmpr(temp, NAMETAG) == 0) {
            fill_value(keeperstring, endpos, _name, NAMETAG);
            find_closing(keeperstring, NAMETAG_END);
        }
        else if(str_cmpr(temp, IDTAG) == 0) {
            fill_value(keeperstring, endpos, _id);
            find_closing(keeperstring, IDTAG_END);
        }
        else if(str_cmpr(temp, ADDYTAG) == 0) {
            fill_value(keeperstring, endpos, _address, ADDYTAG);
            find_closing(keeperstring, ADDYTAG_END);
        }
        else if(str_cmpr(temp, CITYTAG) == 0) {
            fill_value(keeperstring, endpos, _city, CITYTAG);
            find_closing(keeperstring, CITYTAG_END);
        }
        else if(str_cmpr(temp, STATETAG) == 0) {
            fill_value(keeperstring, endpos, _state, STATETAG);
            find_closing(keeperstring, STATETAG_END);
        }
        else if(str_cmpr(temp, COUNTRYTAG) == 0) {
            fill_value(keeperstring, endpos, _country, COUNTRYTAG);
            find_closing(keeperstring,COUNTRYTAG_END);
        }
        else if(str_cmpr(temp, PHONETAG) == 0) {
            fill_value(keeperstring, endpos, _phone, PHONETAG);
            find_closing(keeperstring, PHONETAG_END);
        }
        else if(str_cmpr(temp, EMPTAG_END) == 0) {
            keeperstring.clear();
        }
        else
        {
            throw runtime_error(INVALID + temp);
        }
    }
    
    if(_name.empty())
        throw runtime_error("Missing Name unable to create Employee");
    if(_id == -1)
        throw runtime_error("Missing ID unable to create Employee");
    unique_ptr<Employee> em(new Employee(_name, _id, _address, _city, _state, _country, _phone, _salary));
    
	return move(em);
}
string Employee::find_tag(const string& s, size_t& pos, size_t& endpos)
{
	pos = s.find_first_of('<');
	endpos = s.find_first_of('>');
	size_t length = (endpos + 1) - pos; // index starts at zero
	string temp = s.substr(pos, length);
	return temp;
    
}
int Employee::str_cmpr(const string& s1, const string& s2)
{
    
	char * c1 = new char[s1.length() + 1]; // include '\0'
	char * c2 = new char[s2.length() + 1];
	std::strcpy(c1, s1.c_str());
	std::strcpy(c2, s2.c_str());
	int temp =  strcasecmp(c1, c2);
	delete [] c1;
	delete [] c2;
	return temp;
}
string Employee::string_emp_read(istream& is, bool& found)
{
    found = false;
    string keeperstring = "";
    
    bool flag = true;
    char c;
    if(is)
    {
        string tempstring;
        string temp;
        
        size_t pos, endpos;
        
        is >> noskipws;
        while((is >> c) && flag){
            keeperstring+= c;
            tempstring+=c;
            
            if(c == '>'){
                temp = find_tag(tempstring, pos, endpos);
                
                if( str_cmpr(temp, EMPTAG) == 0){
                    if(found){
                        string temp = INVALID + EMPTAG;
                        throw std::runtime_error(temp);
                    }
                    else{
                        found = true;
                    }
                }
                else if( str_cmpr(temp, EMPTAG_END) == 0){
                    flag = false;
                }
                tempstring.clear();
                
            }
        }
    }
    if(!found && is.good()){
        keeperstring.clear();
        throw runtime_error(MISSING_TAG+EMPTAG);
    }
    return keeperstring;
}
void Employee::fill_value(string& s, size_t endpos, string& value, const string& tag){
	s.erase(0, (endpos + 1));
    if (value.empty())
        value = getValue(s);
    else
        throw runtime_error(MULTIPLE_TAGS + tag);
	erase_value(s);
}
void Employee::fill_value(string& s, size_t endpos, double& value){
	s.erase(0, (endpos +1));
	if(value == 0.0){
  	 	double temp = stod(getValue(s));
        value = temp;
    }
  	else
  		throw std::runtime_error(MULTIPLE_TAGS + SALTAG);
  	erase_value(s);
}
void Employee::fill_value(string& s, size_t endpos, int& value){
	s.erase(0, (endpos +1));
	if(value == -1){
  		int temp = stoi(getValue(s));
        value = temp;
    }
  	else
  		throw std::runtime_error(MULTIPLE_TAGS + IDTAG);
  	erase_value(s);
    
}
void Employee::find_closing(string& s, const string& compare)
{
    size_t pos = s.find_first_of('<');
    size_t endpos = s.find_first_of('>');
    size_t length = (endpos + 1) - pos; // index starts at zero
    string temp = s.substr(pos, length);
    if(str_cmpr(temp, compare)!= 0){
        throw runtime_error(MISSING_TAG + compare);
    }
    else{
        s.erase(0, (endpos + 1));
    }
}
void Employee::earse_tag(string& s)
{
	size_t endpos = s.find_first_of('>');
	s.erase(0, (endpos + 1));
}
void Employee::erase_value(string& s)
{
	size_t endpos = s.find_first_of('<');
	s.erase(0, (endpos));
    
}
string Employee::getValue(string& s)
{
	string temp;
	size_t pos = s.find_first_of('<');
	temp = s.substr(0, pos); // index is actually pos +1
	return temp;
}
