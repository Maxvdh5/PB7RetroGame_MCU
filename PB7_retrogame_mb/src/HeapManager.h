#ifndef HEAPMANAGER_H
#define HEAPMANAGER_H

#include <cstdlib>

class HeapManager
{
public:
    void * operator new(size_t size);
    void operator delete(void *location);
private:
    HeapManager() = default;
};

#endif // HEAPMANAGER_H
