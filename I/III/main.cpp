/*Для заданного e найти наименьшее n такое, что 2^n / n! < e. Вывести все члены последовательности от 1-го до n-го.*/
#include <math.h>
#include <stdio.h>
#include <conio.h>

int Factorial(int number) 
{ 
	if (number > 1) 
		return number * Factorial(number - 1);
	return 1; 
} 

int main()
{
	int n=0;
	double x,f,e;
	while(e>0)
	{
		scanf("%f", &e);
	}
	while(x<=e)
	{
		n++;
	f=f/n;
	x=2*n/f;
	printf("%d",&n);
	}
	return 0;
}