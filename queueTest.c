#include "testUtils.h"
#include <string.h>
#include "queue.h"
#include <stdlib.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int areEqual(Queue* actual,Queue* expected){
	int res = (actual->typeSize == expected->typeSize) &&
				(actual->capacity == expected->capacity);
	if(!res)
		 return res;
	res = memcmp(actual->elements,expected->elements,actual->capacity*actual->typeSize);
	return 0==res;
};

void dispose(Queue* queue){
	free(queue->elements);
	free(queue);
};

int checkQueueElements(Queue* queue,void* elements,int front){
	int i=0;
	if(queue->front != front)
		return 0;
	return 0 == memcmp(queue->elements,elements,queue->capacity*queue->typeSize);
};

typedef struct{
	int data;
	char ch;
} Simple;

void test_creation_of_Queue_of_three_integers(){
	Queue* actual = create(sizeof(int),3);
	int expected_arr[3] = {0,0,0};
	Queue expected = {3,sizeof(int),0,-1,expected_arr};
	ASSERT(areEqual(actual,&expected));
	dispose(actual);
};

void test_creation_of_Queue_of_three_characters(){
	Queue *actual = create(sizeof(char),3);
	char expected_arr[3] = {0,0,0};
	Queue expected = {3,sizeof(char),0,-1,expected_arr};
	ASSERT(areEqual(actual,&expected));
	dispose(actual);
};

void test_creation_of_Queue_of_three_floats(){
	Queue *actual = create(sizeof(float),3);
	float expected_arr[3] = {0.0f,0.0f,0.0f};
	Queue expected = {3,sizeof(float),0,-1,expected_arr};
	ASSERT(areEqual(actual,&expected));
	dispose(actual);
};

void test_creation_of_Queue_of_three_doubles(){
	Queue *actual = create(sizeof(double),3);
	double expected_arr[3] = {0.0,0.0,0.0};
	Queue expected = {3,sizeof(double),0,-1,expected_arr};
	ASSERT(areEqual(actual,&expected));
	dispose(actual);
};

void test_creation_of_Queue_of_three_strings(){
	Queue *actual = create(sizeof(String),3);
	String expected_arr[3] = {"","",""};
	Queue expected = {3,sizeof(String),0,-1,expected_arr};
	ASSERT(areEqual(actual,&expected));
	dispose(actual);
};

void test_creation_of_Queue_of_three_structures(){
	Queue* actual = create(sizeof(Simple),3);
	Simple *s = calloc(3,sizeof(Simple));
	Queue expected = {3,sizeof(Simple),0,-1,s};
	ASSERT(areEqual(actual,&expected));
	dispose(actual);
};

void test_inserting_an_integer_element_to_Queue(){
	Queue* q = create(sizeof(int),3);
	int element = 10;
	int elements[3] = {10,0,0};
	int res = enqueue(q,&element);
	ASSERT(res == 1);
	ASSERT(checkQueueElements(q,elements,0));
	dispose(q);
};

void test_inserting_an_character_element_to_Queue(){
	Queue* Queue = create(sizeof(char),3);
	char element = 'a';
	char elements[3] = {'a',0,0};
	int res = enqueue(Queue,&element);
	ASSERT(res == 1);
	ASSERT(checkQueueElements(Queue,elements,0));
	dispose(Queue);
};

void test_inserting_an_float_element_to_Queue(){
	Queue* Queue = create(sizeof(float),3);
	float element = 10.0f;
	float elements[3] = {10.0f,0.0f,0.0f};
	int res = enqueue(Queue,&element);
	ASSERT(res == 1);
	ASSERT(checkQueueElements(Queue,elements,0));
	dispose(Queue);
};

void test_inserting_an_double_element_to_Queue(){
	Queue* Queue = create(sizeof(double),3);
	double element = 10.0;
	double elements[3] = {10.0,0.0,0.0};
	int res = enqueue(Queue,&element);
	ASSERT(res == 1);
	ASSERT(checkQueueElements(Queue,elements,0));
	dispose(Queue);
};

