// Quick Sort

#include<stdio.h>
int arr[7]= {3,5,6,2,1,89,34};
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int l, int r){
    int pivot = arr[l];
    int i = l+1;
    int j = r;
    while(i<j){
        while(arr[i]<pivot && i<=r){
            i++;
        }
            
        while(arr[j]>pivot && j>=l){
            j--;
        }
            
        
        if(i<j){
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[l], &arr[j]);
    return j;
}

void QuickSort(int arr[], int l, int r){
    if(l<r){
        int pi = partition(arr, l, r);
        QuickSort(arr, l, pi-1);
        QuickSort(arr, pi+1, r);
    }
}

void main(){
    printf("Before Applying Quick Sort:\n");
    for(int i = 0 ; i<7;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    QuickSort(arr, 0, 6);
    printf("After Applying Quick Sort:\n");
    for(int i = 0 ; i<7;i++){
        printf("%d ", arr[i]);
    }
}
