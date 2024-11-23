#include<stdio.h>
#include<stdlib.h>

struct n{
    int data;
    struct n *next;
};

typedef struct n node;

node *root = NULL;

node *push(int data){
    node * newNode = (node*)malloc(sizeof(node));
    newNode -> data = data;
    newNode -> next = NULL;
    if(newNode == root)
        root = newNode;
    else{
        newNode -> next = root;
        root = newNode;
    }
}

void pop(){
    if(root == NULL){
        printf("this stack is empty\n");
        return;
    }else{
        node *temp = root;
        root = temp-> next;
        free(temp);
    }
}

void top(){
    if(root == NULL){
        printf("this stack is empty\n");
        return;
    }else
        printf("last element: %d \n",root -> data);
}

void display(){
    if(root == NULL){
        printf("this stack is empty\n");
        return;
    }else{
        node *temp = root;
        while(temp  != NULL){
            printf("%d ",temp -> data);
            temp = temp -> next;
        }
        printf("\n");
    }
}

int main(){
    push(10);
    push(20);
    push(30);
    display();
    pop();
    display();
    top();
    return 0;
}