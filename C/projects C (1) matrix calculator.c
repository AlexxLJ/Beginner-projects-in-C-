
#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 
#define N 100

typedef struct{
	int Matr1;
	int Matr2;
	int Result;
	
}matrix;

matrix M1[5];

void empty(); 
void start (int b);
void introduce (int a, int b);
void random (int a, int b, int matriz[a][b]);		
void dictation (int a, int b, int matriz[a][b]);	
void read (int a, int b, int matriz[a][b]);	
void Add(int a, int b);
void Subtract(int a, int b);	
void Multiply(int a, int b, int matriz[a][b]);
void Determinant(int a, int b, int matriz[a][b]);


int main(){
	
	int b=0;
	
	empty();
	start(b);
	
	
	return 0;
	
}
	
	
void empty() {
	
	int i;
		
	for (i = 0; i<N; i++){
		M1[i].Matr1 = 0;
		M1[i].Matr2 = 0;
		M1[i].Result = 0;
		
	}
}


void start (int b){
	
	int op, d1, d2,D;
	
	
	do{
		if (M1[0].Matr1 == 0 || M1[1].Matr1 == 0){
			
			printf ("We are going to represent a matrix. \n");
			D=0;
		
		}
		else{
		
			printf ("\nWe are going to represent a matrix. \n");
				
		}
		
		printf ("Choose between: \n");
		printf ("(1)Square matrix. \n");
		printf ("(2)Rectangular matrix. \n");
		
		scanf("%i", &op);
		
	}while (op < 1 || op > 2);
	
	printf ("\n");
	
	switch(op){
		
	case 1:
		d1=2;
		
		do{
			
			printf ("Enter your dimension in d1 format: \n");
			fflush(stdin);
			scanf("%i", &d1);
			
			
		}while (d1 < 2 || d1 > 9);
		
		if (D == 0) {
			D = d1;
			b = D;
			//c=a;}
		}
		else {
			
			D=b;
			do{
				printf ("Enter your dimension in d1 format: \n");
				fflush(stdin);
				scanf("%i", &d1);
				
				
			}while (d1 != D);	
		}
		
		introduce(d1,d1);	
		
		
		break;
	case 2:
		
		if (D == 0){
			d1=2;
			d2=3;
			
			do{printf ("Enter your dimension in d1xd2 format: \n");
				fflush(stdin);
				scanf("%ix%i", &d1, &d2);
				printf("\n");
				
			}while(d1 ==d2);		
			
			D=d2;
			b = D;
			//c=a;
		}else {
			D = b;
			
			do{
				printf ("Enter your dimension in d1xd2 format: \n");
				fflush(stdin);
				scanf("%ix%i", &d1, &d2);
			
			
				if (d1 != D){
					printf ("IMPOSSIBLE with that dimension \n");
					printf ("Try again if you want.\n");
				}
			
			}while (d1 != D);	}
		
		introduce(d1,d2);	
		
		break;
		
		}
}	

	
	
void introduce (int a, int b){	
	
	int op1;

	int matriz1[a][b];
	
	do{
		
		printf ("Choose between: \n");
		printf ("(1)A random matrix. \n");
		printf ("(2)A dictated matrix number by number. \n");
		fflush(stdin);
		scanf("%i", &op1);
		
	}while (op1 < 1 || op1 > 2);
	
	printf ("\n");	
	
	switch(op1){
	case 1:
		
			random(a, b, matriz1);
			
	
		break;
	case 2:
			
			dictation(a, b, matriz1);;
	
			
			break;
			
	}

}

