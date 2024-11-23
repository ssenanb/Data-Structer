#include<stdio.h>
#include<stdlib.h>

struct n{
    int data;
    struct n *next;
    struct n *prev;
};

typedef struct n node;

node *root = NULL;

node *add_head(int data){
    node *newNode = (node*)malloc(sizeof(node));
    newNode -> data = data;
    newNode -> next = NULL;
    newNode -> prev = NULL;
    if(root == NULL)
        root = newNode;
    else{
        root -> prev = newNode;
        newNode ->next = root;
        root = newNode;
    }
}
node *add_tile(int data){
    node *newNode = (node*)malloc(sizeof(node));
    newNode -> data = data;
    newNode ->next = NULL;
    newNode -> prev = NULL;
    if(root == NULL)
        root = newNode;
    else{
        node *temp = root;
        while(temp-> next != NULL)
            temp = temp -> next;
        temp -> next = newNode;
        newNode-> prev = temp;
    }
}
void delete_head(){
    if(root == NULL){
        printf("this list is empty\n");
        return;
    }
    else{
        node *temp = root;
        root = temp -> next;
        root -> prev = NULL;
        free(temp); 
    }
}
void delete_tail(){
    if(root == NULL){
        printf("this list is empty");
        return;
    }
    else{
        node *temp = root;
        while(temp -> next -> next != NULL)
            temp = temp -> next;
        temp -> next = NULL;
        free(temp->next);
    }
}
 void find(int find){
    node *temp = root;
    while(temp != NULL){
        if(find == temp -> data){
            printf("element found\n");
            return;
        }
        temp = temp -> next;
    }
    printf("element wasn't\n");
}

void counter(){
    int counter = 0;
    node *temp = root;
    while(temp != NULL){
        counter++;
        temp = temp -> next;
    }
    printf("there are %d element",counter);
    printf("\n");
}


void display(){
    node *temp = root;
    while(temp != NULL){
        printf("%d ",temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}

int main(){
    add_head(2);
    add_head(4);
    add_head(6);
    add_tile(8);
    add_tile(10);
    display();
    delete_head();
    display();
    delete_tail();
    display();
    find(2);
    find(10);
    counter();
    return 0;
}