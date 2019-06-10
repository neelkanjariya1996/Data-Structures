#include <stdio.h>
#include <stdlib.h>

typedef struct list_node_t_ {

	int 			data;
	struct list_node_t_ 	*prev;
	struct list_node_t_ 	*next;
} list_node_t ;

list_node_t*
create_node (int data) {

	list_node_t *new_node = NULL;

	new_node = malloc(sizeof(list_node_t));

	if (!new_node) {
		return NULL;
	}

	new_node->data = data;
	new_node->prev = NULL;
	new_node->next = NULL;

	return new_node;

}

void
push (list_node_t **head, int data) {

	list_node_t *new_node = NULL;

	new_node = create_node(data);

	new_node->next = *head;
	new_node->prev = NULL;

	if (!(*head)) {
		*head = new_node;
		return;
	}

	if ((*head) != NULL) {
		(*head)->prev = new_node;
	}

	*head = new_node;

}

void
triplet_count (list_node_t **head, int x) {

	int sum			= 0;
	int found		= 0;
	int trip_count		= 0;
	list_node_t *curr 	= NULL;
	list_node_t *first 	= NULL;
	list_node_t *last 	= NULL;

	curr 	= *head;
	first	= *head;
	last	= *head;
	while (last->next != NULL) {
		last = last->next;
	}
	
	if ((*head) == NULL) {
		printf("List Empty and thus no pairs are there\n");
		return;
	}

	while (curr != NULL) {
		sum = x - curr->data;
		first = curr->next;
		while (first != NULL && last != NULL && 
		       last != first && last->next != first &&
		       first->next != NULL && last->prev != NULL &&
		       last->next != first->next) {
			
			if ((first->data + last->data) == sum) {
				found = 1;
				printf("(%d, %d, %d)\n", curr->data, first->data, last->data);
				trip_count++;
				first = first->next;
				last = last->prev;
			} else {
				if ((first->data + last->data) < sum) {
					first = first->next;
				} else {
					last = last->prev;
				}
			}
		}
		curr = curr->next;
	}

	if (found == 1) {
		printf("Number of triplets: %d\n", trip_count);
	} else if (found == 0) {
		printf("No pair found\n");
	}

}

void
foursum (list_node_t **head, int x) {

	int sum1 		= 0;
	int sum2		= 0;
	int found 		= 0;
	int four_count		= 0;
	list_node_t *curr	= NULL;
	list_node_t *curr1 	= NULL;
	list_node_t *first	= NULL;
	list_node_t *last	= NULL;

	curr 	= *head;
	curr1	= *head;
	first	= *head;
	last	= *head;
	while (last->next != NULL) {
		last = last->next;
	}

	while (curr != NULL) {
		sum1 = x - curr->data;
		curr1 = curr->next;
		while (curr1 != NULL) {
			sum2 = sum1 - curr1->data;
			first = curr1->next;
			while (first != NULL && last != NULL && 
				last != first && last->next != first &&
				first->next != NULL && last->prev != NULL &&
				last->next != first->next) {
					
				if ((first->data + last->data) == sum2) {
					found = 1;
					printf("(%d, %d, %d, %d)\n", curr->data, curr1->data, first->data, last->data);
					four_count++;
					first = first->next;
					last = last->prev;
				} else {
					if ((first->data + last->data) < sum2) {
						first = first->next;
					} else {
						last = last->prev;
					}
				}
			}
			curr1 = curr1->next;
		}
		curr = curr->next;
	}

	if (found == 1) {
		printf("Number of fourpairs: %d\n", four_count);
	} else if (found == 0) {
		printf("No pair found\n");
	}

}

void
print_list (list_node_t *node) {

	while (node != NULL) {
		printf("%d ", node->data);
		node = node->next;
	}
	printf("\n");

}

int
main () {

	list_node_t *head = NULL;

	push (&(head), 5);
	push (&(head), 4);
	push (&(head), 3);
	push (&(head), 2);
	push (&(head), 1);
	push (&(head), 0);

	print_list (head);

	printf("Sum : %d : ", 0);
	triplet_count (&(head), 0);
	printf("Sum : %d : ", 1);
	triplet_count (&(head), 1);
	printf("Sum : %d : ", 2);
	triplet_count (&(head), 2);
	printf("Sum : %d : ", 3);
	triplet_count (&(head), 3);
	printf("Sum : %d : ", 4);
	triplet_count (&(head), 4);
	printf("Sum : %d : ", 5);
	triplet_count (&(head), 5);
	printf("Sum : %d : ", 6);
	triplet_count (&(head), 6);
	printf("Sum : %d : ", 7);
	triplet_count (&(head), 7);
	printf("Sum : %d : ", 8);
	triplet_count (&(head), 8);
	printf("Sum : %d : ", 9);
	triplet_count (&(head), 9);
	printf("Sum : %d : ", 10);
	triplet_count (&(head), 10);
	printf("Sum : %d : ", 11);
	triplet_count (&(head), 11);
	printf("Sum : %d : ", 12);
	triplet_count (&(head), 12);
	printf("Sum : %d : ", 13);
	triplet_count (&(head), 13);

	printf("Sum : 6");
	foursum (&(head), 6);
	printf("Sum : 10");
	foursum (&(head), 10);

	return 0;

}
