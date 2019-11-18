/*
 * sharpen.c
 *
 *  Created on: Nov 18, 2019
 *      Author: panikos
 */
#include "sharpen.h"
void sharpen(bmp_image *prev) {
	double_word width = prev->header->infoHeader.biWidth;
	double_word height = prev->header->infoHeader.biHeight;
	int padding = (width * 3) % 4;

	Pixel ***pixelArray = (Pixel***) malloc(height * sizeof(Pixel**));
	Pixel *temp = malloc(sizeof(Pixel));
	for (int i = 0; i < height; i++) {
		pixelArray[i] = (Pixel**) malloc((width+padding) * sizeof(Pixel*));
		for (int j = 0; j < width; j++) {
			pixelArray[i][j] = (Pixel*) malloc(sizeof(Pixel));
		}
		for (int j = width; j < width+padding; j++) {
					pixelArray[i][j] = makePaddingPixel();
				}

	}
	int i = 0;
	int j = 0;
	Pixel ***ar = prev->data->pixelArray;
	for (i = 1; i < height - 2; ++i) {
		for (j = 1; j < width - 2; ++j) {

			pixelArray[i][j] = calcPixel(ar[i - 1][j - 1], ar[i - 1][j],
					ar[i - 1][j + 1], ar[i][j - 1], ar[i][j], ar[i][j + 1],
					ar[i + 1][j - 1], ar[i + 1][j], ar[i + 1][j + 1]);

		}
	}
	/*
	 * *          *
	 * *          *
	 * *          *
	 * *          *
	 * *          *
	 *
	 */
	for (i = 1; i < height - 1; ++i) {
		pixelArray[i][0] = calcPixel(ar[i - 1][width - 1], ar[i - 1][0],
				ar[i - 1][1], ar[i][width - 1], ar[i][0], ar[i][1],
				ar[i + 1][width - 1], ar[i + 1][0], ar[i + 1][1]);

		pixelArray[i][width - 1] = calcPixel(ar[i - 1][width - 1],
				ar[i - 1][width], ar[i - 1][0], ar[i][width - 1], ar[i][width],
				ar[i][0], ar[i + 1][width - 1], ar[i + 1][width], ar[i + 1][0]);

	}
	/*        *********************
	 *
	 *
	 *        *********************
	 */
	for (i = 1; i < width - 1; ++i) {
		pixelArray[0][i] = calcPixel(ar[height - 1][i - 1], ar[height - 1][i],
				ar[height - 1][i + 1], ar[0][i - 1], ar[0][i], ar[0][i + 1],
				ar[1][i - 1], ar[1][i], ar[1][i + 1]);

		pixelArray[height - 1][i] = calcPixel(ar[height - 2][i - 1],
				ar[height - 2][i], ar[height - 1][i + 1], ar[height - 1][i - 1],
				ar[height - 1][i], ar[height - 1][i + 1], ar[0][i - 1],
				ar[0][i], ar[0][i + 1]);
	}

	pixelArray[0][0] = calcPixel(ar[height - 1][width - 1], ar[height - 1][0],
			ar[height - 1][1], ar[0][width - 1], ar[0][0], ar[0][1],
			ar[1][width - 1], ar[1][0], ar[1][1]);
	pixelArray[height - 1][0] = calcPixel(ar[height - 2][width - 1],
			ar[height - 2][0], ar[height - 2][1], ar[height - 1][width - 1],
			ar[height - 1][0], ar[height - 1][1], ar[0][width - 1], ar[0][0],
			ar[0][1]);
	pixelArray[0][width - 1] = calcPixel(ar[height - 1][width - 2],
			ar[height - 1][width - 1], ar[height - 1][0], ar[0][width - 2],
			ar[0][width - 1], ar[0][0], ar[1][width - 2], ar[1][width - 1],
			ar[1][0]);
	pixelArray[height - 1][width - 1] = calcPixel(ar[height - 2][width - 2],
			ar[height - 2][width - 1], ar[height - 2][0],
			ar[height - 1][width - 2], ar[height - 1][width - 1],
			ar[height - 1][0], ar[0][width - 2], ar[0][width - 1], ar[0][0]);

	bmp_image *ans = (bmp_image*) malloc(sizeof(bmp_image));
	ans->header = copyHeader(prev->header);
	ans->data = pixelArray;
	char* tempC= (char*) malloc((strlen(prev->nameOfFile)+9)*sizeof(char));
		strcpy(tempC,"sharpen-");
		strcat(tempC,prev->nameOfFile);
		printf("name of original %s\n",prev->nameOfFile);
		ans->nameOfFile=tempC;
		printImageNot(ans);
	return;
}

Pixel* calcPixel(Pixel m1, Pixel m2, Pixel m3, Pixel m4, Pixel m5, Pixel m6,
		Pixel m7, Pixel m8, Pixel m9) {
	Pixel *pix = (Pixel*) malloc(sizeof(Pixel));
	pix->blue = calcSharpenValues(m1.blue, m2.blue, m3.blue, m4.blue, m5.blue,
			m6.blue, m7.blue, m8.blue, m9.blue);
	pix->red = calcSharpenValues(m1.red, m2.red, m3.red, m4.red, m5.red, m6.red,
			m7.red, m8.red, m9.blue);
	pix->green = calcSharpenValues(m1.green, m2.green, m3.green, m4.green,
			m5.green, m6.green, m7.green, m8.green, m9.green);
	return pix;
}
int calcSharpenValues(int val1, int val2, int val3, int val4, int val5,
		int val6, int val7, int val8, int val9) {
	int m1 = -1;
	int m2 = -1;
	int m3 = -1;
	int m4 = -1;
	int m5 = 9;
	int m6 = -1;
	int m7 = -1;
	int m8 = -1;
	int m9 = -1;

	int final = m1 * val1 + m2 * val2 + m3 * val3 + m4 * val4 + m5 * val5
			+ m6 * val6 + m7 * val7 + m8 * val8 + m9 * val9;
	return final;
}
