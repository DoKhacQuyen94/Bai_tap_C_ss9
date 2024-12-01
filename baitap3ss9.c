#include <stdio.h>


int main() {
    int arr[100]; 
    int currentLength = 0; 
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
    printf("Mảng hiện tại:\n");
    for (int i = 0; i < currentLength; i++) {
        printf("%d ", arr[i]);
    }
    int position;
    printf("\nNhập vị trí cần xóa (từ 1 đến %d): ", currentLength );
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
    for (int i = 0; i < currentLength; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}