#include <stdio.h>
#include <stdlib.h>

typedef struct list_node_t_ {
       int data;
       struct  list_node_t_ *next;
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
list_add_at_end (list_node_t **head, int data) {

        list_node_t *new_node = NULL;
        list_node_t *temp = NULL;

        new_node = create_node(data);

        if(!(*head)) {
                *head = new_node;
                return;
        }

        temp = *head;
        while(temp->next) {
                temp = temp->next;
        }

        temp->next = new_node;
}

void
print_list (list_node_t *node) {

        while(node != NULL) {
                printf("%d ", node->data);
                node = node->next;
        }
	printf("\n");

}

void
merge_list (list_node_t *head1, list_node_t *head2) {

	list_node_t *head = NULL;
	list_node_t *temp = NULL;

	if (head1->data < head2->data) {
		head = head1;
		head1 = (head1)->next;
		head->next = NULL;
	} else if (head1->data > head2->data) {
		head = head2;
		head2 = (head2)->next;
		head->next = NULL;
	}
	temp = head;

	while (head1 != NULL && head2 != NULL) {
		if (head1 == NULL) {
			temp->next = head2;
			break;
		} else if (head2 == NULL) {
			temp->next = head1;
			break;
		}
		if (head1->data < head2->data) {
			temp->next = head1;
			head1 = (head1)->next;
		} else if (head1->data > head2->data) {
			temp->next = head2;
			head2 = (head2)->next;
		}
		temp = temp->next;	
	}

	printf("Merged list: ");
	print_list (head);

}

int
main () {

	list_node_t *head1 = NULL;
	list_node_t *head2 = NULL;

	list_add_at_end (&(head1), 0);
	list_add_at_end (&(head1), 8);
	list_add_at_end (&(head1), 10);
	list_add_at_end (&(head1), 12);

	print_list (head1);

	list_add_at_end (&(head2), 1);
	list_add_at_end (&(head2), 7);
	list_add_at_end (&(head2), 9);
	list_add_at_end (&(head2), 11);

	print_list (head2);

	merge_list ((head1), (head2));

	return 0;

}
