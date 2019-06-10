#include <stdio.h>
#include <stdlib.h>

typedef struct list_node_t_ {

	int 	data;
	struct 	list_node_t_ *next;
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

list_node_t*
add_to_empty (list_node_t *last, int data) 
{
	
	if (last != NULL) 
		return last;

	list_node_t *temp = NULL;

	temp = create_node(data);

	temp->data	= data;
	last 		= temp;
	last->next 	= last;

	return last;

}

list_node_t*
add_at_begin (list_node_t *last, int data) 
{
	
	if (last == NULL)
		return add_to_empty (last, data);

	list_node_t *temp = NULL;

	temp = create_node (data);

	temp->data = data;
	temp->next = last->next;
	last->next = temp;

	return last;

}

list_node_t*
add_at_end (list_node_t *last, int data)
{
	
	if (last == NULL) 
		return add_to_empty (last, data);

	list_node_t *temp = NULL;

	temp = create_node (data);

	temp->data 	= data;
	temp->next 	= last->next;
	last->next 	= temp;
	last		= temp;

	return last;

}

list_node_t*
add_in_between (list_node_t *last, int data, int item)
{

	if (last == NULL)
		return NULL;

	list_node_t *temp = NULL;
	list_node_t *prev = NULL;

	prev = last->next;

	do {
		if (prev->data == item) {
			temp 		= create_node (data);
			temp->data 	= data;
			temp->next 	= prev->next;
			prev->next 	= temp;
			if (prev == last)
				last = temp;
			return last;
		}
		prev = prev->next;
	} while (prev != last->next);

	printf("%d not present in the list\n", item);
	
	return last;

}

void
print_list (list_node_t *last) 
{
	if (last == NULL) {
		printf("List is empty\n");
		return;
	}
	
	list_node_t *temp = NULL;

	temp = last->next;

	do {
		printf("%d ", temp->data);
		temp = temp->next;
	} while (temp != last->next);

	printf("\n");

}

int
main () {

	list_node_t *last = NULL;

	last = add_to_empty (last, 1);
	print_list (last);

	last = add_in_between (last, -3, 1);
	print_list (last);

	last = add_at_end (last, -2);
	print_list (last);
	
	last = add_at_begin (last, -1);
	print_list (last);

	last = add_at_begin (last, 0);
	print_list (last);

	last = add_at_end (last, 3);
	print_list (last);

	last = add_in_between (last, 2, 1);
	print_list (last);

	last = add_in_between (last, 4, 3);
	print_list (last);

	return 0;

}
