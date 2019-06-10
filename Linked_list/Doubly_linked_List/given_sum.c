#include <stdio.h>
#include <stdlib.h>

typedef struct list_node_t_ {

	int 			data;
	struct list_node_t_ 	*prev;
	struct list_node_t_ 	*next;
} list_node_t;

list_node_t*
create_node (int data) {

	list_node_t *new_node = NULL;

	new_node = malloc(sizeof(list_node_t));

	if(!new_node) {
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

	if (head != NULL) {
		(*head)->prev = new_node;
	}

	*head = new_node;

}

void
pair_sum (list_node_t **head, int x) {

	list_node_t *first 	= NULL;
	list_node_t *second 	= NULL;
	int found		= 0;

	first 	= *head;
	second 	= *head;
	while (second->next != NULL) {
		second  = second->next;
	}
	
	while (first->next != NULL && second->prev != NULL && second->next != first->next && second->next != first) {

		if ((first->data + second->data) == x) {
			found = 1;
			printf("(%d, %d)\n", first->data, second->data);
			first 	= first->next;
			second 	= second->prev;
		} else {
			if ((first->data + second->data) < x) {
				first = first->next;
			} else {
				second = second->prev;
			}
		}
	}

	if (found == 0) {
		printf("No pair found");
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

	push(&(head), 5);
	push(&(head), 4);
	push(&(head), 3);
	push(&(head), 2);
	push(&(head), 1);
	push(&(head), 0);

	print_list(head);
	
	printf("Finding pair for 9\n");
	pair_sum(&(head), 9);
	printf("Finding pair for 8\n");
	pair_sum(&(head), 8);
	printf("Finding pair for 7\n");
	pair_sum(&(head), 7);
	printf("Finding pair for 6\n");
	pair_sum(&(head), 6);
	printf("Finding pair for 5\n");
	pair_sum(&(head), 5);
	printf("Finding pair for 4\n");
	pair_sum(&(head), 4);
	printf("Finding pair for 3\n");
	pair_sum(&(head), 3);
	printf("Finding pair for 2\n");
	pair_sum(&(head), 2);
	printf("Finding pair for 1\n");
	pair_sum(&(head), 1);

	return 0;

}
