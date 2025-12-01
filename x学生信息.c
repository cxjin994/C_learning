#include<stdio.h>
#include<string.h>

typedef struct student{
  char name[100];
  int age;
}stu;

void input(stu* p);

int main()
{
    stu st1 = {"zhansan", 1};
    stu st2 = {"lisi", 2};
    stu st3 = {"wangwu", 3};
    
    stu Arr[3]={st1, st2, st3};
    for(int i=1; i<=3; i++){
    	struct student temp =Arr[i-1];
	printf("name:%s %d\n", temp.name, temp.age);
	
    }

    printf("输入想要修改的学生\n");
    int n;
    scanf("%d", &n);
    
    input(&Arr[n-1]);
    return 0;
}

void input(stu* p){
	
	printf("初始name:%s,age:%d\n", (*p).name, (*p).age);
	printf("输入新的name\n");
	scanf("%s", (*p).name);
	printf("输入新的age\n");
	scanf("%d", &((*p).age));
	printf("新的name:%s,age:%d\n", (*p).name, (*p).age);
}
