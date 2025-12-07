#include <stdio.h>
#include <string.h>
int main() {
    char str[80];
    printf("输入字符串：");
    scanf("%s", str);
    int k=strlen(str), n=strlen(str), flag=1;
    printf("k=%d\n", k);
    for(int i=0; i<n; i++){
        if(str[i] != str[k-1]){
            flag=0;
            break;
        }
        k--;
        if(i>=k) break;
    }
    if(flag==1) printf("回文字符串");
    else printf("不是回文字符串");
    return 0;
}