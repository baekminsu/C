#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct information {
	double height;
	double weight;
	double GPA;
	double linear;
	double earning;
}INFOR;

void printStudent(INFOR* student,double* resultE,double resultCov[5][5],double resultCorr[5][5]) {
	printf("-------information--------\n\n");
	for (int i = 0; i < 10; i++) {
		printf("%.2lf ", student[i].height);
		printf("%.2lf ", student[i].weight);
		printf("%.2lf ", student[i].GPA);
		printf("%.2lf ", student[i].linear);
		printf("%.2lf\n", student[i].earning);
	}
	printf("\n-------resultE--------\n\n");
	for (int i = 0; i < 5; i++) {
		printf("%.2lf ", resultE[i]);
	}
	printf("\n\n-------resultCov--------");
	printf("\n\n          height    weight      GPA        linear     earning\n\n");
	for (int i = 0; i < 5; i++) {
		if (i == 0) {
			printf("height   ");
		}
		else if (i == 1) {
			printf("weight   ");
		}
		else if (i == 2) {
			printf("GPA      ");
		}
		else if (i == 3) {
			printf("linear   ");
		}
		else if (i == 4) {
			printf("earning   ");
		}

		for (int j = 0; j < 5; j++) {
			printf("%.2lf       ", resultCov[i][j]);
		}
		printf("\n");
	}
	printf("\n-------resultCorr--------\n");
	printf("\n          height    weight      GPA        linear     earning\n\n");
	for (int i = 0; i < 5; i++) {
		if (i == 0) {
			printf("height   ");
		}
		else if (i == 1) {
			printf("weight   ");
		}
		else if (i == 2) {
			printf("GPA      ");
		}
		else if (i == 3) {
			printf("linear   ");
		}
		else if (i == 4) {
			printf("earning   ");
		}

		for (int j = 0; j < 5; j++) {
			printf("%.2lf       ", resultCorr[i][j]);
		}
		printf("\n");
	}


}

void calcE(INFOR* student,double* resultE) {
	double sumHeight = 0;
	double sumWeight =0;
	double sumGPA = 0;
	double sumLinear =0;
	double sumEarning= 0;

	for (int i = 0; i < 10; i++) {
		sumHeight += student[i].height;
		sumWeight += student[i].weight;
		sumGPA += student[i].GPA;
		sumLinear += student[i].linear;
		sumEarning += student[i].earning;
	}
	resultE[0] = sumHeight * 0.1;	resultE[1] = sumWeight * 0.1;
	resultE[2] = sumGPA * 0.1;
	resultE[3] = sumLinear * 0.1;	resultE[4] = sumEarning * 0.1;
}

