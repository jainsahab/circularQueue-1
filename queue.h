typedef struct{
    int capacity;
    int typeSize;
    int front;
    int rear;
    void* elements;
} Queue;

typedef char String[256];

Queue* create(int typeSize,int capacity);

int isFull(Queue* queue);
int isEmpty(Queue* queue);

int enqueue(Queue* queue,void* element);
void* dequeue(Queue* queue);