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
#include "functions.h"
int checkArgsFor(char *str, int argc, char **argv);
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
			//TODO	list(temp);
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
				zoomIn(temp);
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
		//		reverse(temp);
			}

		}
	} else {
		printf("en edoses sosto option");
	}

	return 0;
}

int checkArgsFor(char *str, int argc, char **argv) {
	int i = 0;
	for (i = 0; i < argc; ++i) {
		if (strcmp(argv[i], str) == 0)
			return i;
	}
	return -1;

}
