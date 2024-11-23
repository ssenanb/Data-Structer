#include<stdio.h>
#include<stdlib.h>

struct n{
    int data;
    struct n *next;
};

typedef struct n node;

node * root = NULL;

node *add_head(int data){
    node *newNode = (node*)malloc(sizeof(node));
    newNode -> data = data;
    newNode -> next = NULL;
    if(root == NULL){
        newNode -> next = newNode;
        root = newNode;
    }
    else{//önemli!!!
        node *temp = root;
        while(temp -> next != root)
            temp = temp -> next;
        temp -> next = newNode;
        newNode -> next = root;
        root = newNode;
    }
}
node *add_tail(int data){
    node *newNode = (node*)malloc(sizeof(node));
    newNode -> data = data;
    newNode -> next = NULL;
    if(root == NULL){
        newNode ->next = newNode;
        root = newNode;
    }else{
        node *temp = root;
        while(temp -> next != root)
            temp = temp -> next;
        temp -> next = newNode;
        newNode -> next = root;
    }
}
void delete_head(){
    if(root == NULL){
        printf("this list is empty\n");
        return;
    }else{
        node *temp = root;
        while(temp -> next != root)
            temp = temp -> next;
        temp -> next = root -> next;
        free(root);
        root = temp -> next;
    }
}
void delete_tail(){
    if(root == NULL){
        printf("this list is empty\n");
        return;
    }else{
        node *temp = root;
        while(temp -> next -> next != root)
            temp = temp -> next;
        free(temp -> next);
        temp -> next = root;
    }
}
void find(int find){
    node *temp = root;
    do {
        if (find == temp->data) {
            printf("Element found\n");
            return;
        }
        temp = temp->next;
    } while (temp != root);
    printf("element wasn't\n");
}

void counter(){
    int counter = 0;
    node *temp = root;
    do{
         counter++;
        temp = temp -> next;
    }while(temp != root);
    
    printf("there are %d element",counter);
    printf("\n");
}
void display(){
    node* temp = root;
    do{
        printf("%d ",temp -> data);
        temp = temp -> next;
    } while (temp != root);
    printf("\n");
}

int main(){
    add_head(2);
    add_head(4);
    add_head(6);
    display();
    add_tail(1);
    add_tail(0);
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