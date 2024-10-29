#include<stdio.h>
#include<stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int countNodes(struct TreeNode* root, int val) {
    int temp = 0;
    if(!root)
        return 0;

    if(root->val >= val) {
        temp++;
        val = root->val;
    }

    temp += countNodes(root->left, val);
    temp += countNodes(root->right, val);

    return temp;
}

int goodNodes(struct TreeNode* root) {
    return countNodes(root, root->val);
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

    printf("The number of good nodes of the tree is %d\n", goodNodes(root));
    return 0;
}
