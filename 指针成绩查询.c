#include<stdio.h> 
void MAXMIN(int arr[], int *max, int *min);

int main()
{
	int arr[5], *p, num=0;
	double average=0.0;
	
	//获取数据
	printf("请输入五个学生的成绩\n");
	p = arr;
	
	for(int i=0; i<5; i++)
	{	scanf("%d", p);
		num=num+*p;
		p++;
	}
	p=arr;
	
	//获取最大最小值
	int max=*p;
	int min=*p;
	MAXMIN(arr, &max, &min);
	printf("max=%d\nmin=%d\n", max, min);

    //求平均值
	average=num/5.0;
	printf("平均分为%.2f\n", average);
	
	//输出大于平均值的值
	for(int k=0; k<5; k++)
	{
		if(*p > average)
		{
		  printf("%d  ", *p);
		  p++;
		}else{
		  p++;
		
		}
	
	}
	p=arr;	
	return 0;
}






void MAXMIN(int arr[], int *max, int *min)
{
	
	for(int j=1; j<5; j++ )
	{
	    if(*max<*(arr+j)){
	      *max=*(arr+j);
	    }
	
	    if(*min>*(arr+j)){
	      *min=*(arr+j);
	    }
	}

}
