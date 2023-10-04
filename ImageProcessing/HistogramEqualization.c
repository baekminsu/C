/*----------------------------------------------------------------------
  HistogramEqualization.c
------------------------------------------------------------------------
----------------------------------------------------------------------*/
#include <stdio.h>
#define uc unsigned char

uc cc[1500][1500], char$ptr[1500];

main() {
	char IOBUFF[30], * IOPTR;
	char IOC;
	FILE* file$nameA, * file$nameB;
	int	block = 16, fhd = 256, fvd = 256;
	int ii1, ii2;
	int	numwrite, numread;
	int histogram[256] = { 0, };
	int cdf[256] = { 0, };

	/* receive file names */
	for (;;) {
		printf("\n\rINPUT FILE NAME : ");
		fflush(stdin);
		gets(IOBUFF);
		if ((file$nameA = fopen(IOBUFF, "rb")) != NULL) break;
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
		}
	}
/////////
	for (ii1 = 0; ii1 < fvd; ii1++) {
		for (ii2 = 0; ii2 < fhd; ii2++) {
			histogram[cc[ii1][ii2]]++;
		}
	}
	cdf[0] = histogram[0];
	int i;
	for (i = 1; i < 256; i++) {
		cdf[i] = cdf[i - 1] + histogram[i];
	}

	for (i = 0; i < 256; i++) {
		cdf[i] = (cdf[i] * 255.0) / (float)cdf[255];
	}

	for (ii1 = 0; ii1 < fvd; ii1++) {
		for (ii2 = 0; ii2 < fhd; ii2++) {
			cc[ii1][ii2] = (uc)cdf[(int)cc[ii1][ii2]];
		}
	}


/////////
	for (ii1 = 0; ii1 < fvd; ii1++) {
		for (ii2 = 0; ii2 < fhd; ii2++) {
			char$ptr[ii2] = cc[ii1][ii2];
		}
		numwrite = fwrite((char*)char$ptr, sizeof(uc), fhd, file$nameB);
	}
	fclose(file$nameA); fclose(file$nameB);
}
