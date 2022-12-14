// Zoe Carter, Kyndall Jones, Julian Forbes
//https://www.includehelp.com/c-programs/function-pointer-example-in-c.aspx
//https://www.geeksforgeeks.org/function-pointer-in-c/
#include <stdio.h>
#include <stdlib.h>

/* IMPLEMENT ME: Declare your functions here */
int add (int a, int b);
int subtract (int a, int b);
int multiply (int a, int b);
int divide (int a, int b);
//the declaration of the function pointer

int main (void)
{

	int (*operator[]) (int, int) = {add, subtract, multiply, divide};
  int op, a, b;
	/* IMPLEMENT ME: Insert your algorithm here */
  printf("0 for add, 1 for subtract, 2 for multiply, 3 for divide. What operation do you want?\n");
  scanf("%d",&op);
  printf("What numbers do you want to use the operator with?\n");
  scanf("%d and %d",&a,&b);
  (*operator[op])(a, b);

	return 0;
}

/* IMPLEMENT ME: Define your functions here */
int add (int a, int b) { printf ("Adding '%d' and '%d' gives you\n", a,b); return a + b; }
int subtract (int a, int b){printf("Substracting '%d' and '%d' gives you\n", a,b); return a-b;}
int multiply(int a, int b){printf("Multiplying '%d' and '%d' gives you\n", a,b); return a * b;}
int divide(int a, int b){printf("Dividing '%d' and '%d' gives you\n", a,b); return a/b;}
