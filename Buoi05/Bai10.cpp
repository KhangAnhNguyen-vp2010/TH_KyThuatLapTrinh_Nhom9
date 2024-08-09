#include <stdio.h>
#include<conio.h>
int chia_phan_thuong(int m, int n) {
    if (n == 1) {
        return 1; 
    }
    if (m < 2 * n) {
        return 0; 
    }
    int so_cach = 0;
    for (int k = n - 1; k <= m - (n - 1); k++) {
        so_cach += chia_phan_thuong(m - k, n - 1);
    }
    return so_cach;
}

int main() {
    int m = 10; 
    int n = 3;  
    int ket_qua = chia_phan_thuong(m, n);
    printf("So cach chia %d phan thuong cho %d hoc sinh la: %d\n", m, n, ket_qua);
}
