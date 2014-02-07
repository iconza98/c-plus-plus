//
//  MyObject.cpp
//  program1
//
//  Created by Ikani Samani on 1/16/14.
//  Copyright (c) 2014 Ikani Samani. All rights reserved.
//

#include "MyObject.h"
#include <iostream> // to use the ostream function

using namespace std;

Pool MyObject::pool(sizeof(MyObject)); // elemSize == sizeof(MyObject),

 ostream& operator<<(ostream& out, const MyObject& m){
    return out << '{' << m.getId() << ',' << m.getName() << '}';

}
