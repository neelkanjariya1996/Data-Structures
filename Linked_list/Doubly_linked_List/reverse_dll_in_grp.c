#include <stdio.h>
#include <stdlib.h>

typedef struct list_node_t_ {

	int 			data;
	struct list_node_t_ 	*prev;
	struct list_node_t_	*next;
} list_node_t;

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

	new_node = create_node (data);

	if ((*head) == NULL) {
		*head = new_node;
		return;
	}

	if ((*head) != NULL) {
		new_node->next 	= *head;
		(*head)->prev 	= new_node;
		*head 		= new_node;
	}

}

void
reverse_dll_in_grp (list_node_t **head, int k) {

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

	push ((&head), 5);
	push ((&head), 4);
	push ((&head), 3);
	push ((&head), 2);
	push ((&head), 1);
	push ((&head), 0);

	print_list (head);

	return 0;

}
