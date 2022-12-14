#include <stdio.h>
#include "list.h"

int main() 
{
  printf("Write your Tests for your linked list implementation\n");
  
  list_t *linked_list;
  
  linked_list = list_alloc();

  list_print(linked_list)
  list_add_to_front(linked_list,1);
  list_add_at_index(linked_list,2,1);
  list_add_to_back(linked_list,3);
  list_print(linked_list);
  list_add_to_front(linked_list,0);
  printf("%d\n", list_length(linked_list));
  


  

 
}
