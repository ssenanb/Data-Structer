#include<stdio.h>
#include<stdlib.h>

struct dugum{
    int veri;
    struct dugum *adres;
};

typedef struct dugum bliste;

bliste *dugum1;

bliste* dugumolustur(int veri);
void dugumyazdır();
int elemansay();

int main(){
    dugum1 = dugumolustur(3);
    bliste *dugum2 = dugumolustur(4);
    bliste *dugum3 = dugumolustur(5);
    dugum1 ->adres = dugum2;
    dugum2 ->adres = dugum3;
    dugumyazdır();
    elemansay();
    return 0; 
}


bliste *dugumolustur(int veri){
    bliste *yenidugum;
    yenidugum = (bliste*)malloc(sizeof(bliste));
    yenidugum -> veri = veri;
    yenidugum -> adres = NULL;
    return yenidugum;
}

void dugumyazdır(){
    bliste * temp = dugum1;
    while(temp != NULL){
        printf("%d ",temp ->veri);
        temp = temp -> adres;
    }
    printf("\n");
}

int elemansay(){
    bliste *temp = dugum1;
    int sayac = 0;
    while(temp != NULL){
        sayac += 1;
        temp = temp -> adres;
    }
    printf("%d",sayac);
    printf("\n");
}
