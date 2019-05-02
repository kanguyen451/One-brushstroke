//
//  graph.cpp
//  pa6
//
//  Created by Kim Nguyen on 4/16/19.
//  Copyright © 2019 Kim Nguyen. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "graph.h"
using namespace std;

Graph::Graph(int amount){
    this->amount = amount;
    array = new AdjList [amount];
    for (int i = 0; i < amount; ++i){array[i].head = NULL;}}

ListNode* Graph::newListNode(int value){
    ListNode* add = new ListNode;
    add->value = value;
    add->next = NULL;
    return add;}

void Graph::new_edge(int source, int value){
    ListNode* add = newListNode(value);
    add->next = array[source].head;
    array[source].head = add;
    add = newListNode(source);
    add->next = array[value].head;
    array[value].head = add;}

void Graph::print(){
    int v;
    for (v = 1; v < amount; ++v){
        ListNode* pc = array[v].head;
        cout<<"\nAdj list of "<<v<<":\n"<<v;
        while (pc){cout<<" -> "<<pc->value; pc = pc->next;}
        cout<<endl;}}

void Graphh::print(){
    cout<<"\nThis is the adjacency matrix of the graph:\n";
    for(int i=1;i<this->size;++i){
        for(int j=1; j<this->size; ++j){cout<<a[i][j]<<" ";}
        cout<<endl;
    }
}

void Graphh::draw(string d){
    if(d=="graph1.data"){cout<<endl<<"1 - 2 - 4"<<endl<<"  \\ | \\ |"<<endl<<"    3 - 5"<<endl;}
    if(d=="graph2.data"){cout<<endl<<"    3"<<endl<<"  / |"<<endl<<"1 - 2"<<endl<<"    | \\"<<endl<<"    4 - 5"<<endl;}
    if(d=="graph4.data"){cout<<endl<<"        6 - - -"<<endl<<"       / \\  / /"<<endl<<"      /  / / /"<<endl<<"1 - 3 - 5 / /"<<endl; cout<<"  \\      / /"<<endl<<"    2 - 4 /"<<endl<<"     \\   /"<<endl<<"       7"<<endl;}
    if(d=="graph5.data"){cout<<"    1   5"<<endl<<"  / | / |"<<endl<<"3 - 2 - 4"<<endl;}}

istream& operator>>(istream& in, pair<int,int>& v){
    int num1, num2;
    in>>num1>>num2;
    v = make_pair(num1, num2);
    return in;}

