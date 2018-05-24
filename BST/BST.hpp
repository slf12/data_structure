//
//  BST.hpp
//  BST
//
//  Created by slf on 2018/5/23.
//  Copyright © 2018年 slf. All rights reserved.
//

#ifndef BST_hpp
#define BST_hpp

#include <iostream>
using namespace std;

#endif /* BST_hpp */
struct Node {
    int val;
    Node * left;
    Node * right;
};

class BST{
private:
    Node *root;
    void clear();
    
    Node* makeEmpty(Node *p);
    Node* insert(int data, Node* p);
    
    Node* searchNode(int data, Node *p);
    Node* findMin(Node *p);
    Node* remove(int data, Node* p);
    void inorder(Node* p);
    void preorder(Node* p);
public:
    
    Node* search(int data);
    BST(){
        root = NULL;
    }
    ~BST(){
        clear();
    }
    void insert(int data);
    void remove(int data);
    void display();
    bool searchNum(int data);
};
