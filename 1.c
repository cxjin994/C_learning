#include <stdio.h>
int main() {
    int a, count=0;
    printf("输入数组长度");
    scanf("%d", &a);
    int x;
    printf("输入要查找的数字");
    scanf("%d", &x);
    int arr[a];
    for(int i=0;i<a;i++){
        scanf("%d", &arr[i]);
        if(arr[i]==x) {
            
            printf("下标为%d\n", i);
            count++;
        }
    }
    if(count==0) printf("Not Found");
    printf("\n");
    return 0;
}