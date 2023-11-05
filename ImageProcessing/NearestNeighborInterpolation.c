/*----------------------------------------------------------------------
  NearestNeighborInterpolation.c
----------------------------------------------------------------------*/
#include <stdio.h>
#define uc unsigned char

uc cc[1500][1500], char$ptr[1500];
uc cc2[1500][1500];

main() {
	char IOBUFF[30], * IOPTR;
	char IOC;
	FILE* file$nameA, * file$nameB;
	int fhd = 256, fvd = 256;
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
	printf("\rOUTPUT FILE SIZE [H_dim V_dim] : ");
	int fhd2, fvd2;
	scanf("%d %d", &fhd2, &fvd2);


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
	int nearestX;
	int nearestY;
	for(ii1=0;ii1<fvd2;ii1++){
		for(ii2=0;ii2<fhd2;ii2++){
			nearestX = (ii2 * fhd) / fhd2;
			nearestY = (ii1 * fvd) / fvd2;
			cc2[ii1][ii2] = cc[nearestY][nearestX];
		}	
	}

	/////////////////////////////

	for (ii1 = 0; ii1 < fvd2; ii1++) {
		for (ii2 = 0; ii2 < fhd2; ii2++) {
			char$ptr[ii2] = cc2[ii1][ii2];
		}
		numwrite = fwrite((char*)char$ptr, sizeof(uc), fhd2, file$nameB);
	}
	fclose(file$nameA); fclose(file$nameB);
}
