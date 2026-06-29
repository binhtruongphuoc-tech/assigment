#include "ringbuffer.h"

void rb_init(RingBuffer* rb) {
    rb->head = 0;
    rb->tail = 0;
    rb->count = 0;
}

int rb_is_full(RingBuffer* rb) { return rb->count == BUFFER_SIZE; }
int rb_is_empty(RingBuffer* rb) { return rb->count == 0; }

int rb_push(RingBuffer* rb, int value) {
    if (rb_is_full(rb)) return 0;
    rb->buffer[rb->tail] = value;
    rb->tail = (rb->tail + 1) % BUFFER_SIZE;
    rb->count++;
    return 1;
}

int rb_pop(RingBuffer* rb, int* out_value) {
    if (rb_is_empty(rb)) return 0;
    *out_value = rb->buffer[rb->head];
    rb->head = (rb->head + 1) % BUFFER_SIZE;
    rb->count--;
    return 1;
}