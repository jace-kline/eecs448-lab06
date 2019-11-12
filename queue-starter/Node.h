/**
*	@file Node.h
*	@author John Gibbons
*	@date 2014.04.02
*/

#ifndef NODE_H
#define NODE_H

template <typename T>
class Node
{
	public:

	/**
	*	@post Creates a Node. Pointer set to nullptr and value stored.
	*/
	Node(T entry);

	/** 
	*	@return Pointer to next node.
	*/
	Node<T>* getNext() const;

	/** 
	*	@post The Node's m_next will point to the next passed in
	*/
	void setNext(Node<T>* next);

	
	/** 
	*	@return The entry in the node
	*/
	T getEntry() const;

	/** 
	*	@pre Entry is a valid T
	*	@post The entry is stored in the node
	*/
	void setEntry(T value);


	protected:
	T m_entry;
	Node<T>* m_next;


};

#include "Node.hpp"

#endif


