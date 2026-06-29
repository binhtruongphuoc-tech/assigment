#ifndef MEMORYPOOL_H
#define MEMORYPOOL_H

#include <stdint.h>

#define BLOCK_SIZE 32
#define POOL_SIZE  5

void pool_init();
void* pool_alloc();
void pool_free(void* ptr);

#endif // MEMORYPOOL_H#pragma once
