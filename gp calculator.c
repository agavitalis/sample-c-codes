#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
//my first programming outing
//trying to program a gp calculator

int main()
{
float unTotalUnitsLoad=0;
char chCourse[6];
char grade=0;
int nUnitLoad=0;
unsigned x=0;
float unSum=0;
float GP=0;
    printf("WELCOME TO VITA & 0KWY'S GP CALCULATOR\n\tnever give up!!!");
    printf("\n\nEnter the total no of units load pls:\n");
    scanf("%f",&unTotalUnitsLoad);
    
    int count = 1;
    int unTotalCourses;
      
    printf("Enter the total no of courses offered:\n");
    scanf("%d",&unTotalCourses);
      
while(count<=unTotalCourses) {
      
int a = 5;
int b = 4;
int c = 3;
int d = 2;
int e = 1;
int f = 0;
     
puts("Name of course:\n");
scanf("%s",&chCourse);
     
puts("Unitload\n");
scanf("%d",&nUnitLoad);
           
puts("Enter your grade:\n");
scanf("%s",&grade);
    
  
if( grade == 'a')
    grade = 5;     //you can either enclose it or leave it,it works on both ways.
      
else if( grade == 'b')
{ 
grade = 4;
}
else if (grade == 'c')
{
grade = 3;  
}
else if (grade == 'd')
{
grade = 2;
}
else if (grade == 'e')
{
grade = 1;
}
                         
else grade = 0;
                
x = grade*nUnitLoad;
//   printf("x%u\n",x);
unSum +=x;  //to compute the general sum 
count++; //performs the operation for no of course time
}

printf("unSum is:%f\n",unSum);

GP =(unSum / unTotalUnitsLoad);
printf("loading...............");
printf("Your GP is:%f\n",GP);
//declearation of gp  values
if (GP<1.0)
{printf("You made a PASS...\n\tDont Give Up,you can still make it!!");}
else if (GP>=1.0 && GP<2.5)
{printf("You made a THIRD CLASS...\n\tKeep on struggling,you star is about to shine");}
else if (GP>=2.5 && GP<3.5)
{printf("You made a SECOND CLASS LOWER...\n\tKeep your face straight bro,You made it");}
else if (GP>=3.5 && GP<4.5)
{printf("You made a SECOND CLASS UPPER...\n\tYou did it,I was just like you!!!\n\tYou are a good student\nGo into the world and make History!!!");
}
else if (GP>=4.5)
{printf("YOU MADE A FIRST CLASSSSSS!!!!!\n\tkeep the flag flying,You are just like me,I made FIRST CLASS too.\n\tGo out and make name for yourself...\nremain focused and the sky will be your starting point!!");
}
printf("\n\n\n\tcompiled by vita&okwy call for assitance:08163922749");
// system("PAUSE");	
  return 0;
}
