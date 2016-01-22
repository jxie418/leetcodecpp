#include<string>
#include<iostream>

using namespace std;

class TrieNode {
public:
bool iskey;
TrieNode *children[26];
TrieNode () {
	iskey = false;
	memset(children,0,26 * sizeof(TrieNode*));
}
};
class Trie {
public:
	Trie() {
		root = new TrieNode();
	}
	void insert(string s) {
		TrieNode *node = root;
		for (int i = 0 ; i < s.size() ; i++) {
			if (node->children[s[i]-'a'] == NULL) {
				node->children[s[i] -'a'] = new TrieNode();
			}	
			node = node->children[s[i] - 'a'];
		}
		node->iskey = true;
	}
	bool search(string key) {
		TrieNode* node = root;
		for (int i = 0 ; i < key.size() ; i++) {
			if (node != NULL)
				node = node->children[key[i]-'a'];
			else 
				break; 
		}
		if ( node == NULL )
			return false;
		else 
			return node->iskey; 
	}
	bool startsWith(string prefix) {
		TrieNode * node = root;
		for (int i = 0; i < prefix.size() ; i++) {
			if ( node != NULL) {
				node = node->children[prefix[i]-'a'];
			} else {
				break;
			}
		}
                if (node == NULL)
			return false;
		else 
			return true; 
	}
private:
	TrieNode * root;
};

int main() {
Trie s;
return 0;
}
