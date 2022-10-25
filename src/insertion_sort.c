#include "insertion_sort.h"
#include "linked_list.h"

void sort(linked_list *llPtr)
{
    // Add your sort function here
    node_t *ptr = llPtr -> head;
    node_t *temp;
    node_t *temp_ptr = llPtr -> head;
    while(ptr -> next != NULL)
    {
        if((ptr -> data) >= (ptr -> next -> data))
        {
            temp = ptr -> next;
            printLL(llPtr);
            ptr -> next = ptr -> next -> next;
            while(temp_ptr != ptr -> next)
            {
                if(temp -> data <= temp_ptr -> data)
                {
                    temp -> next = temp_ptr;
                    llPtr -> head = temp;
                    break;
                }
                else if((temp -> data) <= (temp_ptr -> next -> data))
                {
                    temp -> next = temp_ptr -> next;
                    temp_ptr -> next = temp;
                    break;
                }
                temp_ptr = temp_ptr -> next; 
            }
            temp_ptr = llPtr -> head;
        }
        else
            ptr = ptr -> next;
    }
}