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

//删除指定值节点
Node* deleteNode(Node* head, int data){
    Node* current=head;
    
    if(head->data == data){
        Node* temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    
    while(current->next->data != data){
    	current=current->next;
        if(current->next == NULL && current->data != data){
	    printf("Error,没有那个数");
	    return head;
	}
    }
    
    if(current->next->next != NULL){
    	Node* temp=current->next->next;
    	free(current->next);
    	current->next=temp;
    }else{
    	free(current->next);
	current->next=NULL;
    }
    return head;
}

//查找节点
void findNode(Node* head, int data){
    int count=1;
    Node* current=head;
    while(current->data != data){
    	count++;
	current=current->next;
    }
    if(current->data == data){
    	printf("%d在第%d个节点\n", data, count);
    }else{
    	printf("没有找到相应的节点\n");
    }
}

//反转链表
void printList(Node* head);
Node* reverceList(Node* head){
    printf("反转之前：");
    printList(head); printf("\n");

    Node* next=NULL, * prev=NULL, * current=head;
    while(current != NULL){
    	next=current->next;
    	current->next=prev;
    	prev=current;
   	current=next;
    }

    printf("反转之后：");
    printList(prev);

    return prev;

}

//打印链表
void printList(Node* head){
    int count=0;
    if(head==NULL){
    	printf("无链表");
    }else{Node* current=head;
      while(current != NULL){
      	  printf("%d ", current->data);
      	  current=current->next;
	  count++;
      }
    }
    printf("一共有%d个节点", count);
    printf("\n");
    
}

//释放空间
void freeList(Node* head){
    Node* current=head;
    while(current != NULL){
    	Node* temp=current;	
	current=current->next;
	free(temp);
    }
    head=NULL;
}

int main(){
    int ch, data;
    Node* head=NULL;
    printf("在头部插入节点选择：1\n");
    printf("在尾部插入节点选择：2\n");
    printf("查找节点选择：3\n");
    printf("删除节点选择：4\n");
    printf("反转链表选择：5\n");
    printf("退出选择：0\n");
    scanf("%d", &ch);
    
    while(ch!=0){
    	switch(ch){
	    case 1: printf("输入想插入的数"); scanf("%d", &data); head=insertHead(head,data); break;
	    case 2: printf("输入想插入的数"); scanf("%d", &data); head=insertTail(head,data); break;
	    case 3: printf("输入想查找的数"); scanf("%d", &data); findNode(head,data); break;
	    case 4: printf("输入想删除的数"); scanf("%d", &data); head=deleteNode(head,data); break;
	    case 5: head=reverceList(head); break;
	    case 0: break;
	    default: printf("Error\n"); break;
	}
	printf("继续选择");
	scanf("%d", &ch);
    }
    
    printList(head);
    return 0;
}

