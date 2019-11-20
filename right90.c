/**
 * right90.h
 *
 *	@brief blurs the image
 *
 *	rotates the image to the right 90 deg
 *	It does thi by switching axis and starting from the right of the old pixels
 *  Created on: Nov 20, 2019
 *      Author: panikos
 */
#include"right90.h"
void right90(bmp_image *prev) {
	double_word prevwidth = prev->header->infoHeader.biWidth;
	double_word prevheight = prev->header->infoHeader.biHeight;
	double_word width = prevheight;
	double_word height = prevwidth;

	int padding = 0;
	;
	int pad = (width * 3) % 4;
	if (pad == 0) {
		padding = 0;
	} else {
		padding = 4 - pad;
	}
	int i = 0;
	int j = 0;
	Pixel ***pixelArray = (Pixel***) malloc(height * sizeof(Pixel**));
	for (i = 0; i < height; i++) {
		pixelArray[i] = (Pixel**) malloc((width + padding) * sizeof(Pixel*));
		for (j = 0; j < width; j++) {
			pixelArray[i][j] = (Pixel*) malloc(sizeof(Pixel));
		}
	}

	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			pixelArray[i][j] = prev->data->pixelArray[width - 1 - j][i];
		}
	}

	int posaBytePouPixels = height * width * sizeof(Pixel);
	int posaPouHeader = sizeof(image_header);
	int posaPouPadding = padding * sizeof(byte);
	int posaEminan = 4
			- (posaBytePouPixels + posaPouHeader + posaPouPadding) % 4;
	bmp_image *ans = (bmp_image*) malloc(sizeof(bmp_image));
	ans->header = copyHeader(prev->header);
	ans->header->fileHeader.bfSize = (double_word) (posaBytePouPixels
			+ posaPouHeader + posaEminan + posaPouPadding);
	ans->header->infoHeader.biWidth = width;
	ans->header->infoHeader.biHeight = height;
	ans->header->infoHeader.biSizeImage = posaBytePouPixels + posaPouPadding;

	ans->data = (image_data*) malloc(sizeof(image_data));
	ans->data->pixelArray = pixelArray;
	ans->nameOfFile = malloc(
			(strlen(prev->nameOfFile) + 1 + (strlen("right90-")))
					* sizeof(char*));
	char *name = strcpy(ans->nameOfFile, "right90-");
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
	return;

}
#ifdef DEBUGRight90
int main(int argc, char **argv) {
bmp_image *prev = readBmp("image1.bmp");
right90(prev);
}

#endif
