/*
 * zoomout.c
 *
 *  Created on: Nov 18, 2019
 *      Author: panikos
 */

#include "zoomout.h"
void zoomout(bmp_image *prev) {
	double_word width = prev->header->infoHeader.biWidth;
	double_word height = prev->header->infoHeader.biHeight;
	int padding = (width*2 * 3) % 4;
	int i/2 = 0;
			int j = 0;
	Pixel ***pixelArray = (Pixel***) malloc(height *2*sizeof(Pixel**));
	Pixel *temp = malloc(sizeof(Pixel));
	for ( i = 0; i < height*2; i++) {
		pixelArray[i] = (Pixel**) malloc((width*2 + padding) * sizeof(Pixel*));
		for ( j = 0; j < width*2; j++) {
			pixelArray[i][j] = (Pixel*) malloc(sizeof(Pixel));
		}
		for ( j = width*2; j < width*2 + padding; j++) {
			pixelArray[i][j] = makePaddingPixel();
		}

	}
	for ( i = 0; i < height*2; i+=2) {
		for (j = 0; j < width*2; i+=2) {
			pixelArray[i][j] = prev->data->pixelArray[i/2][j/2];
			pixelArray[i+1][j] = prev->data->pixelArray[i/2][j/2];
			pixelArray[i][j+1] = prev->data->pixelArray[i/2][j/2];
			pixelArray[i+1][j+1] = prev->data->pixelArray[i/2][j/2];
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

