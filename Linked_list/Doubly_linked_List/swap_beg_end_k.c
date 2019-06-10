#include <stdio.h>
#include <stdlib.h>

typedef struct list_node_t_ {

	int 			data;
	struct list_node_t_	*prev;
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
		new_node->next	= (*head);
		(*head)->prev 	= new_node;
		*head 		= new_node;
		return;
	}

}

void
swap_beg_end_k (list_node_t **head, int k) {

	list_node_t *temp 	= NULL;
	list_node_t *x		= NULL;
	list_node_t *x_prev	= NULL;
	list_node_t *y		= NULL;
	list_node_t *y_prev	= NULL;
	int size		= 0;
	int i			= 0;

	if ((*head) == NULL) {
		printf("List Empty\n");
		return;
	}
	
	temp = *head;
	while (temp != NULL) {
		size++;
		temp = temp->next;
	}
	
	if ((2*k - 1) == size) {
		return;
	}

	if (k > size) {
		printf("K is greater than the size of doubly linked list\n");
		return;
	}

	x 	= *head;
	x_prev 	= NULL;
	for (i = 1; i < k; i++) {
		x_prev 	= x;
		x 	= x->next;
	}
	
	y	= *head;
	y_prev	= NULL;
	for (i = 1; i < (size - k + 1); i++) {
		y_prev 	= y;
		y	= y->next;
	}

	if (x_prev) {
		x_prev->next = y;
	}

	if (y_prev) {
		y_prev->next = x;
	}

	temp 	= x->next;
	x->next = y->next;
	y->next = temp;

	if (k == 1) {
		*head = y;
	}

	if (k == size) {
		*head = x;
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

	push ((&head), 8);
	push ((&head), 7);
	push ((&head), 6);
	push ((&head), 5);
	push ((&head), 4);
	push ((&head), 3);
	push ((&head), 2);
	push ((&head), 1);

	print_list (head);

	printf("K = 1: ");
	swap_beg_end_k ((&head), 1);
	print_list (head);

	printf("K = 2: ");
	swap_beg_end_k ((&head), 2);
	print_list (head);
	
	printf("K = 3: ");
	swap_beg_end_k ((&head), 3);
	print_list (head);

	printf("K = 4: ");
	swap_beg_end_k ((&head), 4);
	print_list (head);
	
	printf("K = 5: ");
	swap_beg_end_k ((&head), 5);
	print_list (head);

	printf("K = 6: ");
	swap_beg_end_k ((&head), 6);
	print_list (head);

	printf("K = 7: ");
	swap_beg_end_k ((&head), 7);
	print_list (head);

	printf("K = 8: ");
	swap_beg_end_k ((&head), 8);
	print_list (head);

	return 0;

}
