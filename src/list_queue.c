#include "list_queue.h"


void init_queue(queue *q)
{
  // Add your init_queue
  q -> front = NULL;
  q -> rear = NULL;
  q -> size = 0; //sets size to 0
}

int empty(queue *q)
{
  // Add your empty function
  return(q -> size <= 0);  //return true if size == 0
}

void enqueue(queue *q, int x)
{
  // Add your enqueue function
  qnode *new = malloc(sizeof(qnode)); //allocates memory to pointer new
  if(q -> rear == NULL) 
  {
    q -> rear = new; //makes rear the new element if empty
    q -> rear -> data = x;
    q -> size++;
  }
  else if(q -> front == NULL)
  {
    q -> front = new;
    q -> front -> data = x; //sets new to the front if empty
    q -> rear -> next = q -> front; //sets next of rear to front
    q -> size++;
  }
  else
  {
    q -> front -> next = new; //if front and rear are not empty new is put in the list as front's next
    q -> front = new; //front pointer is then set to point to new
    q -> front -> data = x;
    q -> size++;
  }

}
int dequeue(queue *q)
{
  // Add your dequeue function
  int return_value = q -> rear -> data; //saves the value to be returned
  qnode *temp = q -> rear; //temporary pointer to save the space in storage
  q -> rear = q -> rear -> next; //makes rear point to next element
  q -> size = q -> size - 1;
  free(temp); //frees the space from the rear
  return return_value;
}