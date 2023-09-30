/*----------------------------------------------------------------------
  MachBandEffect.c
----------------------------------------------------------------------*/
#include <stdio.h>
#define uc unsigned char

uc cc[800][1000],char$ptr[1000];

main()
{
char   IOBUFF[30];
FILE   *file$nameB;
int   fhd=1000,fvd=800;
int    ii1,ii2;
int   numwrite;
int division;
int division_num;
int present = 0 ;
int present2;
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
/* createf the file */
   rewind(file$nameB);
   
   division_num = 255 / division;
   for(ii1=0;ii1<fvd;ii1++){
      present = 0;
      present2 = fhd/division;
       for(ii2=0;ii2<fhd;ii2++){
          if (ii2 >present2){
             present += division_num;
             present2 += fhd/division;// 1000 / 8  ->125
         }
           cc[ii1][ii2]=0 + present;
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
