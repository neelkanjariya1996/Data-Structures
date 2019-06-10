#include <stdio.h>
#include <stdlib.h>

typedef struct list_node_t_ {

	int 				data;
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

	new_node->data = data;
	new_node->next = *head;

	list_node_t *temp = NULL;

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

void
split_list (list_node_t *head,
			list_node_t **head1,
			list_node_t **head2)
{

	list_node_t *slow_ptr = NULL;
	list_node_t *fast_ptr = NULL;

	slow_ptr = head;
	fast_ptr = head;

	if (head == NULL)
		return;

	while (fast_ptr->next != head &&
		  fast_ptr->next->next != head) {

		fast_ptr = fast_ptr->next->next;
		slow_ptr = slow_ptr->next;
	}

	if (fast_ptr->next->next == head)
		fast_ptr = fast_ptr->next;

	*head1 = head;

	if (head->next != head)
		(*head2)->next = slow_ptr->next;

	fast_ptr->next = slow_ptr->next;

	slow_ptr->next = head;

}

void
print_list (list_node_t *head)
{

	list_node_t *temp = NULL;

	temp = head;

	if (head != NULL) {
		do {
			printf("%d ", temp->data);
			temp =temp->next;
		} while (temp != head);	
	}

	printf("\n");
}

int
main ()
{

	list_node_t *head 	= NULL;
	list_node_t *head1 	= NULL;
	list_node_t *head2 	= NULL;

	push(&(head), 0);
	push(&(head), 1);
	push(&(head), 2);
	push(&(head), 3);
	push(&(head), 4);

	print_list (head);

	split_list (head, &head1, &head2);

	printf("Original List: ");
	print_list (head);

	printf("First circular list: ");
	print_list (head1);

	printf("Second circular list: ");
	print_list (head2);

	return 0;

}
