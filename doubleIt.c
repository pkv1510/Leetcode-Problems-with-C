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

int countNodes(struct ListNode* head) {
    int count = 0;
    while(head != NULL) {
        count++;
        head = head->next;
    }

    return count;
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

struct ListNode *createNode(int val) {
    struct ListNode *temp = (struct ListNode *)malloc(sizeof(struct ListNode));
    temp->val = val;
    temp->next = NULL;

    return temp;
}

struct ListNode* addAtFront(struct ListNode* head, int val) {
    struct ListNode *temp = createNode(val);
    if(head == NULL)
        return temp;

    temp->next = head;

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

struct ListNode* doubleIt(struct ListNode* head){
    int carry = 0;
    struct ListNode *temp = reverseList(head);
    struct ListNode *temp2 = temp;
    while(temp) {
        temp->val = temp->val * 2 + carry;
        if(temp->val > 9) {
            carry = temp->val / 10;
            temp->val = temp->val % 10;
        } else {
            carry = 0;
        }
        temp = temp->next;
    }

    head = reverseList(temp2);
    if(carry)
        head = addAtFront(head, carry);

    printf("The num of nodes is %d\n", countNodes(head));

    return head;
}

int main() {
    int arr[] = {1, 8, 9};
    int size = sizeof(arr) / sizeof(int);

    struct ListNode* head = NULL;

    for(int i = 0;i < size;i++) {
        head = addAtEnd(head, arr[i]);
    }
    printList(head);
    head = doubleIt(head);
    printList(head);

    return 0;
}