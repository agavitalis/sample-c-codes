
#include <stdio.h>
int main()
{
	int Age;
	printf("enter your Age sir:\n\a");
	scanf("%d",&Age);
	
	if (Age<18)
	{
		printf("\ayou are a minor");
		printf("\n\n go home and help your mum");
	}
	else if (Age>=18 && Age<60)
	{
		printf("you are welcome");
		printf("\n\n proeed to the next level");
	}
	else if (Age>=60)
	{
		printf("you are a senior citizen");
		printf("\n pls go home and have a rest");
	}
	return 0;
}
