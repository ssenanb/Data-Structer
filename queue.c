#include<stdio.h>
#include<stdlib.h>

struct n{
    int data;
    struct n *next;
};

typedef struct n node;

node *head = NULL;
node *tail = NULL;

node *enqueue(int data){
    node *newNode = (node*)malloc(sizeof(node*));
    newNode -> data = data;
    newNode -> next = NULL;
    if(head == NULL){
        head = newNode;
        tail = newNode;
    }else{
        tail -> next = newNode;
        tail = newNode;
    }
}

void dequeue(){
    if(head == NULL){
        printf("this queue is empty\n");
        return;
    }else{
        node *temp = head;
        head = temp -> next;
        free(temp);
    }
}

void display(){
    if(head == NULL){
        printf("this queue is empty\n");
        return;
    }else{
        node *temp = head;
        while(temp != NULL){
            printf("%d ",temp-> data);
            temp = temp -> next;
        }
        printf("\n");
    }
}


int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();

    return 0;
}