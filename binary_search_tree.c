#include <stdlib.h>
#include <stdio.h>

struct n{
    int data;
    struct n *sol;
    struct n *sag;
};

typedef struct n node;

node *ekle(node *agac,int data){
    if(agac == NULL){
        node *dugum = (node *)malloc(sizeof(node));
        dugum -> data = data;
        dugum -> sol = NULL;
        dugum -> sag = NULL;
        return dugum; // *
    }else{
        node *dugum = (node *)malloc(sizeof(node));
        dugum -> data = data;
        dugum -> sol = NULL;
        dugum -> sag = NULL;

        if(agac -> data > data)
           agac -> sol = ekle(agac -> sol,data);
        else
            agac -> sag = ekle(agac -> sag ,data);
    }
    return agac;//* return önemli bunlarda!
}

int min(node *agac){
    while(agac -> sol != NULL)
        agac = agac -> sol;
    return agac -> data;
}
int max(node *agac){
    while(agac -> sag != NULL)
        agac = agac -> sag;
    return agac -> data;
}

node * sil(node *agac,int data){
    if(agac == NULL)
        printf("agac bos\n");
    else{
        if(agac -> data == data){// kök silme
            if(agac -> sol == NULL && agac -> sag == NULL)
                return NULL;
           else if (agac -> sag != NULL){
                agac -> data = min(agac -> sag);//roota değeri getir
                agac -> sag = sil(agac -> sag,min(agac -> sag));//roota getirdiğin değeri eski yerinden sil
                return agac;            
            }//üstte ağacı sağının en büyüğünü koyduk eğer sağ tamamen boşsa solun en küçüğünü koyacak aşağıda da bunu yaptık
            else{
                agac -> data = max(agac -> sol);//roota değeri getir
                agac -> sol = sil(agac -> sol,max(agac -> sol));//roota getirdiğin değeri eski yerinden sil
                return agac;
            }
        }else if(agac -> data < data){
                agac -> sag = sil(agac -> sag,data);
                return agac;
        }else{//agac -> data > data
                agac -> sol = sil(agac -> sol,data);
                return agac;
        }
    }
}

node *ara(node *agac,int data){
    if(agac == NULL)
        return NULL;
    else if(agac -> data == data)
        return agac;
    else if(agac -> data > data)
        return ara(agac -> sol,data);
    else
        return ara(agac -> sag,data);
}

//sol kök sağ
void inorder(node* agac){
    if(agac != NULL){
        inorder(agac -> sol);
        printf("%d ",agac -> data);
        inorder(agac -> sag);
    }
}
//kök sol sağ
void preorder(node *agac){
    if(agac != NULL){
        printf("%d ",agac -> data);
        preorder(agac -> sol);
        preorder(agac -> sag);
    }
}
//sol sağ kök
void postorder(node * agac){
    if(agac != NULL){
        postorder(agac-> sol);
        postorder(agac -> sag);
        printf("%d ",agac -> data);
    }
}

int main(){
    node *root = NULL;

    root = ekle(root,10);
    root = ekle(root,15);
    root = ekle(root,5);
    root = ekle(root,25);
    root = ekle(root,2);
    root = ekle(root,6);
    root = ekle(root,11);
    root = ekle(root,30);

    printf("inorder: ");
    inorder(root);
    printf("\n");
    printf("preorder: ");
    preorder(root);
    printf("\n");
    printf("postorder: ");
    postorder(root);
    printf("\n");

    root = sil(root,10);
    printf("inorder: ");
    inorder(root);
    printf("\n");

    root = sil(root,2);
    printf("inorder: ");
    inorder(root);
    printf("\n");


    if(ara(root,25) != NULL)
        printf("bulundu\n");
    else
        printf("bulunamadı\n");

    if(ara(root,100) != NULL)
        printf("bulundu\n");
    else
        printf("bulunamadı\n");

    printf("%d ",min(root));
    printf("%d ",max(root));
    

    return 0;
}
