#include <stdio.h>
#include <stdlib.h>

struct dugum{
    int veri1;
    int veri2;
    struct dugum *onceki;
    struct dugum *sonraki;
};
typedef struct dugum cift_yonlu_bliste;

cift_yonlu_bliste *dugum1;

cift_yonlu_bliste *dugumolustur(int veri1,int veri2);
void dugumyazdir();
void bastanekle(int veri1,int veri2);
void sondanekle(int veri1,int veri2);

int main(){
    dugum1 = dugumolustur(1,2);
    cift_yonlu_bliste* dugum2 = dugumolustur(3,4);
    cift_yonlu_bliste* dugum3 = dugumolustur(5,6);
    cift_yonlu_bliste* dugum4 = dugumolustur(7,8);
    cift_yonlu_bliste* dugum5 = dugumolustur(9,10);
    dugum1 ->sonraki = dugum2;
    dugum2 ->sonraki = dugum3;
    dugum3 -> sonraki = dugum4;
    dugum4 ->sonraki = dugum5;
    dugum2 ->onceki = dugum1;
    dugum3 -> onceki = dugum2;
    dugum4 -> onceki = dugum3;
    dugum5 -> onceki = dugum4;
    dugumyazdir();
    bastanekle(-1,0);
    dugumyazdir();
    sondanekle(11,12);
    dugumyazdir();
    return 0;

}

cift_yonlu_bliste *dugumolustur(int veri1,int veri2){
    cift_yonlu_bliste *yenidugum = (cift_yonlu_bliste*)malloc(sizeof(cift_yonlu_bliste));
    yenidugum -> veri1 = veri1;
    yenidugum -> veri2 = veri2;
    yenidugum ->onceki = NULL;
    yenidugum -> sonraki = NULL;
    return yenidugum;
}

void dugumyazdir(){
    cift_yonlu_bliste *temp = dugum1;
    while(temp != NULL){
        printf("%d %d ",temp->veri1,temp->veri2);
        temp = temp ->sonraki;
    }
    printf("\n");
}

void bastanekle(int veri1,int veri2){
    cift_yonlu_bliste *temp = dugum1;
    cift_yonlu_bliste *yenidugum = dugumolustur(veri1,veri2);
    yenidugum -> sonraki = dugum1;
    dugum1 ->onceki = yenidugum;
    yenidugum -> onceki = NULL;
    dugum1 = yenidugum;
}

void sondanekle(int veri1,int veri2){
    cift_yonlu_bliste *temp = dugum1;
    cift_yonlu_bliste *yenidugum = dugumolustur(veri1,veri2);
    while(temp -> sonraki != NULL)
        temp = temp ->sonraki;
   yenidugum -> onceki = temp;
   temp ->sonraki = yenidugum;
   yenidugum -> sonraki = NULL;
}


        

