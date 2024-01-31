#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct MyQueue{
    int val;
    struct MyQueue *next;
} MyQueue;

struct MyQueue *tail = NULL;
struct MyQueue *head = NULL;

MyQueue* myQueueCreate() {
    struct MyQueue *MyQueueObj = NULL;
    return MyQueueObj;
}

void myQueuePush(MyQueue* MyQueueObj, int x) {
    struct MyQueue *temp = (struct MyQueue *)malloc(sizeof(struct MyQueue));
    temp->val = x;
    temp->next = NULL;

    if(!head) {
        head = temp;
        tail = temp;
    } else {
        tail->next = temp;
        tail = tail->next;
    }

    printf("Successfully pushed the value %d\n", x);
}

int myQueuePop(MyQueue* MyQueueObj) {
    if(head) {
        int x = head->val;
        head = head->next;
        return x;
    } else {
        return 0;
    }
}

int myQueuePeek(MyQueue* MyQueueObj) {
    if(head) {
        return head->val;
    } else {
        return 0;
    }
}

bool myQueueEmpty(MyQueue* MyQueueObj) {
    if(!head) {
        return true;
    } else {
        return false;
    }
}

void myQueueFree(MyQueue* MyQueueObj) {
    head = NULL;
    tail = NULL;
}

int main()
{
    int x;
    printf("Enter the value to be pushed into the MyQueue\n");
    scanf("%d", &x);

    MyQueue* obj = myQueueCreate();
    myQueuePush(obj, x);

    int param_2 = myQueuePop(obj);
    printf("The popped out value is %d\n", param_2);

    int param_3 = myQueuePeek(obj);
    printf("The value at the head is %d\n", param_3);

    bool param_4 = myQueueEmpty(obj);

    myQueueFree(obj);

    return 0;
}