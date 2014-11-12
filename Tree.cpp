#include <stdio.h>
#include "Tree.h"

Tree::Tree()
{
	m_value = -1;
	m_letter = '*';
	m_left = NULL;
	m_right = NULL;
	m_leftSet = false;
	m_rightSet = false;
}
Tree::Tree(int value, char letter)
{
	m_value = value;
	m_letter = letter;
	m_left = NULL;
	m_right = NULL;
	m_leftSet = false;
	m_rightSet = false;
}
Tree::Tree(int value, char letter, Tree *left, Tree *right)
{
	m_value = value;
	m_letter = letter;
	m_left = left;
	m_right = right;
	m_leftSet = true;
	m_rightSet = true;
}
int Tree::getValue()
{
	return m_value;
}
char Tree::getLetter()
{
	return m_letter;
}
Tree* Tree::getLeft()
{
	return m_left;
}
Tree* Tree::getRight()
{
	return m_right;
}
string Tree::toString()
{
	char buffer[50];
	sprintf(buffer, "%c (%d) ", m_letter, m_value);
	string s(buffer);
	return s;
}