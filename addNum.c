#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

void printList(struct ListNode* ptr) {
    while(ptr != NULL) {
        printf("%d ", ptr->val);
        ptr = ptr->next;
    }
    printf("\n");
}

//Method-1
struct ListNode* createNode(struct ListNode** head, int value) {
    struct ListNode* temp = NULL;
    temp = (struct ListNode*)malloc(sizeof(struct ListNode));
    temp->next = NULL;
    temp->val = value; 

    if(*head == NULL)
        *head = temp;

    return temp;
}

void addNode(struct ListNode* head, struct ListNode* temp) {
    struct ListNode* ptr = head;
    if(head == temp)
        return;
    while(ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = temp;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int sum, carryFlag = 0;
    struct ListNode* head = NULL;

    if(l1 == NULL && l2 == NULL)
        return NULL;

    while(l1 != NULL && l2 != NULL) {
	    if(l1 != NULL && l2 != NULL) {
	        sum = l1->val + l2->val + carryFlag;

        	addNode(head, createNode(&head, sum % 10));
            carryFlag = sum / 10;
            l1 = l1->next;
            l2 = l2->next;
    	}
    }

    if(l1 == NULL && l2 != NULL) {
        while(l2 != NULL) {
            sum = l2->val + carryFlag;

            addNode(head, createNode(&head, sum % 10));
            carryFlag = sum / 10;
            l2 = l2->next;
        }
    }
    
    if(l2 == NULL && l1 != NULL) {
        while(l1 != NULL) {
            sum = l1->val + carryFlag;

            addNode(head, createNode(&head, sum % 10));
            carryFlag = sum / 10;
            l1 = l1->next;   
        }
    }
    if(l1 == NULL && l2 == NULL) {
       	if(carryFlag == 1) {
           	addNode(head, createNode(&head, carryFlag));
       	}
    }

    return head;   
}

//Method-2
void updateNode(struct ListNode* l1, struct ListNode* l2, struct ListNode** ptr) {
    int carryFlag = 0;
    struct ListNode* temp = NULL;

    if(!l1 && !l2)
        return;

    while(l1 || l2 || carryFlag) {
        int sum = carryFlag;
	    if(l1 != NULL) {
	        sum = sum + l1->val;
            l1 = l1->next;
    	}
        if(l2 != NULL) {
	        sum = sum + l2->val;
            l2 = l2->next;
    	}

        temp = (struct ListNode*)malloc(sizeof(struct ListNode));
        temp->next = NULL;
        temp->val = sum % 10;

        carryFlag = sum / 10;

        *ptr = temp;
        ptr = &((*ptr)->next);   
    } 
}

struct ListNode* addTwoNumbers1(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* head = NULL;

    updateNode(l1, l2, &head);

    return head;
}

int main()
{
    struct ListNode l1, l2, *ptr = NULL;
    l1.val = 1;
    l1.next = NULL;
    /*
    l1.next->val = 2;
    l1.next->next = l1.next->next;
    l1.next->next->val = 3;
    l1.next->next->next = NULL;
    */
    l2.val = 9;
    l2.next = NULL;
    /*
    l2.next->val = 5;
    l2.next->next = l2.next->next;
    l2.next->next->val = 6;
    l2.next->next->next = NULL;
    */
    ptr = addTwoNumbers1(&l1, &l2);
    printList(ptr);

    return 0;
}
