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
sorted_insert (list_node_t **head, int data)
{

	list_node_t *new_node 	= NULL;
	list_node_t *curr		= NULL;

	new_node 	= create_node (data);
	curr		= *head;

	if (curr == NULL) {

		new_node->next  = new_node;
		(*head) 		= new_node;

	} else if (curr->data >= new_node->data) {
		
		while (curr->next != (*head)) {
			curr = curr->next;
		}
		curr->next 		= new_node;
		new_node->next 	= (*head);
		(*head) 		= new_node;

	} else {
	
		while (curr->next != (*head) &&
			  curr->next->data < new_node->data) {
			
			curr = curr->next;
		}
		new_node->next  = curr->next;
		curr->next		= new_node;

	}
}

void
print_list (list_node_t *head)
{

	list_node_t *temp = NULL;

	if ((head) != NULL) {

		temp = head;
		do {

			printf("%d ", temp->data);
			temp = temp->next;

		} while (temp != head);

	}

}

int
main ()
{

	list_node_t *head = NULL;

	sorted_insert (&(head), 5);
	sorted_insert (&(head), 1);
	sorted_insert (&(head), 10);
	sorted_insert (&(head), 2);
	sorted_insert (&(head), 7);

	print_list (head);

	return 0;

}
