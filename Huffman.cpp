#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include "Tree.h"
using namespace std;

void printTree(Tree* t);
bool Compare(Tree *t1, Tree *t2);
void readFile(string filename, vector<Tree*> &v);
Tree* makeTree(vector<Tree*> &list);

int main()
{
	vector<Tree *> list;
	readFile("letters.txt", list);
	printf("%s%d\n", "Size: ", (int)list.size());
	sort(list.begin(), list.end(), Compare);

	for (int x = 0; x < list.size(); x++)
	{
		cout << list[x]->toString() << endl;
	}
	
	
	Tree *tree = makeTree(list);
	
	cout << tree->toString() << endl;
	Tree *t1 = tree->getLeft();

	cout << tree->getLeft()->getValue() << endl;

	printTree(tree);


	return 0;
}
void printTree(Tree* t)
{
	cout <<  t->toString() << endl;
	
	if (t->isLeftSet())
	{
		printTree(t->getLeft());	
	}
	if (t->isRightSet())
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
		/*
		if (!(iss >> letter >> value)) 
		{
			cout << "Error" << endl; 
			break; 
		}
		*/
		iss >> letter >> value;
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
