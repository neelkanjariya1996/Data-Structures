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

	if (*head != NULL) {
		(*head)->prev = new_node;
	}

	*head = new_node;

}

void
del_node (list_node_t **head, list_node_t *del) {

	if ((*head) == NULL || del == NULL) {
		return;
	}

	if ((*head) == del) {
		*head = del->next;
	}

	if (del->prev != NULL) {
		del->prev->next = del->next;
	}

	if (del->next != NULL) {
		del->next->prev = del->prev;
	}

	free(del);

}

void
rem_dup (list_node_t **head) {

	if ((*head) == NULL) {
		return;
	}

	list_node_t *temp = NULL;

	temp = *head;
	while (temp->next != NULL) {
		if (temp->data == temp->next->data) {
			del_node(head, temp->next);
		} else {
			temp = temp->next;
		}
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
	push(&(head), 5);
	push(&(head), 5);
	push(&(head), 5);
	push(&(head), 4);
	push(&(head), 4);
	push(&(head), 4);
	push(&(head), 3);
	push(&(head), 3);
	push(&(head), 2);
	push(&(head), 2);
	push(&(head), 1);
	push(&(head), 0);
	push(&(head), 0);
	push(&(head), 0);

	print_list(head);

	rem_dup (&(head));

	print_list(head);

	return 0;

}
