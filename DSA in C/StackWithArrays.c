// STACK IMPLEMENTSTION USING ARRAYS


#include<stdio.h>
int stack[100], n;
int top = -1;
void pop();
void peek();
void push();
void display();
void main(){
    printf("Enter the total elements you needed in stack: ");
    scanf("%d", &n);
    // Pushing some elements
    printf("\nPushing some elements:");
    push();
    push();
    push();

    // Displaying
    display();

    // Popping a elements
    printf("\nPopping a element:\n");
    pop();

    // Displaying
    display();

    // Peek element of the stack
    peek();

}

void push(){
    if (top == n-1){
        printf("\nOverflow");
    }
    else{
        top+=1;
        int val;
        printf("\nEnter a value: ");
        scanf("%d", &val);
        stack[top]= val;
    }
}

void pop(){
    if(top == -1){
        printf("\nUnder flow");
    }
    else{
        top-=1;
        printf("Popped successful\n");
    }
}

void peek(){
    if(top == -1){
        printf("\nStack is empty");
        return;
    }
    printf("The peek element is %d", stack[top]);
}

void display(){
    if(top == -1){
        printf("\nStack is empty");
        return;
    }
    printf("The elemets are:");
    for(int i = top;i>=0;i--){
        printf("%d ", stack[i]);
    }
    printf("\n");
}
