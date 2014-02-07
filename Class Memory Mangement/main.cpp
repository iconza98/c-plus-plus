/*
 Ikani Samani
 
 This program is demostrate dynamic memory managment done within in a class by overloading the the global new
 operators and with use of the placement new function.
 When the class MyObject calls the operator new function it will call the static class Pool. Pool will manually
 allocate dynamic memory for it and return a pointer for the default constructor of MyObject to be called.
 
 This file is a test file. The Pool class has trace statements to track its work.
 
 
 */

#include <iostream>
#include <string>
#include "MyObject.h" //
using namespace std;

int main() {
    // Create an array of MyObject heap objects
    constexpr size_t MAXOBJS = 20;
    MyObject* objs[MAXOBJS];
    for (int i = 0; i < MAXOBJS; ++i)
        objs[i] = MyObject::create(i, "\"" + to_string(i) + "\"");
    cout << "Object 5 == " << *objs[5] << endl;
    delete objs[5];
    objs[5] = 0;
    
    cout << "Creating another object:\n";
    MyObject* anotherObject = MyObject::create(100, "anotherObject");
    cout << "anotherObject == " << *anotherObject << endl;
    
    cout << "Creating yet another object:\n";
    MyObject* yetAnotherObject = MyObject::create(120, "yetAnotherObject");
    cout << "yetAnotherObject == " << *yetAnotherObject << endl;
    
    // Delete everything (although it's not "necessary"!)
    delete anotherObject;
    delete yetAnotherObject;
    for (size_t i = 0; i < MAXOBJS; ++i)
        delete objs[i];
}
