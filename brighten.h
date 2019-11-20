/*
 * brighten.h
 *
 *  Created on: Nov 20, 2019
 *      Author: panikos
 */

#ifndef brighten_H_
#define brighten_H_

#include "BMP_Image.h"
void brighten(bmp_image *prev);
Pixel*  brightencalcSharpenValues(bmp_image* image, int x, int y) ;


#endif /* brighten_H_ */
