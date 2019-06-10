#include <stdio.h>
#include <stdlib.h>

typedef struct list_node_t_ {

	int 			data;
	struct list_node_t_	*prev;
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

	new_node = create_node (data);

	if (!(*head)) {
		*head = new_node;
		return;
	}

	if (head != NULL) {
		(*head)->prev = new_node;
		new_node->next = *head;
	}

	*head = new_node;

}

void
rot_dll_by_n (list_node_t **head, int n) {

	list_node_t *new_last 	= NULL;
	list_node_t *new_head	= NULL;
	list_node_t *old_last	= NULL;
	int i			= 0;

	if (n == 0) {
		return;
	}

	if (head == NULL) {
		return;
	}

	old_last = *head;
	i = 1;
	while (old_last->next != NULL) {
		if (i == n) {
			new_last = old_last;
			new_head = new_last->next;
		}
		i++;
		old_last = old_last->next;
	}

	old_last->next 	= *head;
	(*head)->prev 	= old_last;
	new_last->next 	= NULL;
	(*head) 	= new_head;
	new_head->prev 	= NULL;

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

	printf("Original Linked List\n");
	print_list (head);

	printf("Rotating by 0\n");
	rot_dll_by_n (&(head), 0);
	print_list (head);
	printf("Rotating by 1\n");
	rot_dll_by_n (&(head), 1);
	print_list (head);
	printf("Rotating by 2\n");
	rot_dll_by_n (&(head), 2);
	print_list (head);
	printf("Rotating by 3\n");
	rot_dll_by_n (&(head), 3);
	print_list (head);
	printf("Rotating by 4\n");
	rot_dll_by_n (&(head), 4);
	print_list (head);
	printf("Rotating by 5\n");
	rot_dll_by_n (&(head), 5);
	print_list (head);

	return 0;

}
