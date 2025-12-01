#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

//创建新的节点
Node* creatNode(int data){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

//在头部插入节点
Node* insertHead(Node* head, int data){
    Node* newNode=creatNode(data);
    if(head==NULL) return newNode;
    Node* current=head;
    head=newNode;
    newNode->next=current;
    return head;
}

//在尾部插入节点
Node* insertTail(Node* head, int data){
    Node* newNode=creatNode(data);
    if(head==NULL) return newNode;
    Node* current=head;
    while(current->next != NULL){
    	current=current->next;
    }
    current->next=newNode;
    return head;
}

//打印链表
void printList(Node* head){
    Node* current=head;
    while(current != NULL){
    	printf("%d ", current->data);
	current=current->next;
    }
    printf("\n");
}

int main(){
    Node* first=creatNode(10);
    printf("%d\n", first->data);    
    return 0;
}
