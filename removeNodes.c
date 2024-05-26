#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void printList(struct ListNode *head) {
    while(head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    
    printf("\n");
}

struct ListNode* reverseList(struct ListNode* head) {
    if(!head || !head->next)
        return head;
    struct ListNode *curr = head;
    curr = curr->next;
    head->next = NULL;

    while(curr->next) {
        struct ListNode* nextNode = curr->next;

        curr->next = head;
        head = curr;
        curr = nextNode;
    }
    curr->next = head;
    return curr;
}

struct ListNode* removeNodes(struct ListNode* head) {
    struct ListNode *temp = reverseList(head);
    struct ListNode *temp2 = temp;
    while(temp->next != NULL) {
        if(temp->next->val >= temp->val)
            temp = temp->next;
        else
            temp->next = temp->next->next;
    }
    return (reverseList(temp2));
}

struct ListNode *createNode(int val) {
    struct ListNode *temp = (struct ListNode *)malloc(sizeof(struct ListNode));
    temp->val = val;
    temp->next = NULL;

    return temp;
}

struct ListNode* addAtEnd(struct ListNode* head, int val) {
    struct ListNode *temp = createNode(val);
    struct ListNode *temp2 = head;
    if(head == NULL)
        return temp;

    while(head->next != NULL)
        head = head->next;

    head->next = temp;

    return temp2;
}

int main() {
    int arr[] = {5, 2, 13, 3, 8};
    int size = sizeof(arr) / sizeof(int);

    struct ListNode* head = NULL;

    for(int i = 0;i < size;i++) {
        head = addAtEnd(head, arr[i]);
    }
    printList(head);
    head = removeNodes(head);
    printList(head);

    return 0;
}