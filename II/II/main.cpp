/*Многочлены Pm(x) и Qn(x) заданы массивами своих коэффициентов.
Найти частное и остаток от деления Pm(x) и Qn(x) (в виде массивов коэффициентов).*/

#include <stdio.h>
#include <stdlib.h>
const int LEN = 20;

int sub_poly(double* p, double* q, int len);
int main()
{
    double poly1[LEN] = {0};
    double poly2[LEN] = {0};    
    int    len1, len2;
    int    i;
    double coeff;
    int    zero_count;
	puts("Input Poly_1 len\n");
	scanf("%d",&len1);
	puts("Input Poly_1 coeff\n");
    for (i = 0; i < len1; i++)
    {
       scanf("%d",&poly1[i]);
    }
	puts("Input Poly_2 len\n");
	scanf("%d",&len2);
	puts("Input Poly_2 coeff\n");
    for (i = 0; i < len2; i++)
    {
		scanf("%d",&poly2[i]);
    }
    i = 0;
    while ((len1 - i) >= len2)     // пока еще возможно разделить остаток на делитель
    {
        zero_count = sub_poly(poly1 + i, poly2, len2);   // вычитаем коэффициенты
        i += zero_count;
    }
    puts("Ostatok is :\n");
    for (i; i < len1; i++)
       printf("%d\n",&poly1[i]);
    system("pause");
    return 0;
}

int sub_poly(double* p, double* q, int len)
{
    double coeff;
    int  zero_count = 0;
    int  i;
    coeff = p[0] / q[0];     // при умножении на этот коэффициент убивается старший коэфф.
    p[0] = 0;
    for (i = 1; i < len; i++)
        p[i] = p[i] - coeff * q[i];
    while (p[zero_count] == 0)
       zero_count++;
       
    return zero_count;
}