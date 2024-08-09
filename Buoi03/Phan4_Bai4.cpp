#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<malloc.h>
void TaoMaTranVuong(int a[][100], int& n) {
	printf("Nhap cap cua ma tran vuong:");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {
			a[i][j] = rand() % 100;
		}
	}
}
void XuatMTVuong(int a[][100], int n) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
}
void SapXepCheoPhu(int a[][100], int n) {
	int b[100];
	for (int i = 0; i < n; i++)
	{
		b[i] = a[i][n - 1 - i];
	}
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++) {
			if (b[i] > b[j]) {
				int temp = b[i];
				b[i] = b[j];
				b[j] = temp;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		a[i][n - 1 - i] = b[i];
	}
}
void SapXepDongTang(int a[], int n) {
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j]) {
				int temp = a[i];
				a[i] = a[j];
				a[i] = temp;
			}
		}
	}
}
void SapXepDongGiam(int a[], int n) {
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++) {
			if (a[i] < a[j]) {
				int temp = a[i];
				a[i] = a[j];
				a[i] = temp;
			}
		}
	}
}
void SapXepMT(int a[][100], int n) {
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0) SapXepDongGiam(a[i], n); else SapXepDongTang(a[i], n);
	}
}
int main() {
	int a[100][100], n;
	TaoMaTranVuong(a, n);
	XuatMTVuong(a, n);
	SapXepCheoPhu(a, n);
	printf("\nMa tran da sap xep duong cheo phu\n");
	XuatMTVuong(a, n);
	printf("\nMa tran da sap xep dong le tang dong chan giam\n");
	SapXepMT(a, n);
	XuatMTVuong(a, n);
}