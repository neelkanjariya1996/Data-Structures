#include <stdio.h>
#include <stdlib.h>

typedef struct list_node_t_ {

	int 			data;
	struct list_node_t_ 	*prev;
	struct list_node_t_	*next;
} list_node_t ;

int size_dll = 0;

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

	if ((*head) == NULL) {
	       *head = new_node;
		return;
	}

	if ((*head) != NULL) {
		(*head)->prev = new_node;
	}

	*head = new_node;

}

void
length (list_node_t *node) {

	while (node != NULL) {
		size_dll++;
		node = node->next;
	}

}

void
del_node_at_pos (list_node_t **head, int pos) {

	list_node_t *temp = NULL;
	
	if ((*head) == NULL || size_dll == 0) {
		printf("List Empty\n");
		return;
	}

	if (pos > size_dll || pos < 0) {
		printf("Position exceeds the size of DLL\n");
		return;
	}

	if ((*head) != NULL && pos == 1 && (*head)->next == NULL) {
		temp = *head;
		size_dll--;
		free (temp);
		return;
	}
	
	if ((*head) != NULL && pos == 1 && (*head)->next != NULL) {
		temp = *head;
		temp->next->prev = NULL;
		*head = temp->next;
		size_dll--;
		free (temp);
		return;
	}
	
	if ((*head) != NULL && pos > 1 && pos < size_dll) {
		temp = *head;
		while (temp != NULL) {
			temp = temp->next;
			pos--;
			if (pos == 1) {
				temp->next->prev = temp->prev;
				temp->prev->next = temp->next;
				size_dll--;
				free (temp);
				return;
			}
		}
	}

	if ((*head) != NULL && pos == size_dll) {
		temp = *head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->prev->next = NULL;
		size_dll--;
		free (temp);
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
	push (&(head), 3);
	push (&(head), 2);
	push (&(head), 1);
	push (&(head), 0);

	print_list (head);

	length (head);

	printf("Deleting head\n");
	del_node_at_pos ((&head), 1);
	print_list (head);

	printf("Deleting middle node\n");
	del_node_at_pos ((&head), 3);
	print_list (head);
	
	printf("Deleting last node\n");
	del_node_at_pos ((&head), 4);
	print_list (head);

	printf("Deleting last node\n");
	del_node_at_pos ((&head), 3);
	print_list (head);
	
	printf("Deleting last node\n");
	del_node_at_pos ((&head), 2);
	print_list (head);

	printf("Deleting last node\n");
	del_node_at_pos ((&head), 1);
	print_list (head);

	printf("Number of elements in list: %d\n", size_dll);
	printf("Deleting node which does not exist\n");
	del_node_at_pos ((&head), 10);
	print_list (head);
	
	printf("Deleting last node\n");
	del_node_at_pos ((&head), 1);
	print_list (head);
	
	return 0;

}
