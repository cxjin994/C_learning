#include<stdio.h>

void swap(int* a, int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
//分区函数
int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i=low-1;
    for(int k=low; k<=high; k++){
    	if(arr[k]<=pivot){
	    i++;
	    swap(&arr[i], &arr[k]);
	}
    }
    swap(&arr[i+1], &arr[high]);
    return i+1;
}
//快速排序
void quickSort(int arr[], int low, int high){
    if(low<high){
        int pi=partition(arr, low, high);

	quickSort(arr, low, pi-1);
	quickSort(arr, pi+1, high);
    }
}
