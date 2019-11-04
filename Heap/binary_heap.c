#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct heap_t_ {

	int *harr;
	int cap;
	int heap_size;
} heap_t;

heap_t *
create_heap (int cap)
{

	heap_t *new_heap = NULL;

	new_heap = malloc (sizeof (heap_t));

	if (!new_heap) {
	
		printf ("Memory Allocation Failed!!\n");
		return NULL;
	}

	new_heap->cap		= cap;
	new_heap->heap_size	= 0;
	new_heap->harr		= malloc (new_heap->cap * sizeof (int));

	if (!new_heap->harr) {
	
		free (new_heap);
		return NULL;
	}

	return new_heap;

}

void
swap (int *a, int *b)
{

	int temp = 0;

	temp	= *a;
	*a		= *b;
	*b		= temp;

}

int
get_min (heap_t *h)
{

	return h->harr[0];

}

int
parent (int i)
{

	return ((i - 1) / 2);

}

int 
left (int i)
{

	return ((2 * i) + 1);

}

int
right (int i)
{

	return ((2 * i) + 2);

}

void
min_heapify (heap_t *h, int i)
{

	int l			= left (i);
	int r			= right (i);
	int smallest	= i;

	if ((l < h->heap_size) &&
		(h->harr[l] < h->harr[smallest])) {
	
		smallest = l;
	}

	if ((r < h->heap_size) &&
		(h->harr[r] < h->harr[smallest])) {
	
		smallest = r;
	}

	if (smallest != i) {
	
		swap (&h->harr[i], &h->harr[smallest]);
		min_heapify (h, smallest);
	}

}

void
heapify (heap_t *h, int i)
{

	while ((i != 0) && (h->harr[parent (i)] > h->harr[i])) {
	
		swap (&h->harr[parent (i)], &h->harr[i]);
		i = parent (i);
	}

}

void
insert (heap_t *h, int key)
{

	if (h->heap_size == h->cap) {
	
		printf ("Heap Overflow \n");
		return;
	}

	int i = 0;

	h->heap_size++;
	i 			= h->heap_size - 1;
	h->harr[i]	= key;
	
	heapify (h, i);

}

void
decrease_key (heap_t *h, int i, int new_val)
{

	h->harr[i]	= new_val;
	heapify (h, i);

}

int
extract_min (heap_t *h)
{

	if (h->heap_size <= 0) {
	
		return INT_MAX;
	}

	if (h->heap_size == 1) {
	
		h->heap_size--;
		return h->harr[0];
	}

	int root = 0;

	root		= h->harr[0];
	h->harr[0]	= h->harr[h->heap_size - 1];
	h->heap_size--;
	min_heapify (h, 0);

	return root;

}

void
delete (heap_t *h, int i)
{

	decrease_key (h, i,INT_MIN);
	extract_min (h);

}

int
main ()
{

	heap_t *h = NULL;

	h = create_heap (11);

	insert (h, 3);
	insert (h, 2);
	delete (h, 1);
	insert (h, 15);
	insert (h, 5);
	insert (h, 4);
	insert (h, 45);

	printf ("Extract Min: %d\n", extract_min (h));
	printf ("Get Min: %d\n", get_min (h));
	decrease_key (h, 2, 1);
	printf ("Get Min: %d\n", get_min (h));
	
}