void test_inserting_an_String_element_to_Queue(){
	Queue* Queue = create(sizeof(String),3);
	String element = "abc";
	String elements[3] = {"abc","",""};
	int res = enqueue(Queue,&element);
	ASSERT(res == 1);
	ASSERT(checkQueueElements(Queue,elements,0));
	dispose(Queue);
};

void test_inserting_an_strucure_element_to_Queue(){
	Queue* Queue = create(sizeof(Simple),3);
	Simple *element = calloc(1,sizeof(Simple));
	Simple *emptyElement = calloc(1,sizeof(Simple));
	Simple* elements = calloc(3,sizeof(Simple));
	int res;
	element->data = 10;
	element->ch ='a';
	elements[0].data = 10;
	elements[0].ch = 'a';
	res = enqueue(Queue,element);
	ASSERT(res == 1);
	ASSERT(checkQueueElements(Queue,elements,0));
	dispose(Queue);
};

void test_isFull_gives_1_if_Queue_is_full(){
	int expected_arr[3] = {0,0,0};
	Queue queue = {3,sizeof(int),0,2,expected_arr};
	int result = isFull(&queue);
	ASSERT(1 == result);
};

void test_isFull_gives_0_if_Queue_is_not_full(){
	double expected_arr[3] = {0.0,0.0,0.0};
	Queue queue = {3,sizeof(double),0,1,expected_arr};
	int result = isFull(&queue);
	ASSERT(0 == result);
};

void test_isEmpty_returns_1_if_the_Queue_is_empty(){
	Queue* queue = create(sizeof(int), 3);
	int result = isEmpty(queue);
	ASSERT(1 == result);
	dispose(queue);
};

void test_isEmpty_returns_0_if_the_Queue_is_not_empty(){
	Queue* queue = create(sizeof(int), 3);
	int data = 10;
	int element = enqueue(queue,&data);
	int result = isEmpty(queue);
	ASSERT(0 == result);
	dispose(queue);
};

void test_deleting_an_integer_element_from_Queue(){
	Queue* queue = create(sizeof(int), 3);
	int* result;
	int status ,element = 10;
	status = enqueue(queue, &element);
	result = dequeue(queue);
	ASSERT(*result == element);
	ASSERT(queue->rear-1 == -1);
	dispose(queue);
};

void test_deleting_an_character_element_from_Queue(){
	Queue* Queue = create(sizeof(char), 3);
	char* result;
	int status;
	char element = 'a';
	status = enqueue(Queue, &element);
	result = dequeue(Queue);
	ASSERT(*result == 'a');
	ASSERT(Queue->rear-1 == -1);
	dispose(Queue);
};

void test_deleting_an_double_element_from_Queue(){
	Queue* Queue = create(sizeof(double), 3);
	double* result;
	int status;
	double element = 10.0;
	status = enqueue(Queue, &element);
	result = dequeue(Queue);
	ASSERT(*result == 10.0);
	ASSERT(Queue->rear-1 == -1);
	dispose(Queue);
};

void test_deleting_an_float_element_from_Queue(){
	Queue* Queue = create(sizeof(float), 3);
	float* result;
	int status;
	float element = 10.0;
	status = enqueue(Queue, &element);
	result = dequeue(Queue);
	ASSERT(*result == 10.0);
	ASSERT(Queue->rear-1 == -1);
	dispose(Queue);
};

void test_deleting_an_String_element_from_Queue(){
	Queue* Queue = create(sizeof(String), 3);
	String* result;
	int status;
	String element = "abc";
	status = enqueue(Queue, &element);
	result = dequeue(Queue);
	ASSERT(0 == strcmp(*result,"abc"));
	ASSERT(Queue->rear-1 == -1);
	dispose(Queue);
};

void test_deleting_an_integer_element_when_the_Queue_is_empty(){
	Queue* Queue = create(sizeof(int), 3);
	int* result;
	result = dequeue(Queue);
	ASSERT(NULL == result);
	dispose(Queue);
};