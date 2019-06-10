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

	new_node = malloc (sizeof (list_node_t));

	if (!new_node)
		return NULL;

	new_node->data = data;
	new_node->next = NULL;

	return new_node;

}

void
push (list_node_t **head, int data)
{

	list_node_t *new_node 	= NULL;
	list_node_t *temp		= NULL;

	new_node 		= create_node (data);
	new_node->next 	= *head;
	
	temp = *head;
	if (*head != NULL) {
	
		while (temp->next != *head)
			temp = temp->next;

		temp->next = new_node;
	} else {
	
		new_node->next = new_node;
	}

	*head = new_node;

}

int
node_count (list_node_t *head)
{

	int count			= 0;
	list_node_t *temp 	= NULL;

	if (head == NULL)
		return 0;

	temp = head;
	if (head != NULL) {

		do {

				count++;
				temp = temp->next;
		} while (temp != head);
	}

	return count;

}

void
print_list (list_node_t *head)
{
	
	list_node_t *temp = NULL;

	temp = head;
	if (head != NULL) {

		do {

				printf("%d ", temp->data);
				temp = temp->next;
		} while (temp != head);
	}
	printf("\n");

}

int
main () 
{
	
	list_node_t *head   = NULL;
	int count			= 0;

	push (&(head), 0);
	push (&(head), 1);
	push (&(head), 2);
	push (&(head), 3);
	push (&(head), 4);
	push (&(head), 5);

	print_list (head);

	count = node_count (head);
	printf("The number of nodes in the list = %d \n", count);

	return 0;

}
