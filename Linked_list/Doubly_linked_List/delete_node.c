#include <stdio.h>
#include<stdlib.h>

typedef struct list_node_t_ {
	int data;
	struct list_node_t_ *prev;
	struct list_node_t_ *next;
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

	if (!(*head)) {
		*head = new_node;
		new_node->prev = NULL;
		new_node->next = NULL;
		return;
	}

	new_node->next = *head;
	new_node->prev = NULL;

	if(*head != NULL) {
		(*head)->prev = new_node;
	}

	*head = new_node;

}

void
delete (list_node_t **head, list_node_t *del ) {

	if (*head == NULL || del == NULL) {
		printf("Head and node to be deleted are empty\n");
		return;
	}

	if (*head == del) {
		*head = del->next;
	}

	if (del->next != NULL) {
		del->next->prev = del->prev;
	}

	if (del->prev != NULL) {
		del->prev->next = del->next;
	}

	if (del->next == NULL) {
		del->prev->next = NULL;
	}

	free(del);
	
	return;

}

void
print_list (list_node_t *node) {

	list_node_t *last = NULL;

	printf("Traversal in forward direction:\n");
	while (node != NULL) {
		printf("%d ", node->data);
		last = node;
		node = node->next;
	}
	printf("\n");

	printf("\nTravesal in reverse direction\n");
	while (last != NULL) {
		printf("%d ", last->data);
		last = last->prev;
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

	printf("\nDeleting head\n");
	delete(&(head), head);
	print_list(head);

	printf("\nDeleting from middle\n");
	delete(&(head), head->next);
	print_list(head);
	delete(&(head), head->next);
	print_list(head);
	delete(&(head), head->next);
	print_list(head);

	printf("\nDeleting last node\n");
	delete(&(head), head->next);
	print_list(head);

	return 0;

}
