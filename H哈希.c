#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int key;
    int value;
    struct Node* next;
}Node;

typedef struct{
    Node** buckets;
    int size;
    int count;
}HashTable;

//创建链表节点
Node* creat_N(int key,int value){
    Node* newNode=(Node*)malloc(sizeof(Node));
    if(!newNode){
    	printf("创建节点空间不足\n");
	return NULL;
    }

    newNode->key=key;
    newNode->value=value;
    newNode->next=NULL;

    return newNode;
}

//插入链表
Node* insert_N(Node* list,int key, int value){
    Node* newNode=creat_N(key,value);

    newNode->next=list;
    return newNode;
}

//初始化哈希表
HashTable* creat_HT(int size){
    if(size < 0){
    	printf("size错误！\n");
	return NULL;
    }

    HashTable* HT=(HashTable*)malloc(sizeof(HashTable));
    HT->buckets=(Node**)malloc(size*sizeof(Node*));

    if(!HT || !HT->buckets){ 
	printf("空间不足\n");
    }else{
    	for(int i=0; i<size; i++){
	    HT->buckets[i]=NULL;
	}
	HT->size=size;
	HT->count=0;
    }

    return HT;
}

//哈希函数
unsigned int hash(int key,int size){
    return key%size;
}

//插入数据
void insert_HT(HashTable* ht,int key,int value){
    Node* tempNode=ht->buckets[hash(key,ht->size)];

    tempNode=insert_N(tempNode,key,value);
}

//查找数据
int find(HashTable* ht,int key){
    Node* temp=ht->buckets[hash(key,ht->size)];
    while(temp){
    	if(temp->key == key) return temp->value;
	temp=temp->next;
    }
    return -1;
}

//删除数据
void delete(HashTable* ht,int key){
    Node* temp=ht->buckets[hash(key,ht->size)];
    if(temp->key == key){
    	ht->buckets[hash(key,ht->size)]=temp->next;
	printf("已删除key=%d value=%d\n",temp->key,temp->value);
	free(temp);
    }

    Node* current=temp;
    temp=temp->next;
    while(temp){
    	if(temp->key == key){
	    current->next=temp->next;
	    printf("已删除key=%d value=%d\n",temp->key,temp->value);
	    free(temp);
	}
	temp=temp->next;
    }
}

//释放所有内存
void free_HT(HashTable* ht){
    for(int i=0; i < ht->size; i++){
    	while(ht->buckets[i]){
	    Node* temp=ht->buckets[i];
	    ht->buckets[i]=temp->next;
	    free(temp);
	}
    }
}
