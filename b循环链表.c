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
Node* inserthead(Node* head, int data){
    Node* newNode=creatNode(data);
    newNode->next=head; head->last=newNode;
    return newNode;
}

//在尾部插入节点


int main(){


    return 0;
}
