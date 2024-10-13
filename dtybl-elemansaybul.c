#include <stdio.h>
#include <stdlib.h>

struct dugum{
	int veri;
	struct dugum *sonraki;
};
typedef struct dugum dairesel_ty_bliste;

dairesel_ty_bliste *dugum1;

dairesel_ty_bliste *dugumolustur(int veri);
void dugumyazdir(dairesel_ty_bliste *root);
void elemansay(dairesel_ty_bliste *root);
void elemanbul(int aranan,dairesel_ty_bliste *root);

int main(){
    dairesel_ty_bliste *dugum1 = dugumolustur(2);
    dairesel_ty_bliste *dugum2 = dugumolustur(4);
    dairesel_ty_bliste *dugum3 = dugumolustur(6);
    dairesel_ty_bliste *dugum4 = dugumolustur(8);
    dairesel_ty_bliste *dugum5 = dugumolustur(10);
    dugum1 -> sonraki = dugum2;
    dugum2 -> sonraki = dugum3;
    dugum3 -> sonraki = dugum4;
    dugum4 -> sonraki = dugum5;
    dugum5 -> sonraki = dugum1;

    dugumyazdir(dugum1);
    elemansay(dugum1);
    elemanbul(6,dugum1);
    elemanbul(12,dugum1);
}

dairesel_ty_bliste *dugumolustur(int veri){
    dairesel_ty_bliste *yenidugum;
    yenidugum = (dairesel_ty_bliste*)malloc(sizeof(dairesel_ty_bliste));
    yenidugum -> veri = veri;
    yenidugum ->sonraki = NULL;
    return yenidugum;
}

void dugumyazdir(dairesel_ty_bliste *root){
    dairesel_ty_bliste *temp = root;
    printf("%d ",temp-> veri);
    temp = temp -> sonraki;
    while(temp != root){
        printf("%d ",temp->veri);
        temp = temp ->sonraki;
        }
    printf("\n");
}

void elemansay(dairesel_ty_bliste *root){
    dairesel_ty_bliste *temp = root;
    int sayac = 0;
    do{
        temp = temp -> sonraki;
        sayac += 1;
    }while(temp != root);
    
    printf("eleman sayisi %d\n",sayac);
}

void elemanbul(int aranan,dairesel_ty_bliste *root){
    dairesel_ty_bliste *temp = root;
    int yok = 0; // kontrol ibaresi,
    do{
        if(temp -> veri == aranan){
            printf("%d elemani bulundu\n",aranan);
            yok = 1;//eleman bulundugunda ibare guncellenir.
            }
        temp = temp -> sonraki;
    }while (temp != root);
    
    if(!yok) printf("bu eleman listede yok.\n");         
}