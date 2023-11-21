/* 
	A linked list
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct List_Node {
	int value;
	struct List_Node *next;
} List_Node;

void print_list (List_Node node) {
	List_Node *node_ref = &node;
	while (node_ref != NULL) {
		printf("%d\t", node_ref->value);
		node_ref = node_ref->next;
	}

	printf("\n");

	return;
}

List_Node *init_linked_list () {
	int initial_input = 0;
	List_Node *head_node = (List_Node *) malloc(sizeof(List_Node));

	scanf("%d", &initial_input);

	head_node->value = initial_input;
	head_node->next = NULL;

	return head_node;
}

List_Node *create_linked_list (int size) {
	List_Node *head = init_linked_list();

	size--;

	for (int i = 0; i < size; i++) {
		int input = 0;
		List_Node *new_node = (List_Node *) malloc(sizeof(List_Node));

		scanf("%d", &input);

		new_node->value = input;
		new_node->next = head;

		head = new_node;
	}

	return head;
}

int main (void) {
	int size = 0;
	List_Node *list;

	scanf("%d", &size);

	list = create_linked_list(size);

	print_list(*list);

	return 0;
}
