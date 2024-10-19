#include<stdio.h>
#include<stdlib.h>

struct ListNode {
     int val;
     struct ListNode *next;
};

void printList(struct ListNode* head) {
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

int countNodes(struct ListNode* head) {
    int count = 0;

    while(head != NULL) {
        head = head->next;
        count++;
    }

    return count;
}

int pairSum(struct ListNode* head) {
    int nofNodes = countNodes(head);
    int temp[100000] = {0};

    int count = nofNodes / 2;
    int idx = 0;

    while(head != NULL) {
        temp[idx] = head->val;
        head = head->next;
        idx++;
    }
    int max = 0;
    for(int i = 0;i < count;i++) {
        temp[i] += temp[nofNodes - i - 1];
        printf("%d \n", temp[i]);
        if(temp[i] > max)
            max = temp[i];
    }

    return max;
}

int main() {
    int arr[] = {1,2,3,4,5,6,7,8};
    int size = *(&arr + 1) - arr;
    struct ListNode* head = NULL;

    for(int i = 0;i < size;i++) {
        head = insertNode(head, arr[i]);
    }
    printf("The list is  \n");
    printList(head);

    printf("The maximum pairsum in the list is %d\n", pairSum(head));

    return 0;
}
