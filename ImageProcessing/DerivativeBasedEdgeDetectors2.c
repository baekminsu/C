/*----------------------------------------------------------------------
  DerivativeBasedEdgeDetectors2.c
----------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>
#define uc unsigned char
#define PI 3.14

uc cc[1500][1500], char$ptr[1500];
uc ccc[1500][1500];
uc ff[1500][1500];
double maskHc[3][3];
double maskHr[3][3];
double ffHr[1500][1500];
double ffHc[1500][1500];
double ffS[1500][1500];
uc cc1[1500][1500];
main() {
	char IOBUFF[30], * IOPTR;
	char IOC;
	FILE* file$nameA, * file$nameB;
	int	block = 16, fhd = 256, fvd = 256;
	int ii1, ii2, ii3, ii4, ii5;
	int	numwrite, numread;
	double ff1, ff2;
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
	int index1;

	/* receive file size */
	printf("\rFILE SIZE [H_dim V_dim] : ");
	scanf("%d %d", &fhd, &fvd);
	printf("Horizontal (0) virtical (1) Diagonal (2) Off-Diagonal (3) ALL (4): ");
	scanf("%d", &index1);
	/* reading the file */ //512 512
	rewind(file$nameA);
	rewind(file$nameB);
	for (ii1 = 0; ii1 < fvd; ii1++) {
		numread = fread((char*)char$ptr, sizeof(char), fhd, file$nameA);
		for (ii2 = 0; ii2 < fhd; ii2++) {
			cc[ii1][ii2] = char$ptr[ii2];
		}
	}

	/////////////////////////////
	//mask sets

	//Roberts
	/*
	maskHr[0][0] = 0.0; maskHr[0][1] = 0.0; maskHr[0][2] = -1.0;
	maskHr[1][0] = 0.0; maskHr[1][1] = 1.0; maskHr[1][2] = 0.0;
	maskHr[2][0] = 0.0; maskHr[2][1] = 0.0; maskHr[2][2] = 0.0;
	maskHc[0][0] = -1.0; maskHc[0][1] = 0.0; maskHc[0][2] = 0.0;
	maskHc[1][0] = 0.0; maskHc[1][1] = 1.0; maskHc[1][2] = 0.0;
	maskHc[2][0] = 0.0; maskHc[2][1] = 0.0; maskHc[1][2] = 0.0;
	*/
	//Prewitt
	/*
	maskHr[0][0] = 1.0; maskHr[0][1] = 0.0; maskHr[0][0] =-1.0;
	maskHr[1][0] = 1.0; maskHr[1][1] = 0.0; maskHr[1][2] =-1.0;
	maskHr[2][0] = 1.0; maskHr[2][1] = 0.0; maskHr[2][2] =-1.0;
	maskHc[0][0] =-1.0; maskHc[0][1] =-1.0; maskHc[0][2] =-1.0;
	maskHc[1][0] = 0.0; maskHc[1][1] = 0.0; maskHc[1][2] = 0.0;
	maskHc[2][0] = 1.0; maskHc[2][1] = 1.0; maskHc[2][2] = 1.0;
	*/
	//Sobel

	maskHr[0][0] = 1.0; maskHr[0][1] = 0.0; maskHr[0][2] = -1.0;
	maskHr[1][0] = 2.0; maskHr[1][1] = 0.0; maskHr[1][2] = -2.0;
	maskHr[2][0] = 1.0; maskHr[2][1] = 0.0; maskHr[2][2] = -1.0;
	maskHc[0][0] = -1.0; maskHc[0][1] = -2.0; maskHc[0][2] = -1.0;
	maskHc[1][0] = 0.0; maskHc[1][1] = 0.0; maskHc[1][2] = 0.0;
	maskHc[2][0] = 1.0; maskHc[2][1] = 2.0; maskHc[2][2] = 1.0;

	//Fri-Chen
	/*
	maskHr[0][0] =1.0; maskHr[0][1] =0.0; maskHr[0][2] = -1.0;
	maskHr[1][0] =sqrt(2.0); maskHr[1][1] =0.0; maskHr[1][2] = -sqrt(2.0);
	maskHr[2][0] =1.0; maskHr[2][1] =0.0; maskHr[2][2] = -1.0;
	maskHc[0][0] =-1.0; maskHc[0][1] =0.0; maskHc[0][2] = -1.0;
	maskHc[1][0] =0.0; maskHc[1][1] =0.0; maskHc[1][2] = 0.0;
	maskHc[2][0] =1.0; maskHc[2][1] =sqrt(2.0); maskHc[2][2] = 1.0;


	*/


	for (ii1 = 1; ii1 < (fvd - 1); ii1++) {
		for (ii2 = 1; ii2 < (fhd - 1); ii2++) {
			ff1 = 0.0; ff2 = 0.0;
			for (ii3 = -1; ii3 <= 1; ii3++) {
				for (ii4 = -1; ii4 <= 1; ii4++) {
					ff1 = ff1 + maskHr[ii3 + 1][ii4 + 1] * (float)cc[ii1 + ii3][ii2 + ii4];
					ff2 = ff2 + maskHc[ii3 + 1][ii4 + 1] * (float)cc[ii1 + ii3][ii2 + ii4];
				}
			}
			ffHr[ii1][ii2] = ff1;
			ffHc[ii1][ii2] = ff2;
		}
	}
	for (ii1 = 1; ii1 < (fvd - 1); ii1++) {
		for (ii2 = 1; ii2 < (fhd - 1); ii2++) {
			ffS[ii1][ii2] = sqrt(ffHr[ii1][ii2] * ffHr[ii1][ii2] + ffHc[ii1][ii2] * ffHc[ii1][ii2]);
		}
	}

	//Edge strength normalization
	double fmax = ffS[1][1], fmin = ffS[1][1];
	for (ii1 = 1; ii1 < (fvd - 1); ii1++) {
		for (ii2 = 1; ii2 < (fhd - 1); ii2++) {
			if (fmax < ffS[ii1][ii2]) {
				fmax = ffS[ii1][ii2];
			}
			if (fmin > ffS[ii1][ii2]) {
				fmax = ffS[ii1][ii2];
			}
		}
	}
	for (ii1 = 1; ii1 < (fvd - 1); ii1++) {
		for (ii2 = 1; ii2 < (fhd - 1); ii2++) {
			ffS[ii1][ii2] = 255.0 * ((ffS[ii1][ii2] - fmin) / (fmax - fmin));
		}
	}

	for (ii1 = 1; ii1 < (fvd - 1); ii1++) {
		for (ii2 = 1; ii2 < (fhd - 1); ii2++) {
			ff1 = atan(ffHr[ii1][ii2] / ffHc[ii1][ii2]);
			if ((index1 == 1) && ((ff1 > (3.0 * PI / 8.0)) || ((ff1 < (-3.0 * PI / 8.00))))) {
				cc1[ii1][ii2] = (uc)ffS[ii1][ii2];
			}
			else if ((index1 == 0) && ((ff1 < (PI / 8.0)) && ((ff1 > (-PI / 8.0))))) {
				cc1[ii1][ii2] = (uc)ffS[ii1][ii2];
			}
			else if ((index1 == 2) && ((ff1 < (-PI / 8.0)) && ((ff1 > (-3.0 * PI / 8.0))))) {
				cc1[ii1][ii2] = (uc)ffS[ii1][ii2];
			}
			else if ((index1 == 3) && ((ff1 > (PI / 8.0)) && ((ff1 < (3.0 * PI / 8.0))))) {
				cc1[ii1][ii2] = (uc)ffS[ii1][ii2];
			}
			else if (index1 == 4) {
				cc1[ii1][ii2] = (uc)ffS[ii1][ii2];
			}
		}
	}

	/////////////////////////////

	for (ii1 = 0; ii1 < fvd; ii1++) {
		for (ii2 = 0; ii2 < fhd; ii2++) {
			char$ptr[ii2] = cc1[ii1][ii2];
		}
		numwrite = fwrite((char*)char$ptr, sizeof(uc), fhd, file$nameB);
	}
	fclose(file$nameA); fclose(file$nameB);
}

