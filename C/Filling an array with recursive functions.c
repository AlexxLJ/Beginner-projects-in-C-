#include <stdio.h>

int menu(int a, int b, int arr[]);
void printArray(int index, int size, int arr[]);
//void set_max(int arr[], int size);

int main() {
	int numero, i = 0, arr[100];
	
	printf("Enter a size: ");
	scanf("%i", &numero);
	
	// Call the menu function to fill the array
	menu(i, numero, arr);
	
	// Print the contents of the array using recursion
	printf("The numbers entered are:\n");
	printArray(0, numero, arr);
	printf("\n");
	
	return 0;
}

int menu(int a, int b, int arr[]) {
	if (a < b) {
		printf("Enter a number: ");
		scanf("%i", &arr[a]);
		a += 1;
		return menu(a, b, arr); // Return the result of the recursive call
	}
	return 0;
}

void printArray(int index, int size, int arr[]) {


	if (index < size) {
		printf("%i ", arr[index]);
		printArray(index + 1, size, arr); // Recursive call to print the next element
	}
	
}
