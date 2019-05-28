#include <stdlib.h>

    struct s_node {
        void *content;
        struct s_node *next;
    };

    struct s_queue {
        struct s_node *first;
        struct s_node *last;
    };



struct s_queue *init(void)
{
    struct s_queue *el;

    el = (struct s_queue *)malloc(sizeof(struct s_queue));
    el->first = 0;
    el->last = 0;
    return el;
}

void enqueue(struct s_queue *queue, void *content)
{
    struct s_node *lastel;
    lastel = (struct s_node *)malloc(sizeof(struct s_node));
    lastel->content = content;
    lastel->next = 0;


    if (!queue->first)
    {
        queue->first = lastel;
        queue->last = lastel;
    }
    else 
    {
        queue->last->next = lastel;
        queue->last = lastel;
    }
}

// copy content , check that last and first not the same address, 
// relink first on next, free first via tmp, adjust last if needed
void *dequeue(struct s_queue *queue)
{
    void *cont;
    struct s_node *tmp;


    if (!queue->first)
    {
       return 0;
    }
    else 
    {
        if (queue->first != queue->last)
        {
            cont = queue->first->content;  
            tmp = queue->first;

            queue->first = queue->first->next;
            free(tmp);
            return cont;
        }
        else 
        {
            cont = queue->first->content;  
            tmp = queue->first;
            queue->first = 0;
            queue->last = 0; 
            free(tmp);
            return cont;
        }

    }
}

void *peek(struct s_queue *queue)
{
    return ((queue->first) ? queue->first->content : 0);
}

int isEmpty(struct s_queue *queue)
{
    return ((queue->first) ? 0: 1);
}

#include <stdio.h>
int main(void)
{
    char * s = "abcded";

    struct s_queue *myqueue = init();
    printf("1 - %d\n", isEmpty(myqueue));

    //1 element 
    enqueue(myqueue, s);
    printf("abcded - %s\n", (char *)peek(myqueue));
    printf("0 - %d\n", isEmpty(myqueue));

    //2 elements 
    enqueue(myqueue, s + 1);
    printf("abcded - %s\n", (char *)peek(myqueue));
    printf("bcded - %s\n", (char*)myqueue->last->content);
    printf("0 - %d\n", isEmpty(myqueue));

    //3 elements 
    enqueue(myqueue, s + 2);
    printf("abcded - %s\n", (char *)peek(myqueue));
    printf("bcded - %s\n", (char*)myqueue->first->next->content);
    printf("cded - %s\n", (char*)myqueue->last->content);
    printf("0 - %d\n", isEmpty(myqueue));

    // dequeue 
    printf("dequeue abcded - %s\n", (char *)dequeue(myqueue));
    printf("bcded - %s\n", (char *)peek(myqueue));
    printf("cded - %s\n", (char*)myqueue->last->content);

    printf("dequeue bcded - %s\n", (char *)dequeue(myqueue));
    printf("cded - %s\n", (char *)peek(myqueue));

    printf("dequeue cded - %s\n", (char *)dequeue(myqueue));
    printf("null - %s\n", (char *)peek(myqueue));
    printf("1 - %d\n", isEmpty(myqueue));

    return 0;

}
