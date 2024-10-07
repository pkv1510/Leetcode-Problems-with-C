#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void getSequence(struct TreeNode* root, int *index, int* leaves) {
    if(!root)
        return;

    if(root->left== NULL && root->right == NULL) {
        leaves[(*index)++] = root->val;
    }
    
    getSequence(root->left, index,leaves);
    getSequence(root->right, index, leaves);
}

bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2) {
    int leaves1[100] = {0};
    int leaves2[100] = {0};
    int idx1 = 0;
    int idx2 = 0;
    /* Fetching the sequence of the leaves in both the trees 
     * And storing it in the respective arrays 
    */
    getSequence(root1, &idx1, leaves1);
    getSequence(root2, &idx2, leaves2);

    if(idx1 != idx2)
        return false;

    for(int i = 0;i < idx1;i++) {
        if(leaves1[i] != leaves2[i])
            return false;
    }

    return true;
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
    struct TreeNode* root2 = NULL;

    /* First tree */
    root = createNode(3);
    root->left = createNode(5);
    root->left->left = createNode(6);
    root->left->right = createNode(2);
    root->left->right->left = createNode(7);
    root->left->right->right = createNode(4);
    
    root->right = createNode(1);
    root->right->left = createNode(9);
    root->right->left = createNode(8);

    /* Second tree */
    root2 = createNode(3);
    root2->left = createNode(5);
    root2->left->left = createNode(6);
    root2->left->right = createNode(7);
    
    root2->right = createNode(1);
    root2->right->left = createNode(4);
    root2->right->right = createNode(2);
    root2->right->right->left = createNode(9);
    root2->right->right->right = createNode(8);

    if(leafSimilar(root, root2))
	printf("The leaves on both the given trees are in similar order\n");
    else
	printf("The leaves on both the given trees are not in similar order\n");

    return 0;
}
