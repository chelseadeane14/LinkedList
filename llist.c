//
//  llist.c
//  
//
//  Created by Chelsea Deane on 12/17/15.
//
//

#include "llist.h"
#include "ldata.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ==============================================================
// Utility operations
// ==============================================================

// Creates and returns an new node
struct LNode *create_new_node(struct LData *data){
    struct LNode *Node;
    Node = malloc(sizeof(struct LNode));
    Node->data = data;
    Node->next = NULL;
    return Node;

}

// Creates and returns an empty list
struct LList *create_empty_list() {
    struct LList *newList;
    newList = malloc(sizeof(struct LList));
    newList->root = NULL;
    newList->sentinal = NULL;
    newList->size = 0;
    return newList;

}

// Clears (empties) the specified list
void clear_list(struct LList *list) {
    list->root = NULL;
    list->sentinal = NULL;
    list->size = 0;
    return;
}

// Swaps the elements of a list
void swap_elems(struct LList *list, int idx1, int idx2) {
    struct LData *temp = get_elem(list, idx1);
    struct LData *temp2 = get_elem(list, idx2);
    swap_data(temp, temp2);
}

// Prints the list to standard output in the form [elem_1 elem_2 ... elem_n]
void print_list(struct LList *list) {
    struct LNode *curr;
    if(list->root == NULL) {
        printf("[ ");
        printf("]");
    }
    if(list->root != NULL){
        curr = list->root;
        printf("[ ");
        do {
            printf("(");
            printf("%s", curr->data->city);
            printf(", ");
            printf("%.1f", curr->data->lat);
            printf(", ");
            printf("%.1f",curr->data->lon);
            printf(") ");
            curr = curr->next;
        } while(curr != NULL);
        printf("]\n");
    }
}

// ==============================================================
// Query functions (no side effects)
// ==============================================================

// Checks if the list is empty
    int is_empty(struct LList *list) {
        if(list->size > 0) {
            return 0;
        }
        else {
            return 1;
        }
        
        return 0;

    }

// Returns the size of the list
    int size(struct LList *list) {
        return list->size;
    }

// Checks if the list contains the specified data
// Uses the are_equal operation of LData
    int contains(struct LList *list, struct LData *data) {
        struct LNode *temp = list->root;
        while(temp->next != NULL) {
            if(strcmp(temp->data->city, data->city) == 0){
                if(temp->data->lat == data->lat){
                    if(temp->data->lon == data->lon) {
                        return 1;
                    }
                }
            }
            else {
                return 0;
            }
            temp = temp->next;
        }
        
        return 0;

    }

// ==============================================================
// Add operations
// ==============================================================

// Adds the specified element to the specified position
    void add_elem(struct LList *list, struct LData *data, int idx) {
        if(idx == 0) {
            add_first(list, data);
            return;
        }
        else if(idx < 0 || idx >= list->size){
            return;
        }
        else {
            struct LNode *temp = malloc(sizeof(struct LNode));
            temp = list->root;
            struct LNode *addNode = create_new_node(data);
            int count = 0;
            while(count <= idx - 1) {
                if(count == idx-1) {
                    addNode->next = temp->next;
                    temp->next = addNode;
                    list->size++;
                    return;
                }
                else{
                    temp = temp->next;
                    count++;
                }
            }
            return;
        }
    }

// Adds the specified data to the front of the list
    void add_first(struct LList *list, struct LData *data) {
        struct LNode *addNode = create_new_node(data);
        struct LNode *temp = malloc(sizeof(struct LNode));
        if(list->root != NULL){
            temp = list->root;
            list->root = addNode;
            addNode->next = temp;
            list->size++;
        }
        else {
            list->root = addNode;
            list->sentinal = addNode;
            list->size++;
        }
        return;
    }

// Adds the specified data to the end of the list
    void add_last(struct LList *list, struct LData *data) {
        struct LNode *addNode = create_new_node(data);
        if(list->root == NULL){
            list->root = addNode;
            list->sentinal = addNode;
        }
        else {
            list->sentinal->next = addNode;
            list->sentinal = addNode;
        }
        list->size++;
        return;

    }

// ==============================================================
// Get operation
// ==============================================================

// Returns a handle (pointer) to the element of the list at the specified position
    struct LData *get_elem(struct LList *list, int idx) {
        struct LNode *temp = list->root;
        int count = 0;
        while(temp->next != NULL){
            while(count <= idx) {
                if(count == idx){
                    return temp->data;
                }
                else {
                    temp = temp->next;
                    count++;
                }
            }
        }
        return NULL;

    }

// ==============================================================
// Remove operations
// ==============================================================

// Removes and returns the specified element from the specified position
struct LData *rem_elem(struct LList *list, int idx) {
    if(idx == 0) {
        rem_first(list);
        return NULL;
    }
    else if(idx < 0 || idx >= list->size){
        return NULL;
    }
    else {
        struct LNode *temp = malloc(sizeof(struct LNode));
        temp = list->root;
        struct LNode *next1;
        int count = 0;
        while(count <= idx - 1) {
            if(count == idx-1) {
                next1 = temp->next;
                temp->next = next1->next;
                list->size--;
                return next1->data;
            }
            else{
                temp = temp->next;
                count++;
            }
        }
        return NULL;
    }
}

// Removes and returns the first element in the list
// Assumes that the list is not empty
struct LData *rem_first(struct LList *list) {
    if(list->root == NULL){
        list->size = 0;
        return NULL;
    }
    else {
        struct LNode *curr = list->root;
        struct LData *temp;
        while(curr->next != NULL) {
            temp = curr->data;
            list->root = curr->next;
            list->size--;
            return temp;
        }
    }
    return NULL;
}

// Removes and returns the last element in the list
// Assumes that the list is not empty
struct LData *rem_last(struct LList *list) {
    if(list->root == NULL) {
        list->size = 0;
        return NULL;
    }
    else {
        struct LNode *curr = list->root;
        struct LData *temp = list->sentinal->data;
        while(curr->next != list->sentinal) {
            curr = curr->next;
        }
        list->sentinal = curr;
        curr->next = NULL;
        list->size--;
        return temp;
    }
}

// ==============================================================
// Sort operations
// ==============================================================

// Sorts the list according to the are_ordered operation of LData
void insertion_sort(struct LList *list) {
    int i = 1;
    for(; i < list->size; i++) {
        struct LData *temp = get_elem(list, i);
        int j = i;
        struct LData *x = get_elem(list, j);
        struct LData *y = get_elem(list, j - 1);
        while(j < list->size && strcmp(y->city,x->city) > 0) {
            swap_elems(list, j, j- 1);
            temp = get_elem(list, j-1);
            j++;
        }
    }
    
    return;
}

