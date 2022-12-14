// list/list.c
//
// Implementation for linked list.
//
// <Author>
//Zoe Carter, Kyndall Jones, Julian Forbes
//<References>
//https://www.geeksforgeeks.org/find-length-of-a-linked-list-iterative-and-recursive/
//https://www.geeksforgeeks.org/insertion-in-linked-list/
//https://www.geeksforgeeks.org/deletion-in-linked-list/
#include <stdbool.h>
#include "list.h"
#include <stdlib.h>
#include <stddef.h>

//1 - memory allocation
list_t *list_alloc(){
  //Point list_t to the linked list data
  list_t *linked_list;
  //Point each element to the next node and the last element is NULL
  node_t *head = NULL;
  //using malloc for dynamic memory 
    head = (node_t *)malloc(sizeof(node_t));
    head->value = 0;
    head->next = NULL;
  linked_list -> head = head;
  return linked_list;
};
//2 - memory freeing
void list_free(list_t *l){
  free(l -> head);
};
//3 - prints linked_list
void list_print(list_t *l){
  //Points node_t to the current node
  // and that is in the free allacted memory
  node_t *curr_node = l -> head;
  //if there is no node, its null == the array is ended - end loop
  while(curr_node != NULL){
    printf("%d\t",curr_node -> value);
    //updates the current node
    curr_node = curr_node -> next;
  }
};

//4 - length of linked_list
//finding count using recursion
int list_length(list_t *l, int count = 0){
  node_t *curr_node = l -> head;
  //Base Case
  if (curr_node == NULL)
    return count;
  //Recursive Case
  return list_length(curr_node-> next, count +1)
};
//5 - Adding to back of linked_list
void list_add_to_back(list_t *l, elem value){
  node_t *curr_node = l -> head;
  //If linked_list is empty, make curr_node the head
  if (l -> head == NULL){
    curr_node -> value = value;
    curr_node -> next = NULL;
  }
  else{
    //Go through linked_list until we reach the last node
    while(curr_node -> next != NULL){
      curr_node = curr_node -> value

    }
    curr_node -> next = (node_t*)malloc(sizeof(node_t));
    curr_node -> next-> value = value;
    curr_node -> next->next = NULL;
  }
};
//6 - Adding to front of linked_list
void list_add_to_front(list_t *l, elem value){
  node_t * first_node;
  first_node = (node_t*)malloc(sizeof(node_t));
  first_node -> value = value;
  first_node -> next = l -> head;
  l -> head = first_node;
};
//7 - Adding at index and end if out of bounds
void list_add_at_index(list_t *l, elem value, int index){
  if (l -> head == NULL){
    l -> head -> value = value;
    l ->head -> next = NULL;
    }
  else{
    node_t * first_node;
    first_node = (node_t*)malloc(sizeof(node_t));
    first_node -> value = value;
    int curr_ind = 0
    node_t *curr_node = l -> head;
    while (curr_ind < index-1) {
        if (curr_node->next == NULL) {
            curr_node->next = curr_node;
            curr_node->next = NULL;
            return ;
        }
        curr_node = curr_node->next;
        curr_ind++;
    }
    first_node -> next = curr_node -> next;
    curr_node -> next = first_node;
  }
};
'''Returns the removed element, or -1 for empty list'''
//8 - Removing from Back of linked_list
elem list_remove_from_back(list_t *l){
  node_t *curr_node = l -> head;
  while(curr_node ->next -> next != NULL){
    curr_node = curr_node -> next;
  }
  int removed = curr_node -> next -> value;
  free(curr_node -> next);
  curr_node -> next = NULL;
  return removed;
};
//9 - Removing from Front of linked_list
elem list_remove_from_front(list_t *l){
  int removed = -1;
  node_t *first_node = NULL;
  first_node = l -> head -> next;
  removed = l -> head -> value;
  free(l -> head);
  l -> head = first_node
  return removed
};
//10 - Removing at an index of linked_list
elem list_remove_at_index(list_t *l, int index){
  int removed = -1;
  node_t *first_node = NULL;
  node_t *curr_node = l -> head;
  int ind = 0;
  while (ind < index-1){
    ind++;
    curr_node =curr_node -> next;
  }
  removed = curr_node -> next -> value;
  first_node = curr_node -> next -> next;
  free(curr_node -> next);
  curr_node ->next = first_node;
  return removed
};
//11 - Checks if element is in linked_list
bool list_is_in(list_t *l, elem value){
  node_t *curr_node = l -> head;
  while (curr_node -> next != NULL){
    if (curr_node -> value == value) reutrn true;
    curr_node = curr_node -> next;
  }
  return false;
};
//12 - Returns the element at a specific index or -1 if empty or out of bounds in linked_list
elem list_get_elem_at(list_t *l, int index){
  node_t *curr_node = l -> head;
  int ind = 0;
  while (curr_node != NULL){
    if (ind == index) return curr_node -> value;
    curr_node = curr_node -> next;
    ind++;
  }
  return -1;
};
//13 - Returns the index where the element appears, or -1 if not found in linked_list
int list_get_index_of(list_t *l, elem value){
  node_t *curr_node = l -> head;
  int ind = 0;
  while (curr_node != NULL){
    if (curr_node -> value == value) return ind;
    curr_node = curr_node -> next;
    ind++;
  }
  return -1;
};