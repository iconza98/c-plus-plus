//
//  employee.h
//  program 3
//
//  Created by Ikani Samani on 2/24/14.
//  Copyright (c) 2014 Ikani Samani. All rights reserved.
//
//
/*
    This program is designed to take an Employee xml file and parse the information and populate an employee class.
    An employee

*/

#ifndef __program_3__employee__
#define __program_3__employee__

#include <iostream>
#include <memory>

using std::string;

class Employee
{
    string name;
    int id;
    string address;
    string city;
    string country;
    string state;
    string phone;
    double salary;
    
    struct emprec {
        char name[31];
        int id;
        char address[26];
        char city[21];
        char state[21];
        char country[21];
        char phone[21];
        double salary;
    };
    
    // Helper functions

    // String_emp_read function
    // pupose: take an istream parse into a string from opening and closing Employee tags
    // Returns: a string containing all char from istream uncluding closing bracket
    static string string_emp_read(std::istream& is, bool& found);

    // find_tag function
    // purpose: search a string looking nearest tag
    // postcondition: string s is still the same
    // return: a string containing a tag
    static string find_tag(const string& s, size_t&, size_t&);

    // find_closing funciton
    // purpose: find the nearest closing tag
    // Parameters: the string being read, the string being compared to
    // postconditions: if the correct string is found it will be delete
    //                  if incorrect tag is found will throw an runtime error
    static void find_closing(string& s, const string& compare);

    // fill value
    // purpose, read a string and pass its value to the second parameter
    static void fill_value(string& s, size_t endpos, int& value);
    static void fill_value(string& s, size_t endpos, double& value);
    static void fill_value(string& s, size_t endpos, string& value, const string& tag);

    // str_cmpr
    // purpose: compare two strings by case-insensitive
    // return: similar to string.compare() returns 0 if equal
    static int str_cmpr(const string& s1, const string& s2);

    // getValue
    // purpose: is to search the string looking for '<'
    // returns a substring of just the value before '<'
    static string getValue(string& s);

    // erase_value
    // purpose: erase upto the '<' to remove value from string
    // postcondition: string will begin with next tag
    static void erase_value(string& s);

    // erase_tag
    // purpose: to remove the end tag from string
    static void earse_tag(string& s);
    
    
    
public:
    // Object Management
    Employee(){
        name = "";
        id = -1;
        address = "";
        city = "";
        country ="";
        state = "";
        phone = "";
        salary = 0.0;
    };
    Employee(string _name, int _id, string _address, string _city, string _state, string _country, string _phone, double _salary): name(_name), id(_id), address(_address), city(_city), state(_state), country(_country), phone(_phone), salary(_salary) {}
    
    // Copy constructor
    Employee(const Employee& e): name(e.name), id(e.id), address(e.address), city(e.city), state(e.state), country(e.country), phone(e.phone), salary(e.salary) {}
    
    Employee& operator=(const Employee& e)
    {
        name = e.name;
        id = e.id;
        address = e.address;
        city = e.city;
        country = e.country;
        state = e.state;
        phone = e.phone;
        salary = e.salary;
        return *this;
    };

    // Wrtie a readable Employee representation to a stream
    void display(std::ostream& os) const{
        os << "id: " << id << "\n"
        << "name: " << name << "\n";
        if(!address.empty())
            os<< "address: " << address << "\n";
        if(!city.empty())
            os<< "city: " << city << "\n";
        if(!state.empty())
            os<< "state: " << state << "\n";
        if(!country.empty())
            os<< "country: " << country << "\n";
        if(!phone.empty())
            os<< "phone: " << phone << "\n";
        if(salary != 0.0)
            os<< "salary: " << salary << "\n" << std::endl;

    };
    
    // Write a fixed-length record to current file position
    void write(std::ostream& os) const;
    
    
    //Overwrite (or append) record in (to) file
    void store(std::iostream& is) const;
    
    // Write XML record for Employee
    void toXML(std::ostream& os) const;
    
    // Read record from current file position
    // Return nullptr if they fail
    static std::unique_ptr<Employee> read(std::istream& is);
    
    // Search file for record by id
    // Return nullptr if they fail
    static std::unique_ptr<Employee> retrieve(std::istream& is, int num);
    
    // Read the XML record from a stream
    // Return nullptr if they fail
    static std::unique_ptr<Employee> fromXML(std::istream& is);
    
    // check if the this employee is not an empty object
    bool isValid() const {
        return id != -1;
    }
    // simple setter
    void setSalary(double money) {
       salary = money;
    }

    // simple getter
    double getSalary() const{
        return salary;
    }
    
};

#endif /* defined(__program_3__employee__) */
