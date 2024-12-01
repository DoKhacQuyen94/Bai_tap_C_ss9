#include <stdio.h>

int main() {
    int arr[100][100];
    int rows = 0, cols = 0;
    int choice;

    do {
        printf("\nMENU\n");
        printf("1. Nhập kích cỡ và giá trị các phần tử của mảng\n");
        printf("2. In giá trị các phần tử của mảng theo ma trận\n");
        printf("3. In giá trị các phần tử là lẻ và tính tổng\n");
        printf("4. In ra các phần tử nằm trên đường biên và tính tích\n");
        printf("5. In ra các phần tử nằm trên đường chéo chính\n");
        printf("6. In ra các phần tử nằm trên đường chéo phụ\n");
        printf("7. In ra dòng có tổng giá trị các phần tử là lớn nhất\n");
        printf("8. Thoát\n");
        printf("Lựa chọn của bạn: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Nhập số hàng: ");
            scanf("%d", &rows);
            printf("Nhập số cột: ");
            scanf("%d", &cols);

            if (rows <= 0 || cols <= 0 || rows > 100 || cols > 100) {
                printf("Kích cỡ không hợp lệ.\n");
                rows = cols = 0;
            } else {
                printf("Nhập các phần tử của mảng:\n");
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        printf("arr[%d][%d] = ", i, j);
                        scanf("%d", &arr[i][j]);
                    }
                }
            }
        } else if (choice == 2) {
            if (rows == 0 || cols == 0) {
                printf("Mảng chưa được khởi tạo.\n");
            } else {
                printf("Ma trận:\n");
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        printf("%3d ", arr[i][j]);
                    }
                    printf("\n");
                }
            }
        } else if (choice == 3) {
            if (rows == 0 || cols == 0) {
                printf("Mảng chưa được khởi tạo.\n");
            } else {
                int sum = 0;
                printf("Các phần tử lẻ trong mảng:\n");
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        if (arr[i][j] % 2 != 0) {
                            printf("%d ", arr[i][j]);
                            sum += arr[i][j];
                        }
                    }
                }
                printf("\nTổng các phần tử lẻ: %d\n", sum);
            }
        } else if (choice == 4) {
            if (rows == 0 || cols == 0) {
                printf("Mảng chưa được khởi tạo.\n");
            } else {
                int product = 1;
                printf("Các phần tử trên đường biên:\n");
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1) {
                            printf("%d ", arr[i][j]);
                            product *= arr[i][j];
                        }
                    }
                }
                printf("\nTích các phần tử trên đường biên: %d\n", product);
            }
        } else if (choice == 5) {
            if (rows == 0 || cols == 0 || rows != cols) {
                printf("Mảng không phải ma trận vuông.\n");
            } else {
                printf("Các phần tử trên đường chéo chính:\n");
                for (int i = 0; i < rows; i++) {
                    printf("%2d ", arr[i][i]);
                }
                printf("\n");
            }
        } else if (choice == 6) {
            if (rows == 0 || cols == 0 || rows != cols) {
                printf("Mảng không phải ma trận vuông.\n");
            } else {
                printf("Các phần tử trên đường chéo phụ:\n");
                for (int i = 0; i < rows; i++) {
                    printf("%d ", arr[i][cols - i - 1]);
                }
                printf("\n");
            }
        } else if (choice == 7) {
            if (rows == 0 || cols == 0) {
                printf("Mảng chưa được khởi tạo.\n");
            } else {
                int maxSum = 0, maxRow = 0;
                for (int i = 0; i < rows; i++) {
                    int sum = 0;
                    for (int j = 0; j < cols; j++) {
                        sum += arr[i][j];
                    }
                    if (sum > maxSum) {
                        maxSum = sum;
                        maxRow = i;
                    }
                }
                printf("Dòng có tổng lớn nhất là dòng %d với tổng = %d\n", maxRow, maxSum);
                printf("Các phần tử của dòng đó: ");
                for (int j = 0; j < cols; j++) {
                    printf("%d ", arr[maxRow][j]);
                }
                printf("\n");
            }
        } else if (choice == 8) {
            printf("Thoát chương trình.\n");
        } else {
            printf("Lựa chọn không hợp lệ. Vui lòng thử lại.\n");
        }
    } while (choice != 8);

    return 0;
}
