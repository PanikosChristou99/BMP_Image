FILE *bin;
	bin = fopen(fileName, "rb");
	image_header *header = (image_header*) malloc(sizeof(image_header));
	fread(header, sizeof(image_header), 1, bin);
	int height = header->infoHeader.biHeight;
	int width = header->infoHeader.biWidth;
	int padding = 4- (width * 3) % 4;

	//printHeader(header);
	image_data *data = (image_data*) malloc(sizeof(image_data));
	data->pixelArray = (Pixel***) malloc(height * sizeof(Pixel**));
	Pixel *temp = malloc(sizeof(Pixel));
	for (int i = height-1; i >=0; i--) {
		data->pixelArray[i] = (Pixel**) malloc((width+padding) * sizeof(Pixel*));
		for (int j = 0; j < width + padding; j++) {
			if (j< width) {
				data->pixelArray[i][j] = (Pixel*) malloc(sizeof(Pixel));
				fread(data->pixelArray[i][j], sizeof(Pixel), 1, bin);
				//printPixel(data->pixelArray[i][j]);
			} else {
				fread(temp, sizeof(byte), 1, bin);
			}
			//printPixel(temp);

		}
	}

	bmp_image *image = (bmp_image*) malloc(sizeof(bmp_image));
	image->data = data;
	image->header = header;
	image->nameOfFile = fileName;
	return image;
