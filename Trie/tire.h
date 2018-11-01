// #include "TrieNode.h"
#include <string>
#include <vector>
class TrieNode {
	public :
	char data;
	TrieNode **children;
	bool isTerminal;

	TrieNode(char data) {
		this -> data = data;
		children = new TrieNode*[26];
		for(int i = 0; i < 26; i++) {
			children[i] = nullptr;
		}
		isTerminal = false;
	}
};

class Trie {
	TrieNode *root;

	public :
	int count;

	Trie() {
		this->count = 0;
		root = new TrieNode('\0');
	}

	bool insertWord(TrieNode *root, string word) {
		// Base case
		if(word.size() == 0) {
			if (!root->isTerminal) {
				root -> isTerminal = true;
				return true;	
			} else {
				return false;
			}
		}

		// Small Calculation
		int index = word[0] - 'a';
		TrieNode *child;
		if(root -> children[index] != NULL) {
			child = root -> children[index];
		}
		else {
			child = new TrieNode(word[0]);
			root -> children[index] = child;
		}

		// Recursive call
		return insertWord(child, word.substr(1));
	}

	// For user
	void insertWord(string word) {
		if (insertWord(root, word)) {
			this->count++;
		}
	}
    
  private:
  	void helper(TrieNode* child, vector<string> input, string output){
      if(child == NULL){
        return;
      }     
      if(child -> isTerminal){
        cout << output << endl;
      }
      for(int i = 0; i < 26; i++){
        TrieNode *temp;
        if(child -> children[i]!= NULL){
          temp = child -> children[i];
          string t = output + temp -> data;
          helper(temp, input, t);
        }
      }
    }
  
  public:
  
    void autoComplete(vector<string> input, string pattern) {
      string temp = "";
      int index = pattern[0] - 'a';
      for(int i = 0; i < input.size(); i++){
        insertWord(input[i]);
      }
      TrieNode* t = root -> children[index];
      temp = pattern[0];
      int i = 1;
      while(temp != pattern &&  t != NULL){
        index = pattern[i] - 'a';
        temp = temp + pattern[i];
        t = t -> children[index];
        i++;
      }
      helper(t, input, temp);
 
    }
};
