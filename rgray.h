/**
 * rgray.h
 *
 *	@brief revrse grayscales the image
 *
 *	Applies the grayscale but now its 255 - grayscale
 *
 *  Created on: Nov 20, 2019
 *      Author: panikos
 */

#ifndef RGRAY_H_
#define RGRAY_H_
#include "BMP_Image.h"
/**creates and prints the reversed grayed image*/
Pixel* rcalcGray(Pixel* prev);
/**calculates the reverse geayscale value*/
void rgray(bmp_image *prev);
#endif /* RGRAY_H_ */
