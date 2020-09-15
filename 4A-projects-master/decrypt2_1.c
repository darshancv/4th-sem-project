#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX  2
int top = -1;
int s[MAX];
int digit,conv;
float convert;
int isPrime(int n)
{
    
    if (n <= 1)  return 0;
    if (n <= 3)  return 1;
    if (n%2 == 0 || n%3 == 0) return 0;
 
    for (int i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
           return 0;
 
    return 1;
}
void mapit(int digit,FILE *fp2)
{
	if((digit>57)&&(digit<63))
	{	
		convert = digit - (6*8.85);
		conv = ceil(convert);
		digit = (6*10) + conv;
		fprintf(fp2,"%c",digit);		 
	}
	else if((digit/10>5&&digit/10<9)&&(isPrime(digit)))
			fprintf(fp2,"%c",digit);
			
	else if((digit>49)&&(digit<57))
	{
		convert = digit - (7*6.97);
		conv = (int)ceil(convert);
		digit = (7*10) + conv;
		fprintf(fp2,"%c",digit);	
	}
	else if((digit>41)&&(digit<50))
	{
		convert = digit - (8*5.2);
		conv = (int)ceil(convert);
		digit = (8*10) + conv;
		fprintf(fp2,"%c",digit);	
	}
	else if((digit>30)&&(digit < 39))
	{
		convert = digit - (5 * 6.37);
		conv = (int)ceil(convert);
		digit = (5*10) + conv;printf("%d\n",digit);
		fprintf(fp2,"%c",digit);
	}
	else{	printf("error decrypting ,invalid file .ch is %c\n",digit); }			
 return;
}

void push(int a)
{
	if(top == MAX - 1)
	{
		printf("Stack is full\n");
		return;
	}
	else
	{
		s[++top] = a;
	}
return;
}

int pop()
{
	int elem;	
	if(top == -1)
	{
		printf("Stack is empty\n");	
		return 0;
	}
	else
	{
		elem = s[top--];
	}
return elem;	
}

void main()
{
	char ch='a';int i=0;
	int first,count=0,second,num;
	FILE * fp1,*fp2;
	fp1 = fopen("mesEn.txt","r");
	fp2 = fopen("message.txt","w");
	if(fp1==NULL||fp2==NULL) printf("file not open");
	l1 : while((ch) != EOF)
	{
		{
			ch = fgetc(fp1);
			if(ch == ' ')
		    	{
				count=0;
				num =ch + 47;
				fprintf(fp2,"%c",num);
				goto l1;
			}
			else
			{
				num = ch - '0';
				push(num);
				count++;
			}
		}
		if(count == 2)
		{	
			count = 0;
			first = pop();
			second = pop();
			digit = (second * 10) + first;
			switch(digit)
			{
				case 25: fprintf(fp2,"%c",48);  break;
				case 26: fprintf(fp2,"%c",49);  break;
				case 62 : fprintf(fp2,"%c",69); break;
				case 63 : fprintf(fp2,"%c",69); break;
				case 70 : fprintf(fp2,"%c",70); break;
				case 80 : fprintf(fp2,"%c",80); break;
				case 90 : fprintf(fp2,"%c",90); break;
				case 10 :break;
				case 30 : fprintf(fp2,"%c",51); break; 	
				case 79 : fprintf(fp2,"%c",32); break; 	
				default : mapit(digit,fp2);break;
			}	
		}
		
	}
fclose(fp1);
fclose(fp2);
}
