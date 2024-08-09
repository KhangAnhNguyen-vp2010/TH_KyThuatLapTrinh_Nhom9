#include<stdio.h>
#include<conio.h>
int tim_kiem_nhi_phan(int arr[], int left, int right, int x) {
    if (right >= left) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x) {
            return mid;
        }
        if (arr[mid] > x) {
            return tim_kiem_nhi_phan(arr, left, mid - 1, x);
        }
        return tim_kiem_nhi_phan(arr, mid + 1, right, x);
    }
    return -1;
}

int main() {
    int arr[] = { 2, 3, 4, 10, 40 };
    int n = 5;
    int x = 10;

    int ket_qua = tim_kiem_nhi_phan(arr, 0, n - 1, x);

    if (ket_qua != -1) {
        printf("Phan tu %d duoc tim thay tai vi tri so %d\n", x, ket_qua);
    }
    else {
        printf("Phan tu %d khong ton tai trong mang\n", x);
    }
}
