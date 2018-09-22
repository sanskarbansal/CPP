#include "TrieNode.h"
#include<string>
#include<iostream>
using namespace std;
class Trie {
    TrieNode *root;
  public:
    Trie() {
        root = new TrieNode('\0');
    }

    void insertWord(TrieNode *root, string word) {
        // Base case
        if(word.size() == 0) {
            root -> isTerminal = true;
            return;
        }
        // Small Calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if(root -> children[index] != NULL) {
            child = root -> children[index];
        }else {
            child = new TrieNode(word[0]);
            root -> children[index] = child;
        }

        // Recursive call
        insertWord(child, word.substr(1));
    }

    // For user
    void insertWord(string word) {
        insertWord(root, word);
    }
  private:
  	bool search_helper(string word, TrieNode* root){
      if(word.length() == 0){
        return false;
      }
      int index = word[0] - 'a';
      TrieNode *child = root ->  children[index];
      if(child == NULL){
        return false;
      }else if(word.length() == 1 && child -> isTerminal){
        return true;
      }
      return search_helper(word.substr(1), child);
    }

  	void autoComplete_helper(TrieNode* child, vector<string> input, string output){
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
          autoComplete_helper(temp, input, t);
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
      autoComplete_helper(t, input, temp);
    }
    bool search(string word) {
     return search_helper(word, root);
    }
};
