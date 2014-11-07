using namespace std;
#include "string.h"
class Tree
{
	private:
		int m_value;
		char m_letter;
		Tree *m_left;
		Tree *m_right;
		bool m_leftSet;
		bool m_rightSet;
	public:
		Tree();
		Tree(int value, char letter);
		Tree(int value, char letter, Tree* left, Tree* right);
		string toString();
		int getValue();
		char getLetter();
		Tree* getLeft();
		Tree* getRight();
		bool isRightSet();
		bool isLeftSet();
};
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
bool Tree::isLeftSet()
{
	return m_leftSet;
}
bool Tree::isRightSet()
{
	return m_rightSet;
}
string Tree::toString()
{
	string s =  m_letter + string(" (") + to_string(m_value) + string(")");
	return s;
}
