#ifndef _BMP_H
#define _BMP_H

typedef struct Pixel
{
	unsigned char r,g,b;
} Pixel;

typedef struct Image
{
	int w,h;
	Pixel* dat;
} Image;

/* Charge une image bitmap 
Retourne l'image bmp chargée 
*/
Image* Charger(const char* fichier);

/* Enregistre l'image modifiée
Retourne 0 (pour l'instant)
*/
int Sauver(Image*,const char* fichier);

/* Crée une image d'une largeur w et d'une hauteur h
Retourne un pointeur vers la nouvelle image crée
*/
Image* NouvelleImage(int w,int h);

/* Copie l'image entrée en paramètre et retourne un pointeur vers la nouvelle iamge */
Image* CopieImage(Image*);

/* Rempli les couleurs d'un pixel passé en paramètre dans un pixel de l'image
Paramètres : image* = pointeur vers une image à modifier
             (i,j) = coordonnée du pixel à modifier
             p = pixel servant à remplir un pixel donné de l'image
*/
void SetPixel(Image*,int i,int j,Pixel p);

/* Retourne un certain pixel de l'image */
Pixel GetPixel(Image*,int i,int j);

/* Libère l'espace alloué pour une image */
void DelImage(Image*);

#endif
 
