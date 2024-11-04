#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct ListNode {
     int val;
     struct ListNode *next;
};

bool checkAndReturn(struct ListNode* head, struct TreeNode* root) {
    if(!root || root->val != head->val) {
        return false;
    }

    if(!head->next)
        return true;

    bool flag = false;
    flag |= checkAndReturn(head->next, root->left);
    flag |= checkAndReturn(head->next, root->right);

    return flag;
}

bool isSubPath(struct ListNode* head, struct TreeNode* root) {
    if(!root)
        return false;

    if(!head)
        return true;

    bool flag = false;
    
    flag |= checkAndReturn(head, root);
    if(flag)
        return true;

    flag |= isSubPath(head, root->left);
    flag |= isSubPath(head, root->right);

    return flag;
}

struct ListNode* createListNode(int value) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode) * 1);
    newNode->val = value;
    newNode->next = NULL;

    return newNode;
}

struct ListNode* insertNode(struct ListNode* head, int value) {
    struct ListNode* newNode = createListNode(value);
    struct ListNode* prev = head;

    if(head == NULL) {
        return newNode;
    }

    while(prev->next != NULL) {
        prev = prev->next;
    }
    prev->next = newNode;

    return head;
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
    struct ListNode* head = NULL;
    int arr[] = {4, 2, 6};
    int size = *(&arr + 1) - arr;

    root = createNode(1);
    root->left = createNode(4);
    root->right = createNode(4);
    root->left->left = NULL;
    root->left->right = createNode(2);
    root->right->left = createNode(2);
    root->right->right = NULL;
    root->left->right->left = createNode(1);
    root->left->right->right = NULL;
    root->right->left->left = createNode(6);
    root->right->left->right = createNode(8);
    root->right->left->right->left = createNode(1);
    root->right->left->right->right = createNode(3);

    for(int i = 0;i < size;i++) {
        head = insertNode(head, arr[i]);
    }

    if(isSubPath(head, root))
        printf("The List can be accomodated in the tree\n");
    else
        printf("The List can not be accomodated in the tree\n");

    return 0;
}
