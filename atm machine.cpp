#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int main()
{
	int x;
	long int password;
	start:;
	printf("\tWELCOME TO VITA MICOFINANCE BANK\n\tyou are at the right place\n\n");
pass:;	//password declearation
printf("PLS ENTER YOUR PASSWORD\n");
scanf("%ld",&password);
	if ( password !=12345)
	{
 printf("\t\tenter the correct password pls\n\n");
	goto pass;
	}
start1:;
	printf("\n\nWHAT CAN WE DO FOR YOU?");
	
	printf("\n\n1.ACCOUNT INFORMATION\t2.WITHDRAWAL\n\n3.TRANSFER\t4.RECHARGE CARD\n\n5.ENQUIRY\t6.EXIT\n");
	
	scanf("%d",&x);
	if (x ==1)//computation for amount
	{
		printf("YOUR ACCOUNT BALANCE IS #3333000,000\n\nwould you like to perform another transaction?");
		printf("\n1.YES\t2.NO\n");
		scanf("%d",&x);
		if (x==1)
	{
		goto start1;
	}	
	if (x==2)
	{
		goto exit;
	}
	}
	else if (x==2)//withdrawal computation
	{
		printf("\nENTER THE AMOUNT");
		printf("\n\n1.#1000\t2.#2000\t3.#5000\n4.#10,0000\t5.#20,0000\t6.others\n");
		scanf("\n%d",&x);
		 if(x==6)
		 {printf("enter the amount pls\n");
		 scanf("%ld");
		 }
		printf("\n\tYOUR TRANSACTION WAS SUCCESSFUL\n\t\tPLS TAKE YOUR CASH\n\nwould you like to perform another transaction?\n");
		printf("\n\n1.YES\t2.NO\n");
		scanf("%d",&x);
		
		if (x==1)
		{
			goto start1;
		}
		if (x==2)
		{
			goto exit;
		}
	}
	//computation for transfer
	else if(x==3)
	{
	printf("HOW MUCH WOULD YOU LIKE TO TRANSFER\n\nenter the amount pls....\n");
	scanf("%ld");
	printf("ENTER THE ACCOUNT NUMBER,TO BE TRANSFERD TO\n\n");
	scanf("%ld");
	printf("YOUR TRANSACTION WAS SUCCESSFUL\n\nwould you like to perform another transaction?");
	
		printf("\n\n1.YES\t2.NO\n");
		scanf("%d",&x);
		
		if (x==1)
		{
			goto start1;
		}
		if (x==2)
		{
			goto exit;
		}
	}
	else if (x==4)//computation for recharge
{
	printf("enter the phone number pls\n");
	scanf("%ld");
	printf("enter the amount pls\n");
scanf("%ld");
	
	printf("\nYOUR TRANSACTION WAS SUCCESSFUL\n\nwould you like to perform another transaction?");
	
		printf("\n\n1.YES\t2.NO\n");
		scanf("%d",&x);
		
		if (x==1)
		{
			goto start1;
		}
		if (x==2)
		{
			goto exit;
		}
	
	}
	else if (x==5)//computation for enquiry
{
printf("for complains, suggestions and futher enquiries call our customer care line call:08163922749\n");
printf("\n\t\t\twe are here for you!!");

	printf("\n\nwould you like to perform another transaction?");
	
		printf("\n\n1.YES\t2.NO\n");
		scanf("%d",&x);
		
		if (x==1)
		{
			goto start1;
		}
		if (x==2)
		{
			goto exit;
		}


}
else if (x==0||x>=6)
{
	goto exit;
}	
	
	
	
	exit:;
	printf("THANKS FOR BANKING WITH US\n\nhave a pleasant day!!");
	return 0;
	
}
