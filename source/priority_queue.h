#ifndef _PRIORITY_QUEUE_H_
#define _PRIORITY_QUEUE_H_

void pq_upheap(int at, int* items);
void pq_downheap(int at, int* items, int size);
void pq_insert(int item, int* items, int* _size);
int pq_remove(int* items, int* _size);
void pq_build(int* items, int size);
void pq_update_at(int at, int item, int* items, int size);
void pq_remove_at(int at, int* items, int* _size);
void pq_reset(int* items, int* _size);

#endif
