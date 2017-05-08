#include <stdio.h>

/* This function asks the user to input
   the value of the Electrical Field. */

float *consdef()
{
	int n;
	static float E[3];
	char Coo[3] = {'x','y','z'};
	for (n=0; n<3; n++)
	{
		printf ("Please Enter the value of Electrical Field (in N/C) in the %c-direction:", Coo[n]);
		scanf ("%f",&E[n]);
	}
	return E;
}
