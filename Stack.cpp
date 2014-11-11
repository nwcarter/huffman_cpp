#include <stdio.h>
#include "Stack.h"

template <class T> Stack<T>::Stack()
{
	m_size = 0;
}
template <class T> void Stack<T>::push(T item)
{
	m_stack.push_back(item);
}
template <class T> T Stack<T>::pop()
{
	return m_stack.pop_back();
}
template <class T> int Stack<T>::size()
{
	return m_stack.size();
}
template <class T> string Stack<T>::reverse(Stack* stack)
{
	return "hello";
}