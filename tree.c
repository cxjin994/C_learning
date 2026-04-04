#include<stdlib.h>
#include<stdio.h>

typedef struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
    int lTag;
    int rTag;
}TreeNode;

//创建节点
TreeNode* creatNode(int data){
    TreeNode* Node=(TreeNode*)malloc(sizeof(TreeNode));
    if(Node == NULL){
    	printf("节点空间分配失败");
	return NULL;
    }

    Node->data=data;
    Node->left=NULL;
    Node->right=NULL;
    Node->lTag=0;
    Node->rTag=0;
    return Node;
}

//二叉搜索树创建
TreeNode* insertBST(TreeNode* p,int val){
    if(p == NULL) return creatNode(val);

    if(val < p->data) p->left=insertBST(p->left,val);
    if(val > p->data) p->right=insertBST(p->right,val);
    return p;
}

//统计节点个数
int countNodes(TreeNode* p){
    if(p == NULL) return 0;
    return 1+countNodes(p->left)+countNodes(p->right);
}

//节点值之和
int sumOfNodes(TreeNode* p){
    if(p == NULL) return 0;
    return p->data+sumOfNodes(p->left)+sumOfNodes(p->right);
}

//计算高度
int maxDepth(TreeNode* p){
    if(p == NULL) return 0;
    int left=maxDepth(p->left);
    int right=maxDepth(p->right);
    return 1+(left>right ? left : right);
}

//前序遍历
void preorder(TreeNode* root){
    if(root == NULL) return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

//中序线索化
void inorderThread(TreeNode* p, TreeNode** prev){
    if(p == NULL) return;

    inorderThread(p->left,prev);
    if(p->left == NULL){
    	p->lTag=1;
	p->left=*prev;
    }
    if(*prev != NULL && (*prev)->right == NULL){
    	(*prev)->right=p;
	(*prev)->rTag=1;
    }
    *prev=p;
    inorderThread(p->right,prev);
}

int main(){

    TreeNode* root=NULL;
    for(int i=0;i<10;i++){
        root=insertBST(root,rand()%100);
    }
    preorder(root);
    printf("\n节点个数: %d\n",countNodes(root));
    printf("节点值之和: %d\n",sumOfNodes(root));
    printf("树的高度: %d\n",maxDepth(root));
    return 0;
}
