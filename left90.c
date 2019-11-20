/*
 * left90.c
 *
 *  Created on: Nov 18, 2019
 *      Author: panikos
 */
#include "left90.h"
void left90(bmp_image *prev) {
	double_word prevwidth = prev->header->infoHeader.biWidth;
	double_word prevheight = prev->header->infoHeader.biHeight;
	double_word width = prevheight;
		double_word height = prevwidth;

	int padding = 4-((width * 3) % 4);
	int i = 0;
			int j = 0;
	Pixel ***pixelArray = (Pixel***) malloc(height *sizeof(Pixel**));
	Pixel *temp = malloc(sizeof(Pixel));
	for ( i = 0; i < height; i++) {
		pixelArray[i] = (Pixel**) malloc((width + padding) * sizeof(Pixel*));
		for ( j = 0; j < width; j++) {
			pixelArray[i][j] = (Pixel*) malloc(sizeof(Pixel));
		}
		for ( j = width; j < width + padding; j++) {
			pixelArray[i][j] = makePaddingbyte();
		}

	}
	for ( i = height-1; i >= 0; i--) {
		for (j = 0; j < width; j++) {

			 pixelArray[i][j] = prev->data->pixelArray[j][i];

		}
	}

	int posaBytePouPixels=height*(padding+width)*sizeof(Pixel);
	int posaPouHeader=sizeof(image_header);
	bmp_image *ans = (bmp_image*) malloc(sizeof(bmp_image));
	ans->header = copyHeader(prev->header);
		ans->header->fileHeader.bfSize=(double_word)(posaBytePouPixels+posaPouHeader);
		ans->header->infoHeader.biWidth=(double_word)width;
		ans->header->infoHeader.biHeight=(double_word)height;
		ans->header->infoHeader.biSizeImage=(double_word)0;
		ans->header->infoHeader.biBitCount = (word)24;
		ans->data=(image_data*)malloc(sizeof(image_data));
		ans->data->pixelArray = (Pixel***)pixelArray;
		ans->nameOfFile = malloc((strlen(prev->nameOfFile)+1+(strlen("left90-")))*sizeof(char*));
		char* name = strcpy(ans->nameOfFile,"left90-");
		 name = strcat(name,prev->nameOfFile);
		ans->nameOfFile = name;
		ans->header->infoHeader.biSizeImage = 0;
		printInBinaryFile(ans);
		return;


}


