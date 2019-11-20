/*
 * blur.c
 *
 *  Created on: Nov 20, 2019
 *      Author: panikos
 */

#include "blur.h"
#include "BMP_Image.h"
void blur(bmp_image *prev) {
	double_word width = prev->header->infoHeader.biWidth;
	double_word height = prev->header->infoHeader.biHeight;
	int padding = (width * 3) % 4;

	Pixel ***pixelArray = (Pixel***) malloc(height * sizeof(Pixel**));
	int i = 0;
		int j = 0;
	for ( i = 0; i < height; i++) {
		pixelArray[i] = (Pixel**) malloc((width+padding) * sizeof(Pixel*));
		for ( j = 0; j < width; j++) {
			pixelArray[i][j] = (Pixel*) malloc(sizeof(Pixel)); // pithanon tuto na en garbge
		}


	}

	for(int i=0; i<height; i++)
	{
		for(int j=0; j<width; j++)
		{
			pixelArray[i][j]=calcSharpenValues(prev,j,i);
		}
	}

	bmp_image *ans = (bmp_image*) malloc(sizeof(bmp_image));
	ans->header = copyHeader(prev->header);
	ans->data=(image_data*)malloc(sizeof(image_data));
	ans->data->pixelArray = pixelArray;
	ans->nameOfFile = malloc(sizeof(char*));
	ans->nameOfFile = malloc((strlen(prev->nameOfFile)+1+(strlen("sharpen-")))*sizeof(char*));
			char* name = strcpy(ans->nameOfFile,"sharpen-");
			 name = strcat(name,prev->nameOfFile);
			ans->nameOfFile = name;
			printInBinaryFile(ans);
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
		Pixel* temp = (Pixel*) malloc(sizeof(Pixel));
		temp->red=(byte)red;
		temp->green=(byte)green;
		temp->blue=(byte)blue;

		return temp;
}



