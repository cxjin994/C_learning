#include<stdlib.h>
#include<stdio.h>
#include<time.h>

#define MAX_LEVEL 4
#define P_FACTOR 0.5

//节点结构体                            
typedef struct SkipNode{
    int value;
    struct SkipNode** forward;
    int level;
}SkipNode;

//跳跃表结构体
typedef struct SkipList{
    int max_level;
    int current_level;
    float probability;
    SkipNode* header;
    int size;
}SkipList;

//创建节点
SkipNode* creat_skipnode(int value,int level){
    SkipNode* node=(SkipNode*)malloc(sizeof(SkipNode));
    
    if(node == NULL){
    	printf("node内存分配失败");
	return NULL;
    }
    
    node->value=value;
    node->forward=(SkipNode**)malloc(level*sizeof(SkipNode*));

    if(node->forward == NULL){
    	printf("forward内存分配失败");
	free(node);
	return NULL;
    }

    for(int i=0; i<level; i++){
    	node->forward[i]=NULL;
    }
    node->level=level;
    return node;
}

//创建跳跃表
SkipList* creat_skiplist(int max_level,float p_factor){
    SkipList* list=(SkipList*)malloc(sizeof(SkipList));
    
    if(list == NULL){
    	printf("list内存分配失败");
	return NULL;
    }
    
    list->max_level=max_level;
    list->current_level=0;
    list->probability=p_factor;
    list->header=creat_skipnode(-1,max_level);
    list->size=0;
    return list;
}

//生成随机层数
int random_level(SkipList* list){
    int level=1;

    while((rand()/(RAND_MAX+1.0)) < list->probability && level <= list->max_level){
    	level++;
    }
    return level;
}

//查找节点
SkipNode* search(SkipList* list,int value){
    if(list == NULL){
    	printf("没有这个跳跃表");
    }

    SkipNode* current=list->header;
    SkipNode* temp;
    //SkipNode* resault=NULL;
    int i=list->max_level;
    
    while(current->forward[0] != NULL){
    	temp=current;
	current=current->forward[i];
	if(current->value > value){
	    if(i>0){
	    	i--;
		current=temp;
	    }else{
	    	break;
	    }
	}
    }
    return temp;
}

//插入节点
void insert(SkipList* list,int value){
    SkipNode* node=search(list,value);
    SkipNode* current=list->header;

    if(node->value == value){
    	printf("该节点已存在");
	return;
    }

    int num=random_level(list);
    SkipNode* newnode=creat_skipnode(value,num);
    int i=num-1;
    SkipNode* temp;
    while(i>=0){
	temp=current;
    	current=current->forward[i];
	
	if(current->value > value){
	    temp->forward[i]=newnode;
	    newnode->forward[i]=current;
	    current=temp;
	    i--;
	}
    }
}

//删除节点
void delete(SkipList* list,int value){
    SkipNode* node=search(list,value);
    
    if(node->value != value){
    	printf("没有这个节点");
	return;
    }
    
    SkipNode* current=list->header;
    SkipNode* temp;    
    int i=node->level-1;
    
    while(i>=0){
    	temp=current;
	current=current->forward[i];

	if(current->value==value){
	    temp->forward[i]=current->forward[i];
	    current=temp;
	    i--;
	}
    }

    free(node);
}
