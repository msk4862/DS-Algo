#include<bits/stdc++.h>
using namespace std;

class TrieNode
{
	char data;
	unordered_map<char, TrieNode*> childs;
	bool isTerminal;
	
public:
	TrieNode(char _data, bool _isTerminal = false) {
		data = _data;
		isTerminal = _isTerminal;
	}

	friend class Trie;
};

class Trie
{
	TrieNode* root;

public:
	Trie() {
		root = new TrieNode('\0');
	}
	void insertWord(string&);
	bool isPresent(string&);
};

// Insertion
void Trie::insertWord(string& word) {
	TrieNode* cur = root;
	for (int i = 0; i < word.size(); ++i) {
		// doesn't have child node with key word[i]
		if(cur->childs.count(word[i]) == 0) {
			cur->childs[word[i]] = new TrieNode(word[i]);

		}
		cur = cur->childs[word[i]];
	}

	// make last char as terminal
	cur->isTerminal = true;
}


// Lookup
bool Trie::isPresent(string& word) {
	TrieNode* cur = root;
	for (int i = 0; i < word.size(); ++i) {
		if(cur->childs.count(word[i]) == 0) return false;
		cur = cur->childs[word[i]];
	}

	return cur->isTerminal;
}


int main() {
	vector<string> words = {
		"apple", "ape", "coder", "coding", "hello bro", "bye"
	};

	Trie dictionary;
	for (int i = 0; i < words.size(); ++i) {
		dictionary.insertWord(words[i]);
	}

	string search;
	cout<<"Enter a word to search: ";
	getline(cin, search);

	if(dictionary.isPresent(search)) cout<<search<<" Found.";
	else cout<<search<<" Not found!";
	cout<<endl;
	return 0;
}