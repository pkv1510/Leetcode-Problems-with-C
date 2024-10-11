#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define INT_MIN (-2147483648)

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* findSuccessor(struct TreeNode* root) {
    if(!root->left) {
        return root;
    }

    return findSuccessor(root->right);
}

struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    if(!root)
        return NULL;

    if(root->val > key) {
        root->left = deleteNode(root->left, key);
    } else if(root->val < key) {
        root->right = deleteNode(root->right, key);
    } else {
        if(!root->left && !root->right) {
            return NULL;
        }
        
        if(root->left) {
            return root->right;
        } else if(root->right) {
            return root->left;
        }

        struct TreeNode *successor = findSuccessor(root->right);
        root->val = successor->val;
        root->right = deleteNode(root->right, successor->val);
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

    root = createNode(5);
    root->left = createNode(3);
    root->right = createNode(6);
    root->left->left = createNode(2);
    root->left->right = createNode(4);
    root->right->right = createNode(7);

    printf("The maximum sum ataa a level in the tree is at %d level\n", maxLevelSum(root));

    return 0;
}
