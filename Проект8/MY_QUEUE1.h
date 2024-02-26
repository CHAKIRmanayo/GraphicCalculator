#ifndef MY_QUEUE1_H
#define MY_QUEUE1_H
#include <stdio.h>


struct Node1
{
	char* value;
	Node1* next;
};


struct MyQueue
{
	Node1* front;
	Node1* back;
	MyQueue(){
		front = nullptr;
		back = nullptr;
	}
};

struct Iterator
{
	Node1* current;
};

Iterator begin(MyQueue);

MyQueue initMyQueue();

bool isFront(MyQueue);

bool isBack(MyQueue);

bool operator==(Iterator, Iterator);

bool operator!=(Iterator, Iterator);

bool popFront(MyQueue&, char*);

char* peekQ(MyQueue);

void clearQ(MyQueue&);

void pushBackStr(MyQueue&, char*);

MyQueue clone(MyQueue);

char* printq(MyQueue);

Iterator end(MyQueue);

bool moveNext(Iterator&);

bool hasNext(Iterator);

char* get(Iterator);

bool deleteNext(MyQueue&, Iterator);

bool hasCurrent(Iterator);

char* getNext(Iterator);

#endif