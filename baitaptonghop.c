#include <stdio.h>


int main() {
    int arr[100]; 
    int currentLength = 0; 
    int choice;

    do {
        printf("\nMENU\n");
        printf("1. Nhập vào mảng\n");
        printf("2. Hiển thị mảng\n");
        printf("3. Thêm phần tử\n");
        printf("4. Sửa phần tử\n");
        printf("5. Xóa phần tử\n");
        printf("6. Thoát\n");
        printf("Lựa chọn của bạn: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Nhập số phần tử của mảng (tối đa 100): ");
            scanf("%d", &currentLength);

            if (currentLength <= 0 || currentLength > 100) {
                printf("Số phần tử không hợp lệ.\n");
                currentLength = 0;
            } else {
                printf("Nhập các phần tử của mảng:\n");
                for (int i = 0; i < currentLength; i++) {
                    printf("Phần tử thứ [%d]: ", i+1);
                    scanf("%d", &arr[i]);
                }
            }
        } else if (choice == 2) {
            if (currentLength == 0) {
                printf("Mảng trống.\n");
            } else {
                printf("Mảng hiện tại:\n");
                for (int i = 0; i < currentLength; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
            }
        } else if (choice == 3) {
            if (currentLength >= 100) {
                printf("Mảng đã đầy, không thể thêm phần tử.\n");
            } else {
                int value, position;
                printf("Nhập giá trị cần thêm: ");
                scanf("%d", &value);
                printf("Nhập vị trí muốn thêm (từ 0 đến %d): ", currentLength);
                scanf("%d", &position);

                if (position < 0 || position > currentLength) {
                    printf("Vị trí không hợp lệ.\n");
                } else {
                    for (int i = currentLength; i > position; i--) {
                        arr[i] = arr[i - 1];
                    }
                    arr[position] = value;
                    currentLength++;
                    printf("Đã thêm phần tử thành công.\n");
                }
            }
        } else if (choice == 4) {
            if (currentLength == 0) {
                printf("Mảng trống, không thể sửa phần tử.\n");
            } else {
                int position, value;
                printf("Nhập vị trí cần sửa (từ 1 đến %d): ", currentLength);
                scanf("%d", &position);
                if (position < 0 || position > currentLength) {
                    printf("Vị trí không hợp lệ.\n");
                } else {
                    printf("Nhập giá trị mới: ");
                    scanf("%d", &value);
                    arr[position-1] = value;
                    printf("Đã sửa phần tử thành công.\n");
                }
            }
        } else if (choice == 5) {
            if (currentLength == 0) {
                printf("Mảng trống, không thể xóa phần tử.\n");
            } else {
                int position;
                printf("Nhập vị trí cần xóa (từ 1 đến %d): ", currentLength );
                scanf("%d", &position);

                if (position < 0 || position > currentLength) {
                    printf("Vị trí không hợp lệ.\n");
                } else {
                    for (int i = position-1; i <= currentLength ; i++) {
                        arr[i] = arr[i + 1];
                    }
                    currentLength--;
                    printf("Đã xóa phần tử thành công.\n");
                }
            }
        } else if (choice == 6) {
            printf("Thoát chương trình.\n");
        } else {
            printf("Lựa chọn không hợp lệ. Vui lòng chọn lại.\n");
        }
    } while (choice != 6);

    return 0;
}
