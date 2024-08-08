#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#define MAXSIZE 100

struct HonSo
{
	int phanNguyen, tuSo, mauSo;
};

void tao_HonSo(HonSo a[], int &n)
{
	printf("Nhap so luong phan tu:");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		a[i].phanNguyen=rand()%10;
		a[i].tuSo=rand()%10;
		int t=rand()%10;
		if (t!=0)
		{
			a[i].mauSo=t;
		}
		else t=1;
	}
}

void xuat_HonSo(HonSo a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("Hon so thu %d: %d va %d/%d\n", i+1,a[i].phanNguyen, a[i].tuSo, a[i].mauSo);
	}
}

int SoSanh_HonSo(HonSo a, HonSo b)
{
	if (a.phanNguyen>b.phanNguyen)
	{
		return 1;
	}
	else if (a.phanNguyen<b.phanNguyen)
	{
		return -1;
	}
	else if (a.phanNguyen==b.phanNguyen)
	{
		int tong1 = (float) a.tuSo / a.mauSo;
		int tong2 = (float) b.tuSo / b.mauSo;
		if (tong1>tong2)
		{
			return 1;
		}
		else if (tong1<tong2)
		{
			return -1;
		}
		else return 0;
	}
}

void swap(HonSo &a, HonSo &b)
{
	HonSo temp = a;
	a = b;
	b = temp;
}

int tim_Kiem_LinearSearch(HonSo a[], int n, HonSo x)
{
	for (int i = 0; i < n; i++)
	{
		if (SoSanh_HonSo(x,a[i])==0)
		{
			return i;
		}
	}
	return -1;
}

void SapXep(HonSo a[], int n)
{
	int left=0;
	int right=n-1;
	while (left<right)
	{
		while (a[left].phanNguyen%2==0 && left<right)
		{
			left++;
		}

		while (a[right].phanNguyen%2!=0 && left<right)
		{
			right--;
		}

		if (left < right)
		{
			swap(a[left],a[right]);
			left++;
			right--;
		}
	}
}

void Interchange_Sort(HonSo a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (SoSanh_HonSo(a[i],a[j])==1)
			{
				swap(a[i], a[j]);
			}
		}
	}
}

int tim_Kiem_BinarySearch(HonSo a[], int n, HonSo x)
{
	int left = 0, right = n - 1, middle;
	while (left <= right)
	{
		middle = (left + right) / 2;
		if (SoSanh_HonSo(a[middle],x)==0)
		{
			return middle;
		}
		else if (SoSanh_HonSo(a[middle],x)==1)
		{
			right = middle - 1;
		}
		else if (SoSanh_HonSo(a[middle],x)==-1)
		{
			left = middle + 1;
		}
	}
	return -1;
}

void xoa_PT(HonSo a[], int &n, int vitri)
{
	for (int i = vitri; i < n; i++)
	{
		a[i]=a[i+1];
	}
	n--;
}


int main()
{
	HonSo a[MAXSIZE];
	int n;
	tao_HonSo(a,n);
	xuat_HonSo(a,n);
	printf("\n----------------------------------\n");
	printf("Ta co hon so: %d va %d/%d\n", a[1].phanNguyen, a[1].tuSo, a[1].mauSo);
	printf("Tim kiem hon so tren trong mang\n");
	if (tim_Kiem_LinearSearch(a,n,a[1])!=-1)
	{
		printf("=>>Da tim thay!!!");
	}
	else printf("=>>Khong tim thay!!!");
	printf("\n----------------------------------\n");
	printf("PHAN NGUYEN CHAN DAU MANG - PHAN NGUYEN LE CUOI MANG\n");
	SapXep(a,n);
	xuat_HonSo(a,n);
	printf("\n----------------------------------\n");
	printf("Ta co hon so: %d va %d/%d\n", a[3].phanNguyen, a[3].tuSo, a[3].mauSo);
	printf("Tim kiem hon so tren trong mang\n");
	Interchange_Sort(a,n);
	xuat_HonSo(a,n);
	if (tim_Kiem_BinarySearch(a,n,a[3])!=-1)
	{
		printf("=>>Da tim thay!!!");
	}
	else printf("=>>Khong tim thay!!!");
	printf("\n----------------------------------\n");
	printf("\nXOA PHAN TU\n");
	int vitri;
	printf("Nhap vi tri:");
	scanf("%d", &vitri);
	xoa_PT(a,n,vitri-1);
	xuat_HonSo(a,n);

	getch();
	return 0;
}