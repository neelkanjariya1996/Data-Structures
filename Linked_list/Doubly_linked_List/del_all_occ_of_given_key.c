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

	if(!new_node)
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

	if(!(*head)) {
		*head = new_node;
		new_node->next = NULL;
		new_node->prev = NULL;
		return;
	}

	if (head != NULL) {
		(*head)->prev = new_node;
	}

	*head = new_node;

}

void
del_node (list_node_t **head, list_node_t *del) {

	if (*head == NULL || del == NULL) {
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

	free(del);

}

void
del_all_occ_of_key (list_node_t **head, int x) {

	list_node_t *curr = NULL;
	list_node_t *next = NULL;

	if (*head == NULL) {
		return;
	}

	curr = *head;

	while (curr != NULL) {
		if (curr->data == x) {
			next = curr->next;
			del_node(head, curr);
			curr = next;
		} else {
			curr = curr->next;
		}
	}

}

void
print_list (list_node_t *node) {

	while (node != NULL) {
		printf("%d ", node->data);
		node= node->next;
	}
	printf("\n");

}

int
main () {

	list_node_t *head = NULL;

	push(&(head), 5);
	push(&(head), 5);
	push(&(head), 5);
	push(&(head), 4);
	push(&(head), 3);
	push(&(head), 5);
	push(&(head), 5);
	push(&(head), 2);
	push(&(head), 1);
	push(&(head), 5);
	push(&(head), 0);
	push(&(head), 5);

	print_list(head);

	del_all_occ_of_key(&(head), 5);
	printf("After deleting 5\n");
	print_list(head);
	del_all_occ_of_key(&(head), 4);
	printf("After deleting 4\n");
	print_list(head);
	del_all_occ_of_key(&(head), 3);
	printf("After deleting 3\n");
	print_list(head);
	del_all_occ_of_key(&(head), 2);
	printf("After deleting 2\n");
	print_list(head);
	del_all_occ_of_key(&(head), 1);
	printf("After deleting 1\n");
	print_list(head);
	del_all_occ_of_key(&(head), 0);
	printf("After deleting 0\n");
	print_list(head);

	return 0;

}
