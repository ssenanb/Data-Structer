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
void elemanbul(int aranan);
void bastansil();
void sondansil();
void aradansil(bliste *dugum);

int main(){
    dugum1 = dugumolustur(3);
    bliste *dugum2 = dugumolustur(4);
    bliste *dugum3 = dugumolustur(5);
    bliste *dugum4 = dugumolustur(6);
    bliste* dugum5 = dugumolustur(7);
    bliste * dugum6 = dugumolustur(8);
    dugum1 ->adres = dugum2;
    dugum2 ->adres = dugum3;
    dugum3 -> adres =dugum4;
    dugum4 ->adres = dugum5;
    dugum5 -> adres = dugum6;
    dugumyazdır();
    elemansay();
    
    elemanbul(4);
    elemanbul(1);

    bastansil();
    dugumyazdır();

    sondansil();
    dugumyazdır();

    aradansil(dugum3);
    dugumyazdır();

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
    printf("%d",sayac); //"return sayac" ifadeside kullanılabilirdi.
    printf("\n");
}

void elemanbul(int aranan){
    bliste * temp = dugum1;
    while(temp != NULL){
       // temp = temp -> adres; yeri burada olduğunda segmantasyon hatası veriyor çünkü önce sıradaki düğüme geçip sonra karşılaştırma yapıyoruz ,hatalı durum.
       // düzeltmek için tempi aşağıya alıp return ekledik çünkü return sonlanma ifadesi veriyor.
        if(temp -> veri == aranan){
            printf("aranan eleman bulundu\n");
            return;//fonksiyondan çık(başarılı sonlanma durumu)
        }
        temp = temp -> adres;
    }
        printf("aranan eleman bu listede yok,bulunamadı\n");
}

void bastansil(){
    bliste * temp = dugum1;
    dugum1 = dugum1 ->adres;
    free(temp);
}

void sondansil(){
    bliste * temp = dugum1;
    while (temp->adres->adres != NULL){//temp->adres->adres bir kalıptır.sondan önceki düğüme erişmede kullanılır.
        temp = temp->adres; 
    }
    free(temp->adres);  
    temp->adres = NULL;//temp şu an sondan bir önceki düğüm
}

void aradansil(bliste *dugum){
    bliste *temp = dugum1;
    while( temp->adres != dugum){
        temp = temp ->adres;
    }
    temp ->adres = dugum ->adres;
    free(dugum);
}