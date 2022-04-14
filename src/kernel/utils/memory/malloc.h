#ifndef __MALLOC_H__
    #define __MALLOC_H__

    #include <stddef.h>

void *malloc(size_t size);

unsigned int mem_addr = 0x10000;        // Start address of the memory (Far adress from kernel)
                                        // Must be rebuild because kernel can overwrite the adress 
                                        // kernel start : 0x1000 (with Makefile -Ttext flag)
size_t used = 0;                        // Used memory space, upgrading with malloc called

#endif