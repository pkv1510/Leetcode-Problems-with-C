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

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int pos = countNodes(head) - n;
    struct ListNode *temp = head, *temp2 = head;

    while(pos > 0) {
        temp2 = temp2->next;
        pos--;
    }

    while(temp->next != temp2)
        temp = temp->next;

    temp->next = temp2->next;
    temp2 = NULL;
    return head;
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

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(int);

    struct ListNode* head = NULL;

    for(int i = 0;i < size;i++) {
        head = addAtEnd(head, arr[i]);
    }
    printList(head);
    int pos;
    printf("Enter the position of the element to be removed\n");
    scanf("%d", &pos);
    head = removeNthFromEnd(head, pos);
    printList(head);

    return 0;
}