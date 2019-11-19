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
image_header* copyHeader(image_header* original)
{
	// tuta dame epd enen pointers simeni pos anigrafounte sosta?
	image_header * temp = (image_header*)malloc(sizeof(image_header));
	// gia to fileHeader
	temp->fileHeader.bfOffBits=original->fileHeader.bfOffBits;
	temp->fileHeader.bfReserved1=original->fileHeader.bfReserved1;
	temp->fileHeader.bfReserved2=original->fileHeader.bfReserved2;
	temp->fileHeader.bfSize=original->fileHeader.bfSize;
	temp->fileHeader.bfType1=original->fileHeader.bfType1;
	temp->fileHeader.bfType2=original->fileHeader.bfType2;
	// gia to infoHEader
	temp->infoHeader.biBitCount=original->infoHeader.biBitCount;
	temp->infoHeader.biClrImportant=original->infoHeader.biClrImportant;
	temp->infoHeader.biClrUsed=original->infoHeader.biClrUsed;
	temp->infoHeader.biCompression=original->infoHeader.biCompression;
	temp->infoHeader.biHeight=original->infoHeader.biHeight;
	temp->infoHeader.biPlanes=original->infoHeader.biPlanes;
	temp->infoHeader.biSize=original->infoHeader.biSize;
	temp->infoHeader.biSizeImage=original->infoHeader.biSizeImage;
	temp->infoHeader.biWidth=original->infoHeader.biWidth;
	temp->infoHeader.biXPelsPerMeter=original->infoHeader.biXPelsPerMeter;
	temp->infoHeader.biYPelsPerMeter=original->infoHeader.biYPelsPerMeter;
	return temp;
}

Pixel* copyPixel(Pixel* original)
{
	Pixel* temp = (Pixel*)malloc(sizeof(Pixel));
	temp->blue=original->blue;
	temp->green=original->green;
	temp->red=original->red;
	return temp;
}
Pixel * makePaddingPixel()
{
	Pixel * pad= (Pixel*)malloc(sizeof(Pixel));
	pad->red=(unsigned char) 0;
	pad->green=(unsigned char) 0;
	pad->blue=(unsigned char) 0;
	return pad;
}
void checkMissingFiles(int argc){
	if (argc==2) {
				printf("you didnt put any files");
				exit(-1);
			}
}
int checkLegal(bmp_image *im) {
	char *str = im->nameOfFile;
	if (str[strlen(str) - 4] != '.' || str[strlen(str) - 3] != 'b'
			|| str[strlen(str) - 2] != 'm' || str[strlen(str) - 1] != 'p')
		return 1;
	if (im->header->fileHeader.bfType1 != 'B'
			|| im->header->fileHeader.bfType2 != 'M'
			|| im->header->infoHeader.biBitCount != 24
			|| im->header->infoHeader.biCompression != 0) {
		return 1;
	}
	return 0;
}
bmp_image* readBmp(char *fileName) {
	FILE *bin;
	bin = fopen(fileName, "rb");
	image_header *header = (image_header*) malloc(sizeof(image_header));
	fread(header, sizeof(image_header), 1, bin);
	int height = header->infoHeader.biHeight;
	int width = header->infoHeader.biWidth;
	int padding = (width * 3) % 4;

	printHeader(header);
	image_data *data = (image_data*) malloc(sizeof(image_data));
	data->pixelArray = (Pixel***) malloc(height * sizeof(Pixel**));
	Pixel *temp = malloc(sizeof(Pixel));
	for (int i = height-1; i >=0; i--) {
		data->pixelArray[i] = (Pixel**) malloc(width * sizeof(Pixel*));
		for (int j = 0; j < width; j++) {
			data->pixelArray[i][j] = (Pixel*) malloc(sizeof(Pixel));
			fread(data->pixelArray[i][j], sizeof(Pixel), 1, bin);
			//printPixel(data->pixelArray[i][j]);
		}
		for (int j = 0; j < padding; j++) {
			fread(temp, sizeof(Pixel), 1, bin);
			//printPixel(temp);

		}
	}

	bmp_image *image = (bmp_image*) malloc(sizeof(bmp_image));
	image->data = data;
	image->header = header;
	image->nameOfFile = fileName;
	return image;

}
