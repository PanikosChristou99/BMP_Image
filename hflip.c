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
#include "hflip.h"
void hflip (bmp_image *original)
{
	image_header* header= copyHeader(original->header);
	image_data *data = (image_data*) malloc(sizeof(image_data));
	int height=original->header->infoHeader.biHeight;
	int width= original->header->infoHeader.biWidth;
//	int padding=0;
//			int pad=(width*3)%4;
//			if(pad==0)
//			{
//				padding=0;
//			}
//			else
//			{
//				padding=4-pad;
//			}
	data->pixelArray = (Pixel***) malloc( height * sizeof(Pixel**));

	int z=height-1;
	for (int i =0; i <height; i++) {
		data->pixelArray[i] = (Pixel**) malloc((width) * sizeof(Pixel*));
		for (int j = 0; j < width; j++) {
			data->pixelArray[i][j] = (Pixel*) malloc(sizeof(Pixel));
			data->pixelArray[i][j] = copyPixel(original->data->pixelArray[z][j]);
			//printPixel(data->pixelArray[i][j]);
		}
		z--;
	}
	bmp_image* ans= (bmp_image*)malloc(sizeof(bmp_image));
	ans->header=header;
	ans->data=data;
	char* tempC= (char*) malloc((strlen(original->nameOfFile)+7)*sizeof(char));
	strcpy(tempC,"hflip-");
	strcat(tempC,original->nameOfFile);
	printf("name of original %s\n",original->nameOfFile);
	ans->nameOfFile=tempC;
	printInBinaryFile(ans);
}

