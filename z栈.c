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
//测试
int main(){
    Stack s;
    initStack(&s);

    //测试入栈
    printf("入栈测试:\n");
    for(int i=1; i<=6; i++){
    	if(push(&s, i*10)){
	    printf("入栈成功:%d\n", i*10);
	    printStack(&s);
	}else{
	    printf("入栈失败，栈已满\n");
	}
    }
    printf("\n");
    
    //测试查看栈顶
    printf("查看栈顶测试\n");
    int topValue;
    if (peek(&s, &topValue)) {
        printf("当前栈顶: %d\n", topValue);
    }

    // 测试出栈
    printf("\n出栈测试：\n");
    int poppedValue;
    while (pop(&s, &poppedValue)) {
        printf("出栈: %d\n", poppedValue);
        printStack(&s);
    }

    // 测试空栈操作
    printf("\n空栈测试：\n");
    if (!pop(&s, &poppedValue)) {
        printf("出栈失败：栈已空\n");
    }
    if (!peek(&s, &topValue)) {
        printf("查看栈顶失败：栈已空\n");
    }
    return 0;
}
