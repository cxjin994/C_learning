#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* creatNode(int data){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

Node* insertTail(Node* head; int data){

}

int main(){
    Node* first=creatNode(10);
    printf("%d\n", first->data);    
    return 0;
}
