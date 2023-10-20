/*----------------------------------------------------------------------
  Laplacian_operation.c
------------------------------------------------------------------------
----------------------------------------------------------------------*/
#include <stdio.h>
#define uc unsigned char

uc cc[1500][1500], cc1[1500][1500],char$ptr[1500];
int ct;
int mask[3][3];
int ii[1500][1500];
int jj[1500][1500];
main() {
	char IOBUFF[30], * IOPTR;
	char IOC;
	FILE* file$nameA, * file$nameB;
	int	block = 16, fhd = 256, fvd = 256;
	int ii1, ii2;
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
		}
	}
	/////////////////////////////
	//mask sets

	//Laplacian 1
	/*
	mask[0][0] =0; mask[0][1] -1; mask[0][2]= 0;
	mask[1][0] =0; mask[1][1] -1; mask[1][2]=-1;
	mask[2][0] =0; mask[2][1] -1; mask[2][2]= 0;
	*/
	//Laplacian 2

	mask[0][0] = -1; mask[0][1] = -1; mask[0][2] = -1;
	mask[1][0] = -1; mask[1][1] = 8; mask[1][2] = -1;
	mask[2][0] = -1; mask[2][1] = -1; mask[2][2] = -1;

	//1st Laplacian operation
	int index;
	int ii3, ii4;

	for (ii1 = 1; ii1 < (fvd - 1); ii1++) {
		for (ii2 = 1; ii2 < (fhd - 1); ii2++) {
			index = 0;
			for (ii3 = -1; ii3 <= 1; ii3++) {
				for (ii4 = -1; ii4 <= 1; ii4++) {
					index = index = mask[ii3 + 1][ii4 + 1] * (int)cc[ii1 + ii3][ii2 + ii4];
				}
			}
			ii[ii1][ii2] = index;
		}
	}
	//2st Laplacian operation
	for (ii1 = 1; ii1 < (fvd - 1); ii1++) {
		for (ii2 = 1; ii2 < (fhd - 1); ii2++) {
			index = 0;
			for (ii3 = -1; ii3 <= 1; ii3++) {
				for (ii4 = -1; ii4 <= 1; ii4++) {
					index = index + mask[ii3 + 1][ii4 + 1] * ii[ii1 + ii3][ii2 + ii4];
				}
			}
			jj[ii1][ii2] = index;
		}
	}

	//zero crossing
	for (ii1 = 1; ii1 < (fvd - 1); ii1++) {
		for (ii2 = 1; ii2 < (fhd - 1); ii2++) {
			cc1[ii1][ii2] = 0;
			if ( ( (jj[ii1][ii2 - 1] * jj[ii1][ii2 + 1]) < 0) || ((jj[ii1 - 1][ii2] * jj[ii1 + 1][ii2]) < 0) ) {
				cc1[ii1][ii2] = abs(ii[ii1][ii2]);
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
