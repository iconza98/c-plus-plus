//
//  main.cpp
//  program 3
//
//  Created by Ikani Samani on 2/24/14.
//  Copyright (c) 2014 Ikani Samani. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <stdexcept>
#include "employee.h"

using namespace std;

int main(int argc, const char * argv[])
{
    
   vector<unique_ptr<Employee>> empVect;
    
    //    1) Obtain the name of an XML file to read from the command line (argv[1]). Print an error message and halt
    //    the program if there is no command-line argument provided.
    
    ifstream inputFile;

    
    if (argc == 2) {
        string filename = argv[1];
        inputFile.open(filename, std::ifstream::in);
        if (inputFile.fail()) {
            cout << "Error: File not found";
        }
    }
    else{
        cout<< "Error: none or more than one file passed in\n";
        return EXIT_FAILURE;
    }

    

    //    2) Read each XML record in the file by repeatedly calling Employee::fromXML, which creates an Employee
    //       object on-the-fly, and store it in a vector of Employee pointers (you may use smart pointers).
    while(inputFile)
    {
        try{
            unique_ptr<Employee> temp(Employee::fromXML(inputFile));
            if (temp != nullptr) {
                empVect.push_back(move(temp));
            }
        }
        catch(exception& e)
        {
            cout << e.what() << endl << endl;
        }
    }
    
    
    //    3) Loop through your vector and print to cout the Employee data for each object (using the display member
    //                   function).
    for (auto i = 0; i < empVect.size(); ++i) {
        empVect[i]->display(cout);
    }
    
    //    4) The next step is to create a new file of fixed-length Employee records. This is explained below. Write the
    //            records for each employee to your new file (call it “employee.bin”) in the order they appear in your vector.
    //                Open this file as an fstream object with both read and write capability, and in binary format.
    ofstream empdata("employee.bin", ios::out | ios::binary);
    for (auto i = 0; i < empVect.size(); ++i) {
        empVect[i]->write(empdata);
    }
    empdata.close();
    
    //    5) Clear your vector in preparation for the next step.
    empVect.clear();
    
    //    6) Traverse the file by repeated calls to Employee::read, filling your newly emptied vector with
    //      Employee pointers for each record read.
    fstream emprecs("employee.bin", ios::in | ios::out | ios::binary);
    while (emprecs) {
        unique_ptr<Employee>temp(Employee::read(emprecs));
        if (temp->isValid()) {
            empVect.push_back(move(temp));
        }
    }
    //    7) Loop through your vector and print to cout an XML representation of each Employee using
    //                        Employee::toXML.
    for (auto i = 0; i < empVect.size(); ++i) {
        empVect[i]->toXML(cout);
    }
    //    8) Search the file for theEmployee with id 12345 using Employee::retrieve.
    emprecs.clear(); // clear EOF
    emprecs.seekg(0, ios::beg); // rewind the stream
    unique_ptr<Employee>temp(Employee::retrieve(emprecs, 12345));
    
    
    if(temp != nullptr){
        cout << "\nFOUND:" << endl;
        temp->display(cout);
    }
    else
        cout << "\nNOT FOUND" << endl;
    
    //    9) Change the salary for the retrieved object to 150000.0
    temp->setSalary(150000.0);
    cout << temp->getSalary() << endl << endl;
    
    
    //    10) Write the modified Employee object back to file using Employee::store
    temp->store(emprecs);
    
    //    11) Retrieve the object again by id (12345) and print its salary to verify that the file now has the updated salary.
    emprecs.clear(); // clear EOF
    emprecs.seekg(0, ios::beg); // rewind the stream
    unique_ptr<Employee>temp2(Employee::retrieve(emprecs, 12345));
    if(temp2 != nullptr){
        cout << "\nFOUND:" << endl;
        temp2->display(cout);
    }
    else
        cout << "\nNOT FOUND" << endl;
    //    12) Create a new Employee object of your own with a new, unique id, along with other information.
    
    unique_ptr<Employee> unique(new Employee("Chuck Allison", 1223, "", "Orem", "Uah", "USA","", 50000));
    
    //    13) Store it in the file using Employee::store.
    emprecs.clear(); // clear EOF
    emprecs.seekg(0, ios::beg); // rewind the stream
    unique->store(emprecs);
    
//    14) Retrieve the record with Employee::retrieve and display it to cout.
    emprecs.clear(); // clear EOF
    emprecs.seekg(0, ios::beg); // rewind the stream
    unique_ptr<Employee>temp3(Employee::retrieve(emprecs, 1223));
    if(temp3 != nullptr){
        cout << "\nFOUND:" << endl;
        temp3->display(cout);
    }
    else
        cout << "\nNOT FOUND" << endl;
    
    return 0;
    
}


