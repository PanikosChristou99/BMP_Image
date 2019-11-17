/*
 * BMP_Image.c
 *
 *  Created on: Nov 17, 2019
 *      Author: stylianos
 */

#include "BMP_Image.h"


void printPixel(Pixel *p)
{
	printf("red %02X\ngrenn%02X\nblue%02X\n",(int)p->red,(int)p->green,(int)p->blue);
}

void printFileHeader(bitMapFileHeader f)
{
	printf("bfType1 %c\nbfType2 %c\n",f.bfType1,f.bfType2);
	printf("bfSize %d \nbfReserved1 %d\nbfReserved2 %d\n",f.bfSize,f.bfReserved1,f.bfReserved2);
	printf("bfOffBits%d\n",f.bfOffBits);
}
void printInfoHeader(bitMapInfoHeader f)
{
	printf("biSize %d\n",f.biSize);
	printf("biWidth %d\n",f.biWidth);
	printf("biHeight %d\n",f.biHeight);
	printf("biPlanes %d\n",f.biPlanes);
	printf("biBitCount %d\n",f.biBitCount);
	printf("biCompression %d\n",f.biCompression);
	printf("biSizeImage %d\n",f.biSizeImage);
	printf("biXPelsPerMeter %d\n",f.biXPelsPerMeter);
	printf("biYPelsPerMeter %d\n",f.biYPelsPerMeter);
	printf("biClrUsed %d\n",f.biClrUsed);
	printf("biClrImportant %d\n",f.biClrImportant);
}
void printHeader(image_header *header)
{
	printFileHeader(header->fileHeader);
	printInfoHeader(header->infoHeader);
}
void printData(image_data * data, int heigth, int width)
{
	for(int i=0; i<heigth; i++)
	{
		for(int j=0; j<width; j++)
		{
			printPixel(data->pixelArray[i][j]);
		}
	}
}
void printImageNot(bmp_image * pic)
{
	printf("name Of File %s", pic->nameOfFile);
	printHeader(pic->header);
	printData(pic->data,pic->header->infoHeader.biHeight,pic->header->infoHeader.biWidth);
}


