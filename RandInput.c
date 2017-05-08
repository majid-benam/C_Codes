#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Inp 6000			/* 6 x The number of particles*/

/*  This function produces a number of (1000) randomly spaced particles
	with random velocities within a predefined range. The number of particles 
	can be increase by changing the value of Inp.*/

double *RandInput()
{
    static double I[Inp];           
    int i, m, bigN = 1000000;
    double bigD = 1000000.0;
    srand( (unsigned)time( NULL ) );							/* seeds the srand function. */
    for (i=0;i<Inp;)
    {   
		for (m=0; m<3; m++)
		{
			I[i+m] = 2*((rand() % bigN) / bigD);     			  /*random X,Y,Z between 0 and 2*/
        	I[i+m+3] = 200*((rand() % bigN) / bigD) - 100;        /*random vx,Vy,Vz between -100 and +100*/
		}
        i = i+6;
    }
    return I;
}
