/*
 * BMP_Image.h
 *
 *  Created on: Nov 17, 2019
 *      Author: stylianos
 */

#ifndef BMP_IMAGE_H_
#define BMP_IMAGE_H_

typedef unsigned char byte;
typedef unsigned short int word;
typedef unsigned int double_word;


typedef struct bmp_image
{
	image_header* header;
	image_data* data;

}bmp_image;
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
	bitMapFileHeader* fileHeader;
	bitMapInfoHeader* infoHeader;
}image_header;

typedef struct Pixel
{
	byte red;
	byte green;
	byte blue;
}Pixel;
typedef struct image_data
{
	Pixel*** pixelArray;
	//int paddingInEveryRow;
}image_data;






#endif /* BMP_IMAGE_H_ */
