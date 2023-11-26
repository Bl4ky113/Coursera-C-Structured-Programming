/* 
	Program that:
		Takes a linked list and sorts it using Bubble Sort
*/

#include <stdio.h>
#include <stdlib.h>

// Size of the number list
#define SIZE_LIST 100
#define NUMBER_RANGE 256

// Node Struct for a LinkedList
typedef struct Node {
	int value;
	struct Node *next;
} Node;

/**
	* Function that prints a LinkedList's Elements
	* @param{Node} node: Node Element. NOT A POINTER
	* @return{void}
 	**/
void print_list (Node node) {
	Node *node_ref = &node;
	int i = 0;

	while (node_ref != NULL) {
		printf("%d\t", node_ref->value);
		node_ref = node_ref->next;

		i++;

		if (i % 5 == 0) {
			printf("\n");
		}
	}

	printf("\n");

	return;
}

/**
	* Function that creates a Node for a LinkedList
	* param{int} value: value of the node
	* @return{Node*} pointer of the new node
	**/
Node *create_linked_list_node (int value) {
	Node *head_node = (Node *) malloc(sizeof(Node));

	head_node->value = value;
	head_node->next = NULL;

	return head_node;
}

/**
	* Function that creates a LinkedList by using an input file 
	* with the numbers of the list
	* @param{int} size: size of the LinkedList's Input File
	* @return{Node*} pointer of the HEAD of the LinkedList
	**/
Node *create_linked_list_file (int size) {
	Node *head = NULL;
	FILE *numbers_file;

	numbers_file = fopen("./file_input", "r");

	for (int i = 0; i < size; i++) {
		int number = 0;
		fscanf(numbers_file, "%d", &number);

		Node *node = create_linked_list_node(number);

		node->next = head;

		head = node;
	}

	return head;
}

Node *create_linked_list_random (int size) {
	Node *head = NULL;
	unsigned int random_seed = rand();

	for (int i = 0; i < size; i++) {
		int number = rand_r(&random_seed) % NUMBER_RANGE;

		Node *node = create_linked_list_node(number);

		node->next = head;

		head = node;
	}

	return head;
}

/**
	* Function that sorts a given LinkedList, by pointer, 
	* using a bubble sort algorithm
	* @param{Node*} list_head: pointer of the HEAD from the LinkedList
	* @return{Node*} pointer to the same HEAD of the LinkedList
	**/
Node *sort_linked_list (Node *list_head) {
	Node *node_i = list_head;

	// Double loop, or O(n^2), in order to check each posible combination
	while (node_i->next != NULL) {
		Node *node_j = list_head;
		
		while (node_j->next != NULL) {		
			int value_1 = node_j->value;
			int value_2 = node_j->next->value;

			if (value_1 <= value_2) {
				node_j->value = value_2;
				node_j->next->value = value_1;
			}

			node_j = node_j->next;
		}

		node_i = node_i->next;
	}

	return list_head;
}

int main (void) {
	Node *list;

	list = create_linked_list_random(SIZE_LIST);

	print_list(*list);

	list = sort_linked_list(list);

	print_list(*list);

	return 0;
}
