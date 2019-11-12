/**
*	@file QueueInterface.h
*	@author John Gibbons
*	@date 2014.04.02
*/

#ifndef QUEUE_INTERFACE_H
#define QUEUE_INTERFACE_H
#include <stdexcept>

template <typename T>
class QueueInterface
{
	public:
	/**
	*	@pre The queue is in a valid state
	*	@post Deletes the entire queue
	*/	
	virtual ~QueueInterface() {}

	/**
	*	@return True if the queue is empty, false otherwise
	*/
	virtual bool isEmpty() const = 0;

	/** 
	*	@post Entry added to back of queue
	*	@param newEntry The object to be added as a new entry
	*/
	virtual void enqueue(const T& newEntry) = 0;


	/** 
	*	@post Front of the queue is removed
	*	@return The value of the entry at the front of the queue
	*	@throw std::runtime_error if queue is empty
	*/
	virtual void dequeue() = 0;

	/** 
	*	@pre The queue is not empty
	*	@post The value at the front is returned and the queue is unchanged
	*	@return The value of the entry at the front of the queue
	*	@throw std::runtime_error if queue is empty
	*/
	virtual T peekFront() const = 0;
	
	
};

#endif
