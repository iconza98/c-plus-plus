#include "Set.h"
#include "list.h"



Set::Set(void)
{

}

Set::~Set(void)
{

}

void Set :: insert_front(const int entry)
{
	data.insert_front(entry);
}
bool Set :: is_in(const int target)
{
	return data.is_in(target);
}