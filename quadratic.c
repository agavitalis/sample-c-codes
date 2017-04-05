#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//another programming outing,am just anoyed just wana do some coding

int main() 
{
	//a program to solve quadratic equation
	float x1,x2,a,b,c,d,e;
	printf("\tvita is back from the holidays\n\a pls enter the cofficients in the format shown below\n");
	printf("\nax*+bx+c=0\n");
	
	scanf("%f%f%f",&a,&b,&c);
	d = -b + (sqrt(b*b - 4*a*c));
	x1 = d/(2*a);
	
	e = -b - (sqrt(b*b - 4*a*c));
	x2 = e /(2*a);
	
	printf("loading...........................\n");
	printf("x1 = %.2f \nx2 = %.2f",x1,x2);
	
	return 0;
}
