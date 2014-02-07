//
//  Pool.h
//  program1
//
//  Created by Ikani Samani on 1/16/14.
//  Copyright (c) 2014 Ikani Samani. All rights reserved.
//

#ifndef __program1__Pool__
#define __program1__Pool__

#include <iosfwd>
#include <new>

// Return the bytes at address P as a T object
template<typename T>
T peek(void* p){
    return *static_cast<T*>(p);
}
// poke function
// purpose: Place information(T) in the begining of raw data
// parameters: void* , Template type T()
// Returns void
// post condition: create a copy of the object t at address p

template<typename T>
void poke(void* p, T t){
    // Create a copy of the object t at address p
    new (p) T(t);
}

class Pool
{
    
private:
    
    char** pool = nullptr; 
    char* freeptr = nullptr;
    size_t nRows = 1;
    size_t elemSize;
    size_t blockSize;
    
    int count = 0;
    
    // disallow copy and assignment
    Pool(const Pool&) = delete;
    Pool& operator=(const Pool&) = delete;
    
public:
    
    Pool(size_t elemSize, size_t blockSize = 5);
    ~Pool();
    void resize();
    void* allocate(size_t size); // Get a pointer inside a pre-allocated block for a new object
    void deallocate(void*); // Free an object's slot (push the address on the "free list")
};



#endif /* defined(__program1__Pool__) */
