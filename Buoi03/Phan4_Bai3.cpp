#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
void TaoM2C(int a[][100], int& n, int& m) {
	printf("Moi ban nhap so dong:");
	scanf("%d", &n);
	printf("Moi ban nhap so cot:");
	scanf("%d", &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) {
			a[i][j] = rand() % 100;
		}
	}
}
void XuatM2C(int a[][100], int n, int m) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) {
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
}
void XuatCotLe(int a[][100], int n, int m) {
	for (int i = 0; i < m; i++)
	{
		int kt = 1;
		for (int j = 0; j < n; j++)
		{
			if (a[j][i] % 2 == 0) { kt = 0; break; }
		}
		if (kt == 1) {
			printf("Cot %d chi chua so le:", i + 1);
			for (int k = 0; k < n; k++)
			{
				printf("%d\t", a[k][i]);
			}
			printf("\n");
		}
	}
}
void TimMaxTrenBien(int a[][100], int n, int m) {
	int max = a[0][0];
	for (int i = 0; i < m; i++)
	{
		if (a[0][i] > max) max = a[0][i];
		if (a[n - 1][i] > max) max = a[n - 1][i];
	}
	for (int i = 1; i < n-1; i++)
	{
		if (a[i][0] > max) max = a[i][0];
		if (a[i][m - 1] > max) max = a[i][m - 1];
	}
	printf("\nMax tren bien la:%d", max);
}
int main() {
	int a[100][100];
	int n, m;
	TaoM2C(a, n, m);
	XuatM2C(a, n, m);
	XuatCotLe(a, n, m);
	TimMaxTrenBien(a, n, m);
}