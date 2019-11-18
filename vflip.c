/*
 * vflip.c
 *
 *  Created on: Nov 18, 2019
 *      Author: panikos
 */
#include "vflip.h"
void vflip (bmp_image *original)
{
	image_header* header= copyHeader(original->header);
	image_data *data = (image_data*) malloc(sizeof(image_data));
	int height=original->header->infoHeader.biHeight;
	int width= original->header->infoHeader.biWidth;
	int padding = (width * 3) % 4;
	data->pixelArray = (Pixel***) malloc( height * sizeof(Pixel**));


	for (int i =0; i <height; i++) {
		int z=width-1;
		data->pixelArray[i] = (Pixel**) malloc((width+padding) * sizeof(Pixel*));
		for (int j = 0; j < width; j++) {
			data->pixelArray[i][j] = (Pixel*) malloc(sizeof(Pixel));
			data->pixelArray[i][j] = copyPixel(original->data->pixelArray[i][z]);
			//printPixel(data->pixelArray[i][j]);
			z--;
		}
		for (int j = 0; j < padding; j++) {
			data->pixelArray[i][width+j] = (Pixel*) malloc(sizeof(Pixel));
			data->pixelArray[i][width+j] = makePaddingPixel();
			//printPixel(temp);
		}

	}
	bmp_image* ans= (bmp_image*)malloc(sizeof(bmp_image));
	ans->header=header;
	ans->data=data;
	char* tempC= (char*) malloc((strlen(original->nameOfFile)+7)*sizeof(char));
	strcpy(tempC,"vflip-");
	strcat(tempC,original->nameOfFile);
	printf("name of original %s\n",original->nameOfFile);
	ans->nameOfFile=tempC;
	printInBinaryFile(ans);
}
