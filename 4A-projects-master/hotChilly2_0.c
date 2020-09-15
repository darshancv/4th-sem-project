#include<stdio.h>
int takein()
{
       	int a;
   	while(1)
	    {
		printf("\n               \t\t\t");
		 scanf("%d",&a);
		 if(a != 1 &&a != 2 &&a != 3)
		      {
			 printf("You can enter either 1 or 2 or maximum 3\n");
			printf("Take again\n");
			continue;
		      }
			 return a;
			}	
}

void main()
{
	int chocolate,i,n=1,first,multi,number,l1,l2;
	printf("Enter the number of chocolates\n");
	scanf("%d",&chocolate);     /*Read the number of chocolates*/ 
	while((4*n) < chocolate)	/*Determines the iterative number 'n' ie. searches for the number 
					greater than the number of chocolates*/
		n++;
		
	if(chocolate % 4 !=0)		/*If the number of chocolates is not a multiple of 4 ,the it enters */ 
	{
		printf("Computer");
		printf("\t\t\tUser\n");
		multi = (4*n) - 4;	/*Multi will store the value which is a lesser multiple of 4 
						ie.(4*3)-4 = 8*/
		first = chocolate - multi;//First will holds number of chocolates the computer has taken
		for(i=0;i<n-1;i++)
		{
			chocolate = chocolate - first;// remaining number of chocolates is updated
			printf("    %d",first);
			//printf("\t\t\n");
			printf("\n        \t\t\t");
			number = takein();
			chocolate = chocolate - number;// remaining chocolates
			first = 4 - number; //assign 'first' with the number of chocolates the computer has to take
		}
		  printf("    %d",first);
	}
	
	else
	{
		printf("Take your chocolate\n");
		printf("Computer");
		printf("\t\t\tUser\t\t\t");
		for(i=0;i<n;i++)
			{
				
				//number = takein();
				printf("\n \t\t\t\t");
				number = takein();
					
				chocolate = chocolate - number;
				//printf("\t\t\t\t%d",number);
				//printf("\t\t\n");	
				first = 4 - number;
				chocolate = chocolate -first;
				printf("    %d\n",first);
			}
	}
		printf("\n HAHA you lose\n Eat the chilly \n Peace Out!!!!!!!!!\n");
}

