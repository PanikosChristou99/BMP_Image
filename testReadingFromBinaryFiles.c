/*
 * testReadingFromBinaryFiles.c
 *
 *  Created on: Nov 17, 2019
 *      Author: stylianos
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BMP_Image.h"

int main() {

FILE *bin;
bin = fopen("3x4.bmp", "rb");
image_header * header=(image_header*)malloc(sizeof(image_header));
fread(header,sizeof(image_header), 1, bin);
int height= header->infoHeader.biHeight;
int width=header->infoHeader.biWidth;

printHeader(header);
// image_data * data=(image_data*)malloc(sizeof(image_data)+height*width*(sizeof(Pixel)));
// fread(data,sizeof(image_data), 1, bin);
// bmp_image *image=(bmp_image*) malloc(sizeof(bmp_image));
// image->data=data;
// image->header=header;

//printf("these are the first two chars %c, %c", image->header->fileHeader.bfType1,image->header->fileHeader.bfType2);
//printf("these is the first pixel \n red %d, green %d , blue %d ", image->data->pixelArray[0][0].red, image->data->pixelArray[0][0].green, image->data->pixelArray[0][0].blue);

return 0;
}
