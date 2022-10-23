#include "stackHead.h"
#include<iostream>
using namespace std;
template <class T>
Stack<T>::Stack() {
	top = NULL;
	count = 0;
}
template <class T>
Stack<T>::~Stack() {
	empty();
}
template <class T>
void Stack<T>::empty() {
	nodeStack<T>* p;
	while (top!=NULL)
	{
		p = top;
		top = top->next;
		delete p;
	}
	count = 0;
}
template <class T>
T Stack<T>::peep() {
	try {
		if (!isEmpty())
			return top->data;
		else
		{
			throw EmptyStackException();
		}
	}
	catch (EmptyStackException e) {
		cout << e.what();
	}
	
}
template <class T>
int Stack<T>::getCount() {
	return count;
}
template <class T>
bool Stack<T> ::isEmpty() {
	if (getCount() == 0)
		return true;
	return false;
}
template <class T>
void Stack<T>::push(T data) {
	nodeStack<T>* p;
	p = new(nothrow) nodeStack<T>;
	if (p == NULL)
		throw MemoryException();
	else {
		p->data = data;
		p->next=top;
		top = p;
		count++;
	}
}
template <class T>
T Stack<T>::pop() {
	T val;
	nodeStack<T>* p;
	try {
		if (isEmpty())
			throw EmptyStackException();

	}
	catch (EmptyStackException ex) {
		cout << ex.what();
	}
		p = top;
		val = p->data;
		top=p->next;
		delete p;
		count--;
	return val;
}
