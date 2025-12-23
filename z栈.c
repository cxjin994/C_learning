#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX_SIZE 5 //定义常数

typedef struct{
    int data[MAX_SIZE];
    int top;  //栈顶指针，指向最后一个元素的位置(数组下标)
}Stack;

//初始化栈
void initStack(Stack* s){
    s->top=-1;
}

//判断栈是否为空
bool isEmpty(Stack* s){
    return s->top == -1;
}
//判断栈是否已满
bool isFull(Stack* s){
    return s->top == MAX_SIZE - 1;
}

//入栈
bool push(Stack* s, int value){
    if(isFull(s)){
    	printf("栈已满，无法入栈\n");
	return false;
    }

    s->top++;
    s->data[s->top]=value;
    printf("入栈元素:%d\n", value);
    return true;
}

//出栈
bool pop(Stack* s,int* value){
    if(isEmpty(s)){
    	printf("栈为空，无法出栈\n");
	return false;
    }

    *value=s->data[s->top]; //获取栈顶元素
    s->top--;
    printf("出栈元素:%d\n", *value);
    return true;
}

//查看栈顶元素
bool peek(Stack* s, int* value){
    if(isEmpty(s)){
    	printf("栈为空\n");
	return false;
    }

    *value=s->data[s->top];
    printf("栈顶元素:%d\n", *value);
    return true;
}

//打印栈中所有元素
void printStack(Stack* s){
    if(isEmpty(s)){
    	printf("栈为空\n");
	return;
    }

    printf("栈内容(从底到顶):");
    for(int i=0; i<=s->top; i++){
    	printf("%d ", s->data[i]);
    }
}

int main(){
    int value, ch;
    Stack s;
    initStack(&s);
    printf("入栈选择：1\n");
    printf("出栈选择：2\n");
    printf("查看栈顶选择：3\n");
    printf("退出选择：0\n");
    scanf("%d", &ch);

    while(ch != 0){
    	switch(ch){
	    case 1: printf("输入想入栈的数"); scanf("%d",&value); push(&s,value); break;
	    case 2: pop(&s,&value); printf("出栈元素为%d\n",value); break;
	    case 3: peek(&s,&value); printf("栈顶元素为%d\n",value); break;
	    case 0: break; 
	    default: printf("Error\n"); break;
	}
	printf("继续你的选择 ");
	scanf("%d",&ch);
    }
    printStack(&s);
    return 0;
}
