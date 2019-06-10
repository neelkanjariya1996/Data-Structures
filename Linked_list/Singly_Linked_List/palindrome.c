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
list_add_at_end (list_node_t **head, int data) {

        list_node_t *new_node = NULL;
        list_node_t *temp = NULL;

        new_node = create_node(data);

        if(!(*head)) {
                *head = new_node;
                return;
        }

        temp = *head;
        while (temp->next) {
                temp = temp->next;
        }

        temp->next = new_node;

}

int
list_length (list_node_t *head) {

	list_node_t *temp = NULL;
	int len = 0;

	temp = head;
	while (temp) {
		len++;
		temp = temp->next;
	}

	return len;
}

void
palindrome_check (list_node_t *head, int len) {
	
	list_node_t *temp = NULL;
	int i = 0;
	int array[len] ; 

	temp = head;	
	while (temp) {
		array[i] = temp->data;
		i++;
		temp = temp->next;
	}

	temp = head;
	while (temp) {
		if (array[len-1] != temp->data) {
			printf("List is not a palindrome\n");
			return;
		}
		temp = temp->next;
		len--;
	}

	printf("List is a palindrome\n");

}


void
print_list(list_node_t *node) {

        while (node != NULL) {
                printf("%d ", node->data);
                node = node->next;
        }

}

int
main () {

        list_node_t *head = NULL;
	int len = 0;

        list_add_at_end(&(head), 4);
        list_add_at_end(&(head), 4);
        list_add_at_end(&(head), 3);
        list_add_at_end(&(head), 2);
        list_add_at_end(&(head), 1);
        list_add_at_end(&(head), 0);
        list_add_at_end(&(head), 0);
        list_add_at_end(&(head), 1);
        list_add_at_end(&(head), 2);
        list_add_at_end(&(head), 3);
        list_add_at_end(&(head), 4);
        list_add_at_end(&(head), 4);
        printf("The created list is : ");
        print_list(head);
        printf("\n");

	len = list_length(head);
	printf("The length of the list is : %d\n", list_length(head));

	printf("Checking whether or not the list is palindrome: ");
	palindrome_check(head, len);

        return 0;
}

