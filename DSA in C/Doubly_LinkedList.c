#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next, *prev;
};

void insert_at_specific_pos(struct node *head, int val, int pos){
    struct node *back, *newnode, *front;
    newnode = malloc(sizeof(struct node));
    newnode->data = val;
    back = head;
    pos--;
    while(pos!=1 && back!=NULL){              // int cnt = 2;
        back = back->next;      // while(cnt != pos){
        pos--;                       //     temp = temp->next;
    }                            //     cnt+=1;  // }
    if(back == NULL){
        printf("\nInvalid Position, Try again!");
        free(newnode);
        return;
    }
    else{
        front = back->next;
        newnode->next = front;
        if(front!=NULL){
            front->prev = newnode;
        }
        back->next = newnode;
    }
}

struct node* Insert_at_end(struct node*head, int val){
    struct node *temp, *newnode;
    newnode = malloc(sizeof(struct node));
    newnode->data = val;
    temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
    newnode->next = NULL;
    return head;
}

struct node* CreateHead(struct node *head, int val){
    head = malloc(sizeof(struct node));
    head->next = NULL;
    head->data = val;
    head->prev = NULL;
    return head;
}

struct node* CreateList(struct node*head){
    int n, val;
    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);
    if (n == 0){
        return head;
    }
    printf("Enter the value of node 1: ");
    scanf("%d", &val);
    head = CreateHead(head, val);

    for(int i = 2; i<=n ; i++){
        printf("Enter the value of node %d: ", i);
        scanf("%d", &val);
        head = Insert_at_end(head, val);
    }
    return head;
}

struct node* delete_at_beginning(struct node *head){
    if (head == NULL){
        printf("List is already empty bro!");
    }
    else{
        struct node *temp = head;
        head = head->next;
        free(temp);    // deallocating the old head's memory, good practice!!!
        temp = NULL;   // temp holds the old head addresss
        head->prev = NULL;
        return head; 
    } 
}

void delete_at_end(struct node *head){
    if (head == NULL){
        printf("Already list is empty da!");
    }
    else if(head->next == NULL){
        free(head);
        head = NULL;
    }
    else{
        struct node *temp, *temp2;
        temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);    // Deallocating the memory of last node!
        temp->next = NULL;
    }
}

void delete_at_specific_pos(struct node *head, int pos){
    struct node *back, *front;
    back = head;
    pos--;
    while(pos!=1 && back!=NULL){
        back = back->next;
        pos--;
    }
    if(back == NULL){
        printf("\nInvalid Position!!!");
    }
    else{
        free(back->next);
        front = back->next->next;
        back->next = front;
        front->prev = back;
    }  
}

void display(struct node *head){
    if (head == NULL){
        printf("List is empty bro!");
    }
    else
    {
        struct node *temp = head;
        printf("\nThe DLL is:\n");
        while(temp!=NULL){
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }   
}

int main(){
    struct node *head = NULL;
    // 1. Create the entire doubly linked list and displaying (involves inserting in head as well as inserting in last)...
    head = CreateList(head);
    display(head);

    // 3. Insert at a given postion i.e,. pos == 3 like this!
    printf("\n\nDisplaying my linked list after inserting at Specific position:");
    insert_at_specific_pos(head, 57, 5);
    display(head);

    // 4. Delete a node at beginning i.e,. deleting the head!
    head = delete_at_beginning(head);
    printf("\n\nDisplaying my linked list after deleting first node:");
    display(head);

    // 5. Delete a node at end
    delete_at_end(head);
    printf("\n\nDisplaying my linked list after deleting last node:");
    display(head);

    // 6. Delete a node at specified location i.e,. pos == 5!
    printf("\n\nDisplaying my linked list after deleting the node at specified position:");
    delete_at_specific_pos(head, 3);
    display(head);
       
    printf("\nBy\n-Madhesh");
    return 0;
}