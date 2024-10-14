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

struct ListNode* oddEvenList(struct ListNode* head) {
    int idx = 1;
    struct ListNode* oddPtr = head;
    struct ListNode* evenPtr = head;
    struct ListNode* temp = head;
    int count = countNodes(head);
    int total = count;

    while(evenPtr->next != NULL) {
        evenPtr = evenPtr->next;
    }

    while(count) {
        count--;
        if(((idx % 2) != 0) && (idx > 1)) {
            oddPtr->next = temp;
            oddPtr = oddPtr->next;
        } else if((idx % 2) == 0) {
            evenPtr->next = temp;
            evenPtr = evenPtr->next;
            if(total % 2 == 0) {
                oddPtr->next = evenPtr->next;
            }
        }
        temp = temp->next;
        idx++;
    }
    evenPtr->next= NULL;
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
    int arr[] = {1,2,3,4,5,6,7,8};
    int size = *(&arr + 1) - arr;
    struct ListNode* head = NULL;

    for(int i = 0;i < size;i++) {
        head = insertNode(head, arr[i]);
    }
    printf("The list before arrangement is  \n");
    printList(head);

    head = oddEvenList(head);

    printf("The list after arrangement is  \n");
    printList(head);
 
    return 0;
}
