#include<stdio.h>
#include<stdlib.h>
#include<math.h> 
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

int mapIt(char ch,FILE *fp2);
int res = 0;
FILE * fp1,*fp2;
int main()
{
	int res=0,track=0;
  FILE * fp1,*fp2;
	fp1 = fopen("mes.txt","r");
  fp2 = fopen("mesEn.txt","w");
	if(fp1==NULL||fp2==NULL) printf("file not open");
	char ch=fgetc(fp1);
	while(ch!= EOF)
	  {
		switch(ch){
		case 32 : fprintf(fp2,"%d",79);	break; 	
		case 79 : fprintf(fp2,"%c",' ');break;
		case '0': fprintf(fp2,"%d",25);	break;
		case 49:  fprintf(fp2,"%d",26); break;
		case '3': fprintf(fp2,"%d",30); break;
		case 69 :if(track==0){ fprintf(fp2,"%d",62);track++; }
				else {fprintf(fp2,"%d",63);track--;}
				break;
		case 70 : fprintf(fp2,"%d",70);	break;
		case 80 : fprintf(fp2,"%d",80);	break;
		case 10: break;
		case 90 : fprintf(fp2,"%d",90);	break; 
		default :mapIt(ch,fp2); break;
	       } 
	ch=fgetc(fp1); 
	}
fclose(fp1);
fclose(fp2);
}

int mapIt(char ch,FILE *fp2)
{
	 if(ch/10>5&&ch/10<9){

		if(isPrime((int)ch))fprintf(fp2,"%d",ch);
  		else if(ch/10==6){
              		res = (int)(floor(6*8.85)+(ch%10));
               		fprintf(fp2,"%d",res); }
    		else if(ch/10==7){
             		res = ((int)floor(7*6.97))+(ch%10);
               		fprintf(fp2,"%d",res); }
       		else if(ch/10==8){
              		res = ((int)floor(8*5.2))+(ch%10);
               		fprintf(fp2,"%d",res); }
		  }
       else if(ch/10==5) {
              res = ((int)floor(5*6.37))+(ch%10);
               fprintf(fp2,"%d",res); }
	else{ printf("error encrypting"); exit(0);}
return 0;
}














