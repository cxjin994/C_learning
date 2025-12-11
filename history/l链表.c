#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;
//创建节点
Node* creatNode(int data){
    Node* newNode=(Node*)malloc(sizeof(Node));
    if(newNode==NULL){
        printf("内存分配失败");
	return NULL;
    }
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}
//插入尾部
Node* insertTail(Node* head, int data){
    Node* newNode=creatNode(data);
    if(head == NULL){
    	return newNode;
    }

    Node* current=head;
    while(current->next!=NULL){
    	current=current->next;
    }
    current->next=newNode;
    return head;
}
//打印链表
void printList(Node* head){
    Node* current=head;
    while(current!=NULL){
        printf("%d ",current->data);
        current=current->next;
    }
    printf("\n");
}
//释放链表
void freeList(Node* head){
    Node* current = head;
    while(current != NULL){
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main(){
    Node* head=NULL;
    
    head=insertTail(head,10);
    head=insertTail(head,20);
    
    printf("链表中元素为：");
    printList(head);
    freeList(head);
    return 0;
}
		



	
