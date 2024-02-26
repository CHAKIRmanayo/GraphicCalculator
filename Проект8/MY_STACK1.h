#ifndef MY_STACK1_H
#define MY_STACK1_H
#include <stdio.h>

template <typename T>
struct Node
{
	T value;
	Node<T>* next;
};

template <typename T>
struct Stack
{
	Node<T>* top;
	Stack<T>(){
		top = nullptr;
	}
};

template <typename T>
Stack<T> initStack(){
	Stack<T> s;
	return s;
}

template <typename T>
bool pop(Stack<T>& s, T& v) {
	if (!isEmptyS(s))
	{
		Node<T>*temp = s.top;
		v = s.top->value;
		s.top = s.top->next;
		delete temp;
	}
	return !isEmptyS(s);
}

template <typename T>
void push(Stack<T>& s, T v) {
	Node<T>*n = new Node<T>;
	n->value = v;
	n->next = s.top;
	s.top = n;
}

template <typename T>
bool isEmptyS(Stack<T> s){
	return !s.top;
}

template <typename T>
T peekS(Stack<T> s){
	return s.top->value;
}

template <typename T>
void clearS(Stack<T>& s) {
	while (s.top)
	{
		Node<T>*temp = s.top;
		s.top = s.top->next;
		delete temp;
	}
}
#endif