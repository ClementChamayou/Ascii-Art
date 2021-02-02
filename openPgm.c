/*-------------------------------------------------
*
*   Transformation d'une image PGM en AsciiArt
*
*--------------------------------------------------
*
* Auteur : Clément Chamayou
* Fichier : main.c
* Date : 29 janvier 2021
*
*/

#include <stdio.h>

/* renvoyer aussi la valeur maximale + 1*/

int main(){

    FILE * file = fopen("chat.pgm","r");
    char magicNb[2];
    int header[3];

    if(!file){
        printf("Il y a un problème d'ouverture de fichier.\n");
        fclose(file);
        return 0;
    }
    else{
        
        fscanf(file,"%s %d %d %d",magicNb,&header[0],&header[1],&header[2]);
        printf("Nombre magique : %s\nLargeur : %d\nHauteur : %d\nValeur maximale : %d\n",magicNb,header[0],header[1],header[2]);

    }
    fclose(file);
    return 0;

}