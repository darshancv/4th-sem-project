#include<stdio.h>
#include<stdlib.h>
#include<math.h> 
int res =58;
int mapIt(char ch,FILE *fp2);
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
	  {//printf("%d\n",ch);
		switch(ch){
		 case '0': fprintf(fp2,"%d",25);	break;
		case 49: fprintf(fp2,"%d",26);break;
		case '3':fprintf(fp2,"%d",30); break;
		case 83 : fprintf(fp2,"%d",67);break;
		case 62 : fprintf(fp2,"%d",69);	break;
		case 63 : fprintf(fp2,"%d",69);  break;
		case 71 : fprintf(fp2,"%d",70);  break;
		case 70 : fprintf(fp2,"%d",71);	break;
		case 80 : fprintf(fp2,"%d",73);	break;
		case 73 : fprintf(fp2,"%d",80);	break;
		case 69 :if(track==0){ fprintf(fp2,"%d",62);track++; }
				else {fprintf(fp2,"%d",63);track--;}
				break;
		case 10: break;
		case 67 : fprintf(fp2,"%d",83);	break;
		case 90 : fprintf(fp2,"%d",89);	break;
		case 89 : fprintf(fp2,"%d",90);	break;
		case 32 : fprintf(fp2,"%d",79);	break; 	
		case 79 : fprintf(fp2,"%c",' ');break; 
		default :mapIt(ch,fp2); break;
	       } 
	ch=fgetc(fp1); 
	}
fclose(fp1);
fclose(fp2);
}

int mapIt(char ch,FILE *fp2)
{
	 
  	 if(ch/10==6){
              res = (int)(floor(6*8.85)+(ch%10));
               fprintf(fp2,"%d",res); }
     else if(ch/10==7){
              res = ((int)floor(7*6.97))+(ch%10);
               fprintf(fp2,"%d",res); }
       else if(ch/10==8){
              res = ((int)floor(8*5.3))+(ch%10);
               fprintf(fp2,"%d",res); }
       else if(ch/10==5) {
              res = ((int)floor(5*6.37))+(ch%10);
               fprintf(fp2,"%d",res); }
	else{ printf("error encrypting"); exit(0);}
return 0;
}














