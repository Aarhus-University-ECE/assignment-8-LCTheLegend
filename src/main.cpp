extern "C"{
    // Add the header files required to run your main 
    #include "linked_list.h"
    #include "insertion_sort.h"
    #include "list_queue.h"
}

// File for sandboxing and trying out code
int main(int argc, char **argv)
{
    
    linked_list *ptr;
    ptr = createLinkedList();

    for(int i = 0 ; i < 31 ; i++)
    {
        node_t *val = createNode(rand() % 51);
        insertFront(val, ptr);
    }
    printLL(ptr);
    sort(ptr);
    printLL(ptr);
    //Above code was test for the insertion sort
    
    queue q;
    init_queue(&q);
    printf("%d\n", empty(&q));
    enqueue(&q, 10);
    enqueue(&q, 5);
    //enqueue(&q, 15);
    printf("%d\n", empty(&q));
    //printf("%d\n", q.front->data);
    //printf("%d", q.front->next->data);
    //printf("%d", q.rear->data);
    printf("%d\n", dequeue(&q));
    printf("%d\n", dequeue(&q));
    printf("%d", empty(&q));
    return 0;
}