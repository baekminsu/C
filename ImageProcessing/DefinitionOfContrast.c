/*----------------------------------------------------------------------
  DefinitionOfContrast777.c
----------------------------------------------------------------------*/
#include <stdio.h>
#define uc unsigned char

uc cc[1500][1500],char$ptr[1500];

main(){
	
char IOBUFF[30];
FILE *file$nameB;
int fhd=1000,fvd=800;
int ii1,ii2;
int numwrite;
int division;
int division_num;
int present = 0;
int present2;


int temp;
/* Save file name */
   printf("\rOUTPUT FILE NAME : ");
   fflush(stdin);
   gets(IOBUFF);
   file$nameB=fopen(IOBUFF,"wb");
   
/* receive file size */
   printf("\rFILE SIZE [H_dim V_dim] : "); // 1000 800
   scanf("%d %d",&fhd,&fvd);
   printf("\How many pieces should we split the picture into? : ");
   scanf("%d",&division);
   rewind(file$nameB);
   
/* create the file */
   division_num = 255 /division;
   
   for(ii1=0;ii1<fvd;ii1++){ //background 1000 800 division 3
       present =0;
       present2 = fhd/division;
       for(ii2=0;ii2<fhd;ii2++){
          	if(ii2 > present2 ){
             present += division_num; 
             present2 += fhd/division;
         	}
        	cc[ii1][ii2]=0 +present;
      	}
	}
	
	int triple,triple2;
	triple = (fhd/3)/3;
	triple2 = (fvd/3);
	temp = triple;
	int i,j;
	
	for(ii2=0;ii2<fhd;ii2++){
		
		if ( ii2 == triple){
			
			for (i = ii2; i < ii2+temp;i++){
				for(j = triple2; j <triple2*2; j++){
					cc[j][i] = 128;
				}
			}
			triple += (temp*3);		
		}
		
	}
   
   for(ii1=0;ii1<fvd;ii1++){
       for(ii2=0;ii2<fhd;ii2++){
           	char$ptr[ii2]=cc[ii1][ii2];
      	}
     	numwrite=fwrite((char *)char$ptr,sizeof(uc),fhd,file$nameB);
   }
   
   fclose(file$nameB);
}
