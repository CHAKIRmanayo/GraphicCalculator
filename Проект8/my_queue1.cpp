#include "my_queue1.h"
#include <stdio.h>
#include <conio.h>
#include <string.h> 

MyQueue initMyQueue(){

	MyQueue q;
	return q;
}

Iterator begin(MyQueue q){
	Iterator i = { q.front };
	return i;
}

bool isFront(MyQueue q){
	return(q.front);
}

bool isBack(MyQueue q){
	return(q.back);
}

bool operator==(Iterator a, Iterator b) {
	return a.current == b.current;
}

bool operator!=(Iterator a, Iterator b) {
	return a.current != b.current;
}

bool hasCurrent(Iterator i) {
	return i.current != nullptr;
}

char* getNext(Iterator i) {
	bool res = i.current->next;
	if (res)
		return(i.current->next->value);
}

char* get(Iterator i) {
	return i.current->value;
}

bool hasNext(Iterator i) {
	return i.current->next != nullptr;
}

bool moveNext(Iterator &i) {
	bool res = i.current->next;
	i.current = i.current->next;
	return res;
}

bool popFront(MyQueue& q, char* v) {
	if (!isFront(q)) {
		Node1*temp = q.front;
		v = q.front->value;
		q.front = q.front->next;
		delete temp;
	}
	return !isFront(q);
}

char* peekQ(MyQueue q) {
	return(q.front->value);
}

void clearQ(MyQueue& q) {
	while (q.front) {
		Node1*temp = q.front;
		q.front = q.front->next;
		delete temp;
	}
}

void pushBackStr(MyQueue& q, char* v) {
	Node1*n = new Node1;
	n->value = v;
	if (!isBack(q)) {
		q.front = n;
		q.back = n;
	}
	else {
		q.back->next = n;
		q.back = n;
	}
	q.back->next = nullptr;
}

MyQueue clone(MyQueue q) {
	Node1*temp = q.front;
	MyQueue q1 = initMyQueue();
	while (temp)
	{
		pushBackStr(q1, temp->value);
		temp = temp->next;
	}
	delete temp;
	return q1;
}