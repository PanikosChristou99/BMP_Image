/*
 * sharpen.h
 *
 *  Created on: Nov 18, 2019
 *      Author: panikos
 */

#include "BMP_Image.h"
#ifndef SHARPEN_H_
#define SHARPEN_H_
Pixel* calcPixel(Pixel* m1, Pixel *m2, Pixel* m3, Pixel* m4, Pixel* m5, Pixel *m6,
		Pixel *m7, Pixel* m8, Pixel* m9);
void sharpen(bmp_image *prev);
Pixel*  calcSharpenValues(bmp_image* image, int x, int y) ;
#endif /* SHARPEN_H_ */
