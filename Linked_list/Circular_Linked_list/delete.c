#include <stdio.h>
#include <stdlib.h>

typedef struct list_node_t_ {

	int					data;
	struct list_node_t_ *next;
} list_node_t;

list_node_t*
create_node (int data)
{

	list_node_t *new_node = NULL;

	new_node = malloc(sizeof(list_node_t));

	if (!new_node)
		return NULL;

	new_node->data = data;
	new_node->next = NULL;

	return new_node;

}

void
push (list_node_t **head, int data)
{

	list_node_t *new_node = NULL;

	new_node = create_node (data);

	new_node->next = *head;

	list_node_t *temp 	= NULL;
	temp 				= *head;

	if ((*head) != NULL) {

		while (temp->next != *head) {
			temp = temp->next;
		}
		temp->next = new_node;
		
	} else {

		new_node->next = new_node;

	}

	*head = new_node;

}

void
delete_node (list_node_t *head, int key)
{
	
	if (head == NULL)
		return;	

	list_node_t *curr = NULL;
	list_node_t *prev = NULL;

	curr = head;
	while (curr->data != key) {
	
		if (curr->next == head) {
			printf("key to be deleted is not present in the list\n");
			break;
		}

		prev = curr;
		curr = curr->next;

	}

	if (curr->next == head && prev == head) {

		head = NULL;
		free(curr);
		return;

	}
			
	if (curr == head) {

		prev = head;
		while (prev->next != curr)
			prev = prev->next;

		head 		= curr->next;
		prev->next 	= curr->next;
		free(curr);

	} else if (curr->next == head) {
	
		prev->next = head;
		free(curr);

	} else {

		prev->next = curr->next;
		free(curr);

	}

}

void
print_list (list_node_t *head)
{

	list_node_t *temp = NULL;

	if (head != NULL) {
	
		temp = head;
		do {
			
			printf("%d ", temp->data);
			temp = temp->next;

		} while (temp != head);
		
		printf("\n");
	}

}

int 
main () 
{

	list_node_t *head = NULL;

	push (&(head), 0);
	push (&(head), 1);
	push (&(head), 2);
	push (&(head), 3);
	push (&(head), 4);
	push (&(head), 5);

	print_list (head);

	delete_node (head, 0);
	print_list (head);
/*	
	delete_node (head, 5);
	print_list (head);
*/
	delete_node (head, 2);
	print_list (head);
	
	delete_node (head, 3);
	print_list (head);
	
	delete_node (head, 1);
	print_list (head);
	
	delete_node (head, 4);
	print_list (head);

	return 0;

}
