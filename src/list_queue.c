#include "list_queue.h"


void init_queue(queue *q)
{
  // Add your init_queue
  q -> front = NULL;
  q -> rear = NULL;
  q -> size = 0;
}

int empty(queue *q)
{
  // Add your empty function
  return(q -> size <= 0);  
}

void enqueue(queue *q, int x)
{
  // Add your enqueue function
  qnode *new = malloc(sizeof(qnode));
  if(q -> rear == NULL)
  {
    q -> rear = new;
    q -> rear -> data = x;
    q -> size++;
  }
  else if(q -> front == NULL)
  {
    q -> front = new;
    q -> front -> data = x;
    q -> rear -> next = q -> front; 
    q -> size++;
  }
  else
  {
    q -> front -> next = new;
    q -> front = new;
    q -> front -> data = x;
    q -> size++;
  }

}
int dequeue(queue *q)
{
  // Add your dequeue function
  int return_value = q -> rear -> data;
  qnode *temp = q -> rear;
  q -> rear = q -> rear -> next;
  q -> size = q -> size - 1;
  free(temp);
  return return_value;
}