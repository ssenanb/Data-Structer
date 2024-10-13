#include <stdio.h>
#include <stdlib.h>

struct dugum{
	int veri;
	struct dugum *sonraki;
};
typedef struct dugum dairesel_ty_bliste;

dairesel_ty_bliste *root = NULL; // global tanimlama.

dairesel_ty_bliste *dugumolustur(int veri);
void dugumyazdir();
void bastanekle(int veri);
void sondanekle(int veri);

int main(){
    dairesel_ty_bliste *dugum1 = dugumolustur(2);
    dairesel_ty_bliste *dugum2 = dugumolustur(4);
    dairesel_ty_bliste *dugum3 = dugumolustur(6);
    dairesel_ty_bliste *dugum4 = dugumolustur(8);
    dairesel_ty_bliste *dugum5 = dugumolustur(10);

    root = dugum1;

    dugum1 -> sonraki = dugum2;
    dugum2 -> sonraki = dugum3;
    dugum3 -> sonraki = dugum4;
    dugum4 -> sonraki = dugum5;
    dugum5 -> sonraki = dugum1;

    dugumyazdir();
    bastanekle(0);
    dugumyazdir();
    sondanekle(12);
    dugumyazdir();
    
    return 0;
}

dairesel_ty_bliste *dugumolustur(int veri){
    dairesel_ty_bliste *yenidugum;
    yenidugum = (dairesel_ty_bliste*)malloc(sizeof(dairesel_ty_bliste));
    yenidugum -> veri = veri;
    yenidugum ->sonraki = NULL;
    return yenidugum;
}

void dugumyazdir(){
    dairesel_ty_bliste *temp = root;
    printf("%d ",temp-> veri);
    temp = temp -> sonraki;
    while(temp != root){
        printf("%d ",temp->veri);
        temp = temp ->sonraki;
        }
    printf("\n");
}

void bastanekle(int veri){
    dairesel_ty_bliste *temp = root;
    dairesel_ty_bliste * yenidugum = dugumolustur(veri);
    while( temp -> sonraki != root)
        temp = temp -> sonraki;
    yenidugum -> sonraki = root;
    temp -> sonraki = yenidugum;
    root = yenidugum;
}

void sondanekle(int veri){
    dairesel_ty_bliste *temp = root;
    dairesel_ty_bliste *yenidugum = dugumolustur(veri);
    while (temp -> sonraki != root)
        temp = temp -> sonraki;
    temp ->sonraki = yenidugum;
    yenidugum -> sonraki = root;
}
