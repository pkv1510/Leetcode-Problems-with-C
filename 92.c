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

struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    struct ListNode* prev = NULL, *new;
    struct ListNode* temp = head;
    struct ListNode* temp2 = NULL;
    if(right == left)
        return head;
    if(!head || !head->next)
        return head;

    right = right - left;

    while(--left) {
        prev = temp;
        temp = temp->next;
    }

    temp2 = temp;
    while(right--) {
        temp = temp->next;
    }
    new = temp->next;
    temp->next = NULL;

    temp2 = reverseList(temp2);
    if(prev)
        prev->next = temp2;
    else
        head = temp2;
    while(temp2->next != NULL) {
        temp2 = temp2->next;
    }
    temp2->next = new;

    return head;
}

int main() {
    //int arr[] = {1,2,3,4,5};
    int arr[] = {3,5};
    int size = *(&arr + 1) - arr;
    struct ListNode* head = NULL;

    for(int i = 0;i < size;i++) {
        head = insertNode(head, arr[i]);
    }
    printf("The list before reversing is  \n");
    printList(head);

    head = reverseBetween(head, 1, 2);

    printf("The list after reversing is  \n");
    printList(head);
    return 0;
}