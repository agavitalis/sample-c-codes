#include <stdio.h>
#include<math.h>
int main()
{//decleration of variables
	int vitalis[10];
	int count = 10;
	int x = 0,y = 0,z = 0;
	//keying in of values
	printf("enter the no pls\n");
	scanf("%d",&x);
	//computation begins,first division
	while(x>0)
	{for(;y < count;y++)
	{
	vitalis[y] = x % 2; //saving into the array

	//printf("%d",vitalis[y]); i want to print only the binary
	x=x / 2;
	}
    } 
    printf("\n");
    //printing from the array backwards
	for(int y = count-1; y >= 0; --y)
	{printf("\a%d",vitalis[y]);}
	
return 0;
}
