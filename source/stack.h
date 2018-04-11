#ifndef _STACK_H_
#define _STACK_H_

void s_push(int item, int* items, int* _size);
int s_pop(int* items, int* _size);
int s_peek(int* items, int size);
void s_reset(int* items, int* _size);
void rs_push(int item, int* items, int cap, int* _size);
int rs_pop(int* items, int cap, int* _size);
void rs_reset(int* items, int cap, int* _size);

#endif
