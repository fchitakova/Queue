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
		Node(const T & d,Node<T>*prev=NULL,Node<T>*n=NULL):data(d),previous(prev),next(n) {}
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
	bool isEmpty()const;
	void Print(std::ostream&o)const;


private:
	
	void copyFrom(const LLQueue&other);
	void clear();

private:

	Node<T>*top;
	Node<T>*end;
};




#endif

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
	if (top == end)
	{
		delete top;
		end = top = NULL;
	 }
	 else if(!isEmpty() && top!=end)
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
 bool LLQueue<T>::isEmpty() const
{
	 return !top && !end;
}

 template<class T>
 void LLQueue<T>::Print(std::ostream&o) const
 {
	 if (!isEmpty())
	 {
		 Node<T>*temp = end;

		 while (temp)
		 {
			 o << temp->data << ' ';
			 temp = temp->previous;
		 }
		
		 o << '\n';
	 
	 }
 }
template <class T>
void LLQueue<T>::copyFrom(const LLQueue & other)
{
	if (!isEmpty())
	{
		clear();
	}

	if (other.isEmpty())
		return;

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



