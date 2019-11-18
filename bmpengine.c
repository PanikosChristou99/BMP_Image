/*
 * bmpengine.c
 *
 *  Created on: Nov 17, 2019
 *      Author: panikos
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BMP_Image.h"

int main(int argc, char **argv) {
	if (argc == 1) {
		printf("en evales arguments");
	}
	if (checkArgsFor("-list", argc, argv)) {
		int i = 0;
checkMissingFiles(argc);
		bmp_image *temp = NULL;
		for (i = 2; i < argc; ++i) {
			temp = readBmp(argv);
			if (!checkLegal(temp)) {
				printf("cant parse the %d  image \n", i - 1);
			} else {
				list(temp);
			}

		}
	} else if (checkArgsFor("-hflip", argc, argv)) {
		int i = 0;
		checkMissingFiles(argc);
		bmp_image *temp = NULL;
		for (i = 2; i < argc; ++i) {
			temp = readBmp(argv);
			if (!checkLegal(temp)) {
				printf("cant parse the %d  image \n", i - 1);
			} else {
				hflip(temp);
			}

		}

	} else if (checkArgsFor("-vflip", argc, argv)) {
		int i = 0;
		checkMissingFiles(argc);
		bmp_image *temp = NULL;
		for (i = 2; i < argc; ++i) {
			temp = readBmp(argv);
			if (!checkLegal(temp)) {
				printf("cant parse the %d  image \n", i - 1);
			} else {
				vflip(temp);
			}

		}
	} else if (checkArgsFor("-right90", argc, argv)) {
		int i = 0;
		checkMissingFiles(argc);
		bmp_image *temp = NULL;
		for (i = 2; i < argc; ++i) {
			temp = readBmp(argv);
			if (!checkLegal(temp)) {
				printf("cant parse the %d  image \n", i - 1);
			} else {
				right90(temp);
			}

		}
	} else if (checkArgsFor("-left90", argc, argv)) {
		int i = 0;
		checkMissingFiles(argc);
		bmp_image *temp = NULL;
		for (i = 2; i < argc; ++i) {
			temp = readBmp(argv);
			if (!checkLegal(temp)) {
				printf("cant parse the %d  image \n", i - 1);
			} else {
				left90(temp);
			}

		}
	} else if (checkArgsFor("-zoomin", argc, argv)) {
		int i = 0;
		checkMissingFiles(argc);
		bmp_image *temp = NULL;
		for (i = 2; i < argc; ++i) {
			temp = readBmp(argv);
			if (!checkLegal(temp)) {
				printf("cant parse the %d  image \n", i - 1);
			} else {
				zoomin(temp);
			}

		}
	} else if (checkArgsFor("-zoomout", argc, argv)) {
		int i = 0;
		checkMissingFiles(argc);
		bmp_image *temp = NULL;
		for (i = 2; i < argc; ++i) {
			temp = readBmp(argv);
			if (!checkLegal(temp)) {
				printf("cant parse the %d  image \n", i - 1);
			} else {
				zoomout(temp);
			}

		}
	} else if (checkArgsFor("-gray", argc, argv)) {
		int i = 0;
		checkMissingFiles(argc);
		bmp_image *temp = NULL;
		for (i = 2; i < argc; ++i) {
			temp = readBmp(argv);
			if (!checkLegal(temp)) {
				printf("cant parse the %d  image \n", i - 1);
			} else {
				gray(temp);
			}

		}
	} else if (checkArgsFor("-sharpen", argc, argv)) {
		int i = 0;
		checkMissingFiles(argc);
		bmp_image *temp = NULL;
		for (i = 2; i < argc; ++i) {
			temp = readBmp(argv);
			if (!checkLegal(temp)) {
				printf("cant parse the %d  image \n", i - 1);
			} else {
				sharpen(temp);
			}

		}
	} else if (checkArgsFor("-reverse", argc, argv)) {
		int i = 0;
		checkMissingFiles(argc);
		bmp_image *temp = NULL;
		for (i = 2; i < argc; ++i) {
			temp = readBmp(argv);
			if (!checkLegal(temp)) {
				printf("cant parse the %d  image \n", i - 1);
			} else {
				reverse(temp);
			}

		}
	} else {
		printf("en edoses sosto option");
	}

	return 0;
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
int checkArgsFor(char *str, int argc, char **argv) {
	int i = 0;
	for (i = 0; i < argc; ++i) {
		if (strcmp(argv[i], str) == 0)
			return i;
	}
	return -1;

}
