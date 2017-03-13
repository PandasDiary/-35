#define _CRT_NO_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <locale.h>
#include <malloc.h>
int *XA, *YA, *XB, *YB, rx1, rx2, rx3, ry1, ry2, ry3;
bool result;
double minarea=1000000, area;

bool proverka(int X[], int Y[], int x, int y)
{
	int a = (X[0] - x) * (Y[1] - Y[0]) - (X[1] - X[0]) * (Y[0] - y);
	int b = (X[1] - x) * (Y[2] - Y[1]) - (X[2] - X[1]) * (Y[1] - y);
	int c = (X[2] - x) * (Y[0] - Y[2]) - (X[0] - X[2]) * (Y[0] - y);

	if ((a >= 0 && b >= 0 && c >= 0) || (a <= 0 && b <= 0 && c <= 0))
	{
		return true;
	}
	else return false;
	
}

int main()
{
	setlocale(LC_ALL, "rus");
	printf("\nВведите количество точек первого множества:");
	int n;
	scanf_s("%d", &n);
	while (n < 3)
	{
		printf("\nНужно ввести как минимум 3 точки (вершины треугольника)");
		scanf_s("%d", &n);
	}
	printf("\nВведите количество точек второго множества:");
	int m;
	scanf_s("%d", &m);
	while (m < 1)
	{ 
		printf("\nНужно ввести число большее нуля");
		scanf_s("%d", &m);
	}
	XA = (int*)malloc(n*sizeof(int));
	YA = (int*)malloc(n*sizeof(int));
	XB = (int*)malloc(m*sizeof(int));
	YB = (int*)malloc(m*sizeof(int));


	for (int i = 0; i < n; i++)
	{
		int k = i + 1;
		printf("\nВведите элемент первого множества по номером %i:",k);
		printf("\nВведите x[%i]", k);
		scanf_s("%d", &XA[i]);
		printf("\nВведите y[%i]", k);
		scanf_s("%d", &YA[i]);
	}
	for (int i = 0; i < m; i++)
	{
		int k = i + 1;
		printf("\nВведите элемент второго множества по номером %i:", k);
		printf("\nВведите x[%i]", k);
		scanf_s("%d", &XB[i]);
		printf("\nВведите y[%i]", k);
		scanf_s("%d", &YB[i]);
	}


	for (int i = 0; i < n; i++)
		for (int k = 0; k < n; k++)
			for (int m = 0; m < n; m++)
			{
				if ((XA[i] == XA[k] && YA[i] == YA[k]) || (XA[k] == XA[m] && YA[k] == YA[m])||(XA[i] == XA[m]&& YA[i] == YA[m]));
				else 
				{
					int X[3], Y[3];
					X[0] = XA[i];
					X[1] = XA[k];
					X[2] = XA[m];
					Y[0] = YA[i];
					Y[1] = YA[k];
					Y[2] = YA[m];
					for (int l = 0; l < m; l++) //проверка всех точек(входят в треугольник или нет)
					{
						int x = XB[l];
						int y = YB[l];
						if (proverka(X, Y, x, y))
							result = true;
						else {
							result = false;
							break;
						}
					}
					if (result)
					{
						/*Проверка: являются ли данные три точки треугольником */
						int ax = X[1] - X[0];
						int ay = Y[1] - Y[0];
						int bx = X[2] - X[1];
						int by = Y[2] - Y[1];
						int cx = X[2] - X[0];
						int cy = Y[2] - Y[0];
						double moda = sqrt(ax*ax + ay*ay);
						double modb = sqrt(bx*bx + by*by);
						double modc = sqrt(cx*cx + cy*cy);
						if ((moda + modb > modc) && ((modb + modc) > moda) && ((moda + modc) > modb))
							//
						{
							area = abs((X[0] * Y[1] - X[1] * Y[0]) / 2);  //Нахождение площади
							if (minarea > area)
							{
								minarea = area;
								rx1 = X[0];
								ry1 = Y[0];
								rx2 = X[1];
								ry2 = Y[1];
								rx3 = X[2];
								ry3 = Y[2];
							}
						}
					}
				}
			}
	if (minarea == 1000000) printf("\nТакого треугольника в данном множестве нет!");
	else
	{
		printf("\nЭто треугольник с вершинами (%d,%d) (%d,%d) (%d,%d)", rx1, ry1, rx2, ry2, rx3, ry3);
	}
	
	_getch();
	free(XA);
	free(XB);
	free(YA);
	free(YB);
	return 0;
}