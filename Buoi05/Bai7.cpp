#include<stdio.h>
#include<conio.h>
double calculate_amount(double tiengoc, double tienlai, int years) {
    if (years == 0) {
        return tiengoc;
    }
    return calculate_amount(tiengoc, tienlai, years - 1) * (1 + tienlai / 100);
}

int main() {
    double tiengoc = 5000000;
    double tienlai = 8;
    int years = 3;

    double Tong = calculate_amount(tiengoc, tienlai, years);
    printf("So tien sau %d nam se là: %.2f trieu dong\n", years, Tong);

    return 0;
}
