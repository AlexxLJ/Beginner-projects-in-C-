/*
	Author : AlexxLJ
	
*/


#include<stdio.h>
#include<string.h>
#define N 50

typedef struct{
	char name[N];
	int number;
	int added;
	char COMMENTs[N];
}contact;

typedef struct{
	char name_owner[N];
	contact known[10];
	int full_bi;
}list;

list bib[3]; 

void empty();
void change(char palabra[]);
void addlist();
void addcont();
void consult();	


int main(){
	int op;
	char key;
	int c=0;
	
	empty();
	
	do{
		do{
			printf("Choose between: \n");
			printf("(1) Add a new list. \n");
			
			if(c>0){
			printf("(2) Add a new contact to a list. \n");}
			if(c==2){
			printf("(3) Consult a contact. \n");}
			scanf("%i", &op);
			
		} while(op < 1 || op > 3 || (c == 0 && op > 1));
		
		switch(op){
			case 1:{
					c=1;
					addlist();
				break;
		}
			case 2:{
				if(c>0){
					c=2;
					addcont();}
				
				break;
		}
			case 3:{
				if(c==2){
					
					consult();}
				
				break;		
		}
	}
		printf("Wanna do something else? (S/N)");
		fflush(stdin);
		scanf("%c", &key);
		
	} while(key == 's' || key == 'S' );
	
	return 0;
}
	
	
void empty() {
	int i,j;
	
	for (i = 0; i<3; i++){
		bib[i].full_bi = 0;
		for (j = 0; j<10; j++){
			bib[i].known[j].added = 0;
		}
	}
}



void change(char word[N]){
	int i;
		
	for (i = 0; i < N; i++){
		if (word[i] == '\n'){
			word[i] = '\0';
		}
	}
}

	
void addlist(){
	int i, aux;
	aux = 0;
		
	for (i = 0; i < 3 && aux ==0; i++){
		if (bib[i].full_bi == 0){
			printf("Enter the name for the owner of the contact list: ");
			fflush(stdin);
			fgets(bib[i].name_owner, N, stdin);
			change(bib[i].name_owner);
			
			bib[i].full_bi = 1;
			aux = 1;
		}
	}
	if (aux == 0){
		printf("There is no free space left for a new contact. \n");
	}
}

	
void addcont(){
	int i, op, aux = 0;
	
		
	for (i = 0; i < 3; i++){
		if (bib[i].full_bi == 1){
			printf("(%i) %s.\n", i, bib[i].name_owner);
			
		}
	}
	scanf ("%i", &op);
	
	for (i = 0; i < 10 && aux == 0; i++){
		if (bib[op].known[i].added == 0){
			printf("Enter the name of the contact: ");
			fflush(stdin);
			fgets(bib[op].known[i].name, N, stdin);
			change(bib[op].known[i].name);
			
			printf("Enter the number of the contact: ");
			fflush(stdin);
			scanf("%i", &bib[op].known[i].number);
		
			do{printf("Do you want to enter a comment? CLICK : \n");
			printf("(1) = \"Yes\"\n");
			printf("(2) = \"No\"\n");
			fflush(stdin);
			scanf("%i", &op);
			}while (op > 2 || op < 1);
			
			if (op == 1){
				
			
			fflush(stdin);
			fgets(bib[op].known[i].COMMENTs, N, stdin);
			change(bib[op].known[i].COMMENTs);
			}
			
			bib[op].known[i].added = 1;
			aux = 1;
		}
	}
}
	


void consult(){
	
	int op, i, j, aux, numero;
	char search[N];
	
	do{
		printf ("How do you want to search: \n");
		printf ("(1) Contact name. \n");
		printf ("(2) Contact number. \n");
		printf ("(3) Contact comment. \n");
		scanf ("%i", &op);
	
	}while (op<1 || op > 3);
	
	switch(op){
	case 1:{
		printf("Enter the name of the contact: ");
		fflush(stdin);
		fgets(search, N, stdin);
		change(search);
		
		for(i = 0; i<3; i++){
			aux =1;
			for(j = 0; j<10; j++){
				aux = strcmp(search,bib[i].known[j].name);
				if (aux == 0){
					printf ("The contact %s is stored in the %s list. \n", search, bib[i].name_owner);
					printf("The contact number is: %i. \n", bib[i].known[j].number);
					printf("Contact COMMENT is: %s \n", bib[i].known[j].COMMENTs);
				}	
			}
		}	
	
		
		break;
	}
	
	case 2:{
			printf("Enter the number of the contact: ");
			fflush(stdin);
			scanf("%i", &numero);
			
			for(i = 0; i<3; i++){
				
				for(j = 0; j<10; j++){
					if(numero == bib[i].known[j].number){
						
						   printf ("El número de teléfono es de: %s. \n", bib[i].known[j].name);
						   printf ("El contacto %s se encuentra guardado en la lista de %s. \n", bib[i].known[j].name , bib[i].name_owner);
						   printf("El COMENTARIO del contacto es: %s. \n", bib[i].known[j].COMMENTs);
						   
					   }	
					}	
				}
				
			
			
			break;
		}
			
	case 3:{
				printf("Enter the COMMENT (or nickname): ");
				fflush(stdin);
				fgets(search, N, stdin);
				change(search);
				
				for(i = 0; i<3; i++){
					aux = 1;
					for(j = 0; j<10; j++){
						aux = strcmp(search,bib[i].known[j].COMMENTs);
						if (aux == 0){
							printf ("El contacto cuyo apodo es %s se llama %s. \n", search, bib[i].name_owner);
							printf ("Su número de teléfono es: %i. \n", bib[i].known[j].number);
							printf ("El contacto %s se encuentra guardado en la lista de %s. \n", search, bib[i].name_owner);
							
						}	
					}
				}	
				
				
				break;
			}		
	}
}
