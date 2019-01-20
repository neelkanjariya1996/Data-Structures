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
loop_detection (list_node_t **head) {
	
	list_node_t *temp = NULL;
	list_node_t *temp1 = NULL;

	temp = *head;
	temp1 = *head;
	while(temp != NULL) {
		temp = temp->next;
		temp1 = temp1->next->next;
		if (temp == temp1) {
			printf("Loop detected in the list\n");
			return;
		} else if (temp->next == NULL) {
			printf("There is o loop in the list\n");
			return;
		}
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

	printf("Detecting whether or not there is a loop in the list:");
	loop_detection(&head);

        return 0;

}
