#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include "Huffman.h"
using namespace std;

void printTree(Tree* t);
bool Compare(Tree t1, Tree t2);
vector<Tree> readFile(string filename);
void makeTree(vector<Tree> *list);

int main()
{
	vector<Tree> list = readFile("letters.txt");
	printf("%s%d\n", "Size: ", (int)list.size());
	
	sort(list.begin(), list.end(), Compare);

	makeTree(&list);

	for (int x = 0; x < list.size(); x++)
	{
		cout << list[x].toString() << endl;
	}	



	

//	printTree(&tree);
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
bool Compare(Tree t1, Tree t2)
{
	return t1.getValue() < t2.getValue();
}
vector<Tree> readFile(string filename)
{
	std::vector<Tree> v;
	ifstream infile(filename);
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
		Tree t(value, letter);
		v.push_back(t);
	}
	return v;
} 
void makeTree(vector<Tree> *list)
{

}