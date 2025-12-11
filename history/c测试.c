#include<stdio.h>
int main(){
    int m,n,count=0;
	int i,gewei,shiwei,baiwei;
	scanf("%d,%d",&m,&n);
	for(i=m ; i<=n; i++){
		gewei=i%10;
		shiwei=(i%100)/10;
		baiwei=i/100;
		//printf("%d %d %d \n",baiwei,shiwei,gewei);
		//printf("%d\n",i);
		if(gewei*gewei*gewei+shiwei*shiwei*shiwei+baiwei*baiwei*baiwei==i) count++;
	}
	printf("%d",count);
    return 0;
}
