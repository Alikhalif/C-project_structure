#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct{
    char Cin[10];
    char Nom[30];
    int Age;
}perssone;

perssone info[1000];
static int i;
static int nbrC;
static int indexTable=0;

void AjouterCompte();
void PlusieurCompte(int);
int Recherche(int);
void modifier(int);
void supprimer(int);

void AjouterCompte(){
    system("cls");
    printf("\ngive the cin : ");
    scanf("%s",&info[i].Cin);
    printf("give the name :");
    scanf("%s",&info[i].Nom);
    printf("give the Age : ");
    scanf("%d",&info[i].Age);
    //indexTable++;

    
        printf("\nThank you for adding \nyour information : \n");
        printf("%s | %s | %d \n",info[i].Cin,info[i].Nom,info[i].Age);  
    

}

void PlusieurCompte(int nbrC){

    for(i=0; i<nbrC; i++){
        printf("\ngive the cin : ");
        scanf("%s",&info[i].Cin);
        printf("give the name :");
        scanf("%s",&info[i].Nom);
        printf("give the Age : ");
        scanf("%d",&info[i].Age);
        indexTable++;
    }
    printf("\nThank you for adding \nyour information : \n");
    for(i=0; i<indexTable; i++){
        printf("\t %s | %s | %d \n",info[i].Cin,info[i].Nom,info[i].Age);
    }
}

int Recherche(int nbrC){
    char cin[10];
    bool res = false;
    printf("\ngive the cin : ");
    scanf("%s",&cin);
    for(i=0; i<nbrC; i++){
        if(stricmp(cin,info[i].Cin) == 0){
            printf("\n\tResults = %s | %s | %d", info[i].Cin, info[i].Nom, info[i].Age);
            res = true;
            return i;
        }
    }
    if(res == false){
        printf("\n\tAccount not found !");
        return -1;
    }
}

void modifier(int nbrC){
    char cin[10];
    int res = false;
    int cinR = Recherche(nbrC);
    
    if(cinR != -1){
        printf("\ngive the cin : ");
        scanf("%s",&info[cinR].Cin);
        printf("give the name :");
        scanf("%s",&info[cinR].Nom);
        printf("give the Age : ");
        scanf("%d",&info[cinR].Age);
    }
    
    printf("\nThank you for adding \nyour information : \n");
    for(i=0; i<nbrC; i++){
        printf("\n\t %s | %s | %d \n",info[i].Cin,info[i].Nom,info[i].Age);
    }
}

void supprimer(int nbrC){
    int nbrS;
    int j;
    printf("Enter the number of accounts you want to delete : ");
    scanf("%d",&nbrS);
    for(j=0; j<nbrS; j++){
        int cinR = Recherche(nbrC);

        for(i=cinR; i<nbrC; i++){
            info[i] = info[i+1];
        }
        nbrC--;
    
    printf("\nThank you for deleting \nyour information : \n");
    for(i=0; i<nbrC; i++){
        printf("\n\t %s | %s | %d \n",info[i].Cin,info[i].Nom,info[i].Age);
    }
    }
}

void Menu(){
    int choix;
    printf("\n\t>> welcom to my App <<");
    do{
        
        printf("\n\n\t=========================================\n");
        printf("\n\t1 - Create more than one account .\n\t2 - Search .\n\t3 - Update account .\n\t4 - Delete account .\n\t5 - Exit .");
        printf("\n\n\t=========================================\n");
        printf("\n\n\t==> ");
        scanf("%d",&choix);
        

        

        switch(choix){
            case 1:printf("\nEnter the number of accounts : ");
                scanf("%d",&nbrC);
                PlusieurCompte(nbrC);
                break;
            case 2:Recherche(nbrC);
                break;
            case 3:modifier(nbrC);
                break;
            case 4:supprimer(nbrC);
                break;
            case 5: printf("Goodby ^_^");
                break;
        }
    }while (choix != 6);
    
    
}

int main(){
    //int nbrC;
    //int ResSearch;
    Menu();
    //AjouterCompte();
    // printf("donner nomber des compte : ");
    // scanf("%d",&nbrC);
    // PlussiuerCompte(nbrC);
    //ResSearch = Recherche(nbrC);
    //printf("\nRecherche = %d",ResSearch);
    // supprimer(nbrC);
    //modifier(nbrC);
}