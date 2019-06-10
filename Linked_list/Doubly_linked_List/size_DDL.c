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

	new_node->next = (*head);
	new_node->prev = NULL;

	if (!(*head)) {
		*(head) = new_node;
		return;
	}

	if (head != NULL) {
		(*head)->prev = new_node;
	}

	*head = new_node;

}

void
size_dll (list_node_t *node) {

	int count = 0;

	while (node != NULL) {
		if (node == NULL) {
			printf("The size of the doubly linked list is 0\n");
			return;
		}

		count++;
		node = node->next;
	}

	printf("The size of the doubly linked list is: %d\n", count);

	return;

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
	
	size_dll(head);

	return 0;

}
