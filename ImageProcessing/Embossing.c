/*----------------------------------------------------------------------
  Embossing.c
------------------------------------------------------------------------
----------------------------------------------------------------------*/
#include <stdio.h>
#define uc unsigned char

uc cc[1500][1500], char$ptr[1500];
uc temp[514][514];
uc temp2[514][514];
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
	double mask[3][3];
	int i, j;
	for (i = 0; i < 3; i++) {
		printf("\r Embossing mask arr input 3 number : ");
		for(j = 0; j < 3; j++) {
			scanf("%lf", &mask[i][j]);
		}
		printf("\n");
	}

	for (ii1 = 0; ii1 < fvd+2; ii1++) {
		for (ii2 = 0; ii2 < fhd+2; ii2++) {
			temp[ii1][ii2] += 128.0;
		}
	}
	for (ii1 = 0; ii1 < fvd + 2; ii1++) {
		for (ii2 = 0; ii2 < fhd + 2; ii2++) {
			temp[ii1 + 1][ii2 + 1] += cc[ii1][ii2];
		}
	}

	double k;
	int w, z;
	for (i = 0; i < fvd; i++) {
		for (j = 0; j < fhd; j++) {
			k = 0.0;
			for (w = 0; w < 3; w++) {
				for (z = 0; z < 3; z++) {
					k +=mask[w][z] * temp[i+w][j+z];
				}
			}
			temp2[i][j] = k;
		}
	}



	for (ii1 = 0; ii1 < fvd; ii1++) {
		for (ii2 = 0; ii2 < fhd; ii2++) {
			temp2[ii1][ii2] += 128.0;
		}
	}

	int v;
	for(ii1=0;ii1<fvd;ii1++){
		for(ii2=0;ii2<fhd;ii2++){
			v = temp2[ii1][ii2];
			if (v > 255.0) {
				v = 255;
			}
			else if (v < 0) {
				v = 0;
			}
	 		cc[ii1][ii2]=(uc)v;
		}	
	}

	/////////////////////////////

	for (ii1 = 0; ii1 < fvd; ii1++) {
		for (ii2 = 0; ii2 < fhd; ii2++) {
			char$ptr[ii2] = cc[ii1][ii2];
		}
		numwrite = fwrite((char*)char$ptr, sizeof(uc), fhd, file$nameB);
	}
	fclose(file$nameA); fclose(file$nameB);
}
