/*
 * zoomIn.c
 *
 *  Created on: Nov 18, 2019
 *      Author: panikos
 */
#include "zoomIn.h"
void zoomIn(bmp_image *prev) {
	double_word width = prev->header->infoHeader.biWidth;
	double_word height = prev->header->infoHeader.biHeight;
	int padding = (width * 3) % 4;
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
			pixelArray[i][j] = makePaddingPixel();
		}

	}
	for ( i = 0; i < height; i++) {
		for (j = 0; j < width; i++) {
			pixelArray[i][j] = prev->data->pixelArray[i*2][j*2];

		}
	}

	bmp_image *ans = (bmp_image*) malloc(sizeof(bmp_image));
		ans->header = copyHeader(prev->header);
		ans->data = pixelArray;
		ans->nameOfFile = malloc(sizeof(char*));
		char* name = strcpy(ans->nameOfFile,prev->nameOfFile);
		 name = strcat(name,"ZoomedOut");
		ans->nameOfFile = name;
		printInBinaryFile(ans);
		return;


}


