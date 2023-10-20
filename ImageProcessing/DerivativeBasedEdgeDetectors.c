/*----------------------------------------------------------------------
  DerivativeBasedEdgeDetectors.c
------------------------------------------------------------------------
----------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>
#define uc unsigned char

uc cc[1500][1500], char$ptr[1500];
uc array[8];
uc ccc[1500][1500];
uc ff[1500][1500];
main() {
	char IOBUFF[30], * IOPTR;
	char IOC;
	FILE* file$nameA, * file$nameB;
	int	block = 16, fhd = 256, fvd = 256;
	int ii1, ii2, ii3, ii4, ii5;
	int	numwrite, numread;

	/* receive file names */
	for (;;) {
		printf("\n\rINPUT FILE NAME : ");
		fflush(stdin);
		gets(IOBUFF);
		if ((file$nameA = fopen(IOBUFF, "rb")) != NULL) {
			break;
		}
		printf("\rcan't open the file");
	}

	printf("\rOUTPUT FILE NAME : ");
	fflush(stdin);
	gets(IOBUFF);
	file$nameB = fopen(IOBUFF, "wb");

	/* receive file size */
	printf("\rFILE SIZE [H_dim V_dim] : ");
	scanf("%d %d", &fhd, &fvd);

	/* reading the file */ //512 512
	rewind(file$nameA);
	rewind(file$nameB);
	for (ii1 = 0; ii1 < fvd; ii1++) {
		numread = fread((char*)char$ptr, sizeof(char), fhd, file$nameA);
		for (ii2 = 0; ii2 < fhd; ii2++) {
			cc[ii1][ii2] = char$ptr[ii2];
			ff[ii1][ii2] = cc[ii1][ii2];
		}
	}
	/////////////////////////////
	double max;
	int n;
	for (ii1 = 1; ii1 < (fvd - 1); ii1++) {
		for (ii2 = 1; ii2 < fhd; ii2++) {
			array[0] = abs(cc[ii1][ii2] - cc[ii1 - 1][ii2]);
			array[1] = abs(cc[ii1][ii2] - cc[ii1][ii2 - 1]);
			array[2] = abs(cc[ii1][ii2] - cc[ii1 + 1][ii2]);
			array[3] = abs(cc[ii1][ii2] - cc[ii1][ii2 + 1]);
			array[4] = abs(cc[ii1][ii2] - cc[ii1 - 1][ii2 - 1]);
			array[5] = abs(cc[ii1][ii2] - cc[ii1 - 1][ii2 + 1]);
			array[6] = abs(cc[ii1][ii2] - cc[ii1 + 1][ii2 - 1]);
			array[7] = abs(cc[ii1][ii2] - cc[ii1 + 1][ii2 + 1]);
			max = array[0];
			for (n = 0; n < 8; n++) {
				if (max < array[n]) {
					max = array[n];
				}
				ccc[ii1][ii2] = max;
			}
		}
	}

	/////////////////////////////

	for (ii1 = 0; ii1 < fvd; ii1++) {
		for (ii2 = 0; ii2 < fhd; ii2++) {
			char$ptr[ii2] = ccc[ii1][ii2];
		}
		numwrite = fwrite((char*)char$ptr, sizeof(uc), fhd, file$nameB);
	}
	fclose(file$nameA); fclose(file$nameB);
}
