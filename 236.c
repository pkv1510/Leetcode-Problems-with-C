#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if(!root) {
        return NULL;
    }

    if(root->val == p->val || root->val == q->val) {
        return root;
    }

    struct TreeNode *left = lowestCommonAncestor(root->left, p, q);
    struct TreeNode *right = lowestCommonAncestor(root->right, p, q);

    if(!right) {
        return left;
    } 
    if(!left){
        return right;
    }
    return root;
}

struct TreeNode *createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));

    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

int main() {
    struct TreeNode* root = NULL;

    struct TreeNode *p = createNode(5);
    struct TreeNode *q = createNode(4);

    root = createNode(3);
    root->left = createNode(5);
    root->right = createNode(1);
    root->left->left = createNode(6);
    root->left->right = createNode(2);
    root->right->left = createNode(0);
    root->right->right = createNode(8);
    root->left->right->left = createNode(7);
    root->left->right->right = createNode(4);

    printf("The LCA of the binary tree is %d length\n", lowestCommonAncestor(root, p, q)->val);
    return 0;
}
