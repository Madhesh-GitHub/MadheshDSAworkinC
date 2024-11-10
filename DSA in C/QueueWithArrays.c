// Queue implementation using arrays

#include<stdio.h>
int front = -1, rear = -1, n=5;
int Queue[5];

void enqueue();
void dequeue();
void display();

void main(){
    // Adding some elements
    printf("\nAdding some elements:");
    enqueue();
    enqueue();
    enqueue();

    // Displaying
    display();

    // Removing a element
    printf("\nRemoving a element:\n");
    dequeue();

    // Displaying
    display();

}

void enqueue(){
    if(rear == n-1){
        printf("\nQueue overflow\n");
    }
    else if (front == -1 && rear == -1){
        front = 0;
        rear = 0;        
    }
    else{
        rear+=1;
    }
    int val;
    printf("\nEnter a value: ");
    scanf("%d", &val);
    Queue[rear ] = val;
}

void dequeue(){
    if (front == -1 && rear == -1){
        printf("\nUnderflow\n");
    }
    else{
        front+=1;
        printf("\nElement removed!\n");
    }

}

void display(){
    if (front == -1 && rear == -1){
        printf("\nUnderflow\n");
    }else{
        printf("\nElements are: ");
        for(int i = front; i<=rear;i++){
            printf("%d ", Queue[i]);
        }
        printf("\n");
    }
    
}
