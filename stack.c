 #include <stdio.h>
 #include <stdlib.h>
 
 struct s_node {
        void          *content;
        struct s_node *next;
    };
    struct s_stack {
        struct s_node *top;
    };

 struct s_stack *init(void)
 {
    struct s_stack *res = (struct s_stack*)malloc(sizeof(struct s_stack));
    res->top = 0;
    return res;
 }
//   pop(stack) : Remove the top item from the stack and return it.
//   If the stack is empty, the function returns NULL.

void *pop(struct s_stack *stack)
{
    void * content1; 
    struct s_node * tmp; 
    if (stack->top)
    { 
        content1 = stack->top->content;
        tmp = stack->top;
        stack->top = tmp->next;
        free(tmp);
        return content1;
    }
    return 0;
}

//push(stack, item) : Add an item to the top of the stack.
void push(struct s_stack *stack, void *content)
{
    struct s_node *node = (struct s_node *)malloc(sizeof(struct s_node));
    node->content = content;
    node->next = stack->top; 
    stack->top = node; 
}

// peek(stack) : Return the top of the stack.
void *peek(struct s_stack *stack)
{
    void *content1;

    if (stack->top)
    {
        content1 = stack->top->content;
        return content1;
    }
    else 
        return 0; 
}

//isEmpty(stack) : Return 1 if the stack is empty, 0 otherwise.
int isEmpty(struct s_stack *stack)
{
    return (!stack->top) ? 1 : 0;
}

int main(void)
{
    struct s_stack *myStack;

    myStack = init();
    printf("1 = %d\n", isEmpty(myStack));


    push(myStack, "hello");
    printf("0 = %d\n", isEmpty(myStack));

    printf("hello = %s\n", peek(myStack));
    push(myStack, "mam");
    
    printf("mam - %s\n", peek(myStack));

    push(myStack, (void*)42);
    printf("42 - %d\n", (int)peek(myStack));

    pop(myStack);
    printf("mam - %s\n", peek(myStack));

    pop(myStack);
    printf("hello - %s\n", peek(myStack));
    printf("0 = %d\n", isEmpty(myStack));

    pop(myStack);
    printf("0 - %s\n", peek(myStack));
    printf("1 = %d\n", isEmpty(myStack));
}