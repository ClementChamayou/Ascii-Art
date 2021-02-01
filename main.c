/*-------------------------------------------------
*
*   Adaptation du code d'ouverture de fichier bmp
*
*--------------------------------------------------
*
* Auteur : Clément Chamayou
* Fichier : main.c
* Date : 29 janvier 2021
*
*/

#include "bmp.h"
#include <stdlib.h>
#include <stdio.h> 

int main(){
	
	//Image * I = NouvelleImage(256,256);
	Image * I = Charger("zozor.bmp");
    Image * pantone = NouvelleImage(I->h,I->w);

    //if (I != NULL){
        /* Crée un pantone de couleurs */
        for(int i=0; i<pantone->h; i++)
        {
            for(int j=0; j<pantone->w; j++)
            {
                Pixel p;
                p.r = i;
                p.g = j;
                p.b = 0;
                SetPixel(pantone,i,j,p);
            }
        }
        
        Sauver(pantone,"test.bmp");
        DelImage(pantone);
        DelImage(I);
        return 0;
    //}
	/*else{
        printf("L'image s'est mal chargée.\n");
        return 0;
    }*/
}