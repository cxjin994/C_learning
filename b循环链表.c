#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* last, * next;
}Node;

//创建新节点
Node* creatNode(int data){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->last=NULL; newNode->next=NULL;
    newNode->data=data;
    return newNode;
}

//在头部插入节点
Node* insertHead(Node* head, int data){
    Node* newNode=creatNode(data);
    if(head == NULL) return newNode;
    newNode->next=head; head->last=newNode;
    return newNode;
}

//在尾部插入节点
Node* insertTail(Node* head, int data){
    Node* newNode=creatNode(data);
    if(head == NULL) return newNode;
    Node* current=head;
    while(current->next != NULL){
    	current=current->next;
    }
    current->next=newNode; newNode->last=current;
    return head;
}

//根据数查找节点
void findNode(Node* head, int data){
    if(head == NULL){
    	printf("没有这个链表");
    }else{
    	Node* current=head;
	Node* temp=NULL;
	int i=1, count=0;
	while(current->next !=NULL || temp != head){
	    if(current->data == data){
	    	printf("%d在第%d节点 ", data, i);
            count++;
	    }
	    i++;
	    if(current->next == NULL) break;
	    current=current->next;
	    if(temp == head) break;
	    temp=current;
	}
    if(count == 0) printf("没有这个数据");
    }
    printf("\n");
}

//打印链表
void printList(Node* head){
    if(head ==NULL){
        printf("无链表");
    }else{
        Node* current=head;
    	Node* temp=NULL;
    	int i=1;
    	
	while(temp != head || current->next != NULL){
    	    if(head == NULL) break;
	    printf("第%d个节点是%d ", i, current->data);
	   
	    if(current->next == NULL) break;
	    current=current->next;
	   
	    if(temp == head) break;
	    temp=current;
	    i++;
    	}
    }
    
    printf("\n");
}

int main(){
    int ch, data;
    Node* head=NULL;
    printf("在头部插入节点选择：1\n");
    printf("在尾部插入节点选择：2\n");
    printf("查找节点选择：3\n");
    
    printf("退出选择：0\n");
    scanf("%d", &ch);
    
    while(ch!=0){
    	switch(ch){
	    case 1: printf("输入想插入的数"); scanf("%d", &data); head=insertHead(head,data); break;
	    case 2: printf("输入想插入的数"); scanf("%d", &data); head=insertTail(head,data); break;
	    case 3: printf("输入查找的数"); scanf("%d", &data); findNode(head, data); break;
        case 0: break;
	    default: printf("Error\n"); break;
	}
	printf("继续选择");
	scanf("%d", &ch);
    }
    
    printList(head);
    return 0;
}
