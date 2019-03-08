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
sorted_insert (list_node_t **head, int data) {

	list_node_t *node = NULL;
	list_node_t *curr = NULL;
	
	node = create_node (data);

	if ((*head) == NULL) {
		*head = node;
		return;
	} else if ((*head)->data >= node->data) {
		node->next = *head;
		node->prev = NULL;
		(*head)->prev = node;
		*head = node;
		return;
	} else {
		curr = *head;
		while (curr->next != NULL && curr->next->data < node->data) {
			curr = curr->next;
		}
			node->next = curr->next;
			if (curr->next != NULL) {
				node->next->prev = node;
			}
			curr->next = node;
			node->prev = curr;			
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
	push (&(head), 2);
	push (&(head), 1);

	print_list (head);

	printf("Inserting 0: ");
	sorted_insert (&(head), 0);
	print_list (head);

	printf("Inserting 3: ");
	sorted_insert (&(head), 3);
	print_list (head);
	
	printf("Inserting 6: ");
	sorted_insert (&(head), 6);
	print_list (head);

	return 0;

}
