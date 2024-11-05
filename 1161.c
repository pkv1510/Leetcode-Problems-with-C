#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define INT_MIN (-2147483648)

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void fillArray(struct TreeNode* root, int *arr, int i, int *level) {
    if(!root)
        return;

    arr[i] += root->val;
    if(i > *level)
        *level = i;
    fillArray(root->left, arr, i + 1, level);
    fillArray(root->right, arr, i + 1, level);
}

int maxLevelSum(struct TreeNode* root) {
    int *arr = (int*)malloc(sizeof(int) * 100);
    int level = 0;
    fillArray(root, arr, 0, &level);
    int max = INT_MIN;
    int maxId = 0;

    for(int i = 0;i < level + 1;i++) {
        if(arr[i] > max) {
            max = arr[i];
            maxId = i + 1;
        }
    }

    return maxId;
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
    root->left = createNode(7);
    root->right = createNode(0);
    root->left->left = createNode(7);
    root->left->right = createNode(-8);

    printf("The maximum sum ataa a level in the tree is at %d level\n", maxLevelSum(root));

    return 0;
}
