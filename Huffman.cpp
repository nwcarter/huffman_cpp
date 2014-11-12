#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include "Tree.h"
#include "Stack.h"
using namespace std;

void printTree(Tree* t);
bool Compare(Tree *t1, Tree *t2);
void readFile(string filename, vector<Tree*> &v);
Tree* makeTree(vector<Tree*> &list);
void printCodes(Tree* tree, Stack<int> &stack);
string decode(Tree *root, string &code);

int main()
{
	vector<Tree *> list;
	Stack <int> s;
	string code("");

	readFile("letters.txt", list);
	sort(list.begin(), list.end(), Compare);
		
	Tree *tree = makeTree(list);
	printTree(tree);
	cout << "***********************************************" << endl;
	
	printCodes(tree, s);
	cout << "***********************************************" << endl;

	while(code != "Q")
	{
		cout << "Enter a code (Enter \"Q\" to quit): ";
		getline(cin, code);
		string message(decode(tree, code));
		if (code != "Q")
			cout << "Message: " << message << endl;
	}
	
	return 0;
}
void printTree(Tree* t)
{
	cout <<  t->toString() << endl;
	
	if (t->getLeft() != NULL)
	{
		printTree(t->getLeft());	
	}
	if (t->getRight() != NULL)
	{	
		printTree(t->getRight());
	}
	
}
bool Compare(Tree *t1, Tree *t2)
{
	return t1->getValue() < t2->getValue();
}

void readFile(string filename, vector<Tree*> & v)
{
	ifstream infile(filename.c_str());
	string line;
	while(getline(infile, line))
	{
		istringstream iss(line);
		char letter;
		int value;
		
		if (!(iss >> letter >> value)) 
		{
			cout << "File read error." << endl; 
			break; 
		}
	
		Tree *t = new Tree(value, letter);
		v.push_back(t);
	}
	return;
} 
Tree* makeTree(vector<Tree*> &list)
{
	int total;

	while(list.size() > 1)
	{
		Tree *t1 = list.at(0);
		Tree *t2 = list.at(1);
		total = t1->getValue() + t2->getValue();
		Tree *t = new Tree(total, '*', t1, t2);

		list.erase(list.begin(), list.begin()+2);
		list.push_back(t);

		sort(list.begin(), list.end(), Compare);
	}
	return list.at(0);
}
void printCodes(Tree *tree, Stack<int> &stack)
{
	if (tree->getLeft() != NULL)
	{
		stack.push(0);
		printCodes(tree->getLeft(), stack);
		stack.pop();
	}
	if (tree->getLetter() != '*')
		printf("%c: %s\n", tree->getLetter(), stack.reverseString().c_str());
	if (tree->getRight() != NULL)
	{
		stack.push(1);
		printCodes(tree->getRight(), stack);
		stack.pop();
	}
}
string decode(Tree *root, string &code)
{
	Tree *tree = root;
	string message("");

	for (int x = 0; x < code.length(); x++)
	{	
		if(code[x] == '0')
		{
			if (tree->getLeft() != NULL)
				tree = tree->getLeft();
		}
		else if (code[x] == '1')
		{
			if (tree->getRight() != NULL)
				tree = tree->getRight();
		}
		
		if(tree->getLetter() != '*')
		{
			message.append(1, tree->getLetter());
			tree = root;
		}
	}
	return message;
}
