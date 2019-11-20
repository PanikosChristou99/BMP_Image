/*
 * gray.c
 *
 *  Created on: Nov 18, 2019
 *      Author: panikos
 */
#include "BMP_Image.h"
#include "gray.h"
#include "math.h"


void gray(bmp_image *prev){
	double_word width = prev->header->infoHeader.biWidth;
	double_word height = prev->header->infoHeader.biHeight;
	int padding=0; ;
			int pad=(width*3)%4;
			if(pad==0)
			{
				padding=0;
			}
			else
			{
				padding=4-pad;
			}

	Pixel ***pixelArray = (Pixel***) malloc(height * sizeof(Pixel**));
	for (int i = 0; i < height; i++) {
		pixelArray[i] = (Pixel**) malloc((width) * sizeof(Pixel*));
		for (int j = 0; j < width; j++) {
			//pixelArray[i][j] = (Pixel*) malloc(sizeof(Pixel));
		}
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
		ans->data=(image_data*)malloc(sizeof(image_data));
		ans->data->pixelArray = pixelArray;
		ans->nameOfFile = malloc((strlen(prev->nameOfFile)+1+(strlen("gray-")))*sizeof(char*));
		char* name = strcpy(ans->nameOfFile,"gray-");
		name = strcat(name,prev->nameOfFile);
		ans->nameOfFile = name;
		ans->header->infoHeader.biSizeImage = 0;
		printInBinaryFile(ans);
		return;
	}


Pixel* calcGray(Pixel* prev){
	Pixel *pix = (Pixel*) malloc(sizeof(Pixel));
	int temp= 0.299* prev->red+0.299* prev->green+0.299* prev->blue;
	pix->red=temp;
	pix->green=temp;
	pix->blue=temp;
	return pix;
}
//
//int main() {
//	FILE *bin;
//		bin = fopen("image1.bmp", "rb");
//		image_header *header = (image_header*) malloc(sizeof(image_header));
//		fread(header, sizeof(image_header), 1, bin);
//		int height = header->infoHeader.biHeight;
//		int width = header->infoHeader.biWidth;
//		int padding = (width * 3) % 4;
//		//printHeader(header);
//		image_data *data = (image_data*) malloc(sizeof(image_data));
//		data->pixelArray = (Pixel***) malloc(height * sizeof(Pixel**));
//		Pixel *temp = malloc(sizeof(Pixel));
//		for (int i = height-1; i >=0; i--) {
//			data->pixelArray[i] = (Pixel**) malloc(width * sizeof(Pixel*));
//			for (int j = 0; j < width; j++) {
//				data->pixelArray[i][j] = (Pixel*) malloc(sizeof(Pixel));
//				fread(data->pixelArray[i][j], sizeof(Pixel), 1, bin);
//				//printPixel(data->pixelArray[i][j]);
//			}
//			for (int j = 0; j < padding; j++) {
//				fread(temp, sizeof(Pixel), 1, bin);
//				//printPixel(temp);
//
//			}
//		}
//		fclose(bin);
//		bmp_image *image = (bmp_image*) malloc(sizeof(bmp_image));
//		image->data = data;
//		image->header = header;
//		image->nameOfFile =(char*)malloc(sizeof(strlen("image7.bmp")+1));
//		strcpy(image->nameOfFile, "image7.bmp");
//		//printImageNot(image);
//		gray(image);
//
//
//}

