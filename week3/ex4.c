#include <stdio.h>

void qsort(int *arr, int l, int r){
    int pivot = arr[l], f=r, s=l, m=-1;
    l++;
    while(r>l){
        while(pivot>arr[l]&&l<r){
            l++;
        }
        while(pivot<arr[r]&&r>l){
            r--;
        }
        if(r>l){
            int temp = arr[l];
            arr[l]=arr[r];
            arr[r]=temp;
            r--;
            l++;
        }
    }
    for(int i=s; i<f; i++){
        if(arr[i+1]>pivot){
            int temp = arr[s];
            arr[s]=arr[i];
            arr[i]=temp;
            m=i;
            break;
        }
    }
    if(m==-1){
        m=f;
        int temp = arr[s];
        arr[s]=arr[m];
        arr[m]=temp;
    }
    if(s<m-1)
        qsort(arr, s, m-1);
    if(f>m+1)
        qsort(arr, m+1, f);

}

int main()
{
    int n=12;
    int arr[]={1, 5, 6, 3, -1, 52, 235, 1, 15, -64, 1, 0};
    qsort(arr, 0, n-1);
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
