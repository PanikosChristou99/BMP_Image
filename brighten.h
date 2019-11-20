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

#ifndef brighten_H_
#define brighten_H_

#include "BMP_Image.h"
/**creates and prints the blurred image*/
void brighten(bmp_image *prev);
/**calculates the box value*/
Pixel*  brightencalcValues(bmp_image* image, int x, int y) ;


#endif /* brighten_H_ */
