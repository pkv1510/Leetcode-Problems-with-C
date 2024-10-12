#include<stdio.h>
#include<stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int countPaths(struct TreeNode* root, int targetSum) {
    long int tempSum = (root->val == targetSum) ? 1 : 0;

    if(root->left) {
        tempSum += countPaths(root->left, targetSum - root->val);
    }

    if(root->right) {
        tempSum += countPaths(root->right, targetSum - root->val);
    }

    return tempSum;
}

int pathSum(struct TreeNode* root, int targetSum) {
    int count = countPaths(root, targetSum);

    if(root->left) {
        count += pathSum(root->left, targetSum);
    }

    if(root->right) {
        count += pathSum(root->right, targetSum);
    }

    return count;
}

struct TreeNode *createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));

    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

int main() {
    int targetSum = 10;
    struct TreeNode* root = NULL;

    root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = NULL;
    root->left->left->left = NULL;
    root->left->left->right = createNode(7);
    root->left->right->left = createNode(8);
    root->left->right->right = createNode(9);

    printf("The number of paths formed with the sum as %d in the tree is %d\n", targetSum, pathSum(root, targetSum));
    return 0;
}