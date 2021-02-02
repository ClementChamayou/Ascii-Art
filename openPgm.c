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

        int row = header[1];
        int col = header[0];
        int nbNiveaux = header[2];
       
        char imgAscii [row][col];
        char Ascii16[16] = { '.', '-', '_', '/', '|', '(', 'c', 'v', 'u', 'J', 'U', 'Y', 'k', 'b', '#', '@' };
        int temp, ratio;
       
        for (int i=0; i<row; i++){

            for (int j=0; j<col; j++){

                /* Obtenir la valeur du pixel[i][j] */
                fscanf(file,"%d",&temp);
                /* Ramener à 16 niveaux de gris */
                ratio = nbNiveaux / 16;
                temp = temp / ratio ;
                
                switch (temp){
                    case 0: 
                        imgAscii[i][j] =Ascii16[0];
                        break;
                    case 1: 
                        imgAscii[i][j] =Ascii16[1];
                        break;
                    case 2: 
                        imgAscii[i][j] =Ascii16[2];
                        break;
                    case 3: 
                        imgAscii[i][j] =Ascii16[3];
                        break;
                    case 4: 
                        imgAscii[i][j] =Ascii16[4];
                        break;
                    case 5: 
                        imgAscii[i][j] =Ascii16[5];
                        break;
                    case 6: 
                        imgAscii[i][j] =Ascii16[6];
                        break;
                    case 7: 
                        imgAscii[i][j] =Ascii16[7];
                        break;
                    case 8: 
                        imgAscii[i][j] =Ascii16[8];
                        break;
                    case 9: 
                        imgAscii[i][j] =Ascii16[9];
                        break;
                    case 10: 
                        imgAscii[i][j] =Ascii16[10];
                        break;
                    case 11: 
                        imgAscii[i][j] =Ascii16[11];
                        break;
                    case 12: 
                        imgAscii[i][j] =Ascii16[12];
                        break;
                    case 13: 
                        imgAscii[i][j] =Ascii16[13];
                        break;
                    case 14: 
                        imgAscii[i][j] =Ascii16[14];
                        break;
                    case 15: 
                        imgAscii[i][j] =Ascii16[15];
                        break;
                    
                    
                }	
                printf("%c",imgAscii[i][j]);
                
            }
            printf("\n");

        }

    }
    fclose(file);
    return 0;

}