void random(int a, int b, int matriz[a][b]){
		
	int i,j;
	
	srand(time(NULL));
	
	for (i = 0; i<a; i++){
		for (j = 0; j < b; j++){
			matriz[i][j]=rand()%10;
		}
	}
	read (a, b, matriz);
		
}	
		
	
void dictation (int a, int b, int matriz[a][b]){
			
	int i,j, x;
			
	for (i = 0; i<a; i++){
		for (j = 0; j < b; j++){
			printf ("Type row by row, digit by digit: ");
			fflush(stdin);
			scanf("%i", &x);
			matriz[i][j]= x;
		}
	}
	
	printf ("\n");
	read (a, b, matriz);
			
}	
	

	
void read (int a, int b, int matriz[a][b]){
		
	int i,j, y=0, d=10;
	M1[90].Result = b;	
		
		
	for (i = 0; i<a; i++){
		for (j = 0; j < b; j++){
			printf ("%i ", matriz[i][j]);
			
			if ((M1[0].Matr1 == 0 && M1[1].Matr1 == 0) || d == 0 ){
				M1[y].Matr1=matriz[i][j];	
				d=0;
			}else{
				M1[y].Matr2=matriz[i][j];	
			}
			y++;	
			
		} 
			
		printf ("\n");
		
	}
		
	int op2 ;
		
	
	if ( d == 0){
			
			do{
				
				printf ("\nWhat operation you want to do with it? \n");
				printf ("Choose between: \n");
				printf ("(1)Addition. \n");
				printf ("(2)Subtraction \n");
				printf ("(3)Multiplication. \n");
				printf ("(4)Calculate its determinant. \n");
				fflush(stdin);
				scanf("%i",&op2);
				
				
			}while(op2 < 1 || op2 > 4);
			
			
				printf ("\n");
			
			
			switch(op2){
			case 1:
				Add(a,b);
				break;
			case 2:
				Subtract(a,b);
				break;
			case 3:
				Multiply(a,b, matriz);
				break;
			case 4:
				Determinant(a,b, matriz);
				break;
			}	
	}
}
		

		void Add(int a, int b){
			
			introduce (a,b);
			
			
			int i, j, y=0;
			printf ("\n");
			printf ("This is the result: \n");
			
			for (i = 0; i<a; i++){
				for (j = 0; j < b; j++){
					printf ("%i ", M1[y].Matr1+M1[y].Matr2);
					y++;
				} 
				
				printf ("\n");
			}
			
		}

			
		void Subtract(int a, int b){
			
			introduce(a,b);
			
			printf ("\n");
			printf ("This is the result: \n");	
			
			int i, j, y=0;
			
			
			for (i = 0; i<a; i++){
				for (j = 0; j < b; j++){
					printf ("%i ", M1[y].Matr1-M1[y].Matr2);
					y++;
				} 
				
				printf ("\n");
			}	
		}	

			
		void Multiply(int a, int b, int matriz[a][b]){
			
			
			int i, j, k, y=0, z=0, x1;

			start(b);
			
			x1 = M1[90].Result ;	
			
			for (y = 0; y<a*x1; y++){
				M1[y].Result = 1; 
			}
			y=0;
			
			printf ("\nThis is the result: \n");
			for (i = 0; i<a; i++){
				for (j = 0; j<x1; j++){
					for (k = 0; k < b; k++) {	
							if (M1[z].Result == 1){
								
								
								y = y + M1[j+k*x1].Matr2*matriz[i][k];
								
							}
						
						
					}
						
						M1[z].Result = y;
					
						printf ("%i ", M1[z].Result);
						z++;
						y=0;
						
				}
				printf("\n");
			}
			

		}
			

		void Determinant(int a, int b, int matriz[a][b]){
				
			
			if (a == b && a < 4){
				printf ("\n\n");
			
				printf("It is possible and its determinant is: ");
				
				if ( a == 2 ){
					
					printf("%i", matriz[0][0]*matriz[1][1]-matriz[0][1]*matriz[1][0]);
					
				}else 
					{
					
					printf("%i", matriz[0][0]*matriz[1][1]*matriz[2][2]+matriz[1][0]*matriz[2][1]*matriz[0][2]+matriz[0][1]*matriz[1][2]*matriz[2][0]-matriz[0][2]*matriz[1][1]*matriz[2][0]-matriz[0][1]*matriz[1][0]*matriz[2][2]-matriz[0][0]*matriz[2][1]*matriz[1][2]);
				}
			}	
						
			else{
				
				printf("Not possible if not square.\n");
				printf("If so, , ");
				printf("at the moment I cannot calculate with matrices whose d1>3");
			}
				
		
		}
					
					
					
