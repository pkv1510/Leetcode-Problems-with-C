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

int compare(int a, int b) {
    return (a <= b ? 1 : 0);
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

struct ListNode* mergeTwoLists(struct ListNode* head1, struct ListNode* head2) {
    struct ListNode *head = NULL;
    while(head1 != NULL && head2 != NULL) {
        if(head1 && compare(head1->val, head2->val)) {
            head = addAtEnd(head, head1->val);
            head1 = head1->next;
        } else if (head2 && !compare(head1->val, head2->val)){
            head = addAtEnd(head, head2->val);
            head2 = head2->next;
        }
    }
    while(head2 != NULL) {
        head = addAtEnd(head, head2->val);
        head2 = head2->next;
    }
    while(head1 != NULL) {
        head = addAtEnd(head, head1->val);
        head1 = head1->next;
    }

    return head;
}

int main() 
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(int);

    struct ListNode* head1 = NULL;
    struct ListNode* head2 = NULL;
    struct ListNode* head = NULL;

    for(int i = 0;i < size;i++) {
        head1 = addAtEnd(head1, arr[i]);
        head2 = addAtEnd(head2, arr[i]);
    }
    printList(head1);
    printList(head2);

    head = mergeTwoLists(head1, head2);
    printList(head);

    return 0;
}