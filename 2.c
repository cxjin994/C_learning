#include <stdio.h>
int main() {
    printf("1<=m,n<=6");
    int m, n;
    scanf("%d %d", &m, &n);
    int arr[m][n];
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    int temp=arr[0][0], x=0, y=0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n-1; j++){
            if(arr[i][j]<arr[i][j+1] && arr[i][j+1]>temp){
                temp=arr[i][j+1]; 
                x=i; y=j+1;   
            }
        }
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    
    printf("max=%d, x=%d, y=%d\n", temp, x, y);
    
    return 0;
}