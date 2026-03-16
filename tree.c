#include<stdlib.h>
#include<stdio.h>

typedef struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

TreeNode* creatNode(int data){
    TreeNode* Node=(TreeNode*)malloc(sizeof(TreeNode));
    if(Node == NULL){
    	printf("节点空间分配失败");
	return NULL;
    }

    Node->data=data;
    Node->left=NULL;
    Node->right=NULL;
    return Node;
}

void preorder(TreeNode* root){
    if(root == NULL) return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

int main(){
    TreeNode* root = creatNode(1);
    TreeNode* node2 = creatNode(2);
    TreeNode* node3 = creatNode(3);
    TreeNode* node4 = creatNode(4);
    TreeNode* node5 = creatNode(5);

    // 建立连接
    root->left = node2;
    root->right = node3;
    node2->left = node4;
    node2->right = node5;

    preorder(root);
    return 0;
}
