#include<stdio.h>
#include<stdlib.h>

struct dugum{
    int veri;
    struct dugum *sonraki;
};

typedef struct dugum yigin;

yigin *root = NULL;

void push(int);
void bastir();
void pop();
void top();

int main(){
    push(10);
    push(20);
    push(30);
    bastir();
    pop();
    bastir();
    pop();
    bastir();
    push(20);
    push(30);
    bastir();
    top();
    pop();
    bastir();
    top();
}

void push(int veri){
    yigin *yenidugum = (yigin*)malloc(sizeof(yigin));
    yenidugum -> veri = veri;
    if(root == NULL)
        yenidugum -> sonraki = NULL;
    else
        yenidugum-> sonraki = root;
    root = yenidugum;
}

void bastir(){
    yigin *temp = root;
    while(temp != NULL){
        printf("%d ",temp ->veri);
        temp = temp -> sonraki;
    }
    printf("\n");
}

void pop(){//root ifadesi push ifadesinde gucellendi
    yigin *temp = root;
    root = temp -> sonraki;
    free(temp);
}

void top(){
    yigin *temp = root;
    printf("tepedeki eleman: %d",temp ->veri);
    printf("\n");
}
    