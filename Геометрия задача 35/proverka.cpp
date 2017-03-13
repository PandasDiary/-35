#define _CRT_NO_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <locale.h>
#include <malloc.h>

int main()
{
	int X[3], Y[3], x, y;
	X[0] = 0;
	Y[0] = 0;
	X[1] = 3;
	Y[1] = 3;
	X[2] = 6;
	Y[2] = 0;
	x = 3;
	y = 2;
	int a = (X[0] - x) * (Y[1] - Y[0]) - (X[1] - X[0]) * (Y[0] - y);
	int b = (X[1] - x) * (Y[2] - Y[1]) - (X[2] - X[1]) * (Y[1] - y);
	int c = (X[2] - x) * (Y[0] - Y[2]) - (X[0] - X[2]) * (Y[0] - y);

	if ((a >= 0 && b >= 0 && c >= 0) || (a <= 0 && b <= 0 && c <= 0))
	{
		printf("\nTrue");
	}
	else printf("\nFalse");
	_getch();
	return 0;
}