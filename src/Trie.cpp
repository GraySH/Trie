//============================================================================
// Name        : Trie.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

class Trie
{
private:
	vector<char> vec;

public:
	struct Node
	{
		char w;
		Node* next[256];
		bool endMark;

		Node(char _w = ' ', bool _wordMark = false)
		{
			w = _w;
			endMark = _wordMark;

			for(int i = 0; i < 256; i++)
			{
				next[i] = NULL;
			}
		}
	};


	Trie()
	{
		initialize();
	}

	Node* root;


	void initialize()
	{
		root = new Node(' ', false);
		for(int i = 0; i < 250; i++)
		{
			root->next[i] = NULL;

		}
	}

	Node* getRoot()
	{
		return root;
	}

	Node* makeNewNode(char ch, bool _wordMark)
	{
		Node* newNode = new Node(ch, _wordMark);
		for(int i = 0; i < 256; i++)
		{
			newNode->next[i] = NULL;
		}
		newNode->endMark = _wordMark;
		newNode->w = ch;

		return newNode;
	}


	void insertWord(Node* node, string str)
	{
		Node* current = node;
		for(int i = 0; i < str.size(); i++)
		{
			char tempChar = str.at(i);
			if(current->next[tempChar] == NULL) //if next is null, make node and insert node
			{
				if( i == str.size() - 1)
				{
					Node* newNode = makeNewNode(str.at(i), true );
					current->next[str.at(i)] = newNode;

					//move pointer.
					current = current->next[str.at(i)];
				}
				else
				{
					Node* newNode = makeNewNode(str.at(i), false );
					current->next[str.at(i)] = newNode;
					//move pointer.
					current = current->next[str.at(i)];
					//cout << current->w;
				}
			}
			else //if node is not null, char is already in the trie, so just move to the pointer.
			{
				current = current->next[str.at(i)];
			}
		}
	}


	void getWord(Node* node, vector<char> wordVec)
	{
		Node* current = node;
		if(current == NULL)
			return;

		if(current != NULL)
		{
			//cout << current->w;
			wordVec.push_back(current->w);
			if(node->endMark == true)
			{
				for(char x : wordVec)
					cout << x;
			}

			for(int i = 0; i < wordVec.size(); i++)
			{
				getWord(node->next[i], wordVec);
			}
		}

		for(int i = 0; i < 256; i++)
		{
			getWord(node->next[i], wordVec);
		}
	}
};




int main()
{
	Trie myTrie;

	myTrie.insertWord(myTrie.getRoot(),"AAA");
	myTrie.insertWord(myTrie.getRoot(),"AAB");
	myTrie.insertWord(myTrie.getRoot(),"AAC");
	myTrie.insertWord(myTrie.getRoot(),"BAC");


	vector<char> tempVec;

	myTrie.getWord(myTrie.getRoot(), tempVec);



	return 0;
}
