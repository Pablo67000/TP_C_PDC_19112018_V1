#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
//VARIABLE POUR LE MENU
    char cMenu;

//VARIABLE POUR ARABE A ROMAIN
    //On utilisera aussi cette variable pour romain à arabe
    int nNbr = 0;

//VARIABLES POUR ROMAIN A ARABE
    int nLongueur;
    int nCpt;
    //on définit la taille de notre tableau et notre string à 15 car un nombre romain <3999 fera toujours moins de 15 caracteres
    int tTableau[15];
    char sNbr[15];

    //Menu qui permet de choisir le sens de conversion, si on entre 'a' on fait d'arabe à romain, si 'b' l'inverse
    printf("Bonjour, bienvenue dans le convertisseur de nombres romains.\n");
    printf("\n");
    printf("Pour convertir nombre arabe en nombre romain entrez \"a\", pour nombre romain en nombre arabe entrez \"b\":\n");
    scanf("%c",&cMenu);
    //On utilise un cas parmis avec trois possibilités
    switch(cMenu) {
    //Dans le cas où l'utilisateur entre 1, on lance le programme de nombre arabe à nombre romain
    case 'a' :

// ARABE A ROMAIN

            printf("Entrez un entier entre 1 et 3999:\n");
            scanf("%d",&nNbr);
            printf("Votre nombre arabe en nombre romain = ");

            while (nNbr > 0){
                if (nNbr >= 1000){
                    printf("M");
                    nNbr=nNbr-1000;
                }else if (nNbr >= 900){
                    printf("CM");
                    nNbr=nNbr-900;
                }else if (nNbr >= 500){
                    printf("D");
                    nNbr=nNbr-500;
                }else if (nNbr >= 400){
                    printf("CD");
                    nNbr=nNbr-400;
                }else if (nNbr >= 100){
                    printf("C");
                    nNbr=nNbr-100;
                }else if (nNbr >= 90){
                    printf("XC");
                    nNbr=nNbr-90;
                }else if (nNbr >= 50){
                    printf("L");
                    nNbr=nNbr-50;
                }else if (nNbr >= 40){
                    printf("XL");
                    nNbr=nNbr-40;
                }else if (nNbr >= 10){
                    printf("X");
                    nNbr=nNbr-10;
                }else if (nNbr >= 9){
                    printf("IX");
                    nNbr=nNbr-9;
                }else if (nNbr >= 5){
                    printf("V");
                    nNbr=nNbr-5;
                }else if (nNbr >= 4){
                    printf("IV");
                    nNbr=nNbr-4;
                }else if (nNbr >= 1){
                    printf("I");
                    nNbr=nNbr-1;
                }
            }

    break;

    //Dans le cas où l'utilisateur entre 2, on lance le programme de nombre romain à entier
    case 'b' :

//ROMAIN A ARABE

            printf("Entrez un nombre romain inferieur a 3999:\n");
            scanf("%s",sNbr);
            nLongueur = strlen(sNbr);

            for (nCpt = 0; nCpt < nLongueur; nCpt++){
                if(sNbr[nCpt]=='M'){
                    tTableau[nCpt]=1000;
                }else if(sNbr[nCpt]=='D'){
                    tTableau[nCpt]=500;
                }else if(sNbr[nCpt]=='C'){
                    tTableau[nCpt]=100;
                }else if(sNbr[nCpt]=='L'){
                    tTableau[nCpt]=50;
                }else if(sNbr[nCpt]=='X'){
                    tTableau[nCpt]=10;
                }else if(sNbr[nCpt]=='V'){
                    tTableau[nCpt]=5;
                }else if(sNbr[nCpt]=='I'){
                    tTableau[nCpt]=1;
                }else{
                    printf("Caractere invalide, rentrez caractere romain (I,V,X,L,C,D,M)");
                }
            }
            nNbr=tTableau[nLongueur-1];
            for(nCpt=nLongueur-1; nCpt>0; nCpt--){
                if(tTableau[nCpt]>tTableau[nCpt-1]){
                    nNbr=nNbr-tTableau[nCpt-1];
                }else if(tTableau[nCpt]==tTableau[nCpt-1] || tTableau[nCpt]<tTableau[nCpt-1]){
                    nNbr=nNbr+tTableau[nCpt-1];
                }
            }
            printf("Votre nombre romain en nombre arabe = %d\n",nNbr);

    break;

    //Si l'utilisateur entre autre chose que 'a' ou 'b' on indique que son choix est invalide
    default :
            printf("Choix invalide, choisir \"a\" ou \"b\"");
    break;
    }

    return 0;
}
