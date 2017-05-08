#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Consts1.h"
#define Inp 6000

/*  This function generates the output. It actually generates
	80 evolutions in time from the input data. It also prints the
	input along with the outputs to the screen and to a series
	of csv files called Data.csv.xxx which are then */

double *RandInput();

void outgen()
{
	float *consdef();
	float *w;
	w = consdef();
	float Ex, Ey, Ez;
	Ex = *w;
	Ey = *(w+1);
	Ez = *(w+2);

	static double I[Inp];              

    double *p;
    int i=0, l=0;

    FILE *pf0;
    pf0 = fopen("Data.csv.000","w");
    p = RandInput();

    for (i=0; i<Inp;)
    {
		for (l=0; l<6; l++)
		{
			printf("%f\t", *(p + i+l) );
	        fprintf(pf0,",%f", *(p + i+l) );
	    	I[i+l] = *(p+i+l);
		}
		printf("\n");
		fprintf(pf0, "\n");
		i = i+6;
	}	
	fclose(pf0);

	static double Finals[Inp];
	double tt = t;
	int j;	
	FILE *fp;
	for (j=1;j<81;j++)
	{
		char buf[80];
		sprintf(buf,"Data.csv.%03d", j);
		fopen(buf,"w");
		fp = fopen( buf, "w");
        int k=0;
		l=0;
		for (k=0; k < Inp;)
		{
			Finals [k] = (0.5/M)*q*Ex*tt*tt + I[k+3]*tt +I[k];
			Finals [k+1] = (0.5/M)*q*Ey*tt*tt + I[k+4]*tt +I[k+1];
			Finals [k+2] = (0.5/M)*q*Ez*tt*tt + I[k+5]*tt +I[k+2];
			Finals [k+3] = q*Ex*tt/M + I[k+3];
			Finals [k+4] = q*Ey*tt/M + I[k+4];
			Finals [k+5] = q*Ez*tt/M + I[k+5];

			for (l=0; l<6; l++)
			{
				printf("%f\t", Finals[k+l]);
				fprintf(fp,",%f", Finals[k+l]);
			}
			printf("\n");
			fprintf(fp, "\n");	
			k = k+6;
		}
		tt = (j+1)*t;
		fclose(fp);
	}
}


