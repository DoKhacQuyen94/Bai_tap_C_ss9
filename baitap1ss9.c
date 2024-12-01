#include<stdio.h>
int main(){
    int array[100];
    int n,lengthCu;
    printf("Nhap so phan tu mang ");
    scanf("%d",&n);
    
    for(int i=0; i<n;i++){
        printf("nhap phan tu thu %d:",i+1);
        scanf("%d",&array[i]);
    }
    lengthCu =n;
    int position;
    int giaTri;
    printf("nhap vi tri muon them vao mang:");
    scanf("%d",&position);
    printf("nhap gia tri muon them vao: ");
    scanf("%d",&giaTri);
    for(int i=lengthCu ; i>position; i--){
        array[i]=array[i-1];
        lengthCu++;
    }
    array[position-1] = giaTri;
    printf("\nMảng sau khi thêm phần tử:\n");
    for (int i = 0; i < lengthCu; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}