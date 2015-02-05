#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
void main()
{
double p, r, q, t;
printf("\n Enter radius! \n");
  scanf("%lf", &r);
printf("\n Enter Diagonal q!\n ");
  scanf("%lf", &q);
printf("\n Enter Diagonal p!\n ");
  scanf("%lf", &p);
t=(p*q)/2*sqrt(q*q+p*p);  // radius through entered diagonals
  if (t<=r)  printf ("\n The circle can come through the rhombus\n ");
  else printf ("\n The circle can't come through the rhombus\n ");
  getch();
}