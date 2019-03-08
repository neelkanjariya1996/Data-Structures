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
rm_duplicates_from_unsorted_list (list_node_t **head) {

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
print_list(list_node_t *node) {

        while(node != NULL) {
                printf("%d ", node->data);
                node = node->next;
        }

}

int
main () {

        list_node_t *head = NULL;
        int len = 0;

        list_add_at_begin(&(head),9);
        list_add_at_begin(&(head),8);
        list_add_at_begin(&(head),6);
        list_add_at_begin(&(head),1);
        list_add_at_begin(&(head),7);
        list_add_at_begin(&(head),6);
        list_add_at_begin(&(head),5);
        list_add_at_begin(&(head),4);
        list_add_at_begin(&(head),7);
        list_add_at_begin(&(head),1);
        list_add_at_begin(&(head),1);
        list_add_at_begin(&(head),7);
        list_add_at_begin(&(head),3);
        list_add_at_begin(&(head),2);
        list_add_at_begin(&(head),7);
        list_add_at_begin(&(head),1);
        list_add_at_begin(&(head),6);
        list_add_at_begin(&(head),0);

        printf("The created list is: ");
        print_list(head);
        printf("\n");

	printf("The new list after removing the duplicates from the unsorted list is: ");
	rm_duplicates_from_unsorted_list(&head);
	print_list(head);
	printf("\n");

	return 0;

}

