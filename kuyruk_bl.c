#include<stdio.h>
#include<stdlib.h>

struct dugum{
    int veri;
    struct dugum *sonraki;
};

typedef struct dugum queue;

queue *head = NULL;
queue *tail = NULL;

int enqueue(int);
void bastir();
void dequeue();

int main(){
    enqueue(10);
    printf("tail degeri:%d  head degeri:%d\n",tail-> veri,head->veri);
    enqueue(20);
    printf("tail degeri:%d  head degeri:%d\n",tail-> veri,head->veri);
    enqueue(30);
    printf("tail degeri:%d  head degeri:%d\n",tail-> veri,head->veri);
    enqueue(40);
    printf("tail degeri:%d  head degeri:%d\n",tail-> veri,head->veri);
    bastir();
    dequeue();
    printf("tail degeri:%d head degeri:%d \n",tail-> veri,head->veri);
    bastir();
}

int enqueue(int veri){
    queue *yenidugum = (queue*)malloc(sizeof(queue));
    yenidugum -> veri = veri;
    yenidugum -> sonraki = NULL;
    if(tail == NULL){
        head = yenidugum;
        tail = yenidugum;
    }else{
        tail -> sonraki = yenidugum;
        tail = yenidugum; 
    }
}

void dequeue(){
    queue *temp = head;
    head = temp -> sonraki;
    free(temp);

}

void bastir(){
    queue *temp = head ;
    while(temp != NULL){ 
        printf("%d ",temp -> veri);
        temp = temp -> sonraki;
    }
    printf("\n");
} 
