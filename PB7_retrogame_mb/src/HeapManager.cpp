#include "HeapManager.h"

void * operator new(size_t size)
{
    return static_cast<void*>( malloc(size) );
}

void operator delete(void * location)
{
    free(location);
}

