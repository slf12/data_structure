//
//  BST.cpp
//  BST
//
//  Created by slf on 2018/5/23.
//  Copyright © 2018年 slf. All rights reserved.
//

#include "BST.hpp"
#include <iostream>
using namespace std;

void BST::clear(){
    if(root == NULL)
        return;
    makeEmpty(root);

}

Node* BST::makeEmpty(Node *p){
    if(p == NULL)
        return NULL;
    makeEmpty(p->left);
    makeEmpty(p->right);
    delete p;
    return NULL;
}

Node* BST::insert(int data, Node* p){
    if(p == NULL){
        p = new Node;
        p->val = data;
        p->left = NULL;
        p->right = NULL;
    }
    else if(data < p->val){
        p->left = insert(data, p->left);
    }
    else if(data > p->val){
        p->right = insert(data, p->right);
    }
    return p;
}

Node* BST::searchNode(int data, Node *p){
        if(p == NULL)
            return NULL;
        if(p->val == data)
            return p;
        else if(data < p->val)
            return searchNode(data, p->left);
        else{
            return searchNode(data, p->right);
        }

    }

Node* BST::findMin(Node *p){
    if(p == NULL)
        return  NULL;
    if(p->left == NULL)
        return p;
    return findMin(p->left);
}

Node* BST::remove(int data, Node* p){
    Node* temp;
    if(p == NULL)
        return NULL;
    if(data < p->val)
        p->left = remove(data, p->left);
    else if(data > p->val)
        p->right = remove(data, p->right);
    else if(p->left != NULL && p->right != NULL){
        temp = findMin(p->right);
        p->val = temp->val;
        p->right = remove(temp->val, p->right);
    }
    else if(p->left == NULL){
        temp = p;
        p = p->right;
        delete temp;

    }
    else{
        temp = p;
        p =  p->left;
        delete temp;

    }

    return p;
}

void BST::inorder(Node* p){
    if(p == NULL)
        return;
    inorder(p->left);
    cout << p->val << " ";
    inorder(p->right);
}

void BST::preorder(Node* p){
    if(p == NULL)
        return;
    cout << p->val << " ";
    preorder(p->left);
    preorder(p->right);

}


bool BST::searchNum(int data){
     Node* temp = searchNode(data, root);
    if(temp == NULL)
        return false;
    return true;
}

void BST::insert(int data){
    root = insert(data, root);
}

void BST::display(){
    cout << "inorder: ";
    inorder(root);
    cout << endl;
    cout << "preorder: ";
    preorder(root);
    cout << endl;
}

void BST::remove(int data){
    root = remove(data, root);
}

