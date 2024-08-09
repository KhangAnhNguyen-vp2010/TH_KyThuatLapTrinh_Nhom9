#include<stdio.h>
#include<conio.h>
int to_hop_chap_k_cua_n(int n, int k) {
    if (k == 0 || k == n) {
        return 1;
    }
    if (k > n) {
        return 0;
    }
    return to_hop_chap_k_cua_n(n - 1, k - 1) + to_hop_chap_k_cua_n(n - 1, k);
}

int main() {
    int n = 7; 
    int k = 5;
    int ket_qua = to_hop_chap_k_cua_n(n, k);
    printf("To hop chap %d cua %d phan tu là: %d\n", k, n, ket_qua);
}
