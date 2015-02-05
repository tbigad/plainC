/*В массиве h(n) хранятся значения высот некоторого профиля местности (ее вертикального сечения) с постоянным шагом по горизонтали.
Найти области (номера точек измерения высоты), невидимые для наблюдателя, находящегося в точке h1.*/

#include <stdio.h>

int main()
{
	int point[20]={1,2,5,6,12,22,23,20,21,22,23,24,26,28,20,31,37,38,36,39};
	int visible;
	int unvisible=0;
	for (int i = 0; i < 19; i++)
	{
		if(point[i]<point[i+1]&&point[i+1]>unvisible)
		{
			visible = point[i+1]; 
			printf("%d\n",visible);
			if (point[i]>point[i+1])
			{
				unvisible = point[i+1];
			}
		}
		
	}
}