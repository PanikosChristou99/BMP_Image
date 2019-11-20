/**
 * gray.c
 *
 *	@brief grayscales the image
 *
 *	Applies the type : value of all = 0.299* red+0.299* green+0.299* blue;
 *
 *  Created on: Nov 20, 2019
 *      Author: panikos
 */
#include "BMP_Image.h"
#include "gray.h"
#include "math.h"

void gray(bmp_image *prev) {
	double_word width = prev->header->infoHeader.biWidth;
	double_word height = prev->header->infoHeader.biHeight;
	int padding = 0;
	;
	int pad = (width * 3) % 4;
	if (pad == 0) {
		padding = 0;
	} else {
		padding = 4 - pad;
	}

	Pixel ***pixelArray = (Pixel***) malloc(height * sizeof(Pixel**));
	for (int i = 0; i < height; i++) {
		pixelArray[i] = (Pixel**) malloc((width) * sizeof(Pixel*));

	}
	int i = 0;
	int j = 0;
	for (i = 0; i < height; ++i) {
		for (j = 0; j < width; ++j) {
			pixelArray[i][j] = calcGray(prev->data->pixelArray[i][j]);
		}
	}
	bmp_image *ans = (bmp_image*) malloc(sizeof(bmp_image));
	ans->header = copyHeader(prev->header);
	ans->data = (image_data*) malloc(sizeof(image_data));
	ans->data->pixelArray = pixelArray;
	ans->nameOfFile = malloc(
			(strlen(prev->nameOfFile) + 1 + (strlen("gray-"))) * sizeof(char*));
	char *name = strcpy(ans->nameOfFile, "gray-");
	name = strcat(name, prev->nameOfFile);
	ans->nameOfFile = name;
	ans->header->infoHeader.biSizeImage = 0;
	printInBinaryFile(ans);
	free(ans->header);
	free(ans->nameOfFile);
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			free(pixelArray[i][j]);
		}
	}
	for (i = 0; i < height; i++) {
		free(pixelArray[i]);
	}
	free(pixelArray);
	free(ans->data);
	free(ans);
	return;
}

Pixel* calcGray(Pixel *prev) {
	Pixel *pix = (Pixel*) malloc(sizeof(Pixel));
	int temp = 0.299 * prev->red + 0.299 * prev->green + 0.299 * prev->blue;
	pix->red = temp;
	pix->green = temp;
	pix->blue = temp;
	return pix;
}
#ifdef DEBUGGray
int main(int argc, char **argv) {
	bmp_image *prev = readBmp("image1.bmp");
	gray(prev);
}




#endif
