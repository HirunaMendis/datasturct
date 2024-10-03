#include<stdio.h>
#include<stdlib.h>
typedef enum {FALSE,TRUE}Boolean;

#define MAXSTACK 20
 typedef int stackEntry;

typedef struct
    {
        int top;
        stackEntry entry[MAXSTACK];
    }Stack;

Boolean createStack(Stack *s){

    s->top = -1;
    printf ("%d\n",s->top);
    printf("StackCreated \n");
    return TRUE;

}


Boolean isStackEmpty(const Stack*s){
    return(s->top==-1);
}


Boolean isStackFull(const Stack *s){

    return(s->top==MAXSTACK -1);
}

void push(stackEntry item, Stack *s){

    if(!isStackFull(s))
        s->entry[++s->top]=item;
    else{
        printf("----Stack is Full----");
        exit(1);
    }
}

void pop(stackEntry *item, Stack *s){

    if(!isStackEmpty(s))
        *item=s->entry[s->top--];
    else{
        printf("---Stack is Empty !!! ---");
        exit(1);
    }

}

int main(){

    int item[10], oitem[10],j=0;
    Stack s;
    createStack(&s);

    for(int i=0;i<10;i++){

        printf("Please enter the stack item:\n ");
        scanf("%d",&item[i]);

        printf("%d\n",item[i]);

        push(item[i],&s);
    }

      for (int i = 0; i < 10; i++) {
        pop(&oitem[j], &s);
        printf("Popped: %d\n", oitem[j]);
        j++;
    }



    return 0;

}

