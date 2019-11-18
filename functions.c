/*
 * functions.c
 *
 *  Created on: Nov 18, 2019
 *      Author: panikos
 */
#include "BMP_Image.c"
#include "right90.h"
#include "left90.h"
#include "zoomout.h"
#include "zoomIn.h"
#include "sharpen.h"
#include "gray.h"


void printInBinaryFile( bmp_image* image)
{
	FILE * whereToPrint= fopen(image->nameOfFile, "wb");
	int height = image->header->infoHeader.biHeight;
			int width = image->header->infoHeader.biWidth;
			int padding = (width * 3) % 4;
	fwrite((image->header), sizeof(*(image->header)), 1, whereToPrint);
			for(int i=height-1; i>=0; i--)
			{
				for(int j=0; j<(width+padding); j++)
				{
					fwrite((image->data->pixelArray[i][j]), sizeof(Pixel), 1, whereToPrint);
				}
			}
		fclose(whereToPrint);
}

void hflip (bmp_image *original)
{
	image_header* header= copyHeader(original->header);
	image_data *data = (image_data*) malloc(sizeof(image_data));
	int height=original->header->infoHeader.biHeight;
	int width= original->header->infoHeader.biWidth;
	int padding = (width * 3) % 4;
	data->pixelArray = (Pixel***) malloc( height * sizeof(Pixel**));

	int z=height-1;
	for (int i =0; i <height; i++) {
		data->pixelArray[i] = (Pixel**) malloc((width+padding) * sizeof(Pixel*));
		for (int j = 0; j < width; j++) {
			data->pixelArray[i][j] = (Pixel*) malloc(sizeof(Pixel));
			data->pixelArray[i][j] = copyPixel(original->data->pixelArray[z][j]);
			//printPixel(data->pixelArray[i][j]);
		}
		for (int j = 0; j < padding; j++) {
			data->pixelArray[i][width+j] = (Pixel*) malloc(sizeof(Pixel));
			data->pixelArray[i][width+j] = makePaddingPixel();
			//printPixel(temp);
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


