#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool checkTree(struct TreeNode* root) {
    return (root->val == (root->left->val + root->right->val));
}

struct TreeNode *createNode(int val) {
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    return newNode;
}

int main() {
    struct TreeNode *root;
    root = createNode(10);
    root->right = createNode(8);
    root->left = createNode(2);

    if(checkTree(root))
        printf("The Tree is correctly balanced");
    else
        printf("The Tree is not balanced");

    return 0;
}
