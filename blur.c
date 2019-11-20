/**
 * blur.c
 *
 *	@brief blurs the image
 *
 *	Applies the box blur mask [1,1,1]
 *							  [1,1,1]
 *							  [1,1,1]
 *	where a pixel has the format of  the box its in
 *  Created on: Nov 20, 2019
 *      Author: panikos
 */

#include "blur.h"
#include "BMP_Image.h"
#include "BMP_Image.h"
void blur(bmp_image *prev) {
	double_word width = prev->header->infoHeader.biWidth;
	double_word height = prev->header->infoHeader.biHeight;

	//creating our pixel[heigth][width]
	Pixel ***pixelArray = (Pixel***) malloc(height * sizeof(Pixel**));

	int i = 0;
		int j = 0;
	for ( i = 0; i < height; i++) {
		pixelArray[i] = (Pixel**) malloc((width) * sizeof(Pixel*));

	}

	for(int i=0; i<height; i++)
	{
		for(int j=0; j<width; j++)
		{
			pixelArray[i][j]=blurcalcSharpenValues(prev,j,i); //find the boxs value
		}
	}

	bmp_image *ans = (bmp_image*) malloc(sizeof(bmp_image));
	ans->header = copyHeader(prev->header);
	ans->data=(image_data*)malloc(sizeof(image_data));
	ans->data->pixelArray = pixelArray;
	ans->nameOfFile = malloc((strlen(prev->nameOfFile)+1+(strlen("blur-")))*sizeof(char*));
			char* name = strcpy(ans->nameOfFile,"blur-");
			 name = strcat(name,prev->nameOfFile);
			ans->nameOfFile = name; //renaming
			printInBinaryFile(ans);
			free(ans->header);
			free(ans->nameOfFile);
			for(int i=0; i<height; i++){
				for(int j=0; j<width; j++)
				{
					free(pixelArray[i][j]);
				}
			}
			for ( i = 0; i < height; i++) {
				 free(pixelArray[i]);
				}
			free(pixelArray);
			free(ans->data);
			free(ans);
	return;
}

Pixel*  blurcalcSharpenValues(bmp_image* image, int x, int y) {
	int m1 = 1;
	int m2 = 1;
	int m3 = 1;
	int m4 = 1;
	int m5 = 1;
	int m6 = 1;
	int m7 = 1;
	int m8 = 1;
	int m9 = 1;
	//find the x next and x before
	//find the y above and y below
	Pixel*** array= image->data->pixelArray;
	int plinY;
	if(y-1<0)
	{
		plinY=image->header->infoHeader.biHeight-1;
	}
	else
	{
		plinY=y-1;
	}


	int plinX;
	if(x-1<0)
		{
			plinX=image->header->infoHeader.biWidth-1;
		}
		else
		{
			plinX=x-1;
		}

	int sinY;
	if(y+1>=image->header->infoHeader.biHeight)
	{
		sinY=0;
	}
	else
	{
		sinY=y+1;
	}


	int sinX;
	if(x+1>=image->header->infoHeader.biWidth)
		{
			sinX=0;
		}
		else
		{
			sinX=x+1;
		}
	int isoY;
	isoY=y;
	int isoX;
	isoX=x;



	int red=m1*(int)array[plinY][plinX]->red+m2*(int)array[plinY][isoX]->red+m3*(int)array[plinY][sinX]->red;
	red=red+m4*(int)array[isoY][plinX]->red+m5*(int)array[isoY][isoX]->red+m6*(int)array[isoY][sinX]->red;
	red=red+m7*(int)array[sinY][plinX]->red+m8*(int)array[sinY][isoX]->red+m9*(int)array[sinY][sinX]->red;

	int green=m1*(int)array[plinY][plinX]->green+m2*(int)array[plinY][isoX]->green+m3*(int)array[plinY][sinX]->green;
		green=green+m4*(int)array[isoY][plinX]->green+m5*(int)array[isoY][isoX]->green+m6*(int)array[isoY][sinX]->green;
		green=green+m7*(int)array[sinY][plinX]->green+m8*(int)array[sinY][isoX]->green+m9*(int)array[sinY][sinX]->green;

	int blue=m1*(int)array[plinY][plinX]->blue+m2*(int)array[plinY][isoX]->blue+m3*(int)array[plinY][sinX]->blue;
		blue=blue+m4*(int)array[isoY][plinX]->blue+m5*(int)array[isoY][isoX]->blue+m6*(int)array[isoY][sinX]->blue;
		blue=blue+m7*(int)array[sinY][plinX]->blue+m8*(int)array[sinY][isoX]->blue+m9*(int)array[sinY][sinX]->blue;
red = red/9;
blue = blue/9;
green = green/9;
//no out of bounds
		if(blue<0)
		{
			blue=0;
		}
		if(green<0)
		{
			green=0;
		}
		if(red<0)
		{
			red=0;
		}
		if(blue>=255)
		{
			blue=255;
		}
		if(green>=255)
		{
			green=255;
		}
		if(red>=255)
		{
			red=255;
		}
		Pixel* temp = (Pixel*) malloc(sizeof(Pixel));//assign
		temp->red=(byte)(red);
		temp->green=(byte)(green);
		temp->blue=(byte)(blue);

		return temp;
}
#ifdef DEBUGBlur
int main(int argc, char **argv) {
bmp_image *prev = readBmp("image1.bmp");
blur(prev);
}

#endif
