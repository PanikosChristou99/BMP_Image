/*
 * bmpengine_options.c
 *
 *  Created on: Nov 17, 2019
 *      Author: panikos
 */
void exitFunction(){
	printf("thank you for choosing us \n good bye");
	exit(0);
}
void list(bmpimage* a) {
	printf("BITMAP_FILE_HEADER \n");
	printf("================== \n");
	printf("bfType: %s \n",);
	printf("bfSize: %d \n",);
	printf("bfReserved1 : %d \n",);
	printf("bfReserved2 : %d \n",);
	printf("bfOffBits : %d \n\n",);
	printf("BITMAP_INFO_HEADER \n",);
	printf("==================\n",);
	printf("biSize:  %d\n",);
	printf("biWidth: %d\n",);
	printf("biHeight: %d\n",);
	printf("biBitCount: %d\n"),;
	printf("biCompression: %d\n",);
	printf("biSize:  %d\n",);
	printf("biSizeImage:  %d\n",);
	printf("biXPelsPerMeter: %d \n",);
	printf("biYPelsPerMeter: %d \n",);
	printf("biClrUsed: %d \n",);
	printf("***************************************************************************\n");
	exitFunction();


}
void hflip(bmpimage* a) {
	pixels[][] pix = NULL;
	int i = 0;
	int j =0;
	for(i = 0;i<a->data->pixels->rows;i++){
		for (j = 0; j < a->data->pixels->rows; ++j) {
			pix=[data->pixels->rows-i][j] = a->data->pixels[i][j];
		}
	}
	createBmp();
	if ((f_out = fopen(outFile, "w")) == NULL) {
	fprintf(stderr, "\nCan't write in file %s\n",outFile);
	return(EXIT_FAILURE);
	}
	fwrite(tab1, NB * sizeof(int), 1, f_out);
	fclose(f_out);

	whatever


}



