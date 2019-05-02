//
//  graph.h
//  pa6
//
//  Created by Kim Nguyen on 4/15/19.
//  Copyright © 2019 Kim Nguyen. All rights reserved.
//

#ifndef graph_h
#define graph_h

#include <iostream>
#include <fstream>
#include <set>
#include <iterator>
#include <vector>
#include <cstdlib>
using namespace std;

struct ListNode{
    int value;
    struct ListNode* next;};

struct AdjList{
    struct ListNode *head;
};

class Graph{
public:
    int amount;
    struct AdjList* array;
    Graph(int amount);
    ListNode* newListNode(int value);
    void new_edge(int source, int value);
    void print();};

class Graphh{
public:
    int size;
    int a[13][13];
    Graphh(int size){this->size = size;}
    void new_edge(int u, int v){a[u][v]=1;a[v][u]=1;}
    void print();
    void draw(string d);
};



istream& operator>>(istream& in, pair<int,int>& v);
#endif
