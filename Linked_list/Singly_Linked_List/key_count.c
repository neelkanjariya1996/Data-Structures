#include <stdio.h>
#include <stdlib.h>

#define KEY 2

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

int
key_count (list_node_t *head, int key) {
	
	list_node_t *temp = NULL;
	int count = 0;

	temp = head;
	while (temp) {
		if (temp->data == key) {
			count++;
		}
		temp = temp->next;
	}

	return count;

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

        list_add_at_begin(&(head),2);
        list_add_at_begin(&(head),2);
        list_add_at_begin(&(head),2);
        list_add_at_begin(&(head),2);
        list_add_at_begin(&(head),2);
        list_add_at_begin(&(head),2);
        list_add_at_begin(&(head),9);
        list_add_at_begin(&(head),8);
        list_add_at_begin(&(head),7);
        list_add_at_begin(&(head),6);
        list_add_at_begin(&(head),5);
        list_add_at_begin(&(head),4);
        list_add_at_begin(&(head),3);
        list_add_at_begin(&(head),2);
        list_add_at_begin(&(head),1);
        list_add_at_begin(&(head),0);

        printf("The created list is: ");
        print_list(head);
        printf("\n");

	printf("The number of times %d appeared in the linked list is: ", KEY);
	printf("%d\n",key_count(head, KEY));

        return 0;

}

