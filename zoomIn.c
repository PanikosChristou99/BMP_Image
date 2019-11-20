/*
 * zoomIn.c
 *
 *  Created on: Nov 18, 2019
 *      Author: panikos
 */
#include "zoomIn.h"

void zoomIn(bmp_image *prev) {
	double_word prev_width = prev->header->infoHeader.biWidth;
		double_word prev_height = prev->header->infoHeader.biHeight;
	double_word width = 2*prev->header->infoHeader.biWidth;
	double_word height = 2*prev->header->infoHeader.biHeight;
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
	int i = 0;
	int j = 0;
	Pixel ***pixelArray = (Pixel***) malloc(height *sizeof(Pixel**));
	for ( i = 0; i < height; i++) {
		pixelArray[i] = (Pixel**) malloc((width) * sizeof(Pixel*));
		for ( j = 0; j < width; j++) {
			pixelArray[i][j] = (Pixel*) malloc(sizeof(Pixel));
		}

	}



	for ( i = 0; i < prev_height; i++) {
		for (j = 0; j < prev_width; j++) {
			pixelArray[2*i][2*j] = prev->data->pixelArray[i][j];
			pixelArray[2*i][2*j+1] = prev->data->pixelArray[i][j];
			pixelArray[2*i+1][2*j] = prev->data->pixelArray[i][j];
			pixelArray[2*i+1][2*j+1] = prev->data->pixelArray[i][j];
		}
	}

	int posaBytePouPixels=height*(padding+width)*sizeof(Pixel);
	int posaPouHeader=sizeof(image_header);
	int posaEminan=4-(posaBytePouPixels+posaPouHeader)%4;
	bmp_image *ans = (bmp_image*) malloc(sizeof(bmp_image));
		ans->header = copyHeader(prev->header);
		ans->header->fileHeader.bfSize=(double_word)(posaBytePouPixels+posaPouHeader+posaEminan);
		ans->header->infoHeader.biWidth=width;
		ans->header->infoHeader.biHeight=height;
		ans->header->infoHeader.biSizeImage=posaBytePouPixels;

		ans->data=(image_data*)malloc(sizeof(image_data));
		ans->data->pixelArray = pixelArray;
		ans->nameOfFile = malloc((strlen(prev->nameOfFile)+1+(strlen("ZoomedIn-")))*sizeof(char*));
		char* name = strcpy(ans->nameOfFile,"ZoomedIn-");
		 name = strcat(name,prev->nameOfFile);
		ans->nameOfFile = name;
		ans->header->infoHeader.biSizeImage = 0;
		printInBinaryFile(ans);
		return;


}
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
//		zoomIn(image);
//
//
//}

