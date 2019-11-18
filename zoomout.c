/*
 * zoomout.c
 *
 *  Created on: Nov 18, 2019
 *      Author: panikos
 */

void zoomout(bmp_image *prev){
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

			}
}

