/**
 * gray.h
 *
 *	@brief grayscales the image
 *
 *	Applies the type : value of all = 0.299* red+0.299* green+0.299* blue;
 *
 *  Created on: Nov 20, 2019
 *      Author: panikos
 */

#ifndef GRAY_H_
#define GRAY_H_
/**creates and prints the grayscaled image*/
void gray(bmp_image *prev);
/**calculates the gray value*/
Pixel* calcGray(Pixel* prev);
#endif /* GRAY_H_ */
