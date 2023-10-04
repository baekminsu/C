/*----------------------------------------------------------------------
  LinearBlending.c
------------------------------------------------------------------------
----------------------------------------------------------------------*/
#include <stdio.h>
#define uc unsigned char


uc cc[1500][1500], char$ptr[1500];
uc cc2[1500][1500], char$ptr2[1500];
uc cc3[1500][1500];

main() {
	char IOBUFF[30];
	FILE* file$nameA, * file$nameB, * file$nameC;
	int	fhd = 512, fvd = 512;
	int ii1, ii2;
	int	numwrite, numread;
	int	ct;
	double a;

	/* receive file names */
	for (;;) {
		printf("\n\rINPUT FILE NAME : ");
		fflush(stdin);
		gets(IOBUFF);
		if ((file$nameA = fopen(IOBUFF, "rb")) != NULL) break;
		printf("\rcan't open the file");
	}
	for (;;) {
		printf("\n\rINPUT FILE NAME2 : ");
		fflush(stdin);
		gets(IOBUFF);
		if ((file$nameB = fopen(IOBUFF, "rb")) != NULL) break;
		printf("\rcan't open the file");
	}
	printf("\rOUTPUT FILE NAME : ");
	fflush(stdin);
	gets(IOBUFF);
	file$nameC = fopen(IOBUFF, "wb");

	/* receive file size */
	printf("\rFILE SIZE [H_dim V_dim] : ");
	scanf("%d %d", &fhd, &fvd);

	/* select weight */
	printf("\rWhat weight will you use? (0.0~1.0) : ");
	scanf("%lf", &a);

	/* reading the file */ //512 512
	rewind(file$nameA);
	rewind(file$nameB);
	rewind(file$nameC);

	for (ii1 = 0; ii1 < fvd; ii1++) {
		numread = fread((char*)char$ptr, sizeof(char), fhd, file$nameA);
		for (ii2 = 0; ii2 < fhd; ii2++) {
			cc[ii1][ii2] = char$ptr[ii2];
		}
	}
	for (ii1 = 0; ii1 < fvd; ii1++) {
		numread = fread((char*)char$ptr2, sizeof(char), fhd, file$nameB);
		for (ii2 = 0; ii2 < fhd; ii2++) {
			cc2[ii1][ii2] = char$ptr2[ii2];
		}
	}
	///////////////////////
	for (ii1 = 0; ii1 < fvd; ii1++) {
		for (ii2 = 0; ii2 < fhd; ii2++) {
			if (ii1 < fvd / 2) {
				cc3[ii1][ii2] =(uc) ( (a * cc[ii1][ii2]) + ( (1 - a) * cc2[ii1][ii2]));
			}
			else {
				cc3[ii1][ii2] =(uc) ( ((1 - a) * cc[ii1][ii2]) + (a * cc2[ii1][ii2]));
			}
		}
	}
	//////////////////////
	for (ii1 = 0; ii1 < fvd; ii1++) {
		for (ii2 = 0; ii2 < fhd; ii2++) {
			char$ptr[ii2] = cc3[ii1][ii2];
		}
		numwrite = fwrite((char*)char$ptr, sizeof(uc), fhd, file$nameC);
	}

	fclose(file$nameA); fclose(file$nameB); fclose(file$nameC);
}
