/*----------------------------------------------------------------------
  medianfiltering.c
------------------------------------------------------------------------
----------------------------------------------------------------------*/
#include <stdio.h>
#define uc unsigned char

uc cc[1500][1500], char$ptr[1500];
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
	double buf[25];
	for (ii1 = 2; ii1 < fvd - 2; ii1++) {
		for (ii2 = 2; ii2 < fhd - 2; ii2++) {
			ii5 = 0.0;

			for (ii3 = -2; ii3 <= 2; ii3++) {
				for (ii4 = -2; ii4 <= 2; ii4++) {
					buf[ii5] = (cc[ii1 + ii3][ii2 + ii4]);
					ii5 += 1;
				}
			}

			uc cc1;
			for (ii3 = 0; ii3 < 25; ii3++) {
				for (ii4 = 1; ii4 < 25; ii4++) {
					if (buf[ii4] > buf[ii4 - 1]) {
						continue;
					}
					cc1 = buf[ii4]; buf[ii4] = buf[ii4 - 1]; buf[ii4 - 1] = cc1;
				}
			}
			ff[ii1][ii2] = buf[12];
		}
	}


	/////////////////////////////

	for (ii1 = 0; ii1 < fvd; ii1++) {
		for (ii2 = 0; ii2 < fhd; ii2++) {
			char$ptr[ii2] = ff[ii1][ii2];
		}
		numwrite = fwrite((char*)char$ptr, sizeof(uc), fhd, file$nameB);
	}
	fclose(file$nameA); fclose(file$nameB);
}
