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

void free_HT(HashTable* ht);

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

//查找数据
int find(HashTable* ht,int key){
    Node* temp=ht->buckets[hash(key,ht->size)];
    while(temp){
        if(temp->key == key) return temp->value;
        temp=temp->next;
    }
    return -1;
}

//插入数据
void insert_HT(HashTable* ht,int key,int value){
    if((double)ht->count/ht->size > 0.75){
    	HashTable* newht=creat_HT(2*ht->size);
	for(int i=0; i<ht->size; i++){
	    Node* current=ht->buckets[i];
	    while(current){
	    	insert_HT(newht,current->key,current->value);
		current=current->next;
	    }
	}
	free_HT(ht);
	ht=newht;
    }
	
	
    int index=hash(key,ht->size);

    if(find(ht,key) != -1){
    	Node* temp=ht->buckets[index];
    	while(temp){
            if(temp->key == key){
		temp->value=value;
		break;
	    }
       	    temp=temp->next;
    	}
    }else{
    	Node* tempNode=ht->buckets[index];
    	ht->buckets[index]=insert_N(tempNode,key,value);
    	ht->count++;
    }
}

//删除数据
void delete_Key(HashTable* ht,int key){
    int index=hash(key,ht->size);
    Node* temp=ht->buckets[index];
    if(!temp) return;
    
    Node* pre=NULL;
    while(temp){
    	if(temp->key == key){
	    if(pre == NULL){
	    	ht->buckets[index]=temp->next;
	    }else{
	    	pre->next=temp->next;
	    }
	
	    ht->count--;
	    printf("已删除key=%d value=%d\n",temp->key,temp->value);
	    free(temp);
	    return;
	}
	pre=temp;
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
    free(ht->buckets);
    free(ht);
}

int main(){
    HashTable* ht;
    printf("创建哈希表\n");
    int a;
    scanf("%d",&a);
    ht=creat_HT(a);
    printf("插入数据选择：1\n");
    printf("查找数据选择：2\n");
    printf("删除数据选择：3\n");
    printf("退出选择：0\n");
    int choice;
    scanf("%d",&choice);
    while(choice){
        switch(choice){
            case 1:{
                int key,value;
                printf("请输入key和value\n");
                scanf("%d%d",&key,&value);
                insert_HT(ht,key,value);
                printf("此时表内有%d个元素\n",ht->count);
                break;
            }
            case 2:{
                int key;
                printf("请输入key\n");
                scanf("%d",&key);
                int value=find(ht,key);
                if(value != -1){
                    printf("找到key=%d value=%d\n",key,value);
                }else{
                    printf("未找到key=%d\n",key);
                }
                break;
            }
            case 3:{
                int key;
                printf("请输入key\n");
                scanf("%d",&key);
                delete_Key(ht,key);
                printf("此时表内有%d个元素\n",ht->count);
                break;
            }
            default: break;
        }
        printf("继续你的选择\n");
        scanf("%d",&choice);
    }
    free_HT(ht);
    return 0;
}
