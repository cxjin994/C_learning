#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef struct{
    Node* head;
    int capacity;
}Stack;

//创建链表节点
Node* creatNode(int value){
    Node* newNode=(Node*)malloc(sizeof(Node));
    if(newNode==NULL){
    	printf("链表节点创建失败\n");
	return NULL;
    }
    newNode->data=value;
    newNode->next=NULL;
    return newNode;
}

//在头部插入节点
Node* insertHead(Node* head,int value){
    Node* newNode=creatNode(value);
    if(head!=NULL) newNode->next=head;
    return newNode;
}

//创建链表栈
Stack* creatStack(){
    Stack* stack=(Stack*)malloc(sizeof(Stack));
    if(stack==NULL){
        printf("动态栈创建失败\n");
	return NULL;
    }
    stack->head=NULL; stack->capacity=0;
    return stack;
}

//删除栈
void freeStack(Stack* stack){
    if(stack==NULL){
        printf("没有这个栈\n");
	return;
    }
    //还应删除链表
    Node* current=stack->head;
    if(current != NULL){
    	Node* temp;
	while(current!=NULL){
	    temp=current->next;
	    free(current);
	    current=temp;
	}
    }
    free(stack);
}

//判断
bool isEmpty(Stack* stack){
    return stack->capacity == 0;
}

//入栈
bool push(Stack* stack, int value){
    if(stack == NULL){
    	printf("没有这个栈");
	return false;
    }
    stack->head=insertHead(stack->head,value);
    stack->capacity++;
    return true;
}

//出栈
bool pop(Stack* stack,int* value){
    if(stack==NULL){
    	printf("没有这个栈");
	return false;
    }

    if(isEmpty){
    	printf("当前栈里没有元素\n");
        return false;
    }

    Node* current=stack->head->next;
    *value=stack->head->data;
    
    free(stack->head);
    
    stack->head=current;
    printf("出栈元素为%d\n",*value);
    stack->capacity--;
    return true;
}

//查看栈顶
bool peek(Stack* stack,int* value){
    if(stack==NULL){
    	printf("没有这个栈\n");
	return false;
    }

    if(stack->head == NULL){
    	printf("当前栈里没有元素\n");
	return false;
    }else{
        *value=stack->head->data;
        printf("当前栈顶元素为%d\n",*value);
        return true;
    }
}
//打印栈信息
void printStack(Stack* stack){
    if(stack==NULL){
    	printf("没有这个栈");
	return;
    }

    printf("当前栈内一共有%d个元素\n",stack->capacity);
    Node* current=stack->head;
    while(current!=NULL){
    	printf("%d ",current->data);
	current=current->next;
    }
    printf("\n");

}

int main(){
    int value, ch;
    Stack* s=creatStack();
    printf("入栈选择：1\n");
    printf("出栈选择：2\n");
    printf("查看栈顶选择：3\n");
    printf("退出选择：0\n");
    scanf("%d", &ch);

    while(ch != 0){
    	switch(ch){
	    case 1: printf("输入想入栈的数"); scanf("%d",&value); push(s,value); break;
	    case 2: pop(s,&value); break;
	    case 3: peek(s,&value); break;
	    case 0: break; 
	    default: printf("Error\n"); break;
	}
	printf("继续你的选择 ");
	scanf("%d",&ch);
    }

    printStack(s);
    freeStack(s);
    return 0;
}
















