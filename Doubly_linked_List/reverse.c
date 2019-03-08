#include <stdio.h>
#include <stdlib.h>

typedef struct list_node_t_ {
	
	int data;
	struct list_node_t_ *prev;
	struct list_node_t_ *next;
} list_node_t;

list_node_t*
create_node (int data) {

	list_node_t *new_node = NULL;

	new_node = malloc(sizeof(list_node_t));

	if (!new_node)
		return NULL;

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
reverse_list (list_node_t **head) {

	list_node_t *temp = NULL;
	list_node_t *curr = NULL;

	curr = *head;
	while (curr != NULL) {
		temp = curr->prev;
		curr->prev = curr->next;
		curr->next = temp;
		curr = curr->prev;
	}

	if (temp != NULL) {
		*head = temp->prev;
	}

}

void
print_list (list_node_t *node) {

	list_node_t *last = NULL;

	printf("Traversal in forward direction\n");
	while (node != NULL) {
		printf("%d ", node->data);
		last = node;
		node = node->next;
	}

	printf("\nTraversal in reverse direction\n");
	while (last != NULL) {
		printf("%d ", last->data);
		last = last->prev;
	}

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

	print_list (head);

	reverse_list (&(head));

	printf("\nAfter Reversal\n");
	print_list(head);

	return 0;

}
