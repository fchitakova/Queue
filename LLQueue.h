#pragma once
#ifndef LLQUEUE_H
#define LLQUEUE_H

#include <iostream>

template <class T>
class LLQueue
{
private:
	template <class T>
	class Node
	{
	public:
		T data;
		Node<T>*previous;
		Node<T>*next;
		Node(T d,Node<T>*prev=NULL,Node<T>*n=NULL):data(d),previous(prev),next(n) {}
	};
public:
	LLQueue();
	LLQueue(const LLQueue&other);
	LLQueue&operator=(const LLQueue&other);
	~LLQueue();

public:
	void Enqueue(const T&element);
	void Dequeue();
	T getFront()const;
	T getLast()const;
	bool isEmpty()const;
private:
	void copyFrom(const LLQueue&other);
	void clear();
private:
	Node<T>*top;
	Node<T>*end;
};



template<class T>
LLQueue<T>::LLQueue()
{
	top = end = NULL;
}

template<class T>
LLQueue<T>::LLQueue(const LLQueue & other):top(NULL),end(NULL) 
{
	copyFrom(other);
}

template<class T>
LLQueue<T> & LLQueue<T>::operator=(const LLQueue & other)
{
	if (this != &other)
	{
		copyFrom(other);
	}
	return *this;
}

template<class T>
 LLQueue<T>::~LLQueue()
{
	 clear();
}

 template<class T>
 void LLQueue<T>::Enqueue(const T & element)
 {
	 if (!isEmpty())
	 {
		 Node<T>*temp = top;
		 top = new Node<T>(element,NULL,temp);
		 temp->previous = top;
	 }
	 else
	 {
		 top = new Node<T>(element);
		 end = top;
	 }
 }

template<class T>
void LLQueue<T>::Dequeue()
 {
	 if (!isEmpty())
	 {
		 Node<T>*temp = end->previous;
		 delete end;
		 temp->next = NULL;
		 end = temp;
	 }

 }

 template<class T>
 T LLQueue<T>::getFront() const
 {
	 return end->data;
 }

 template<class T>
 T LLQueue<T>::getLast() const
 {
	 return top->data;
 }

template<class T>
 bool LLQueue<T>::isEmpty() const
{
	 return !top && !end;
}

template <class T>
void LLQueue<T>::copyFrom(const LLQueue & other)
{
	if (other.isEmpty())
		return;
	
	clear();

	//pointer to other's top node
	Node<T>*tempOther = other.top;
	
	Node<T>*temp = new Node<T>(tempOther->data);
	top = temp;


	tempOther = tempOther->next;

	while (tempOther)
	{
		temp->next = new Node<T>(tempOther->data,temp);
		temp = temp->next;
		tempOther = tempOther->next;
	}
	end = temp;
	temp->next = NULL;
}


template<class T>
void LLQueue<T>::clear()
{
	if (!isEmpty())
	{
		Node<T>*temp;
		while (top)
		{
			temp = top;
			top = top->next;
			delete temp;
		}
		top = end = NULL;
	}
}

#endif
