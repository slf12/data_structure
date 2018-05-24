//
//  main.cpp
//  BST
//
//  Created by slf on 2018/5/23.
//  Copyright © 2018年 slf. All rights reserved.
//

#include <iostream>
#include "BST.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    BST t;
    t.insert(20);
    t.insert(25);
    t.insert(15);
    t.insert(10);
    t.insert(30);
    t.insert(12);
    t.insert(22);
    t.insert(32);
    t.display();
    t.remove(20);
    t.display();
    t.remove(25);
    t.display();
    t.remove(30);
    t.display();
    cout << t.searchNum(20) << endl;
    cout << t.searchNum(15) << endl;
    return 0;
}
