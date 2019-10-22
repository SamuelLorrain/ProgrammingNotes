#include <stdlib.h>
#include <stdio.h>
/*
 * Dans ce fichier : création d'une stack + creation d'un parseur
 * de notation polonaise inversée
 *
 * ==> parsing de notation polonaise
 * 1:Scan the expression from left to right
 * 2: si c'est une opérande, push dans la stack
 * 3: si c'est un opérator, pull l'opérande de la stack et perform l'opération
 * 4: store 3: dans la stack
 * 5: scan l'expression jusqu'a ce que la totalité des opérandes soient consumés
 * 6: pop la stack et perform l'opération
 *
 *
 */

//******
//
//Définie une stack pour travailler dessus
//pour le parsing
//
//******
typedef struct Stack{
    char* stack;
    int size;
    int allocated;
} Stack;

Stack createStack(int size){
    Stack s;
    s.stack = (char*)malloc(sizeof(char) * size);
    s.size = size;
    s.allocated = 0;
    return s;
}

int isEmpty(Stack *stack){
    return (stack->allocated == 0);
}

int isFull(Stack *stack){
    return (stack->allocated == stack->size);
}

//retourne 1 si l'allocation est réussie,
//retourne 0 sinon
int push(Stack *stack, char value){
    if (stack->allocated >= stack->size)
        return 0;
    stack->allocated++;
    stack->stack[stack->size - stack->allocated] = value;
    return 1;
}

char pop(Stack *stack){
    if (stack->allocated <= 0) return '\0';
    char value = stack->stack[stack->size - stack->allocated];
    stack->allocated--;
    return value;
}

int peek(Stack *stack){
    return stack->stack[stack->size - stack->allocated];
}

int free_stack(Stack *s){
    free(s->stack);
}

void stack_test(){
    Stack s = createStack(3);
    printf("#--------------------------#\n");
    printf("isEmpty : %d\n", isEmpty(&s));
    push(&s,'a');
    printf("Pushing something\n");
    printf("isEmpty : %d\n", isEmpty(&s));
    printf("#--------------------------#\n");
    printf("Push : %c\n", peek(&s));
    push(&s,'b');
    printf("Push : %c\n", peek(&s));
    printf("#--------------------------#\n");
    printf("isFull : %d\n", isFull(&s));
    printf("#--------------------------#\n");
    push(&s,'c');
    printf("Push : %c\n", peek(&s));
    printf("Try to overflow\n");
    push(&s,'d');
    printf("Push : %c\n", peek(&s));
    push(&s,'e');
    printf("Push : %c\n", peek(&s));
    push(&s,'f');
    printf("Push : %c\n", peek(&s));
    printf("#--------------------------#\n");
    printf("isFull : %d\n", isFull(&s));
    printf("Pop : %c\n", pop(&s));
    printf("Pop : %c\n", pop(&s));
    printf("Pop : %c\n", pop(&s));
    printf("#--------------------------#\n");
    printf("allocated : %d\n", s.allocated);
    printf("size : %d\n", s.size);
    printf("Free stack\n");
    free_stack(&s);
}

int parse(char* input){
    //input must be a string wich end with '\0'
    /*
 * ==> parsing de notation polonaise
 * 1:Scan the expression from left to right
 * 2: si c'est une opérande, push dans la stack
 * 3: si c'est un opérator, pull l'opérande de la stack et perform l'opération
 * 4: store 3: dans la stack
 * 5: scan l'expression jusqu'a ce que la totalité des opérandes soient consumés
 * 6: pop la stack et perform l'opération
 */
    Stack s;
    s = createStack(128);
    char* current = input;
    int i;
    while (*current != '\0'){
        if (*current == '+'){
           int a = pop(&s) - 48;
           int b = pop(&s) - 48;
           push(&s, a + b);
        }else if ((*current >= '0') && (*current <= '9')){
            push(&s,*current);
        }
        current++;
    }
    return pop(&s);
}


int main(){
    int a = parse("1 1 +");
    printf("%d\n", a);
    return 0;
}

