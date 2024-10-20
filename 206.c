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

struct ListNode* reverseList(struct ListNode* head) {
    if(!head)
        return NULL;
    if(head->next == NULL)
        return head;

    struct ListNode* prev, *curr, *temp;

    prev = head;
    curr = head->next;
    temp = head->next->next;
    prev->next = NULL;

    while(temp != NULL) {
        curr->next = prev;
        prev = curr;
        curr = temp;
        temp = temp->next;
    }
    curr->next = prev;

    return curr;
}

int main() {
    int arr[] = {1,2,3,4,5,6,7,8};
    int size = *(&arr + 1) - arr;
    struct ListNode* head = NULL;

    for(int i = 0;i < size;i++) {
        head = insertNode(head, arr[i]);
    }
    printf("The list before reversing is  \n");
    printList(head);

    head = reverseList(head);

    printf("The list after reversing is  \n");
    printList(head);
    return 0;
}
