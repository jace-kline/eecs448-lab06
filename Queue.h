/**
*	@file Queue.h
*	@author John Gibbons
*	@date 2014.04.02
*/

#ifndef QUEUE_H
#define QUEUE_H

#include "QueueInterface.h"
#include "Node.h"
#include <stdexcept>

//This Queue class can only hold ints
class Queue : public QueueInterface<int>
{
	public:

	/**
	*	@post Creates an empty queue
	*/
	Queue();

	/**
	*	@post Deletes all entries in the queue
	*/
	~Queue();

	/**
	*	@return True if the queue is empty, false otherwise
	*/
	bool isEmpty() const;

	/** 
	*	@post Entry added to back of queue
	*	@param newEntry The object to be added as a new entry
	*/
	void enqueue(const int& newEntry);


	/** 
	*	@post Front of the queue is removed
	*	@return The value of the entry at the front of the queue
	*	@throw std::runtime_error if queue is empty
	*/
	void dequeue();

	/** 
	*	@pre The queue is not empty
	*	@post The value at the front is returned and the queue is unchanged
	*	@return The value of the entry at the front of the queue
	*	@throw std::runtime_error if queue is empty
	*/
	int peekFront() const;

	protected:
	Node<int>* m_front;
	Node<int>* m_back;

};

#endif

