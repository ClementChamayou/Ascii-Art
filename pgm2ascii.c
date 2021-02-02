#include <stdio.h>
#include <stdlib.h>

char* pgm2ascii(char* pix, int row, int col, char nbNiveaux){
	char* imgAscii = malloc(row * col * sizeof(char)); 
	char Ascii16[16] = { '.', '-', '_', '/', '|', '(', 'c', 'v', 'u', 'J', 'U', 'Y', 'k', 'b', '#', '@' };
	char temp, ratio;
	int i, j;
	for (i=0; i<row; i++){
		for (j=0; j<col; j++){
			/* Obtenir la valeur du pixel[i][j] */
			temp = *(pix + col*i + j);
			/* Ramener à 16 niveaux de gris */
			ratio = nbNiveaux / 16;
			temp = temp / ratio ;
			switch (temp){
				case 0: 
					*(imgAscii + col*i + j)=Ascii16[0];
					break;
				case 1: 
					*(imgAscii + col*i + j)=Ascii16[1];
					break;
				case 2: 
					*(imgAscii + col*i + j)=Ascii16[2];
					break;
				case 3: 
					*(imgAscii + col*i + j)=Ascii16[3];
					break;
				case 4: 
					*(imgAscii + col*i + j)=Ascii16[4];
					break;
				case 5: 
					*(imgAscii + col*i + j)=Ascii16[5];
					break;
				case 6: 
					*(imgAscii + col*i + j)=Ascii16[6];
					break;
				case 7: 
					*(imgAscii + col*i + j)=Ascii16[7];
					break;
				case 8: 
					*(imgAscii + col*i + j)=Ascii16[8];
					break;
				case 9: 
					*(imgAscii + col*i + j)=Ascii16[9];
					break;
				case 10: 
					*(imgAscii + col*i + j)=Ascii16[10];
					break;
				case 11: 
					*(imgAscii + col*i + j)=Ascii16[11];
					break;
				case 12: 
					*(imgAscii + col*i + j)=Ascii16[12];
					break;
				case 13: 
					*(imgAscii + col*i + j)=Ascii16[13];
					break;
				case 14: 
					*(imgAscii + col*i + j)=Ascii16[14];
					break;
				case 15: 
					*(imgAscii + col*i + j)=Ascii16[15];
					break;
			}	

		}

	}
	return imgAscii;
}