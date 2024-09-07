#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

void insert_at_beginning2(struct node **head, int val){
    struct node *newnode;
    newnode=malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = *head;
    *head = newnode;
}

struct node* insert_at_beginning1(struct node *head, int val){
    struct node *newnode;
    newnode=malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = head;
    head = newnode;
    return head;
}

void insert_at_specific_pos(struct node *head, int val, int pos){
    struct node *temp, *newnode;
    newnode = malloc(sizeof(struct node));
    newnode->data = val;
    temp = head;
    pos--;

    while(pos!=1){              // int cnt = 2;
        temp = temp->next;      // while(cnt != pos){
        pos--;                       //     temp = temp->next;
    }                            //     cnt+=1;
                                // }
    newnode->next = temp->next;
    temp->next = newnode;
}

void insert_at_end(struct node *head, int val){
    struct node *temp, *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;
    temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newnode;
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
    struct node *temp;
    temp = head;
    pos--;
    while(pos!=1 && temp!=NULL){
        temp = temp->next;
        pos--;
    }
    if(temp == NULL){
        printf("Invalid Position!!!");
    }
    else{
        free(temp->next);
        temp->next = temp->next->next;
    }
    
    
}

void display(struct node *head){
    if (head == NULL){
        printf("List is empty bro!");
    }
    else
    {
        struct node *temp = head;
        while(temp!=NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
    
}
void free_list(struct node *head) {
    struct node *temp;
    temp = head;
    while (head != NULL) {
        temp = temp->next;
        free(head);
        head = temp;
    }
}

int main(){

    // Just manually creating the linked list with 3 nodes
    struct node *head  = malloc(sizeof(struct node));
    head->data = 50;
    head->next = NULL;

    struct node *temp = malloc(sizeof(struct node));
    temp->data = 55;
    temp->next = NULL;
    head->next = temp;

    temp = malloc(sizeof(struct node));
    temp->data = 60;
    temp->next = NULL;
    head->next->next = temp;

    // Now I will use some of my functions to manipulate in it
    // Before I can print my manually created linked list
    printf("My Linked List is:\n");
    display(head);

    // 1. Insert at end and Displaying it
    insert_at_end(head, 65);
    insert_at_end(head, 70);
    insert_at_end(head, 75);
    printf("\n\nDisplaying my linked list after inserting at end:\n");
    display(head);

    // 2. Insert at starting 
    head = insert_at_beginning1(head, 45);
    printf("\n\nDisplaying my linked list after inserting at start:\n");
    display(head);

    // 3. Insert at a given postion i.e,. pos == 3 like this!
    insert_at_specific_pos(head, 57, 4);
    printf("\n\nDisplaying my linked list after inserting at Specific position:\n");
    display(head);

    // 4. Delete a node at beginning i.e,. deleting the head!
    head = delete_at_beginning(head);
    printf("\n\nDisplaying my linked list after deleting first node:\n");
    display(head);

    // 5. Delete a node at end
    delete_at_end(head);
    printf("\n\nDisplaying my linked list after deleting last node:\n");
    display(head);

    // 6. Delete a node at specified location i.e,. pos == 5!
    delete_at_specific_pos(head, 3);
    printf("\n\nDisplaying my linked list after deleting the node at specified position:\n");
    display(head);

    // 7. Finally freeing up the entire list!
    free_list(head);
    head = NULL;   // This line to ensure that we never accidentally use the freed memory again!
    display(head);
    
    return 0;

}