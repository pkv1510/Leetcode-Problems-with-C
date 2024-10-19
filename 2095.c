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

int countNodes(struct ListNode* head) {
    int count = 0;

    while(head != NULL) {
        head = head->next;
        count++;
    }

    return count;
}

struct ListNode* deleteMiddle(struct ListNode* head) {
    int count = countNodes(head);
    if(count == 1) {
        return NULL;
    }
    count = (count / 2);
    struct ListNode* temp = head;
    count--;

    while(count) {
        temp = temp->next;
        count--;
    }
    temp->next = temp->next->next;

    return head;
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

int main() {
    int arr[] = {1,3,4,7,1,2,6};
    int size = *(&arr + 1) - arr;
    struct ListNode* head = NULL;

    for(int i = 0;i < size;i++) {
        head = insertNode(head, arr[i]);
    }
    printf("The list before deletion is  \n");
    printList(head);

    head = deleteMiddle(head);

    printf("The list after deletion is  \n");
    printList(head);

    return 0;
}
