import java.util.*;
import java.lang.*;
import java.util.Stack;
public class Nqueen2_0{
	static int[][] qu = new int[50][50];
	static Scanner input=new Scanner(System.in);
	static int n;
	static int row=0;
	
       static Stack<Integer> s = new Stack<Integer>();
   	public static void main(String[] args)
	     {
		boolean continueInput= true;
		do{
			try{System.out.println("enter n value"); //taking 'n' as input
			n = input.nextInt();
			continueInput =false;
			}
			catch(InputMismatchException ex){
				System.out.println("error !!,enter whole number");
				continueInput= true;
			}
			input.nextLine();
		  }while(continueInput);
	     	System.out.print("\tthe chess board is represented as matrix\n\t where each box of the board is a '0'(zero)\n\tand the queens are placed as '1'(one)s\n\t");
		nqueen(); //function call
		for(int i=0;i<n;i++){for(int j=0;j<n;j++){ System.out.print(qu[i][j]+" ");} //printing output matrix
				System.out.print("\n\t");}
	     }
	public static void nqueen(){

		int flag;
		for(int i=0;i<n;i++){
			 for(int j=0;j<n;j++)
				qu[i][j]=0;
			}
		
		while(row<n)
		  {	flag=0;
		     for(int k=0;k<n;k++){
			 if(check(row,k))
			    {
				qu[row][k]=1;
				flag++;row++;
				s.push(k);
				break;
			    }	
		        }
		     if(flag==0) {
		      replace(--row,s.pop());}
		
		  }
		return ;		
	     }
	public static void replace(int r,int c) //recursive function for backtracking
             {
		qu[r][c]=0;
		int flag=0;
		for(int i=c+1;i<n;i++){
			if(check(r,i)==true){
			     qu[r][i]=1;
			     flag++; row++;
			     s.push(i);break;
                         }
		      }
		    if(flag==0) replace(--row,s.pop());
		return;
             }
	public static boolean check(int r,int c)  //function to findout the position is feasible 
	     {
		int i=0,j=r,k=c,l=c;
		for(i=0;i<n;i++){    if(qu[r][i]==1||qu[i][c]==1){ return false; }
				      }
	
		while(j>=0){   	if(k>=0 && qu[j][k--]==1) return false; 
				if(l<n && qu[j][l++]==1) return false;
				j--;
			   }

		j=r;k=c;l=c;
		while(j<n){   	if(k<n && qu[j][k++]==1) return false; 
				if(l>=0 && qu[j][l--]==1) return false;
				j++;
			   }
		
		return true;

	    }

}


