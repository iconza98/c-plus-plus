//
//  MyObject.h
//  program1
//
//  Created by Ikani Samani on 1/16/14.
//  Copyright (c) 2014 Ikani Samani. All rights reserved.
//

#ifndef __program1__MyObject__
#define __program1__MyObject__

#include <iosfwd> // allows for refrence to streamd
#include "Pool.h"
#include <string>

using namespace std;

class MyObject
{
    
public:
    static MyObject* create(int _id, const string& _name){
        return new MyObject{_id, _name};
    }

    
    void* operator new(size_t size){return pool.allocate(size);};
    void operator delete(void* p){return pool.deallocate(p);};
    int getId() const{return id;};
    string getName() const{return name;};
    
    
    friend ostream& operator<<(ostream& out, const MyObject& m);
    
private:
    int id;
    string name;
    static Pool pool;
    
    
    //Disallow copy, assign, and direct construction
    MyObject(const MyObject&) = delete;
    MyObject& operator=(const MyObject&) = delete;
    MyObject(int i, const string& nm) :id{i} , name{nm} {}
};


#endif /* defined(__program1__MyObject__) */
