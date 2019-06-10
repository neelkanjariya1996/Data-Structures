#include <stdio.h>
#include <stdlib.h>

typedef struct list_node_t_ {

	int 			data;
	int			priority;
	struct list_node_t_ 	*prev;
	struct list_node_t_	*next;
} list_node_t;

list_node_t*
create_node (int data, int priority) {

	list_node_t *new_node = NULL;

	new_node = malloc(sizeof(list_node_t));

	if (!new_node) {
		return NULL;
	}

	new_node->data 		= data;
	new_node->priority 	= priority;
	new_node->prev 		= NULL;
	new_node->next 		= NULL;

	return new_node;

}

void
push (list_node_t **head, int data, int priority) {

	list_node_t *new_node 	= NULL;
	list_node_t *temp	= NULL;
	list_node_t *temp1	= NULL;

	new_node = create_node (data, priority);

	if ((*head) == NULL) {
		*head = new_node;
		return;
	}

	if ((*head) != NULL && (*head)->next == NULL) {
		if ((*head)->priority <= new_node->priority) {
			(*head)->next 	= new_node;
			new_node->prev 	= *head;
			new_node->next	= NULL;
			return;
		} else {
			new_node->next 	= *head;
			(*head)->prev	= new_node;
			*head		= new_node;
		}
		return;
	}

	if ((*head) != NULL && (*head)->next != NULL) {
		temp = *head;
		while (temp != NULL && temp->next != NULL) {
			if (temp->priority <= new_node->priority &&
			   temp->next->priority > new_node->priority &&
			   temp->next != NULL) { 
				temp1           = temp->next;
                                temp->next      = new_node;
                                new_node->prev  = temp;
                                new_node->next  = temp1;
                                temp1->prev     = new_node;
                                return;

			}
			if (temp->priority > new_node->priority) {
				new_node->next  = temp;
                                temp->prev      = new_node;
                                *head           = new_node;
                                return;
			}
			temp = temp->next;
		}
	}

	temp = *head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	if (temp->priority <= new_node->priority &&
	   temp->next == NULL) {
		temp->next 	= new_node;
		new_node->prev 	= temp;
		new_node->next	= NULL;
		return;
	}

}

void
pop (list_node_t **head) {

	list_node_t *temp = NULL;

	if ((*head) == NULL) {
		printf("List is empty\n");
		return;
	}

	if ((*head)->next != NULL) {
		temp 		= *head;
		*head 		= temp->next;
		(*head)->prev 	= NULL;
		printf("Popping %d \n", temp->data);
		free (temp);
		return;
	}

	if ((*head)->next == NULL) {
		printf("Popping %d \n", (*head)->data);
		free (*head);
		return;
	}

}

void
peek (list_node_t **head) {

	if ((*head) == NULL) {
		printf("List Empty\n");
		return;
	}

	if ((*head) != NULL) {
		printf("%d \n", (*head)->data);
		return;
	}

}

void
print_list (list_node_t *node) {

	if (node == NULL) {
		printf("List empty\n");
		return;
	}

	while (node != NULL) {
		printf("%d(%d) ", node->data, node->priority);
		node = node->next;
	}
	printf("\n");

}

int
main () {

	list_node_t *head = NULL;

	push ((&head), 0, 0);
	print_list (head);
	push ((&head), 3, 3);
	print_list (head);
	push ((&head), 2, 2);
	print_list (head);
	push ((&head), 6, 6);
	print_list (head);
	push ((&head), 2, 2);
	print_list (head);
	push ((&head), 3, 3);
	print_list (head);
	push ((&head), 7, 7);
	print_list (head);
	push ((&head), 0, 0);
	print_list (head);
	push ((&head), 4, 4);
	print_list (head);
	push ((&head), 1, 1);
	print_list (head);
	push ((&head), 5, 5);
	print_list (head);

	printf("Peeking\n");
	peek (&(head));

	printf("\nPopping\n");
	pop (&(head));//0
	printf("Peeking\n");
	peek (&(head));
	pop (&(head));//0
	printf("Peeking\n");
	peek (&(head));
	pop (&(head));//1
	printf("Peeking\n");
	peek (&(head));
	pop (&(head));//2
	printf("Peeking\n");
	peek (&(head));
	pop (&(head));//2
	printf("Peeking\n");
	peek (&(head));
	pop (&(head));//3
	printf("Peeking\n");
	peek (&(head));
	pop (&(head));//3
	printf("Peeking\n");
	peek (&(head));
	pop (&(head));//4
	printf("Peeking\n");
	peek (&(head));
	pop (&(head));//5
	printf("Peeking\n");
	peek (&(head));
	pop (&(head));//6
	printf("Peeking\n");
	peek (&(head));
	pop (&(head));//7
	printf("Peeking\n");
	peek (&(head));

	//print_list (head);
	
	return 0;

}
