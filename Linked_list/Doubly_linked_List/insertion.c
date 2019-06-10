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

	if(!new_node)
		return NULL;

	new_node->data = data;
	new_node->prev = NULL;
	new_node->next = NULL;
	
	return new_node;

}

void
push(list_node_t **head, int data) {

	list_node_t *new_node = NULL;

	new_node = create_node(data);

	new_node->next = (*head);
	new_node->prev = NULL;

	if(!(*head)) {
		*head = new_node;
		return;
	}

	if(head != NULL) {
		(*head)->prev = new_node;
	}

	*head = new_node;

}

void
insert_after (list_node_t *prev_node, int data) {
	
	if(prev_node == NULL) {
		printf("Previous node cannnot be NULL\n");
		return;
	}

	list_node_t *new_node = NULL;

	new_node = create_node(data);

	new_node->next = prev_node->next;
	new_node->prev = prev_node;
	prev_node->next = new_node;
	if (new_node->next != NULL) {
		new_node->next->prev = new_node;
	}

} 

void
append (list_node_t **head, int data) {

	list_node_t *new_node =NULL;
	list_node_t *last = NULL;

	new_node = create_node(data);

	new_node->next = NULL;

	if(*head == NULL) {
		new_node->prev = NULL;
		*head = new_node;
		return;
	}

	last = *head;
	while (last->next != NULL) {
		last = last->next;
	}

	last->next = new_node;

	new_node->prev = last;

}

void
insert_before (list_node_t **head, list_node_t *next_node, int data) {

	if (next_node == NULL) {
		printf("Next node cannot be NULL\n");
		return;
	}

	list_node_t *new_node = NULL;

	new_node = create_node(data);
	
	new_node->prev = next_node->prev;
	new_node->next = next_node;
	next_node->prev = new_node;
	if(new_node->prev != NULL) {
		new_node->prev->next = new_node;
	} else if (new_node->prev == NULL) {
		*head = new_node;
	}
		
}

void
print_list(list_node_t *node) {

	list_node_t *last = NULL;

	printf("Traversal in forward direction\n");
	while(node != NULL) {
		printf("%d ", node->data);
		last = node;
		node = node->next;
	}

	printf("\nTraversal in reverse direction\n");
	while(last != NULL) {
		printf("%d ", last->data);
		last = last->prev;
	}
}

int
main () {

	list_node_t *head = NULL;

	printf("Appending:\n");
	append(&(head), 0);
	append(&(head), 1);
	append(&(head), 2);
	append(&(head), 3);
	append(&(head), 4);
	append(&(head), 5);

	print_list(head);

	printf("\nPushing:\n");
	push(&(head), -5);
	push(&(head), -4);
	push(&(head), -3);
	push(&(head), -2);
	push(&(head), -1);
	push(&(head), 0);

	print_list(head);
	
	printf("\nInserting After:\n");
	insert_after(head, 10);
	insert_after(head->next, 20);
	insert_after(head->next->next, 30);
	insert_after(head->next->next->next, 40);
	insert_after(head->next->next->next->next, 50);

	print_list(head);
	
	printf("\nInserting Before\n");
	insert_before(&head, head, 100);
	insert_before(&head, head->next, 200);
	insert_before(&head, head->next->next, 300);
	insert_before(&head, head->next->next->next, 400);
	insert_before(&head, head->next->next->next->next, 500);

	print_list(head);

	return 0;

}
