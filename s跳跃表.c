#include<stdlib.h>
#include<stdio.h>
#include<time.h>

#define MAX_LEVEL 4
#define P_FACTOR 0.5
                                          
typedef struct SkipNode{
    int value;
    struct SkipNode** forward
    int level;
}SkipNode;

typedef struct SkipList{
    int max_level;
    int current_level;
    SjipNode* header;
    int size;
}SkipList;

SkipNode* creat_skipnode(int value,int level){
    SkipNode* skipnode=(SkipNode*)malloce(SkipNode);
    
    if(skipnode == NULL){
    	printf("skipnode内存分配失败");
	return NULL;
    }


}

SkipList* creat_skiplist(int MAX_LEVEL,float P_FACTOR){
    SkipList* skiplist=(SkipList*)malloc(sizeof(SkipList));
    
    if(skiplist == NULL){
    	printf("skiplist内存分配失败");
	return NULL;
    }
    
    skiplist->max_level=MAX_LEVEL;
    skiplist->current_level=MAX_LEVEL;

    skiplist->size=0;
    return skiplist;
}
