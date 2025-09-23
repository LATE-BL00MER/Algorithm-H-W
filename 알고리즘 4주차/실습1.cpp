#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 20

typedef struct {
	int id; // 머신 넘버
	int avail; // 수행해야 될 요소의 넘버
}element;

typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

HeapType* create() {
	return (HeapType*)malloc(sizeof(HeapType));
}
 
void init(HeapType *h) {
	h->heap_size = 0;
}

void insert_min_heap(HeapType *h, element item) {
	int i;
	i = ++(h->heap_size);

	while ((i != 1) && item.avail < h->heap[i / 2].avail) {
		h->heap[i] = h->heap[i / 2];
		i = i / 2;
	}
	h->heap[i] = item;
}

element delete_min_heap(HeapType *h) {
	int parent, child;
	element item = h->heap[1];
	element temp = h->heap[h->heap_size--];
	parent = 1; child = 2;

	while (child <= h->heap_size) {
		if ((child < h->heap_size) && 
			(h->heap[child].avail > h->heap[child + 1].avail)) {
			child++;
		}
		if (temp.avail < h->heap[child].avail) break; 
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

int main() {
	int jobs[] = { 8, 7, 6, 5, 3, 2, 1 };
	element m = { 0, 0 };
	HeapType* h;
	h = create();
	init(h);

	for (int i = 0; i < 3; i++) {
		m.id = i + 1;
		m.avail = 0;
		insert_min_heap(h, m);
	}

	for (int i = 0; i < 7; i++) {
		m = delete_min_heap(h); //(1,0), (2,0)
		printf("job %d번은 시간 = %d부터 시간 %d까지 Machine %d에 할당\n", 
			i, m.avail, m.avail + jobs[i] - 1, m.id);
		m.avail = m.avail + jobs[i];
		insert_min_heap(h, m); 
	}

	//힙 배열 출력

}