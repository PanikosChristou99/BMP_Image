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
} __attribute__((__packed__)) Pixel;
typedef struct bitMapFileHeader
{
	byte bfType1;
	byte bfType2;
	double_word bfSize;
	word bfReserved1;
	word bfReserved2;
	double_word bfOffBits;
} __attribute__((__packed__))bitMapFileHeader;
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
} __attribute__((__packed__))bitMapInfoHeader;
typedef struct image_header
{
	bitMapFileHeader fileHeader;
	bitMapInfoHeader infoHeader;
} __attribute__((__packed__))image_header;

typedef struct image_data
{
	Pixel *** pixelArray;
} __attribute__((__packed__))image_data;


typedef struct bmp_image
{
	char* nameOfFile;
	image_header*  header;
	image_data* data;

} __attribute__((__packed__))bmp_image;

void printPixel(Pixel *p);
void printHeader(image_header* header);
void printFileHeader(bitMapFileHeader f);
void printInfoHeader(bitMapInfoHeader f);
void printData(image_data* data, int heigth, int width);
void printImageNot(bmp_image* pic);
image_header* copyHeader(image_header* original);
Pixel* copyPixel(Pixel* original);
Pixel * makePaddingPixel();




#endif /* BMP_IMAGE_H_ */
