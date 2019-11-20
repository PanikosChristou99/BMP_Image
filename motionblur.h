/*
 * motionblur.h
 *
 *  Created on: Nov 20, 2019
 *      Author: panikos
 */

#ifndef MOTIONBLUR_H_
#define MOTIONBLUR_H_
#include "BMP_Image.h"
void motionblur(bmp_image *prev);
Pixel*  motionblurcalcSharpenValues(bmp_image* image, int x, int y) ;

#endif /* MOTIONBLUR_H_ */
