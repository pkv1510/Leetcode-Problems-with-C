#include<stdio.h>
#include<stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void printArray(int *arr, int size) {
    for(int i = 0;i < size;i++)
        printf("%d ", arr[i]);

    printf("\n");
}

void fillArray(struct TreeNode *root, int* arr, int* i, int count) {
    if(!root)
        return;

    if(*i == count) {
        arr[(*i)++] = root->val;
    }

    fillArray(root->right, arr, i, count + 1);
    fillArray(root->left, arr, i, ++count);
}

int* rightSideView(struct TreeNode* root, int* returnSize) {
    int *retArray = (int *)malloc(sizeof(int) * 101);
    int i = 0;
    fillArray(root, retArray, &i, 0);
    *returnSize = i;

    return retArray;
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
    int retSize;
    int *arr;

    root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = NULL;
    root->left->right = createNode(5);
    root->right->left = NULL;
    root->right->right = createNode(4);

    printf("The right side view of the tree is \n");
    arr = rightSideView(root, &retSize);
    printArray(arr, retSize);

    return 0;
}
