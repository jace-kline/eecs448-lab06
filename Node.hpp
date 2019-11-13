/**
*	@file Node.hpp
*	@author John Gibbons
*	@date 2014.04.02
*/

template <typename T>
Node<T>::Node(T entry) : m_entry(entry), m_next(nullptr)
{ }


template <typename T>
Node<T>* Node<T>::getNext() const
{
	return(m_next);
}


template <typename T>
void Node<T>::setNext(Node<T>* next)
{
	m_next = next;
}


template <typename T>
T Node<T>::getEntry() const
{
	return(m_entry);
}


template <typename T>
void Node<T>::setEntry(T entry)
{
	m_entry = entry;
}
