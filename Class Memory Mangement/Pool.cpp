//
//  Pool.cpp
//  program1
//
//  Created by Ikani Samani on 1/16/14.
//  Copyright (c) 2014 Ikani Samani. All rights reserved.
//

#include "Pool.h"
#include <cstdlib>
#include <iostream>
using namespace std;

// REMINDER: put in trace statements for pool functions
// elemSize is the byte size
// blockSize is the number of blocks withing

Pool::Pool( size_t elementSize, size_t blkSize)
{
    elemSize = elementSize;
    blockSize = blkSize;
    
    pool = nullptr;
    freeptr = nullptr;
    printf("Initializing a pool with element size %zu and block size %zu\n", elemSize, blockSize);
}
Pool::~Pool(){
    // delete each row in pool
    // delete pool pointer array
    
    for (int i = 0; i < nRows; i++) {
        char *p = pool[nRows];
        delete [] p;
        p = nullptr;
    }
    
    delete [] pool;
    printf("Deleting %zu blocks", nRows);
    
}
void Pool::resize(){
    
    // if freeptr == nullptr
    //      add a row, link it together
    // return freeptr and will point to the first one open
    printf("Expanding pool...\n");
    
    char** newPool = new char*[nRows++];
    newPool[nRows] = new char[blockSize*elemSize];
    char *p = newPool[nRows]; // p now points to the first element in that row of bytes

    printf("Linking cells starting at %p\n", p);
    for (int i = 0; i < blockSize; i++) {
        printf("Cell Allocated at %p\n", p);
        poke(p, p + elemSize);
        p += elemSize;
    }
    poke(p, nullptr); // fifth cell is allocated with nullptr
    freeptr = newPool[nRows++];
    
    delete [] pool;
    pool = newPool;
    
}

void* Pool::allocate(size_t size) // Get a pointer inside a pre-allocated block for a new object
{
    
    if (freeptr == nullptr) {
        resize();
    }
    void *temp = freeptr;
    freeptr = peek<char*>(freeptr);
    return temp;
    
}
void Pool::deallocate(void* p) // Free an object's slot (push the address on the "free list")
{
    char** temp1 = static_cast<char**>(p);
    poke(temp1, freeptr);
    freeptr = *temp1;
    
    
    printf("Cell deallocatted at %p\n", p );
}


