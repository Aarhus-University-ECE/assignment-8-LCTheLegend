#include "insertion_sort.h"
#include "linked_list.h"

void sort(linked_list *llPtr)
{
    // Add your sort function here
    node_t *ptr = llPtr -> head;
    node_t *temp;
    node_t *temp_ptr = llPtr -> head;
    //temporary pointers used in the function

    while(ptr -> next != NULL) //This makes sure we are not at the end of the list
    {
        if((ptr -> data) >= (ptr -> next -> data)) //checks if the number in the sequence is smaller than the previous
        {
            temp = ptr -> next; //temporary pointer saves the smaller number
            //printLL(llPtr);
            ptr -> next = ptr -> next -> next; //links the current nodes' next to the next next node so the list is still linked
            while(temp_ptr != ptr -> next) //This loop is used to count through the entire list
            {
                if(temp -> data <= temp_ptr -> data) //checks if current temporary node is smaller than the first number in list
                {
                    temp -> next = temp_ptr;
                    llPtr -> head = temp; //links the new smallest node to the front of the list and makes the head point to the new smallest node
                    break;
                }
                else if((temp -> data) <= (temp_ptr -> next -> data)) //This checks for numbers that aren't first in the list
                {
                    temp -> next = temp_ptr -> next;
                    temp_ptr -> next = temp; //These lines puts the temp node in between two nodes in the list
                    break;
                }
                temp_ptr = temp_ptr -> next; //Loops through the list
            }
            temp_ptr = llPtr -> head; //resets the temp_ptr to point to the new smallest node
        }
        else //if the number in the sequence is not smaller than the previous it moves to the next element
            ptr = ptr -> next;
    }
}