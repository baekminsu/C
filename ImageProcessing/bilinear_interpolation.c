/*----------------------------------------------------------------------
  bilinear_interpolation.c
----------------------------------------------------------------------*/
#include <stdio.h>
#define uc unsigned char

uc cc[1500][1500], char$ptr[1500];
uc cc2[1500][1500];

double bilinearInterpolation(double tl, double tr, double bl, double br, double x_ratio, double y_ratio) {
	double top = tl + (tr - tl) * x_ratio;
	double bottom = bl + (br - bl) * x_ratio;
	return top + (bottom - top) * y_ratio;
}

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
	double x_ratio;
	double y_ratio;
	x_ratio = (double)(fhd - 1) / (double)(fhd2 - 1);
	y_ratio = (double)(fvd - 1) / (double)(fvd2 - 1);
	double targetX;
	double targetY;
	int x0, y0, x1, y1;
	double x_fraction, y_fraction;
	uc tl, tr, bl, br;
	double interpolated_value;
	for (ii1 = 0; ii1 < fvd2; ii1++) {
		for (ii2 = 0; ii2 < fhd2; ii2++) {
			targetX = ii2 * x_ratio;
			targetY = ii1 * y_ratio;
			x0 = (int)targetX;
			y0 = (int)targetY;
			x1 = x0 + 1;
			y1 = y0 + 1;
			x_fraction = targetX - x0;
			y_fraction = targetY - y0;
			tl = cc[y0][x0];
			tr = cc[y0][x1];
			bl = cc[y1][x0];
			br = cc[y1][x1];
			interpolated_value = bilinearInterpolation(tl, tr, bl, br, x_fraction, y_fraction);
			cc2[ii1][ii2] = (uc)interpolated_value;
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
