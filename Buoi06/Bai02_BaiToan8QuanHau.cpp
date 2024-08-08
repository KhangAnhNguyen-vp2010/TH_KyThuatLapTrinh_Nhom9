#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define N 8

int board[N][N];

// Hàm in bàn cờ ra màn hình
void printBoard() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j])
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
    printf("\n");
}

// Hàm kiểm tra nếu có thể đặt quân hậu tại vị trí board[row][col]
int isSafe(int row, int col) {
    int i, j;

    // Kiểm tra cột
    for (i = 0; i < row; i++)
        if (board[i][col])
            return 0;

    // Kiểm tra đường chéo trên bên trái
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return 0;

    // Kiểm tra đường chéo trên bên phải
    for (i = row, j = col; i >= 0 && j < N; i--, j++)
        if (board[i][j])
            return 0;

    return 1;
}

// Hàm giải bài toán 8 quân hậu sử dụng đệ quy và quay lui
int solveNQueens(int row) {
    if (row == N) {
        printBoard();
        return 1;
    }

    int foundSolution = 0;
    for (int col = 0; col < N; col++) {
        if (isSafe(row, col)) {
            board[row][col] = 1;
            foundSolution = solveNQueens(row + 1) || foundSolution;
            board[row][col] = 0;
        }
    }
    return foundSolution;
}

int main() {
    // Khởi tạo bàn cờ
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = 0;

    // Giải bài toán 8 quân hậu
    if (!solveNQueens(0))
        printf("Khong co loi giai nao.\n");
	getch();
    return 0;
}
