#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#define MAXSIZE 100

int kiemTra_SNT(int a)
{
	if (a<2)
	{
		return 1;
	}
	int dem=0;
	for (int i = 2; i <= a; i++)
	{
		if (a%i==0)
		{
			dem++;
		}
	}

	if (dem>1)
	{
		return 1;
	}
	else return 0;
}

void tao_Mang(int a[], int &n, int input)
{
	n=0;
	bool flag=false;
	for (int i = 1; i < input; i++)
	{
		if (kiemTra_SNT(i)==0)
		{
			a[n]=i;
			n++;
			flag=true;
		}
	}

	if (flag==false)
	{
		printf("Khong co so nguyen to nao nho hon n \n");
	}
}

void xuat_Mang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}

int tong_PT_Le(int a[], int n)
{
	int tong=0;
	for (int i = 0; i < n; i++)
	{
		if (a[i]%2!=0)
		{
			tong+=a[i];
		}
	}
	return tong;
}


int main()
{
	int a[MAXSIZE];
	int n;
	int input;
	printf("Nhap n:");
	scanf("%d", &input);
	tao_Mang(a,n,input);
	xuat_Mang(a,n);
	printf("\n-------------------------------\n");
	printf("Tong cac phan tu le la:%d", tong_PT_Le(a,n));

	getch();
	return 0;
}