#include "malloc.h"

/**
 * @brief 
 * Basic malloc function. For now it's only returning a pointer to the free memory
 * space. No garbage collection, no free management, no memory fragmentation.
 * 
 * @return void * : Pointer to the free memory space
 */
void *malloc(size_t size)
{
    void *ptr = (void *)(mem_addr + used);
    used += size;
    return (ptr);
}