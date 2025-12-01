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
    if(head==NULL){
    	printf("无链表");
    }else{Node* current=head;
      while(current != NULL){
      	  printf("%d ", current->data);
      	  current=current->next;
      }
    }
    printf("\n");
    
}

int main(){
    int ch, data;
    Node* head=NULL;
    printf("在头部插入节点选择：1\n");
    printf("在尾部插入节点选择：2\n");
    printf("退出选择：0\n");
    scanf("%d", &ch);
    
    while(ch!=0){
    	switch(ch){
	    case 1: printf("输入想插入的数"); scanf("%d", &data); head=insertHead(head,data); break;
	    case 2: printf("输入想插入的数"); scanf("%d", &data); head=insertTail(head,data); break;
	    case 0: break;
	    default: printf("Error\n");
	}
	scanf("%d", &ch);
    }
    printList(head);
    
    
    return 0;
}
