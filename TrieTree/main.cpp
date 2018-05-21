//
//  main.cpp
//  TrieTree
//
//  Created by slf on 2018/5/21.
//  Copyright © 2018年 slf. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

const int   ALPHABET_SIZE = 26;

struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;
    TrieNode()
    {
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            children[i] = NULL;
        }
        isEndOfWord = false;
    }
};

class Trie{

private:
    struct TrieNode* root;
    
public:
    Trie()
    {
        root = new TrieNode();
        
    }
    void insert(string word){
        TrieNode *p = root;
        for(char c : word){
            c = tolower(c);
            if(p->children[c-'a'] == NULL)
                p->children[c-'a'] = new TrieNode();
            p = p->children[c-'a'];
        }
        p->isEndOfWord = true;
        
    }
    
    bool search(string word){
        TrieNode* p = root;
        for(char c : word){
            c = tolower(c);
            if(p->children[c-'a'] == NULL)
                return false;
            p = p->children[c-'a'];
        }
        return (p!=NULL && p->isEndOfWord);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Trie tire;
    tire.insert("string");
    tire.insert("apple");
    tire.insert("word");
    tire.insert("noodle");
    tire.insert("noodl");
    cout << tire.search("strinj") << endl;
    cout << tire.search("noodl") << endl;
    return 0;
}
