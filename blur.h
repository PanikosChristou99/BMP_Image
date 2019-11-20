/**
 * blur.c
 *
 *	@brief blurs the image
 *
 *	Applies the box blur mask [1,1,1]
 *							  [1,1,1]
 *							  [1,1,1]
 *	where a pixel has the format of  the box its in
 *  Created on: Nov 20, 2019
 *      Author: panikos
 */
#ifndef BLUR_H_
#define BLUR_H_

#include "BMP_Image.h"
/**creates and prints the new image*/
void blur(bmp_image *prev);
/**calculates the box value*/
Pixel*  blurcalcSharpenValues(bmp_image* image, int x, int y) ;


#endif /* BLUR_H_ */
