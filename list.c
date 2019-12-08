// list/list.c
// 
// Implementation for linked list.
//
// <Torisheju Pessu>

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/*allocates and frees lists*/

list_t *list_alloc() {
    list_t *l;
    l = malloc(sizeof(list_t));
	l->head = NULL;
    return l;
}

void list_free(list_t *l) {
    if (l == NULL){
        return;
    }
    node_t *current_node = l->head;
    node_t *next_node = NULL;
    while (current_node != NULL)
    {
        next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }
    l->head = NULL;
    free(l);
}

/*This function is used to print out the lists*/
void list_print(list_t *l) {
     node_t *current_node = l->head;
    node_t *next_node = NULL;
    while (current_node->next != NULL)
    {
        printf("%d -> ", current_node->value);
        next_node = current_node->next;
        current_node = next_node;
    }
	printf("%d", current_node->value);
	printf("\n");
}

/* This will return lists length*/
int list_length(list_t *l) {
    node_t *current_node = l->head;
    int length = 0;
    while (current_node != NULL)
    {
        length ++;
        current_node = current_node->next;
    }
    return length; 
}

/*Adds a value to the end of the list*/
void list_add_to_back(list_t *l, elem value) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->value = value;
    new_node->next = NULL;
    node_t *current_node = l->head;
    while (current_node->next != NULL)
    {
        current_node = current_node->next;
    }
    current_node->next = new_node;

}


/*Adds a value to the front of the list*/
void list_add_to_front(list_t *l, elem value) {
     node_t *new_node = malloc(sizeof(node_t));
    new_node->value = value;
    new_node->next = l->head;
	l->head = new_node;
}


/*Adds a value at a given position in the list*/
void list_add_at_index(list_t *l, elem value, int index) {
    int count = 1;
    node_t *new_node = malloc(sizeof(node_t));
    new_node->value = value;
    new_node->next = NULL;
    node_t * current_node = l->head;
    node_t* next_node = NULL;
    while (current_node != NULL && count < (index))
    {
        count++;
        next_node = current_node->next;
        current_node = next_node;
    }
    next_node = current_node->next;
    current_node->next = new_node;
    new_node->next = next_node;
}

/*Removes the element from the back and return that element*/
elem list_remove_from_back(list_t *l) {
      node_t *prev_node = l->head;
	node_t *current_node = prev_node->next;
    while (current_node->next != NULL)
    {
		prev_node = current_node;
        current_node = current_node->next;
    }
	prev_node->next = NULL;
    elem value = current_node->value;
    free(current_node);
    return value;
}

/*Removes the element from the front and return that element*/
elem list_remove_from_front(list_t *l) {
     node_t *current_node = l->head;
    l->head = current_node->next;
    elem value = current_node->value;
    free(current_node);
    return value;
}

/*Removes the element from a given index and return that element*/
elem list_remove_at_index(list_t *l, int index) {
     int count = 0;
    node_t *prev_node = l->head;
	node_t *current_node = prev_node->next;
    while (current_node->next != NULL && count < (index - 1))
    {
        count++;
		prev_node = current_node;
        current_node = current_node->next;
    }
    node_t *temp = current_node;
    prev_node->next = current_node->next;
    elem value = temp->value;
    free(temp);
    return value;
}

/*checks if value exist in the list*/
bool list_is_in(list_t *l, elem value) {
	bool available ;
    node_t *current_node = l->head;
    while (current_node->next != NULL && !available)
    {
		if (current_node->value == value){
			available = true;
		}
        current_node = current_node->next;
    }
    return available; 
}


elem list_get_elem_at(list_t *l, int index) {
	int counter = 0;
	elem value = 0;
	node_t *current_node = l->head;
    while (current_node->next != NULL && counter < (index))
    {
		counter++;
        current_node = current_node->next;
    }
	if (current_node != NULL){
		value = current_node->value;
	}
	return value;
}
    
    
int list_get_index_of(list_t *l, elem value) {
    int counter = 0;
	node_t *current_node = l->head;
    while (current_node->next != NULL)
    {
		if (current_node->value == value){
			return counter;
		} else {
			counter++;
			current_node = current_node->next;
		}
    }
	return counter; 
}
