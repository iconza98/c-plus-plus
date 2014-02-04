#include "list.h"

#ifndef SET_H
#define SET_H
#pragma once
class Set
{
public:
	Set(void);
	~Set(void);
	void insert_front(const int entry);
	bool is_in(const int target);
private:
	list data;
};
#endif
