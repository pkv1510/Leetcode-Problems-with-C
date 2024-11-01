#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void countZigZagLen(struct TreeNode* root, bool leftFlag, int tempCount, int* maxCount) {
    if(!root)
        return;

    if(tempCount > *maxCount)
        *maxCount = tempCount;

    countZigZagLen(root->left, false, (!leftFlag) ? 1 : tempCount + 1, maxCount);
    countZigZagLen(root->right, true, (leftFlag) ? 1 : tempCount + 1, maxCount);
}

int longestZigZag(struct TreeNode* root) {
    if(!root)
        return 0;

    int maxCount = 0;
    countZigZagLen(root, true, 0, &maxCount);

    return maxCount;
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

    root = createNode(1);
    root->left = NULL;
    root->right = createNode(1);
    root->right->left = createNode(1);
    root->right->right = createNode(1);
    root->right->left->left = NULL;
    root->right->left->right = NULL;  
    root->right->right->left = createNode(1);
    root->right->right->right = createNode(1);
    root->right->right->left->left = NULL;
    root->right->right->left->right = createNode(1);
    root->right->right->left->right->left = NULL;
    root->right->right->right->left = NULL;
    root->right->right->right->right = NULL;
    root->right->right->left->right->right = createNode(1);

    printf("The longest zigzg can be formed in the tree is of %d length\n", longestZigZag(root));
    return 0;
}
