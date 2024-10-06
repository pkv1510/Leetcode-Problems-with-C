#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int front;
    int rear;
    int* queue;
    int size;
} RecentCounter;

int isQueueEmpty(RecentCounter* obj) {
    if(obj->front == -1)
        return true;
    else 
        return false;
}

int isQueueFull(RecentCounter(obj)) {
    if(((obj->rear + 1) % obj->size) == obj->front)
        return true;
    else
        return false;
}

void enQueue(Recentcounter* obj, int value) {
    if(isQueueFull(obj)) {
        printf("!!WARNING!! : Queue is Full\n");
        return;
    }
    obj->rear = (obj->rear + 1) % obj->size;
    obj->queue[obj->rear] = value;

    // update the front as the deQueue Operation start at front
    if(obj->front == -1)
        obj->front = 0;
}

int deQueue(RecentCounter* obj) {
    int ret = -1;
    if(isQueueEmpty(obj))
        return ret;

    ret = obj->queue[obj->front];
    if(obj->front == obj->rear) {
        // Reinit the queue as it hass gone empty
        obj->front = -1;
        obj->rear = -1;
    } else {
        obj->front = (obj->front + 1) % obj->size; 
    }
    return ret;
}

RecentCounter* recentCounterCreate() {
    RecentCounter* p = (RecentCounter*)malloc(sizeof(RecentCounter));
    p->front = -1;
    p->rear = -1;
    p->size = 10000;
    p->queue = (int*)malloc(sizzeof(int) * p->sizze);

    return p;
}

int recentCounterPing(RecentCounter* obj, int t) {
    if(t <=  3000) {
        // If the timestamp is lesss than 3000
        enQueue(obj, t);
    } else {
        /* If the timestamp is greater than 3000
        *  Then deQueue the element if the timestamp at front(deleting Pos)
        *  should be in the range of 3000*/
        while(!isQueueEmpty(obj) && (t - obj->queue[obj->front]) > 3000) {
            int deQueueVal = deQueue(obj);
        }
        enQueue(obj, t);
    }
    // Return total number of eleemnts inn the range of 3000
    return (obj->rear - obj->front + 1);
}

void recentCounterFree(RecentCounter* obj) {
    free(obj);
}

/**
 * Your RecentCounter struct will be instantiated and called as such:
 * RecentCounter* obj = recentCounterCreate();
 * int param_1 = recentCounterPing(obj, t);
 
 * recentCounterFree(obj);
*/

int main() {
    
    RecentCounter* obj = recentCounterCreate();
    int count = recentCounterPing(obj, t);

    recentCounterFree(obj);
    return 0;
}
