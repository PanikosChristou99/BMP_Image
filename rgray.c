/**
 * rgray.c
 *
 *	@brief revrse grayscales the image
 *
 *	Applies the grayscale but now its 255 - grayscale
 *
 *  Created on: Nov 20, 2019
 *      Author: panikos
 */

#include "BMP_Image.h"
#include "rgray.h"
#include "math.h"

void rgray(bmp_image *prev) {
	double_word width = prev->header->infoHeader.biWidth;
	double_word height = prev->header->infoHeader.biHeight;
	int padding = (width * 3) % 4;

	Pixel ***pixelArray = (Pixel***) malloc(height * sizeof(Pixel**));
	for (int i = 0; i < height; i++) {
		pixelArray[i] = (Pixel**) malloc((width+padding) * sizeof(Pixel*));
		for (int j = 0; j < width; j++) {
			//pixelArray[i][j] = (Pixel*) malloc(sizeof(Pixel));
		}

	}
	int i = 0;
	int j = 0;
	for (i = 0; i < height; ++i) {
		for (j = 0; j < width; ++j) {
			pixelArray[i][j] = rcalcGray(prev->data->pixelArray[i][j]);
		}
	}
	bmp_image *ans = (bmp_image*) malloc(sizeof(bmp_image));
		ans->header = copyHeader(prev->header);
		ans->data=(image_data*)malloc(sizeof(image_data));
		ans->data->pixelArray = pixelArray;
		ans->nameOfFile = malloc((strlen(prev->nameOfFile)+1+(strlen("rgray-")))*sizeof(char*));
		char* name = strcpy(ans->nameOfFile,"rgray-");
		name = strcat(name,prev->nameOfFile);
		ans->nameOfFile = name;
		ans->header->infoHeader.biSizeImage = 0;
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


Pixel* rcalcGray(Pixel* prev){
	Pixel *pix = (Pixel*) malloc(sizeof(Pixel));
	int temp= 0.299* prev->red+0.299* prev->green+0.299* prev->blue;
	pix->red=pix->red-temp;
	pix->green=pix->green-temp;
	pix->blue=pix->blue-temp;
	return pix;
}
#ifdef DEBUGRgray
int main(int argc, char **argv) {
	bmp_image *prev = readBmp("image1.bmp");
	rgray(prev);
}




#endif


