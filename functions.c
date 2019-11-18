/*
 * functions.c
 *
 *  Created on: Nov 18, 2019
 *      Author: panikos
 */
#include "functions.h"

//int main() {
//	FILE *bin;
//		bin = fopen("image1.bmp", "rb");
//		image_header *header = (image_header*) malloc(sizeof(image_header));
//		fread(header, sizeof(image_header), 1, bin);
//		int height = header->infoHeader.biHeight;
//		int width = header->infoHeader.biWidth;
//		int padding = (width * 3) % 4;
//
//		printHeader(header);
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
//		image->nameOfFile =(char*)malloc(sizeof(strlen("image1.bmp")+1));
//		strcpy(image->nameOfFile, "image1.bmp");
//
//		vflip(image);
//
//
//}


