#include <stdio.h>
#include <stdlib.h>

typedef struct list_node_t_ {

	int 			data;
	struct list_node_t_	*prev;
	struct list_node_t_	*next;
} list_node_t ;

list_node_t*
create_node (int data) {

	list_node_t *new_node = NULL;

	new_node = malloc (sizeof(list_node_t));

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

	new_node->next = *head;
	new_node->prev = NULL;

	if(!(*head)) {
		*head = new_node;
		return;
	}

	if ((*head) != NULL) {
		(*head)->prev = new_node;
	}

	*head = new_node;

}
void
rem_dup (list_node_t **head) {
	
	list_node_t *temp = NULL;
        list_node_t *temp1 = NULL;
        list_node_t *dup = NULL;

        temp = *head;
        while (temp != NULL && temp->next != NULL) {
                temp1 = temp;
                while (temp1->next != NULL) {
                        if (temp->data == temp1->next->data) {
                                dup = temp1->next;
                                temp1->next = temp1->next->next;
                                free(dup);
                        } else
                                temp1 = temp1->next;
                }
                temp = temp->next;
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
	push (&(head), 1);
	push (&(head), 5);
	push (&(head), 1);
	push (&(head), 5);
	push (&(head), 4);
	push (&(head), 5);
	push (&(head), 5);
	push (&(head), 4);
	push (&(head), 3);
	push (&(head), 2);
	push (&(head), 4);
	push (&(head), 1);
	push (&(head), 5);
	push (&(head), 5);
	push (&(head), 4);
	push (&(head), 1);
	push (&(head), 0);
	push (&(head), 4);
	push (&(head), 1);
	push (&(head), 1);
	push (&(head), 1);
	push (&(head), 5);

	print_list (head);

	rem_dup (&(head));

	print_list (head);
	
	return 0;

}
