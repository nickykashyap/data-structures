/**Trie Implementation**/

#include <iostream>
#define ALPHABET_SIZE  26
using namespace std;

//Trie Data Structure
class Trie {
	bool isEndOfWord;
	Trie* child[ALPHABET_SIZE];
	
	bool haveChildren(Trie* curr) {
		for (int i = 0; i < ALPHABET_SIZE; i++)
			if (curr->child[i])
				return true;

		return false;
	}
	
public:
	Trie() {
		this->isEndOfWord = false;
		for (int i = 0; i < ALPHABET_SIZE; i++)
			this->child[i] = NULL;
	}

	void Insert(string);
	bool Search(string);
	void Remove(Trie*, string);
};

void Trie::Insert(string key) {
	Trie* curr = this;
	
	for (int i = 0; i < key.length(); i++) {
		if (!curr->child[key[i]-'a'])
			curr->child[key[i]-'a'] = new Trie();

		curr = curr->child[key[i]-'a'];
	}
	
	curr->isEndOfWord = true;
}

bool Trie::Search(string key) {
	Trie* curr = this;
	
	for (int i = 0; i < key.length(); i++) {
		curr = curr->child[key[i]-'a'];
		
		if (curr == NULL)
			return false;
	}
	
	return curr->isEndOfWord;
}

void Trie::Remove(Trie* curr, string key) {
	if (!curr)
		return;

	if (key.length() == 0)
		curr->isEndOfWord = false;
	else
		Remove(curr->child[key[0]-'a'], key.substr(1));
	
	if (!haveChildren(curr)) {
		delete curr;
		curr = NULL;
	}
}

int main() {
	Trie* dictionary = new Trie();

	dictionary->Insert("hello");
	dictionary->Insert("helloworld");
	dictionary->Insert("hell");
	dictionary->Insert("h");
	
	cout << dictionary->Search("hello") << " ";  	
	cout << dictionary->Search("helloworld") << " "; 
	cout << dictionary->Search("helll") << " ";
	cout << dictionary->Search("hell") << " ";
	cout << dictionary->Search("h") << endl;

	dictionary->Remove(dictionary, "hello");
	
	cout << dictionary->Search("hello") << " ";
	cout << dictionary->Search("helloworld") << " ";
	cout << dictionary->Search("hell") << " ";
	cout << dictionary->Search("h") << endl;

	dictionary->Remove(dictionary, "h");
	
	cout << dictionary->Search("h") << " ";
	cout << dictionary->Search("helloworld") << " ";
	cout << dictionary->Search("hell") << endl;

	return 0;
}
