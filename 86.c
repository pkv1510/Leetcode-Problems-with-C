#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void printList(struct ListNode* head) {
    if(!head)
        return;

    printf("%d", head->val);
    head = head->next;
    while(head !=  NULL) {
        printf("-->%d", head->val);
        head = head->next;
    }
    printf("\n");
}

struct ListNode* createNode(int value) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode) * 1);
    newNode->val = value;
    newNode->next = NULL;

    return newNode;
}

struct ListNode* insertNode(struct ListNode* head, int value) {
    struct ListNode* newNode = createNode(value);
    struct ListNode* temp = head;

    if(head == NULL) {
        return newNode;
    }

    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;

    return head;
}

void mergeList(struct ListNode* lesser, struct ListNode* higher) {
    if(!lesser)
        return;

    while(lesser->next != NULL)
        lesser = lesser->next;

    lesser->next = higher;
}

struct ListNode* partition(struct ListNode* head, int x) {
    if(!head)
        return NULL;
    struct ListNode* lesser = NULL;
    struct ListNode* higher = NULL;

    while(head != NULL) {
        if(head->val < x)
            lesser = insertNode(lesser, head->val);
        else
            higher = insertNode(higher, head->val);

        head = head->next;
    }
    mergeList(lesser, higher);

    return (lesser) ? lesser : higher;
}

int main() {
    int arr[] = {1,4,3,2, 5, 2};
    int size = *(&arr + 1) - arr;
    struct ListNode* head = NULL;

    for(int i = 0;i < size;i++) {
        head = insertNode(head, arr[i]);
    }
    printf("The list before partitioning is  \n");
    printList(head);

    head = partition(head, 3);

    printf("The list after partitioning is  \n");
    printList(head);

    return 0;
}
