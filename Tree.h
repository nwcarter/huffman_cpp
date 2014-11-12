#ifndef TREE_H
#define TREE_H

#include <string>
using namespace std;

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
};

#endif
