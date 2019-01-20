#include <stdio.h>
#include <stdlib.h>

typedef struct list_node_t_ {
        int data;
        struct list_node_t_ *next;
} list_node_t;

list_node_t*
create_node (int data) {

        list_node_t *new_node = NULL;

        new_node = malloc(sizeof(list_node_t));

        if(!new_node)
                return NULL;

        new_node->data = data;
        new_node->next = NULL;

        return new_node;
}

void
list_add_at_begin (list_node_t **head, int data) {

        list_node_t *new_node = NULL;
        list_node_t *temp = NULL;

        new_node = create_node(data);

        if(!(*head)) {
                *head = new_node;
                return;
        }

        temp = *head;
        *head = new_node;
        new_node->next = temp;

}

void
last_to_first(list_node_t **head) {

	list_node_t *temp = NULL;
	list_node_t *temp1 = NULL;

	temp = *head;
	if (*head == NULL || temp->next == NULL)
		return;

	while (temp->next != NULL) {
		temp1 = temp;
		temp = temp->next;
	}

	temp1->next = NULL;
	temp->next = *head;
	*head = temp;

}

void
print_list(list_node_t *node) {

        while(node != NULL) {
                printf("%d ", node->data);
                node = node->next;
        }

}

int
main () {

        list_node_t *head = NULL;

        list_add_at_begin(&(head),4);
        list_add_at_begin(&(head),3);
        list_add_at_begin(&(head),2);
        list_add_at_begin(&(head),1);
        list_add_at_begin(&(head),0);


        printf("The created list is: ");
        print_list(head);
        printf("\n");

	printf("Shifting last element to first: ");
	last_to_first(&head);
	print_list(head);
	printf("\n");
	return 0;

}
