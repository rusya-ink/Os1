#include <stdio.h>

void bubble_sort(int *arr, size_t arr_size){
    for(int i=0; i<arr_size; i++){
        int c=0;
        for(int j=1; j<arr_size-i; j++){
            if(arr[j-1]<arr[j]){
                int temp=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=temp;
                c++;
            }
        }
        if(c==0){
            return;
        }
    }
}

int main()
{
    int n=11;
    int arr[11]={0, 3, 1, 4, 16, 7, 8, 9, -1, -2, -3};
    bubble_sort(arr, n);
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}