#include <stddef.h>
#include "memorypool.h"

typedef struct {
    uint8_t buffer[POOL_SIZE][BLOCK_SIZE];
    uint8_t is_used[POOL_SIZE];
} MemoryPool;

// Đưa biến my_pool vào file .c để giấu kín (encapsulation)
// Các file khác chỉ có thể tương tác với nó thông qua các hàm init, alloc, free
MemoryPool my_pool;

void pool_init() {
    for (int i = 0; i < POOL_SIZE; i++) {
        my_pool.is_used[i] = 0;
    }
}

void* pool_alloc() {
    for (int i = 0; i < POOL_SIZE; i++) {
        if (my_pool.is_used[i] == 0) {
            my_pool.is_used[i] = 1;
            return (void*)my_pool.buffer[i];
        }
    }
    return NULL;
}

void pool_free(void* ptr) {
    if (ptr == NULL) return;
    for (int i = 0; i < POOL_SIZE; i++) {
        if ((void*)my_pool.buffer[i] == ptr) {
            my_pool.is_used[i] = 0;
            return;
        }
    }
}