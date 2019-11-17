/*
 * BMP_Image.h
 *
 *  Created on: Nov 17, 2019
 *      Author: stylianos
 */

#ifndef BMP_IMAGE_H_
#define BMP_IMAGE_H_

typedef unsigned char byte  ;
typedef unsigned short int word;
typedef unsigned int double_word;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Pixel
{
	byte red;
	byte green;
	byte blue;
}Pixel;
typedef struct bitMapFileHeader
{
	byte bfType1;
	byte bfType2;
	double_word bfSize;
	word bfReserved1;
	word bfReserved2;
	double_word bfOffBits;
}bitMapFileHeader;
typedef struct bitMapInfoHeader
{
	double_word biSize;
	double_word biWidth;
	double_word biHeight;
	word biPlanes;
	word biBitCount;
	double_word biCompression;
	double_word biSizeImage;
	double_word biXPelsPerMeter;
	double_word biYPelsPerMeter;
	double_word biClrUsed;
	double_word biClrImportant;
}bitMapInfoHeader;
typedef struct image_header
{
	bitMapFileHeader fileHeader;
	bitMapInfoHeader infoHeader;
}image_header;

typedef struct image_data
{
	Pixel ** pixelArray ;
	//int paddingInEveryRow;
}image_data;


typedef struct bmp_image
{
	image_header*  header;
	image_data* data;

}bmp_image;

void printPixel(Pixel p);
void printHeader(image_header* header);
void printFileHeader(bitMapFileHeader f);
void printInfoHeader(bitMapInfoHeader f);
void printData(image_data* data, int heigth, int width);
void printImageNot(bmp_image* pic);











#endif /* BMP_IMAGE_H_ */
