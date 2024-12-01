#include <stdio.h>

int main() {
    int arr[100];
    int currentLength = 0;
    int choice;

    do {
        // Hiển thị menu
        printf("\nMENU\n");
        printf("1. Nhập số phần tử và giá trị các phần tử\n");
        printf("2. In ra giá trị các phần tử\n");
        printf("3. In ra giá trị các phần tử chẵn và tính tổng\n");
        printf("4. In ra giá trị lớn nhất và nhỏ nhất trong mảng\n");
        printf("5. In ra các phần tử là số nguyên tố trong mảng và tính tổng\n");
        printf("6. Nhập vào một số và thống kê trong mảng\n");
        printf("7. Thêm một phần tử vào vị trí chỉ định\n");
        printf("8. Thoát\n");
        printf("Lựa chọn của bạn: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Nhập số phần tử của mảng (tối đa %d): ", 100);
            scanf("%d", &currentLength);

            if (currentLength <= 0 || currentLength > 100) {
                printf("Số phần tử không hợp lệ.\n");
                currentLength = 0;
            } else {
                printf("Nhập các phần tử:\n");
                for (int i = 0; i < currentLength; i++) {
                    printf("Phần tử [%d]: ", i);
                    scanf("%d", &arr[i]);
                }
            }
        } else if (choice == 2) {
            if (currentLength == 0) {
                printf("Mảng trống.\n");
            } else {
                printf("Các phần tử trong mảng:\n");
                for (int i = 0; i < currentLength; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
            }
        } else if (choice == 3) {
            if (currentLength == 0) {
                printf("Mảng trống.\n");
            } else {
                int sumEven = 0;
                printf("Các phần tử chẵn trong mảng:\n");
                for (int i = 0; i < currentLength; i++) {
                    if (arr[i] % 2 == 0) {
                        printf("%d ", arr[i]);
                        sumEven += arr[i];
                    }
                }
                printf("\nTổng các phần tử chẵn: %d\n", sumEven);
            }
        } else if (choice == 4) {
            if (currentLength == 0) {
                printf("Mảng trống.\n");
            } else {
                int max = arr[0], min = arr[0];
                for (int i = 1; i < currentLength; i++) {
                    if (arr[i] > max) max = arr[i];
                    if (arr[i] < min) min = arr[i];
                }
                printf("Giá trị lớn nhất: %d\n", max);
                printf("Giá trị nhỏ nhất: %d\n", min);
            }
        } else if (choice == 5) {
            if (currentLength == 0) {
                printf("Mảng trống.\n");
            } else {
                int sumPrime = 0;
                printf("Các phần tử là số nguyên tố:\n");
                for (int i = 0; i < currentLength; i++) {
                    int isPrime = 1; // gán =1 là số nguyên tố
                    if (arr[i] <= 1) isPrime = 0;
                    for (int j = 2; j * j <= arr[i]; j++) {
                        if (arr[i] % j == 0) {
                            isPrime = 0;// gán =0 không phải số nguyên tố
                            break;
                        }
                    }
                    if (isPrime) {
                        printf("%d ", arr[i]);
                        sumPrime += arr[i];
                    }
                }
                printf("\nTổng các số nguyên tố: %d\n", sumPrime);
            }
        } else if (choice == 6) {
            if (currentLength == 0) {
                printf("Mảng trống.\n");
            } else {
                int num, count = 0;
                printf("Nhập một số: ");
                scanf("%d", &num);

                for (int i = 0; i < currentLength; i++) {
                    if (arr[i] == num) count++;
                }
                printf("Số lần xuất hiện của %d trong mảng: %d\n", num, count);
            }
        } else if (choice == 7) {
            if (currentLength >= 100) {
                printf("Mảng đã đầy, không thể thêm phần tử.\n");
            } else {
                int value, position;
                printf("Nhập giá trị cần thêm: ");
                scanf("%d", &value);
                printf("Nhập vị trí cần thêm (0 đến %d): ", currentLength);
                scanf("%d", &position);

                if (position < 0 || position > currentLength) {
                    printf("Vị trí không hợp lệ.\n");
                } else {
                    for (int i = currentLength; i > position; i--) {
                        arr[i] = arr[i - 1];
                    }
                    arr[position] = value;
                    currentLength++;
                    printf("Phần tử đã được thêm thành công.\n");
                }
            }
        } else if (choice == 8) {
            printf("Thoát chương trình.\n");
        } else {
            printf("Lựa chọn không hợp lệ. Vui lòng thử lại.\n");
        }
    } while (choice != 8);

    return 0;
}
