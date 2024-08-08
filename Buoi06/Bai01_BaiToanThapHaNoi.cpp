#include <stdio.h>
#include <conio.h>

void thapHaNoi(int n, char cotNguon, char cotTrungGian, char cotDich) {
	if (n == 1) {
		printf("Chuyen dia 1 tu cot %c --> %c\n", cotNguon, cotDich);
		return;
	}
	thapHaNoi(n - 1, cotNguon, cotDich, cotTrungGian);
	printf("Chuyen dia %d tu cot %c --> %c\n", n, cotNguon, cotDich);
	thapHaNoi(n - 1, cotTrungGian, cotNguon, cotDich);
}

int main() {
	int soLuongDia;
	printf("Nhap so luong dia: ");
	scanf("%d", &soLuongDia);

	thapHaNoi(soLuongDia, 'A', 'B', 'C');
	getch();
	return 0;
}