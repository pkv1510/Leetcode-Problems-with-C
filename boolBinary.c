#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
 
bool evaluateTree(struct TreeNode* root) {
    if (root->val < 2)
        return root->val;

    bool left = evaluateTree(root->left);
    bool right = evaluateTree(root->right);
    if(root->val == 2)
        return left || right;
    if(root->val == 3)
        return left && right;

    return false;
}

int main() {
    
    return 0;
}