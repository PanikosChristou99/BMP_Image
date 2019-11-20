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

#ifndef LEFT90_H_
#define LEFT90_H_
#include "BMP_Image.h"
void left90(bmp_image *prev);

#endif /* LEFT90_H_ */
