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
}
