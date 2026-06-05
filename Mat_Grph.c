#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int **arc;
    int directed;   // 1:有向, 0:无向
    int vertex_num; // 顶点个数
    int edge_num;   // 边个数
} Mat_Grph;

typedef struct  Node{
    int data;
    struct Node* next;
}Node;

typedef struct{
    Node* head;
    int size;
    Node* end;
}queue;

// 初始化队列
void initQueue(queue *q)
{
    q->head = NULL;
    q->size = 0;
    q->end = NULL;
}

// 创建节点
Node* createNode(int data){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//入队
void insertQueue(queue *q, int data){
    Node* newNode=createNode(data);
    if(q->head == NULL){
        q->head = newNode;
        q->end = newNode;
    }else q->end->next = newNode;
    q->end = newNode;
    (q->size)++;
}

//出队
void deleteQueue(queue *q){
    Node* temp=q->head;
    q->head=q->head->next;
    free(temp);
    (q->size)--;
}

//初始化图
void initGraph(Mat_Grph *G)
{
    printf("有向图/无向图？ 1/0");
    scanf("%d", &G->directed);
    printf("输入顶点个数 vertex_num=");
    scanf("%d", &G->vertex_num);

    G->arc = (int **)malloc(G->vertex_num * sizeof(int *));

    for (int i = 0; i < G->vertex_num; i++)
    {
        (G->arc)[i] = (int *)calloc(G->vertex_num, sizeof(int)); // calloc(个数,大小)   分配空间并初始化为0
    }

    int num = 0;
    while (1)
    {
        int a, b;
        printf("输入想连接的顶点(输入 -1 退出)\n");
        scanf("%d %d", &a, &b);
        if (a == -1 || b == -1) break;
        printf("输入该边的权值 若无权则赋值1\n");
        int temp = G->arc[a - 1][b - 1];
        scanf("%d", &G->arc[a - 1][b - 1]);
        if (G->directed == 0)
        {
            G->arc[b - 1][a - 1] = G->arc[a - 1][b - 1];
        }

        if (temp == 0)
            num++;
    }

    G->edge_num = num;
}

void DFS(Mat_Grph *G, int index, int *visited)
{
    if (index < 0 || index > G->vertex_num - 1)
        index = 0;

    if (visited[index] == 0)
        visited[index]++;
    else
        return;

    printf("当前是第%d个顶点\n", index + 1);
    for (int i = 0; i < G->vertex_num; i++)
    {
        if (G->arc[index][i] > 0)
            DFS(G, i, visited);
    }
}

void BFS(Mat_Grph *G, int index, int *visited){
    memset(visited, 0, G->vertex_num*sizeof(int));
    if (index < 0 || index > G->vertex_num - 1){
        index = 0;
    }
    queue *q = (queue *)malloc(sizeof(queue));
    initQueue(q);
    insertQueue(q, index);
    visited[index]=1;
    while(q->size > 0){
    	for(int i=0; i < G->vertex_num; i++){
	    if(G->arc[q->head->data][i] > 0){
		if(visited[i]==0){
		    insertQueue(q,i);
		    visited[i]=1;
		}
	    }
	}
	printf("%d ",q->head->data);
    printf("\n");
	deleteQueue(q);
    }    
}


int main()
{
    Mat_Grph *MG = (Mat_Grph *)malloc(sizeof(Mat_Grph));
    initGraph(MG);
    int *visited = (int *)calloc(MG->vertex_num, sizeof(int));
    DFS(MG, 0, visited);
    BFS(MG, 0, visited);
    free(MG);
    free(visited);
    return 0;
}
