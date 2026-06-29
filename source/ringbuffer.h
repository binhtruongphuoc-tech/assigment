#ifndef RINGBUFFER_H
#define RINGBUFFER_H

#define BUFFER_SIZE 5

typedef struct {
    int buffer[BUFFER_SIZE];
    int head;
    int tail;
    int count;
} RingBuffer;

void rb_init(RingBuffer* rb);
int rb_is_full(RingBuffer* rb);
int rb_is_empty(RingBuffer* rb);
int rb_push(RingBuffer* rb, int value);
int rb_pop(RingBuffer* rb, int* out_value);

#endif // RINGBUFFER_H#pragma once
