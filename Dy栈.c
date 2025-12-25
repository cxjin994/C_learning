#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct{
    int* data;       //指向动态数组
    int top;         //栈顶索引
    int capacity;    //当前容量
    int minCapacity; //最小容量
}DynamicStack;

//创建栈
DynamicStack* creatStack(int initialCapacity){ // initial 开始的
    if(initialCapacity < 0){
    	printf("容量大小不正确\n");
	return NULL;
    }    

    DynamicStack* Stack=(DynamicStack*)malloc(sizeof(DynamicStack));
    if(Stack==NULL){
    	printf("栈分配失败\n");
	return NULL;
    }

    Stack->data=(int*)malloc(initialCapacity*sizeof(int));
    if(Stack->data==NULL){
    	printf("动态数组分配失败\n");
	free(Stack); //应该把内存释放
	return NULL;
    }
    Stack->top=-1; Stack->capacity=initialCapacity;
    Stack->minCapacity=initialCapacity;
    return Stack;
}

//销毁栈
void destroyStack(DynamicStack* stack){
    if(stack==NULL){
    	printf("没有这个栈\n");
	return;
    }

    free(stack->data);
    free(stack);
}

//清空栈
void clearStack(DynamicStack* stack){
    if(stack==NULL){
    	printf("没有这个栈\n");
	return;
    }

    /*if(Stack->data==NULL){
    	printf("没有找到动态数组");
	return;
    }    没必要,因为Stack->data==NULL时在创建动态栈的时候就会报错
    */
    stack->top=-1;
}

//判断栈是否满
bool isFull(DynamicStack* stack){
    return stack->top == stack->capacity-1;
}
//判断栈是否空
bool isEmpty(DynamicStack* stack){
    return stack->top == -1;
}

//入栈
bool push(DynamicStack* stack, int value){
    if(stack==NULL){
    	printf("没有这个栈\n");
	return false;
    }

    if(isFull(stack)){
    	printf("栈已满,即将扩容\n");
    
    	int newcapacity=stack->capacity*2;
	int* newdata=(int*)realloc(stack->data,sizeof(int)*newcapacity);
    	if(newdata==NULL){
    	    printf("扩容失败\n");
	    return false;
	}
	stack->data=newdata; stack->capacity=newcapacity;
	printf("扩容成功,新容量:%d\n",newcapacity);
    }

    stack->top++; stack->data[stack->top] = value;
    return true;
}

//出栈
bool pop(DynamicStack* stack, int* value){
    if(stack==NULL){
    printf("没有这个栈\n");
    return false;
    }

    if(isEmpty(stack)){
    printf("栈为空\n");
    *value=0;
    return false;
    }

    *value=stack->data[stack->top];  stack->top--;
    printf("出栈元素为%d\n",*value);

    if(stack->capacity < stack->capacity/4 && stack->capacity > stack->minCapacity){
    	printf("栈内元素太少,即将缩容\n");
	int newcapacity=stack->capacity/2;
	if(newcapacity < stack->minCapacity){
	    newcapacity=stack->minCapacity;
	}
	int* newdata=(int*)realloc(stack->data,sizeof(int)*newcapacity);
	if(newdata != NULL){
	    stack->data=newdata; stack->capacity=newcapacity;
    	    printf("缩容成功,新容量:%d\n",newcapacity);
	}else{
	    printf("缩容失败,保持原容量\n");
	}
    }
    return true;
}

//查看栈顶元素
bool peek(DynamicStack* stack, int* value){
    if(stack==NULL){
        printf("没有这个栈\n");
        *value=0;
	    return false;
    }

    *value=stack->data[stack->top];
    printf("当前栈顶为:%d\n",*value);
    return true;
}

//获取栈中元素个数
int getSize(DynamicStack* stack){
    if(stack==NULL){
    	printf("没有这个栈\n");
	return 0;
    }
    return stack->top+1;
}
//获取栈当前的容量
int getCapacity(DynamicStack* stack){
    if(stack==NULL){
    	printf("没有这个栈\n");
	return 0;
    }
    return stack->capacity;
}

//打印栈信息
void printStackInfo(DynamicStack* stack){
    if(stack==NULL){
    	printf("没有这个栈\n");
	return;
    }
    printf("当前栈容量为:%d\n",stack->capacity);
    printf("当前栈最小容量为:%d\n",stack->minCapacity);
    int num=getSize(stack);
    printf("当前栈元素个数为:%d\n",num);
    printf("当前栈元素为(从栈底到栈顶):");
    for(int i=0; i<=stack->top; i++){
    	printf("%d ",stack->data[i]);
    }
    printf("\n");
}

int main(){
    DynamicStack* stack;
    printf("请输入初始容量:");
    int initialCapacity;
    scanf("%d",&initialCapacity);
    stack=creatStack(initialCapacity);
    int value, ch;
    printf("入栈选择：1\n");
    printf("出栈选择：2\n");
    printf("查看栈顶选择：3\n");
    printf("查看栈信息选择选择：4\n");
    printf("退出选择：0\n");
    scanf("%d", &ch);

    while(ch != 0){
    	switch(ch){
	    case 1: printf("输入想入栈的数"); scanf("%d",&value); push(stack,value); break;
	    case 2: pop(stack,&value); printf("出栈元素为%d\n",value); break;
	    case 3: peek(stack,&value); printf("栈顶元素为%d\n",value); break;
        case 4: printStackInfo(stack); break;
	    case 0: break; 
	    default: printf("Error\n"); break;
	}
	printf("继续你的选择 ");
	scanf("%d",&ch);
    }
    printStackInfo(stack);
    return 0;    
}




































