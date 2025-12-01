#include<stdio.h>
#include<string.h>
int main()
{
    //定义账号密码
    //char account []="cxj";
    char password []="123456";

    //输入账号密码
    //char account1[100];
    char password1[100];
    //scanf("%s", account1);
    printf("输入密码");
    scanf("%s", password1);
    printf("%s\n", password1);
    int a;
    
    //判断是否正确
    int i=0;
    do{
     printf ("密码:%s\n", password1);
     printf("i=%d\n",i);
     a= strcmp( password, password1);
     printf("a=%d\n",a);
     if(a==0){
       break;
     }else{
       printf("error,再次输入");
       scanf("%s", password1);
       printf("%s\n", password1);
     }    
     printf("i=%d, password1=%s\n", i, password1);
     i++;	    
    }while(i<3);
    
    printf ("密码:%s\n", password1);
    printf("i=%d\n",i);


    if(a==0){
      printf("ture\n");
    }else{
      printf("error\n");
    }
	    
    return 0;
}
