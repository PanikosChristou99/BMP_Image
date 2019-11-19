/*
 * gray.c
 *
 *  Created on: Nov 18, 2019
 *      Author: panikos
 */
#include "BMP_Image.h"
#include "gray.h"
void gray(bmp_image *prev) {
	double_word width = prev->header->infoHeader.biWidth;
	double_word height = prev->header->infoHeader.biHeight;
	int padding = (width * 3) % 4;

	Pixel ***pixelArray = (Pixel***) malloc(height * sizeof(Pixel**));
	Pixel *temp = malloc(sizeof(Pixel));
	for (int i = 0; i < height; i++) {
		pixelArray[i] = (Pixel**) malloc((width + padding) * sizeof(Pixel*));
		for (int j = 0; j < width; j++) {
			pixelArray[i][j] = (Pixel*) malloc(sizeof(Pixel));
		}
		for (int j = width; j < width + padding; j++) {
			pixelArray[i][j] = makePaddingPixel();
		}

	}
	int i = 0;
	int j = 0;
	Pixel ***ar = prev->data->pixelArray;
	for (i = 0; i < height - 1; ++i) {
		for (j = 0; j < width - 1; ++j) {

			pixelArray[i][j] = calcGray(prev->data->pixelArray[i][j]);

		}
	}

	bmp_image *ans = (bmp_image*) malloc(sizeof(bmp_image));
	ans->header = copyHeader(prev->header);
	ans->data = pixelArray;
	ans->nameOfFile = malloc(sizeof(char*));
	char *name = strcpy(ans->nameOfFile, prev->nameOfFile);
	name = strcat(name, "Grayed");
	ans->nameOfFile = name;
	printInBinaryFile(ans);
	return;
}

Pixel* calcGray(Pixel *prev) {
	Pixel *pix = (Pixel*) malloc(sizeof(Pixel));
	float f = 0.299 * (float) prev->red + 0.587 * (float) prev->green
			+ 0.114 * (float) prev->blue;
	pix->blue = f;
	pix->red = f;
	pix->blue = f;
	return pix;

}
