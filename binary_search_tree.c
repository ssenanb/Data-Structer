#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *right;
    struct node *left;
};

typedef struct node tree;

tree *root = NULL;

tree *add(tree *node,int data);
void in_order_to(tree *node);
tree *delete(tree *node,int data);
tree *min(tree *node);
tree *max(tree *node);
tree *search(tree *node,int data);

int main(){
    root = add(root,10);
    root = add(root,5);
    root = add(root,20);
    root = add(root,4);
    root = add(root,3);
    root = add(root,25);
    root = add(root,12);
    in_order_to(root);
    printf("\n");
    delete(root,10);
    in_order_to(root);
    printf("\n");
    delete(root,4);
    in_order_to(root);
    printf("\n");
    printf("min: %d\n",min(root)-> data);
    printf("max: %d\n",max(root) -> data);

    tree *result = search(root,10);
    if (result != NULL) {
        printf("Found: %d\n", result->data);
    } else {
        printf("Not found\n");
    }

    result = search(root, 20);
    if (result != NULL) {
        printf("Found: %d\n", result->data);
    } else {
        printf("Not found\n");
    }
    return 0;
}

void in_order_to(tree *node){
    if(node != NULL){
        in_order_to(node -> left);
        printf("%d ",node -> data);
        in_order_to(node -> right);
    }
}

tree *add(tree *node,int data){
    tree *newNode = (tree*)malloc(sizeof(tree));
    newNode -> data = data;
    newNode -> right = NULL;
    newNode -> left = NULL;

    if(node == NULL)
        return newNode;
    else{
        if(node -> data > data)
                node -> left = add(node -> left,data);
        else
                node -> right = add(node -> right,data);
        }
    return node;
    printf("\n");
    }

tree *delete(tree *node,int data){
    if(node == NULL)
        printf("empty tree\n");
    else if(node -> data > data)
        node -> left = delete(node -> left,data);
    else if(node -> data < data) 
        node -> right = delete(node -> right,data);
    else{
        // node has 0 or 1 child
        if(node -> left == NULL){
            tree *temp = node -> right;
            free(node);
            return temp;
        }else if(node -> right == NULL){
            tree *temp = node -> right;
            free(node);
            return temp;
        }
        //node has 2 childs
        tree *temp = min(node -> right);
        node -> data = temp -> data;
        node -> right = delete(node -> right, temp -> data);
    }
    return node;
}

tree *min(tree *node){
    if(node == NULL)
        printf("tree empty\n");
    else if(node -> left == NULL)
        return node;
    else
        return min(node -> left);
}

tree *max(tree *node){
    if(node == NULL)
        printf("tree empty\n");
    else if(node -> right == NULL)
        return node;
    else
        return max(node -> right);
}

tree *search(tree *node,int data){
    if(node == NULL)
        return NULL;
    else if(node -> data == data)
        return node;
    else if(node -> data > data)
        return search(node -> left,data);
    else if(node -> data < data)
        return search(node -> right, data);
}