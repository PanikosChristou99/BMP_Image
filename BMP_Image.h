/** @file BMP_IMAGE_H_
 *  @brief this function has structs for all the parts of the bmp image and the prototypes for the
 *  shared functions.
 *
 *  This file contains the prototypes for most of the shared functions.
 *  Also it contains structs for all the parts of the image
 *  from the image itself, header, data, pixels exc.
 *
 *  @author Stylianos Herodotou
 *  @author Pankos Christou
 *  @bug No known bugs.
 */

#ifndef BMP_IMAGE_H_
#define BMP_IMAGE_H_



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char byte  ;
typedef unsigned short int word;
typedef unsigned int double_word;
typedef struct Pixel
{
	byte blue;
	byte green;
	byte red;
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
/** @brief it makes a new header that has the containt of the given one
 *
 *  @param image_header* original
 *  @return image_header* return the new header..
 */

image_header* copyHeader(image_header* original);
Pixel* copyPixel(Pixel* original);
/** @brief creates and returns a new padding pixel.
 * a padding pixel is a pixel with
 * red=0
 * blue=0
 * green=0
 *
 *  @return Pixel * the new pixel
 */
Pixel * makePaddingPixel();
/** @brief writes the containts of an bmp image to a bmp file
 *
 *  @param  bmp_image* image
 *  @return void
 */

void printInBinaryFile( bmp_image* image);
/** @brief it checks to see if there are arguments to work with
 * if it doesnt it exits the program
 *
 *  @param argc
 *  @return void
 */
void checkMissingFiles(int argc);
/** @brief it makes sure that the picture it was given is leagel
 * meaning that is a bmp picture, that is it not copressed and its bit count is 24.
 *
 *  @param  bmp_image* image
 *  @return void
 */
int checkLegal(bmp_image *im);
/** @brief it reads the containt of a bmp image it it makes it an bmp_image struct.
 *
 *  @param  char *fileName
 *  @return bmp_image*
 */
bmp_image* readBmp(char *fileName);
/** @brief it creates and return a padding byte.
 *
 *  @return byte * the new pixel
 */
byte * makePaddingbyte();

void kill_image(bmp_image* image);
#endif /* BMP_IMAGE_H_ */
