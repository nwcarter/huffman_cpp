#ifndef STACK_H
#define STACK_H

#include <string>
#include <vector>
using namespace std;

template <class T> class Stack
{
	private:
		vector<T> m_stack;
		int m_size;
	public:
		Stack();
		void push(T item);
		T pop();
		int size();
		string toString();
		string reverseString(Stack* stack);
}; 

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
	T retItem = m_stack.back();
	m_stack.pop_back();
	return retItem;
}
template <class T> int Stack<T>::size()
{
	return m_stack.size();
}
template <class T> string Stack<T>::reverseString(Stack* stack)
{
	return "hello";
}
template <class T> string Stack<T>::toString()
{
	string s = "Top->";
	for (int x = m_stack.size()-1; x >= 0; x--)
	{
		s.append(to_string(m_stack[x]));
		if (x != 0)
			s.append("->");
	}
	return s;
}

#endif