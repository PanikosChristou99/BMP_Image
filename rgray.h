/*
 * rgray.h
 *
 *  Created on: Nov 20, 2019
 *      Author: panikos
 */

#ifndef RGRAY_H_
#define RGRAY_H_
#include "BMP_Image.h"
Pixel* rcalcGray(Pixel* prev);
void rgray(bmp_image *prev);
#endif /* RGRAY_H_ */
