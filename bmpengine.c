/*
 * bmpengine.c
 *
 *  Created on: Nov 17, 2019
 *      Author: panikos
 */
int main(int argc, char **argv) {

}


int checkArgsFor(char *str, int argc, char **argv) {
	int i = 0;
	for (i = 0; i < argc; ++i) {
		if (strcmp(argv[i], str) == 0)
			return i;
	}
	return -1;

}