void calcCovCorr(INFOR* infor, double* E, double resultCov[5][5],double resultCorr[5][5]) {
	double cov;
	double EXY = 0;
	double sumHeight = 0;
	double sumWeight = 0;
	double sumGPA = 0;
	double sumLinear = 0;
	double sumEarning = 0;

	double equal;
	double hw;
	double hc;
	double hl;
	double he;
	double row;
	double varX, varY;
	double covariance = 0;
	for (int i = 0; i < 5; i++) {
		hw = 0; hc = 0; hl = 0; he = 0; equal = 0; row = 0; varX = 0; varY = 0; covariance = 0;
		for (int j = 0; j < 5; j++) {
			
			hw = 0; hc = 0; hl = 0; he = 0; equal = 0; row = 0; varX = 0; varY = 0; covariance = 0;
			
			if (i == 0) {

				if (j == 0) {
					for (int k = 0; k < 10; k++) {
						equal += (infor[k].height * infor[k].height);
					}
					for (int k = 0; k < 10; k++) {
						covariance += (infor[k].height - E[i]) * (infor[k].height - E[j]);
						varX += pow(infor[k].height - E[i], 2);
						varY += pow(infor[k].height - E[j], 2);
					}
					covariance = covariance * 0.1;
					varX = varX * 0.1;
					varY = varY * 0.1;
					resultCorr[i][j] = covariance / sqrt(varX * varY);
					equal = equal * 0.1;
					resultCov[i][j] = equal - (E[i] * E[j]);
				}

				else if (j == 1) {
					for (int k = 0; k < 10; k++) {
						hw += (infor[k].height * infor[k].weight);
					}
					for (int k = 0; k < 10; k++) {
						covariance += (infor[k].height - E[i]) * (infor[k].weight - E[j]);
						varX += pow(infor[k].height - E[i], 2);
						varY += pow(infor[k].weight - E[j], 2);
					}
					covariance = covariance * 0.1;
					varX = varX * 0.1;
					varY = varY * 0.1;
					resultCorr[i][j] = covariance / sqrt(varX * varY);
					hw = hw * 0.1;
					resultCov[i][j] = hw - (E[i] * E[j]);
				}
				else if (j == 2) {
					for (int k = 0; k < 10; k++) {
						hc += (infor[k].height * infor[k].GPA);
					}
					for (int k = 0; k < 10; k++) {
						covariance += (infor[k].height - E[i]) * (infor[k].GPA - E[j]);
						varX += pow(infor[k].height - E[i], 2);
						varY += pow(infor[k].GPA - E[j], 2);
					}
					covariance = covariance * 0.1;
					varX = varX * 0.1;
					varY = varY * 0.1;
					resultCorr[i][j] = covariance / sqrt(varX * varY);
					hc = hc * 0.1;
					resultCov[i][j] = hc - (E[i] * E[j]);
				}
				else if (j == 3) {
					for (int k = 0; k < 10; k++) {
						hl += (infor[k].height * infor[k].linear);
					}
					for (int k = 0; k < 10; k++) {
						covariance += (infor[k].height - E[i]) * (infor[k].linear - E[j]);
						varX += pow(infor[k].height - E[i], 2);
						varY += pow(infor[k].linear - E[j], 2);
					}
					covariance = covariance * 0.1;
					varX = varX * 0.1;
					varY = varY * 0.1;
					resultCorr[i][j] = covariance / sqrt(varX * varY);
					hl = hl * 0.1;
					resultCov[i][j] = hl - (E[i] * E[j]);
				}
				else if (j == 4) {
					for (int k = 0; k < 10; k++) {
						he += (infor[k].height * infor[k].earning);
					}
					for (int k = 0; k < 10; k++) {
						covariance += (infor[k].height - E[i]) * (infor[k].earning - E[j]);
						varX += pow(infor[k].height - E[i], 2);
						varY += pow(infor[k].earning - E[j], 2);
					}
					covariance = covariance * 0.1;
					varX = varX * 0.1;
					varY = varY * 0.1;
					resultCorr[i][j] = covariance / sqrt(varX * varY);
					he = he * 0.1;
					resultCov[i][j] = he - (E[i] * E[j]);
				}


			}
			else if (i == 1) {
				if (j == 0) {
					for (int k = 0; k < 10; k++) {
						equal += (infor[k].weight * infor[k].height);
					}
					for (int k = 0; k < 10; k++) {
						covariance += (infor[k].weight - E[i]) * (infor[k].height - E[j]);
						varX += pow(infor[k].weight - E[i], 2);
						varY += pow(infor[k].height - E[j], 2);
					}
					covariance = covariance * 0.1;
					varX = varX * 0.1;
					varY = varY * 0.1;
					resultCorr[i][j] = covariance / sqrt(varX * varY);
					equal = equal * 0.1;
					resultCov[i][j] = equal - (E[i] * E[j]);
				}

				else if (j == 1) {
					for (int k = 0; k < 10; k++) {
						hw += (infor[k].weight * infor[k].weight);
					}
					for (int k = 0; k < 10; k++) {
						covariance += (infor[k].weight - E[i]) * (infor[k].weight - E[j]);
						varX += pow(infor[k].weight - E[i], 2);
						varY += pow(infor[k].weight - E[j], 2);
					}
					covariance = covariance * 0.1;
					varX = varX * 0.1;
					varY = varY * 0.1;
					resultCorr[i][j] = covariance / sqrt(varX * varY);
					hw = hw * 0.1;
					resultCov[i][j] = hw - (E[i] * E[j]);
				}
				else if (j == 2) {
					for (int k = 0; k < 10; k++) {
						hc += (infor[k].weight * infor[k].GPA);
					}
					for (int k = 0; k < 10; k++) {
						covariance += (infor[k].weight - E[i]) * (infor[k].GPA - E[j]);
						varX += pow(infor[k].weight - E[i], 2);
						varY += pow(infor[k].GPA - E[j], 2);
					}
					covariance = covariance * 0.1;
					varX = varX * 0.1;
					varY = varY * 0.1;
					resultCorr[i][j] = covariance / sqrt(varX * varY);
					hc = hc * 0.1;
					resultCov[i][j] = hc - (E[i] * E[j]);
				}
				else if (j == 3) {
					for (int k = 0; k < 10; k++) {
						hl += (infor[k].weight * infor[k].linear);
					}
					for (int k = 0; k < 10; k++) {
						covariance += (infor[k].weight - E[i]) * (infor[k].linear - E[j]);
						varX += pow(infor[k].weight - E[i], 2);
						varY += pow(infor[k].linear - E[j], 2);
					}
					covariance = covariance * 0.1;
					varX = varX * 0.1;
					varY = varY * 0.1;
					resultCorr[i][j] = covariance / sqrt(varX * varY);
					hl = hl * 0.1;
					resultCov[i][j] = hl - (E[i] * E[j]);
				}
				else if (j == 4) {
					for (int k = 0; k < 10; k++) {
						he += (infor[k].weight * infor[k].earning);
					}
					for (int k = 0; k < 10; k++) {
						covariance += (infor[k].weight - E[i]) * (infor[k].earning - E[j]);
						varX += pow(infor[k].weight - E[i], 2);
						varY += pow(infor[k].earning - E[j], 2);
					}
					covariance = covariance * 0.1;
					varX = varX * 0.1;
					varY = varY * 0.1;
					resultCorr[i][j] = covariance / sqrt(varX * varY);
					he = he * 0.1;
					resultCov[i][j] = he - (E[i] * E[j]);
				}
			}
			else if (i == 2) {
				if (j == 0) {
					for (int k = 0; k < 10; k++) {
						equal += (infor[k].GPA * infor[k].height);
					}
					for (int k = 0; k < 10; k++) {
						covariance += (infor[k].GPA - E[i]) * (infor[k].height - E[j]);
						varX += pow(infor[k].GPA - E[i], 2);
						varY += pow(infor[k].height - E[j], 2);
					}
					covariance = covariance * 0.1;
					varX = varX * 0.1;
					varY = varY * 0.1;
					resultCorr[i][j] = covariance / sqrt(varX * varY);
					equal = equal * 0.1;
					resultCov[i][j] = equal - (E[i] * E[j]);
				}

				else if (j == 1) {
					for (int k = 0; k < 10; k++) {
						hw += (infor[k].GPA * infor[k].weight);
					}
					for (int k = 0; k < 10; k++) {
						covariance += (infor[k].GPA - E[i]) * (infor[k].weight - E[j]);
						varX += pow(infor[k].GPA - E[i], 2);
						varY += pow(infor[k].weight - E[j], 2);
					}
					covariance = covariance * 0.1;
					varX = varX * 0.1;
					varY = varY * 0.1;
					resultCorr[i][j] = covariance / sqrt(varX * varY);
					hw = hw * 0.1;
					resultCov[i][j] = hw - (E[i] * E[j]);
				}
				else if (j == 2) {
					for (int k = 0; k < 10; k++) {
						hc += (infor[k].GPA * infor[k].GPA);
					}
					for (int k = 0; k < 10; k++) {
						covariance += (infor[k].GPA - E[i]) * (infor[k].GPA - E[j]);
						varX += pow(infor[k].GPA - E[i], 2);
						varY += pow(infor[k].GPA - E[j], 2);
					}
					covariance = covariance * 0.1;
					varX = varX * 0.1;
					varY = varY * 0.1;
					resultCorr[i][j] = covariance / sqrt(varX * varY);
					hc = hc * 0.1;
					resultCov[i][j] = hc - (E[i] * E[j]);
				}
				else if (j == 3) {
					for (int k = 0; k < 10; k++) {
						hl += (infor[k].GPA * infor[k].linear);
					}
					for (int k = 0; k < 10; k++) {
						covariance += (infor[k].GPA - E[i]) * (infor[k].linear - E[j]);
						varX += pow(infor[k].GPA - E[i], 2);
						varY += pow(infor[k].linear - E[j], 2);
					}
					covariance = covariance * 0.1;
					varX = varX * 0.1;
					varY = varY * 0.1;
					resultCorr[i][j] = covariance / sqrt(varX * varY);
					hl = hl * 0.1;
					resultCov[i][j] = hl - (E[i] * E[j]);
				}
				else if (j == 4) {
					for (int k = 0; k < 10; k++) {
						he += (infor[k].GPA * infor[k].earning);
					}
					for (int k = 0; k < 10; k++) {
						covariance += (infor[k].GPA - E[i]) * (infor[k].earning - E[j]);
						varX += pow(infor[k].GPA - E[i], 2);
						varY += pow(infor[k].earning - E[j], 2);
					}
					covariance = covariance * 0.1;
					varX = varX * 0.1;
					varY = varY * 0.1;
					resultCorr[i][j] = covariance / sqrt(varX * varY);
					he = he * 0.1;
					resultCov[i][j] = he - (E[i] * E[j]);
				}
			}
			else if (i == 3) {
				if (j == 0) {
					for (int k = 0; k < 10; k++) {
						equal += (infor[k].linear * infor[k].height);
					}
					for (int k = 0; k < 10; k++) {
						covariance += (infor[k].linear -E[i]) * (infor[k].height - E[j]);
						varX += pow(infor[k].linear - E[i], 2);
						varY += pow(infor[k].height - E[j], 2);
					}
					covariance = covariance * 0.1;
					varX = varX * 0.1;
					varY = varY * 0.1;
					resultCorr[i][j] = covariance / sqrt(varX * varY);
					equal = equal * 0.1;
					resultCov[i][j] = equal - (E[i] * E[j]);
				}

				else if (j == 1) {
					for (int k = 0; k < 10; k++) {
						hw += (infor[k].linear * infor[k].weight);
					}
					for (int k = 0; k < 10; k++) {
						covariance += (infor[k].linear - E[i]) * (infor[k].weight - E[j]);
						varX += pow(infor[k].linear - E[i], 2);
						varY += pow(infor[k].weight - E[j], 2);
					}
					covariance = covariance * 0.1;
					varX = varX * 0.1;
					varY = varY * 0.1;
					resultCorr[i][j] = covariance / sqrt(varX * varY);
					hw = hw * 0.1;
					resultCov[i][j] = hw - (E[i] * E[j]);
				}
				else if (j == 2) {
					for (int k = 0; k < 10; k++) {
						hc += (infor[k].linear * infor[k].GPA);
					}
					for (int k = 0; k < 10; k++) {
						covariance += (infor[k].linear - E[i]) * (infor[k].GPA - E[j]);
						varX += pow(infor[k].linear - E[i], 2);
						varY += pow(infor[k].GPA - E[j], 2);
					}
					covariance = covariance * 0.1;
					varX = varX * 0.1;
					varY = varY * 0.1;
					resultCorr[i][j] = covariance / sqrt(varX * varY);
					hc = hc * 0.1;
					resultCov[i][j] = hc - (E[i] * E[j]);
				}
				else if (j == 3) {
					for (int k = 0; k < 10; k++) {
						hl += (infor[k].linear * infor[k].linear);
					}
					for (int k = 0; k < 10; k++) {
						covariance += (infor[k].linear - E[i]) * (infor[k].linear - E[j]);
						varX += pow(infor[k].linear - E[i], 2);
						varY += pow(infor[k].linear - E[j], 2);
					}
					covariance = covariance * 0.1;
					varX = varX * 0.1;
					varY = varY * 0.1;
					resultCorr[i][j] = covariance / sqrt(varX * varY);
					hl = hl * 0.1;
					resultCov[i][j] = hl - (E[i] * E[j]);
				}
				else if (j == 4) {
					for (int k = 0; k < 10; k++) {
						he += (infor[k].linear * infor[k].earning);
					}
					for (int k = 0; k < 10; k++) {
						covariance += (infor[k].linear - E[i]) * (infor[k].earning - E[j]);
						varX += pow(infor[k].linear - E[i], 2);
						varY += pow(infor[k].earning - E[j], 2);
					}
					covariance = covariance * 0.1;
					varX = varX * 0.1;
					varY = varY * 0.1;
					resultCorr[i][j] = covariance / sqrt(varX * varY);
					he = he * 0.1;
					resultCov[i][j] = he - (E[i] * E[j]);
				}
			}
			else if (i == 4){
				if (j == 0) {
					for (int k = 0; k < 10; k++) {
						equal += (infor[k].earning * infor[k].height);
					}
					for (int k = 0; k < 10; k++) {
						covariance += (infor[k].earning - E[i]) * (infor[k].height - E[j]);
						varX += pow(infor[k].earning - E[i], 2);
						varY += pow(infor[k].height - E[j], 2);
					}
					covariance = covariance * 0.1;
					varX = varX * 0.1;
					varY = varY * 0.1;
					resultCorr[i][j] = covariance / sqrt(varX * varY);
					equal = equal * 0.1;
					resultCov[i][j] = equal - (E[i] * E[j]);
				}

				else if (j == 1) {
					for (int k = 0; k < 10; k++) {
						hw += (infor[k].earning * infor[k].weight);
					}
					for (int k = 0; k < 10; k++) {
						covariance += (infor[k].earning - E[i]) * (infor[k].weight - E[j]);
						varX += pow(infor[k].earning - E[i], 2);
						varY += pow(infor[k].weight - E[j], 2);
					}
					covariance = covariance * 0.1;
					varX = varX * 0.1;
					varY = varY * 0.1;
					resultCorr[i][j] = covariance / sqrt(varX * varY);
					hw = hw * 0.1;
					resultCov[i][j] = hw - (E[i] * E[j]);
				}
				else if (j == 2) {
					for (int k = 0; k < 10; k++) {
						hc += (infor[k].earning * infor[k].GPA);
					}
					for (int k = 0; k < 10; k++) {
						covariance += (infor[k].earning - E[i]) * (infor[k].GPA - E[j]);
						varX += pow(infor[k].earning - E[i], 2);
						varY += pow(infor[k].GPA - E[j], 2);
					}
					covariance = covariance * 0.1;
					varX = varX * 0.1;
					varY = varY * 0.1;
					resultCorr[i][j] = covariance / sqrt(varX * varY);
					hc = hc * 0.1;
					resultCov[i][j] = hc - (E[i] * E[j]);
				}
				else if (j == 3) {
					for (int k = 0; k < 10; k++) {
						hl += (infor[k].earning * infor[k].linear);
					}
					for (int k = 0; k < 10; k++) {
						covariance += (infor[k].earning - E[i]) * (infor[k].linear - E[j]);
						varX += pow(infor[k].earning - E[i], 2);
						varY += pow(infor[k].linear - E[j], 2);
					}
					covariance = covariance * 0.1;
					varX = varX * 0.1;
					varY = varY * 0.1;
					resultCorr[i][j] = covariance / sqrt(varX * varY);
					hl = hl * 0.1;
					resultCov[i][j] = hl - (E[i] * E[j]);
				}
				else if (j == 4) {
					for (int k = 0; k < 10; k++) {
						he += (infor[k].earning * infor[k].earning);
					}
					for (int k = 0; k < 10; k++) {
						covariance += (infor[k].earning - E[i]) * (infor[k].earning - E[j]);
						varX += pow(infor[k].earning - E[i], 2);
						varY += pow(infor[k].earning - E[j], 2);
					}
					covariance = covariance * 0.1;
					varX = varX * 0.1;
					varY = varY * 0.1;
					resultCorr[i][j] = covariance / sqrt(varX * varY);
					he = he * 0.1;
					resultCov[i][j] = he - (E[i] * E[j]);
				}
			}


		}
	}
}

int main() {
	double resultE[5];
	double resultCov[5][5];
	double resultCorr[5][5];
	INFOR student[10] = {
		{170.0,64.0,4.3,3.5,17.24},
		{173.0,70,4.1,4.0,15.0},
		{168.0,63.0,3.5,3.0,9.5},
		{175.0,85.0,3.3,2.5,11.0},
		{183.0,80,3.2,2.0,13.0},
		{165.0,56.0,2.9,3.5,11.0},
		{162.0,62.0,3.6,4.5,12.0},
		{169.0,70.0,3.9,3.0,13.8},
		{154.0,48.0,3.4,3.5,14.2},
		{176.0,68.0,3.3,3.5,17.8}
		};
	
	calcE(student,resultE);
	calcCovCorr(student, resultE, resultCov,resultCorr);


	printStudent(student,resultE,resultCov,resultCorr);

	return 0;
}	
