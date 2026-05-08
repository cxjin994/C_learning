#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int** arc;
    int directed;  //1:有向, 0:无向
    int vertex_num; //顶点个数
    int edge_num;  //边个数
}Mat_Grph;

void initGraph(Mat_Grph* G){
    printf("有向图/无向图？ 1/0");
    scanf("%d",&G->directed);
    printf("输入顶点个数 vertex_num=");
    scanf("%d",&G->vertex_num);
    
    G->arc=(int**)malloc(G->vertex_num*sizeof(int*));

    for(int i=0; i < G->vertex_num; i++){
    	(G->arc)[i]=(int*)calloc(G->vertex_num,sizeof(int)); //calloc(个数,大小)   分配空间并初始化为0
    }

    int num=0;
    while(1){
	int a, b;
    	printf("输入想连接的顶点(输入 -1 退出)\n");
	scanf("%d %d",&a,&b);
	if(a == -1 || b == -1) break;
	printf("输入该边的权值 若无权则赋值1\n");
	int temp=G->arc[a][b];
	scanf("%d",&G->arc[a][b]);
	if(G->directed == 0){
	    G->arc[b][a]=G->arc[a][b];
	}
	
	if(temp == 0) num++;
	
    }

    G->edge_num=num;
}

int main(){
    Mat_Grph* MG=(Mat_Grph*)malloc(sizeof(Mat_Grph));
    initGraph(MG);
    for(int i=0; i< MG->vertex_num; i++){
    	for(int k=0; k< MG->vertex_num; k++){
	    printf("%d ",(MG->arc)[i][k]);
	}
	printf("\n");
    }
    free(MG);
    return 0;
}
